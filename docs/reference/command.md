<h1>The command system</h1>

Unreal Engine 4 has some built-in commands to help game development. These commands can be typed into a built-in console. Using these commands, a developer can profile the game performance and view debug information.  To invoke the built-in console of a game, type the <code>&#96;</code> key (the key above tab).

UnrealCV provides commands useful for computer vision researchers. What is more, these commands can be used by an external program. A built-in command can also be used using the special command `vrun`.

<h2>Command cheatsheet</h2>

!!! Note
    This command list is growing and subject to change

Reply [this thread](https://groups.google.com/d/topic/unrealcv/EuJlibmTN3c/discussion) to tell us what missing functions are needed for your project. We will consider adding it in the future release.

<!-- Do not use table, very hard to extend, this is manually synced from the source code -->

## 1. Camera operation

See `Source/UnrealCV/Private/Commands/CameraHandler.h(.cpp)` for more details.

vget /camera/[id]/location
: (v0.2) Get camera location [x, y, z]

vget /camera/[id]/rotation
: (v0.2) Get camera rotation [pitch, yaw, roll]

vset /camera/[id]/location [x] [y] [z]
: (v0.2) Set camera location [x, y, z]

vset /camera/[id]/rotation [pitch] [yaw] [roll]
: (v0.2) Set camera rotation [pitch, yaw, roll]

vget /camera/[id]/[viewmode]
: (v0.2) Get [viewmode] from the [id] camera, for example: vget /camera/0/depth

vget /camera/[id]/[viewmode] [filename]
: (v0.2) Same as the above, with an extra parameter for filename

vset /viewmode [viewmode]
: (v0.2) Set ViewMode to (lit, normal, depth, object_mask)

vget /viewmode
: (v0.2) Get current ViewMode

## 2. Object interaction

See `Source/UnrealCV/Private/Commands/ObjectHandler.h(.cpp)` for more details

vget /objects
: (v0.2) Get the name of all objects

vget /object/[obj_name]/color
: (v0.2) Get the labeling color of an object (used in object instance mask)

vset /object/[obj_name]/color [r] [g] [b]
: (v0.2) Set the labeling color of an object

## 3. Plugin commands

See `Source/UnrealCV/Private/Commands/PluginHandler.h(.cpp)` for more details.

vget /unrealcv/status
: (v0.2) Get the status of UnrealCV plugin

vget /unrealcv/help
: (v0.2) List all available commands and their help message

## Run UE4 built-in commands

vrun [cmd]
: (v0.3) This is a special command used to execute Unreal Engine built-in commands. UE4 provides some built-in commands for development and debug. They are not very well documented, but very useful.

A few examples are:

- `stat FPS` - show current frame rate
- `shot` - take a screenshot
- `show Material` - toggle the display of Material

These commands can be executed in the UE4 console. If you want to use them in UnrealCV, you can prefix these commands with `vrun stat FPS`.
