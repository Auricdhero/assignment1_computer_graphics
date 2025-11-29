# Rotating Letter L - OpenGL Project

This C++ program displays the letter "L" and rotates it continuously around the Y-axis using OpenGL and GLUT.

## Features

- Renders a 2D letter "L" shape
- Continuous rotation animation around the Y-axis
- Blue colored letter on black background
- Smooth 60 FPS animation

## Requirements

- OpenGL
- GLUT (OpenGL Utility Toolkit)
- C++ compiler (g++ or clang++)

On macOS, these are typically pre-installed with Xcode Command Line Tools.

## Compilation

### macOS

```bash
g++ -o rotating_L rotating_L.cpp -framework OpenGL -framework GLUT
```

### Linux

```bash
g++ -o rotating_L rotating_L.cpp -lGL -lGLU -lglut
```

## Running the Program

```bash
./rotating_L
```

## Controls

- The letter L will automatically rotate around the Y-axis
- Close the window to exit the program

## Customization

You can modify the following in the code:

- **Rotation speed**: Change the increment value in the `timer()` function
- **Rotation axis**: Modify the parameters in `glRotatef()` (currently 0.0f, 1.0f, 0.0f for Y-axis)
- **Color**: Change RGB values in `glColor3f()`
- **Size**: Adjust the vertex coordinates in `drawLetterL()`
