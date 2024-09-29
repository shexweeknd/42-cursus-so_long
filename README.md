# so_long

![playing-image](https://github.com/shexweeknd/blob/blob/main/42-cursus-so_long/play.png)

This repository contains the project "so_long" from the 42 Cursus. The project involves creating a simple `2D game` using the `MiniLibX library`. Below is an overview of the contents of this folder:

## Contents

- **assets/**: Contains the game images and maps in `.ber` and `.XPM` format.
- **includes/**: Contains the header file.
- **libft/**: My tiny library of C functions.
- **Makefile**: The Makefile to compile the project.
- **README.md**: This file, providing an overview of the project.

## Prerequisites

Before proceeding any of the contents bellow. Here are some prerequisites with your running platform.

You should have at least:

- **A Linux OS with X11**
- **Build-essential**

If you do not have X11 support, then use this command in order to install:

```sh
sudo apt-get install libx11-dev libxext-dev libbsd-dev libxrender-dev libxrandr-dev
```

Do the same if there isn't build-essentials:

```sh
sudo apt-get install build-essential
```

## Getting Started

To get started with the project you can clone the repository .

```sh
git clone https://github.com/shexweeknd/42-cursurs-so_long.git
cd 42-cursus-so_long/
```

Now time to import the `MinilibX` library:

```sh
curl -LO https://github.com/shexweeknd/blob/raw/main/42-cursus-so_long/minilibx-linux.tgz && \

tar -xzvf minilibx-linux.tgz && \

rm -rf minilibx-linux.tgz
```

You can now compile the game or code (whatever) using the provided Makefile.

```sh
make
```

## Usage

After compiling, you can run the game using the following command:

```sh
./so_long [map_file]
```

Replace `[map_file]` with the path to a valid map file. Here is an example:

![exaple-image](https://github.com/shexweeknd/blob/blob/main/42-cursus-so_long/exec.png)

## Project Goals

- Learn to use the MiniLibX library.
- Understand basic 2D game development concepts like `Tilesets` and `Sprites`.
- Improve C programming skills.

## License

![42-antananarivo-logo](https://github.com/shexweeknd/blob/blob/main/42-cursus-so_long/42-cursus-Philosophers-42-logo.png)

This project is from 42 School Common Core Cursurs. I do not owe individually any of the concept mentionned above. Instead I owe the provided code in the repository.

Licensed under the MIT License.

## Acknowledgments

- 42 Network for providing the project.
- MiniLibX library for the graphics.
