# MiniRT

MiniRT is a graphic project for @42Paris I made in early 2021.

This project's goal is to create a minimalist 3d raytracing engine. In this implementation, I used a model mostly based
on Phong's Reflection Model, with some tweaks of my own.

Basically, this project is done from scratch, with only a `put_pixel` function. All the ray tracing is built from basic float arithmetic.

# Table of Contents

1. [Examples](#examples)
2. [Installing Dependencies](#installing-dependencies)
3. [Compilation](#compilation)
4. [Installation](#installation)
5. [RT Scene File](#rt-scene-file)

## Examples

![A 3D rendered room with a light at the top and three colored balls reflecting in each other](./images/room.bmp)
![Many colored 3D rendered shapes reflecting in each other](./images/reflect_effects.bmp)
![Colored spheres reflecting in each other](./images/spheres.bmp)

## Installing Dependencies

For this program to run, you will need:

- libbsd
- libext
- libx11

Using `apt` you'll need the following packages:

```shell
$ sudo apt install libbsd-dev libext-dev libx11-dev
```

To build this program, you'll need at least clang and gcc, but it is recommended to also have llvm to allow further
optimisation of the output binary. Using `apt` you'll need the following packages:

```shell
$ sudo apt install clang gcc #llvm
```

## Compilation

Clone the repository with `git clone --recurse-usbmodules -j2 https://github.com/Neirpyc/miniRT`

Two build modes are available, regular `make`, which will output an unoptimized binary, or `make fast`, which will make
compilation about two times longer but make the binary about three times faster. The latter requires `llvm` to be
installed.

The program may then be used in the following way:

```shell
$ ./miniRT <scene_file>.rt [--save]
```

## Installation

The Makefile will output a single binary `miniRT` which can be placed anywhere, but will be more useful in your current
directory or in your `$PATH`.

## RT Scene File

The `.rt` scene file format is fixed by the subject of this exercise. Such a resource is a property of 42, which I can
not redistribute. Yet, I can share examples, which are present in [scenes](./scenes).

I also have added a bonus version of this file format which is specified below:

- The first line of the `.rt` file must be `#BONUS` to enable this extension
- A camera takes two extra parameters :
    - ray bounce depth [1 ; INT_MAX] : up to how many times a ray should bounce
    - over sampling : how many rays should be computed for each pixel (scales in quadratic way : 1 means 1 ray, 2 means
      4 rays, 3 means 9 rays, ...)
- Adds materials:
    - `ma` prefix
    - material id [1 ; INT_MAX] : a unique id for this material
    - specular reflexion coefficient [0 ; 1] : a float describing how much of each ray should bounce off this material
    - refraction index [1 ; infinity] : the refraction index of the material
    - color [0 ; 255],[0 ; 255],[0 ; 255] : color of the material
    - disruption :
      - N : no disruption
      - S : sine normal disruption
      - C : checkerboard color disruption
      - R : normal based rainbow color disruption
- In each object, the color is replaced by a material id