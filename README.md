# Assignment-2
OpenGL 3D implementation of a dining room.

Course Assignment for IS F311- Computer Graphics @ BITS Pilani, Hyderabad Campus.

## Objective:
* To understand OpenGL Transformations, 3D viewing Pipeline and matrix stack operations.
* Incorporating objects made in 3D Modelling software such as Blender.
* Implementing camera functions such as pan ,zoom, pitch, yaw and roll to interact with the scene.

## Scene:
![Scene](https://github.com/krutibaraiya/Graphics-Assignment-2/blob/master/Html%20Pages/images/main_scene.png)

[Objects in the scene](https://github.com/krutibaraiya/Graphics-Assignment-2/tree/master/Html%20Pages/images/objects)

[Different views of the scene](https://github.com/krutibaraiya/Graphics-Assignment-2/tree/master/Html%20Pages/images/scene)

[Doxygen documentation](https://github.com/krutibaraiya/Graphics-Assignment-2/tree/master/html)

## How to run:
* The project is tested on Linux and built in C++ using the following libraries:
    * `GL`
    * `GLUT`
    * `GLEW`
    * `GLM`
    * `CMake`
* To build : `g++ *.cpp *.h -lGL -lglut -lGLU`
* Run the output executable : `./a.out`

## Camera Movements:
| Control          | Action                                            |
|------------------|---------------------------------------------------|
| W, S, A, D, ↑, ↓ | front, back, left, right, up and down respectively|
| [                | Roll anticlockwise                                |
| ]                | Roll clockwise                                    |
| R                | Reset camera                                      |
| Left click and drag  | Pan the scene                                 |
| Scroll mouse     | Zoom                                              |
| Q                | Quit                                              |



## Challenges faced:
* Lag in camera movements while rendering.
* Choosing an appropriate lighting model for the scene.
* Flickering of scene during camera movements.
* Jaggedness in Glut objects.
* Parsing obj files from Blender to load models.

## Team members:
* [Kruti Baraiya](https://github.com/krutibaraiya)
* [Jay Patel](https://github.com/pjay20301)
* [Sristi Sharma](https://github.com/judyhopps24)


