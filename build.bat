@echo Set the environment variable UE4 in the console or in the system variables
@echo For example in my machine, I use "set UE4=D:\Epic Games\4.13\"
"%UE4%/Engine/Build/BatchFiles/RunUAT.bat" BuildPlugin -plugin=%CD%/UnrealCV.uplugin -package=%CD%/built -rocket -targetplatforms=Win64
