# Assignment 3 - Magnetic Constraint
> *By George Padron* 

This repo contains an extension to the Jolt physics engine, adding support for objects with a magnetic pull. This extension supports altering the polarity of objects dynamically, allowing for attraction and repulsion. The attached project has a simple game with a basic magnetic ball scene that can be added and played around with. The attached video showcases the functionality in more detail

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
Make sure that the `godot-cpp` submodule is on branch *4.3*. **OTHERWISE GAME WILL FAIL TO COMPILE**.

4. Build the GDExtension with `scons`. Replace `YOUR-VERSION-HERE` with your choice of `windows`, `linux`, etc. 

```
scons platform={YOUR-VERSION-HERE}
```
5. Open the `assignment-3` folder located within in the cloned repo in Godot. You should now be able to play the game!
