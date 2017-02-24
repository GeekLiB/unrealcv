// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "Networking.h"
#include "NetworkMessage.h"
#include "TcpServer.generated.h"

/**
 * a simplified version from FNFSMessageHeader of UnrealEngine4, without CRC check
 */
class FSocketMessageHeader
{
	/** Error checking */
	uint32 Magic = 0;

	/** Payload Size */
	uint32 PayloadSize = 0;

	static uint32 DefaultMagic;
public:
	FSocketMessageHeader(const TArray<uint8>& Payload)
	{
		PayloadSize = Payload.Num();  // What if PayloadSize is 0
		Magic = FSocketMessageHeader::DefaultMagic;
	}

	/** Add header to payload and send it out */
	static bool WrapAndSendPayload(const TArray<uint8>& Payload, FSocket* Socket);
	/** Receive packages and strip header */
	static bool ReceivePayload(FArrayReader& OutPayload, FSocket* Socket);
};

DECLARE_EVENT_OneParam(UNetworkManager, FReceivedEvent, const FString&)

/**
 * Server to send and receive message
 */
UCLASS()
class UNREALCV_API UNetworkManager : public UObject
// NetworkManager needs to be an UObject, so that we can bind ip and port to UI.
{
	GENERATED_BODY()

public:
	/** The port number this server is listening on */
	int32 PortNum;

	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	// bool bIsConnected = false;
	bool IsConnected();

	bool IsListening()
	{
		return bIsListening;
	}

	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	// FString ListenIP = "0.0.0.0"; // TODO: this is hard coded right now

	/** Start the underlying TcpListener to listen for new connection */
	// TODO: Handle port in use exception
	bool Start(int32 InPortNum);

	/** Send a message to connected client, return false if false to send. Will fail if no connection available */
	bool SendMessage(const FString& Message);

	FReceivedEvent& OnReceived() { return ReceivedEvent;  } // The reference can not be changed

private:
	/** Is the listening socket running */
	bool bIsListening = false;

	/** Handle a new connected client, need to decide accept of reject */
	bool Connected(FSocket* ClientSocket, const FIPv4Endpoint& ClientEndpoint);

	/** The connected client socket, only maintain one client at a time */
	FSocket* ConnectionSocket = NULL; // FSimpleAbstractSocket's receive is hard to use for non-blocking mode

	/** TcpListener used to listen new incoming connection */
	FTcpListener* TcpListener = NULL;

	~UNetworkManager();

	/** (Debug) Start a service that echo whatever it got, for debug purpose */
	bool StartEchoService(FSocket* ClientSocket, const FIPv4Endpoint& ClientEndpoint);

	/** Start a service to handle incoming message, ReceivedEvent will be fired when a new message arrive */
	bool StartMessageService(FSocket* ClientSocket, const FIPv4Endpoint& ClientEndpoint);

	/** Event handler for event `Received` */
	FReceivedEvent ReceivedEvent;

	/** Broadcast event `Received` */
	void BroadcastReceived(const FString& Message)
	{
		ReceivedEvent.Broadcast(Message);
	}
};
