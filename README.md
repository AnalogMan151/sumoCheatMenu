# Zelda-Ocarina-Of-Time-3D-Plugin
A cheats plugin for NTR CFW

This plugin use a lib I created to make the creation of NTR plugin easier / faster.
The lib also use a custom menu that have several advantages such as:
- The limit of entries is now 300 instead of 64
- A spoiler system
- A note system
- A better looking menu which can print 18 lines instead of 10

The debug version of the lib also include a Debug Menu that shows severals infos including a logger.
With the logger you can easily trace your plugin execution and print infos which can lead to a fast debugging.
The logger have 4 types entry:
- INFO
- DEBUG
- WARNING
- ERRORS

Those types don't have major differences apart from the color (respectively GREEN, GREY, ORANGE, RED) except for the ERROR type.
Indeed, when an ERROR type log is thrown, the plugin will put the process in pause and show the Debug Menu from itself.
With that you can look at an error log before the console / game crash.

All the major functions from the lib are documented and can be found in the plugin.h in the Includes folder.
Common.h contain most of hid functions.

This plugin can serve as a template for any game plugin you want to do, I find it easy to understand.
Still if you have trouble or questions, feel free to contact me, either here or on GBATemp.
