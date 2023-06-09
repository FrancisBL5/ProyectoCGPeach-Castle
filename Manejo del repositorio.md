# Manejo del repositorio
En este documento se muestra la organización del presente repositorio, y cómo puede utilizarlo para ejecutar el proyecto.

## Estructura del repositorio
### Models
Carpeta que contiene todos los [modelos](/Models) utilizados en el Proyecto. Las carpetas están organizadas de acuerdo a la declaración en código
de cada modelo usado. Para ejecutar el código debe de tener esta carpeta completa dentro de la carpeta en donde se encuentre el ejecutable.

### Ejecutable
Carpeta que contiene el ejecutable dentro de un archivo ´ZIP´. Además, contiene las librerías necesarias para ejecutar el proyecto.

### Versiones
Las carpetas que comienzan con versión #, contienen archivos de código, shaders y demás, que indican el control de versiones del proyecto.

## Control de versiones
Una vez revisado como se compone el repositorio, ahora se explicará como se manejó el control de versiones en él. En general, cada versión trataba
de hacer cambios significativos en cuanto a la versión anterior. En general, cada versión introduce los siguientes cambios:
- **Versión 1**
  - Carga de modelos en su posición original:
    - Escenario
    - Castillo (versión 1)
    - Arbustos
    - Fire flower
    - Árboles
    - Antorcha
    - Tubo
    - Parrilla
    - Puro huesos
    - Planta piraña
    - Chain chomp
    - Goomba
  - Skybox de día
  - Cámara isométrica
  - Archivos: Todos los códigos contenidos en [Version 1](/Version1)
- **Versión 2**
  - Cambio de escenario: Se eligió un escenario diferente con el fin de asemejar el proyecto lo más posible a un diorama
  - Cambio de códigos a utilizar
  - Reacomodo de los modelos existentes e inclusión de los modelos restantes
  - Animaciones simples
  - Animaciones complejas
  - Archivos: Todos los códigos contenidos en [Version 2](/Version2)
- **Versión 3**
  - Ambientación de la noche:
    - SkyBox noche
    - Iluminación de Point Lights
    - Cocinado de luces para los postes
- **Versión 4**
  - Cambio de SkyBox día / noche
  - Apagado y encendido de luces
- **Versión 5**
  - Corrección Point Ligths en cámara isométrica
- **Versión 6**
  - Implementación de audios:
    - Fondo musical cambiante para día/noche
    - Rugido del avatar
  - Corrección del Skybox en cámara isómetrica
  - Implementación de primitivas
- **Versión 7**
  - Ligamiento de la cámara 3D al avatar
  - Corrección Spot Lights en cámara isométrica
  - Corrección de la inicialización de la cámara isométrica
  - [Ejecutable](/Ejecutable)
