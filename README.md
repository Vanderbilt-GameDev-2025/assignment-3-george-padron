# Assignment 3 - Magnetic Constraint
> *By George Padron* 

This repo contains an extension to the Jolt physics engine, adding support for objects with a magnetic pull. This extension supports altering the polarity of objects dynamically, allowing for attraction and repulsion. The example game showcases this functionality, by creating a simple playground with basic magnetic balls which can 

## Installation Instructions
**Note:** Installation was only tested on Linux and Windows. Nevertheless, it should build just fine on MacOS

1. Ensure that you have all the necessary dependencies 
    - Godot 4.3
    - Scons 
    - Clang
    - GCC/G++ 
    - CMake and Make 
    - Ninja
    - Python 
2. Clone the repository
```bash
git clone "git@github.com:Vanderbilt-GameDev-2025/assignment-3-george-padron.git" 
```

3. Ensure that the `godot-cpp` was pulled and synced properly

```bash
git submodule sync 
git submodule update --init --recursive
```

4. Build the GDExtension with `scons`. Replace `YOUR-VERSION-HERE` with your choice of `windows`, `linux`, etc. 

```
scons platform={YOUR-VERSION-HERE}
```
5. Open the `assignment-one-shooter` folder in Godot. You should now be able to play the game!
