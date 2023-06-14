# Repository Management
In this document, the organization of the current repository is shown, and how you can use it to run the project.

## Repository Structure
### Models
Folder that contains all the [models](/Models) used in the Project. The folders are organized according to the code declaration of each used model. To run the code, you must have this entire folder within the folder where the executable is located.

# Executable
Folder that contains the executable within a 'ZIP' file. It also contains the necessary libraries to run the project.

# Versions
Folders starting with version # contain code files, shaders, and more, indicating the project's version control.

## Version Control
Once the repository composition has been reviewed, now we will explain how version control was managed within it. In general, each version aimed to make significant changes compared to the previous version. In general, each version introduces the following changes:
- **Version 1**
  - Loading of models in their original position:
    - Scenario
    - Castle (version 1)
    - Bushes
    - Fire flower
    - Trees
    - Torch
    - Pipe
    - Grill
    - Grim
    - Piranha plant
    - Chain chomp
    - Goomba
  - Daytime skybox
  - Isometric camera
  - Files: All the code contained in [Version 1](/Version1)
- **Version 2**
  - Change of scenario: A different scenario was chosen in order to make the project resemble a diorama as much as possible
  - Change of codes to use
  - Rearrangement of existing models and inclusion of the remaining models
  - Simple animations
  - Complex animations
  - Files: All the code contained in [Version 2](/Version2)
- **Version 3**
  - Night ambiance setup::
    - Night SkyBox
    - Point Lights illumination
    - Light baking for the lamp posts
- **Version 4**
  - Switching between day and night SkyBox
  - Lights on and off
- **Version 5**
  - Point Lights correction in isometric camera
- **Version 6**
  - Implementation of audio:
  - Changing background music for day/night
  - Avatar roar
  - Skybox correction in isometric camera
  - Implementation of primitives
- **Version 7**
  - Binding of the 3D camera to the avatar
  - Spot Lights correction in isometric camera
  - Initialization correction of the isometric camera
  - [Executable](/Ejecutable)
