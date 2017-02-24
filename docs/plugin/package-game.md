<h1>Package a new game</h1>

In some scenarios you will want to package your game projects into a binary, instead of using it in the editor, for example you want to deploy the game to a deep learning server without UE4 installed or share your game project with other researchers

This page briefly describes how to create a game binary with UnrealCV embedded. Some game binaries can be found in the [model zoo](/reference/model-zoo.md).

<h2>Guide to submit a binary</h2>

1. Modify UE4 config file
2. Package your game project into a binary
3. Make a pull request to modify [this page](https://github.com/unrealcv/unrealcv.github.io/blob/master/_pages/model_zoo.md)   
3. We will review your pull request and merge the changes to the UnrealCV website

### 1. Modify an UE4 config file
First, you need to add a line to UE4 engine config file `Engine\Config\ConsoleVariables.ini` by adding this line to the end.
```
r.ForceDebugViewModes = 1
```

If this line is missing, UnrealCV commands of the packaged game will not work correctly.

### 2. Package your game project

UE4 makes it easy to release your project as a game binary. You can use the editor menu to package a game. Many related blog posts can be found online.

<h3>Use UE4 Editor to package a game</h3>

TODO: Add a screenshot

<h3>(advanced) use script to package a game</h3>

Another approach is used the packaging script contained in unrealcv repository.

### 3. Make a pull request

The last step is making a pull request to modify [this page](https://github.com/unrealcv/unrealcv.github.io/blob/master/_pages/model_zoo.md). This is a markdown file and please add your content. We list some information that should be provided in the pull request. These information can help others better utilize the game binary. This is [an example](https://unrealcv.github.io/reference/model_zoo.html#realistic_rendering).

Binary name (required):
: An easy to remember name that people can refer to the binary you created

Author information (required):
: Author name and contact information

Binary description (required):
: What this virtual world is designed for? Generating dataset, reinforcement learning, etc.??

UnrealCV version (required):
: It can be a release version such as v0.3, a git short sha version, or a pointer to a commit of your fork. This information is to help others find which API is available and the corresponding documentation.

Download link (required):
: Please host binaries in your website, if you have difficulties finding a place to host content, we can help you find some free solutions. Please also include which platform (win,mac,linux) your binaries are built for.

Related paper or project page (optional):
: If this game binary is related to a research project, make a link to here.
