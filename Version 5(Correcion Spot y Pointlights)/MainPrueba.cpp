#include <iostream>
#include <cmath>

// GLEW
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other Libs
#include "stb_image.h"

// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//Load Models
#include "SOIL2/SOIL2.h"


// Other includes
#include "Shader.h"
#include "Camera.h"
#include "Model.h"
#include "Texture.h"
#include "modelAnim.h"

// Function prototypes
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void MouseCallback(GLFWwindow* window, double xPos, double yPos);
void DoMovement();
void animacion();

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
int SCREEN_WIDTH, SCREEN_HEIGHT;

// Camera
Camera  camera(glm::vec3(0.0f, 1.0f, 10.0f));
GLfloat lastX = WIDTH / 2.0;
GLfloat lastY = HEIGHT / 2.0;
bool keys[1024];
bool firstMouse = true;
float range = 0.0f;
float rot = 0.0f;
float movCamera = 0.0f;
bool First = true;
//Dia y Noche
float LaHora = 0.0f;
bool  EstadoDia = true;
float PointlightTrue = 0.0f;
float ambiental1 = 0.9f;
float ambiental2 = 0.9f;
float directionalAmbiental = 1.0f;
float PosteLuzRG = 0.9f;
float PosteLuzB = 0.9f;
float espadaLuz = 0.0f;
//LuzSpots
float Reflectores = 0.0f;
bool EsperaDeLuces = false;
//Chillywilly
float VariableRadioGiros = 0.0f;
float VariableRadioBrincos = 0.0f;
float TraslacionXChilly;
float TraslacionZChilly;
float TraslacionXChainChomp;
float TraslacionZChainChomp;
float TraslacionYChainChomp;
//Luigi
float VariableJuego = 0.0f;
float MovimientoJuego;
float VariableCabezaLuigi = 0.0f;
float MovimientoCabezaLuigi;
//Peach
float VariablePeachGiros = 0.0f;
float TraslacionXPeach;
float TraslacionZPeach;
//Monedas
float VariableMonedasGiros = 0.0f;
float TraslacionXMonedas;
float TraslacionZMonedas;
float TraslacionXMonedas1;
float TraslacionZMonedas1;
float TraslacionXMonedas2;
float TraslacionZMonedas2;
float TraslacionXMonedas3;
float TraslacionZMonedas3;
float TraslacionXMonedas4;
float TraslacionZMonedas4;
float TraslacionXMonedas5;
float TraslacionZMonedas5;
float TraslacionXMonedas6;
float TraslacionZMonedas6;
float TraslacionXMonedas7;
float TraslacionZMonedas7;
//Koopa
float RotCaparazon = 0.0f;
bool sentidoCaparazon = true;
//CheepCheep
float CheepFloat = 0.0f;
float AlturaNadado = 0.0f;
float AletasCheep = 0.0f;
//Toads
float IDLE = 0.0f;
float RotBrazo = 0.0f;
bool sentidoIDLE = true;
bool sentidoBrazo = false;
float Giro = 0.0f;
float auxilar1 = 0.0f;
float auxilar2 = 0.0f;
float auxilar3 = 0.0f;
//Paratroopa
bool Sentido1 = true;
bool Sentido2 = true;
float RoatParatroopa = 0.0f;
float Brinco = 0.0f;
float Rotacion2 = 0.0;
float times;
float Reducir=0.0;
//Purohuesos
bool Hamburguesa = false;
float espera = 0.0f;
bool SentidoHamburguesa = true;
float roatAnteBrazo = 0.0f;
float TiempovueloHamburguesa = 0.0f;
float HamburVuelo = 0.0f;
//Goomba
bool AnimacionGoomba = false;
float CaminataGoomba = 0.0f;
bool SentidoGoomba = false;
float rotCabezaGoomba = 0.0f;
float rotPieDerGoomba = 0.0f;
float rotPieIzqGoomba = 0.0f;
bool RotSentidoGoomba = false;
float VueloParatroopa = 0.0f;
//FlyGuy
float TrasladoFlyguy = 0.0f;
float RoatFlyGuy = 0.0f;
bool SentidoFlyGuy = true;
//Bobomb
float RoatBomba = 0.0f;
float RoatLlave = 0.0f;
float pieIzqBomba = 0.0f;
float pieDerBomba = 0.0f;
float TiempoanimaiconBomba = 0.0f;
bool  MarchaBomba = true;
bool AnimacionBomba = false;
//PlantaPiraña
float piranaPlant = 0.0f;
bool  PiranaplantSentido = true;
float tiempoMordida = 0.0f;
float AnguloMorida = 0.0f;
bool AnimPlantaPriaña = false;
//LadyBug
float LadyBugmovKitX = 0.0;
float LadyBugmovKitZ = 0.0;
float LadyBugmovKitY = 0.0;
float LadyBugrotKit = 0.0;
float LadyBugGiroExtremo = 0.0;
bool LadyBugapertura = false;
bool LadyBugCierre = false;
bool LadyBugDescender = false;
float LadyBugTiempoDelta = 0.0;
bool LadyBugrecorrido1 = true;
bool LadyBugrecorrido2 = false;
bool LadyBugrecorrido3 = false;
bool LadyBugrecorrido3Subida = false;
bool LadyBugrecorrido4 = false;
bool LadyBugrecorrido5 = false;
bool LadyBugrecorrido6 = false;
bool LadyBugrecorrido6Descenso = false;
bool LadyBugrecorrido7 = false;
bool LadyBugrecorrido8 = false;
float LadyBugXscale = 0.0f;
float LadyBugYscale = 0.0f;
float LadyBugZscale = 0.0f;
//Goku
float GokumovKitX = 25.102f;
float GokumovKitZ = 2.847f;
float GokumovKitY = 0.0;
float GokurotKit = -90;
float GokuGiroExtremo = 0.0;
bool Gokuapertura = false;
bool GokuCierre = false;
bool GokuDescender = false;
float GokuTiempoDelta = 0.0;
bool Gokurecorrido1 = false;
bool Gokurecorrido2 = false;
bool Gokurecorrido3 = true;
bool Gokurecorrido3Subida = false;
bool Gokurecorrido4 = false;
bool Gokurecorrido5 = false;
bool Gokurecorrido6 = false;
bool Gokurecorrido6Descenso = false;
bool Gokurecorrido7 = false;
bool Gokurecorrido8 = false;
float GokuXscale = 0.0f;
float GokuYscale = 0.0f;
float GokuZscale = 0.0f;
//BobEsponja
float BobEsponjamovKitX = 23.18f;
float BobEsponjamovKitZ = 31.659f;
float BobEsponjamovKitY = 2.283f;
float BobEsponjarotKit = -180.0;
float BobEsponjaGiroExtremo = 0.0;
bool BobEsponjaapertura = false;
bool BobEsponjaCierre = false;
bool BobEsponjaDescender = false;
float BobEsponjaTiempoDelta = 0.0;
bool BobEsponjarecorrido1 = false;
bool BobEsponjarecorrido2 = false;
bool BobEsponjarecorrido3 = false;
bool BobEsponjarecorrido3Subida = false;
bool BobEsponjarecorrido4 = false;
bool BobEsponjarecorrido5 = true;
bool BobEsponjarecorrido6 = false;
bool BobEsponjarecorrido6Descenso = false;
bool BobEsponjarecorrido7 = false;
bool BobEsponjarecorrido8 = false;
float BobEsponjaXscale = 0.0f;
float BobEsponjaYscale = 0.0f;
float BobEsponjaZscale = 0.0f;
//Mulan
float MulanmovKitX = -3.776;
float MulanmovKitZ = 28.093f;
float MulanmovKitY = 2.283;
float MulanrotKit = -270;
float MulanGiroExtremo = 0.0;
bool Mulanapertura = false;
bool MulanCierre = false;
bool MulanDescender = false;
float MulanTiempoDelta = 0.0;
bool Mulanrecorrido1 = false;
bool Mulanrecorrido2 = false;
bool Mulanrecorrido3 = false;
bool Mulanrecorrido3Subida = false;
bool Mulanrecorrido4 = false;
bool Mulanrecorrido5 = false;
bool Mulanrecorrido6 = false;
bool Mulanrecorrido6Descenso = true;
bool Mulanrecorrido7 = false;
bool Mulanrecorrido8 = false;
float MulanXscale = 0.0f;
float MulanYscale = 0.0f;
float MulanZscale = 0.0f;
//Todos los Karts
float Rotacion1 = 0.0;
bool SentidoViento = true;
float Viento = 0.0f;
//Puertas
bool Puerta = false;
bool AnimPuerta = false;
float RotPuerta = 0.0f;
//Cubo
bool AnimCubo = false;
bool EstadoCubo = true;
float EscalaCubo = 1.00f;
float EscalaVacia = 0.5f;
float RoatChampi = 0.0f;
float TiroVertical;
float Golpe = 0.0f;
float tiempo;
float Redu = 0.0f;
//Flor
float FlorBrinco;
float FlorGiro = 0.0f;
bool FlorSentido = true;
//MarioTanooki
float VueloAltura;
float Tanooki = 0.0f;
//Bowser
float AxuiliarBowser1 = 0.0f;
float AxuiliarBowser2 = 0.0f;
float AxuiliarBowser3 = 0.0f;
float IDLEBowserCuerpo;
float IDLEBowserCabeza;
float IDLEBowserMandibula;
float IDLEBowserBrazos;
float IDLEBowserCodos;
float IDLEBowserManos;
float TiempoRugido = 0.0f;
bool Rugidetapa1 = true;
bool AnimacionBowser = false;


// Light attributes
glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
glm::vec3 PosIni(0.0f, 0.0f, 0.0f);
glm::vec3 lightDirection(0.0f, -1.0f, -1.0f);

bool active;

// keyframes
float reproduciranimacion, habilitaranimacion;

// Deltatime
GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
GLfloat lastFrame = 0.0f;  	// Time of last frame

// Keyframes
float posX = PosIni.x, posY = PosIni.y, posZ = PosIni.z, rotRodIzq = 0;

#define MAX_FRAMES 9
int i_max_steps = 90;
int i_curr_steps = 8;
typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float rotRodIzq;
	float rotInc;

}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 8;			//introducir datos
bool play = false;
int playIndex = 0;

// Positions of the point lights
glm::vec3 pointLightPositions[] = {
	glm::vec3(6.766,0.670,24.985),
	glm::vec3(0.0f, 9.751f, 6.016f),
	glm::vec3(0,1.0,19.892)
};

glm::vec3 LightP1;

void saveFrame(void)
{

	printf("posx %f\n", posX);

	KeyFrame[FrameIndex].posX = posX;
	KeyFrame[FrameIndex].posY = posY;
	KeyFrame[FrameIndex].posZ = posZ;

	KeyFrame[FrameIndex].rotRodIzq = rotRodIzq;


	FrameIndex++;
}

void resetElements(void)
{
	posX = KeyFrame[0].posX;
	posY = KeyFrame[0].posY;
	posZ = KeyFrame[0].posZ;

	rotRodIzq = KeyFrame[0].rotRodIzq;

}

void interpolation(void)
{

	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;
	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;
	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;

	KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;

}

void animateKeyFrame(void) {
	//Movimiento del objeto
	if (play) {
		if (i_curr_steps >= i_max_steps) {//end of animation between frames?
			playIndex++;
			printf("playindex : %d\n", playIndex);
			if (playIndex > FrameIndex - 2) {//end of total animation?
				printf("Frame index= %d\n", FrameIndex);
				printf("termina anim\n");
				espadaLuz = 0.0f;
				playIndex = 0;
				play = false;
			}
			else {//Next frame interpolations
				i_curr_steps = 0; //Reset counter
				interpolation();
			}
		}
		else {
			//Draw animation
			posX += KeyFrame[playIndex].incX;
			posY += KeyFrame[playIndex].incY;
			posZ += KeyFrame[playIndex].incZ;

			rotRodIzq += KeyFrame[playIndex].rotInc;
			i_curr_steps++;
		}
	}
}

void readFile() {	// funcion para leer archivo que contiene los keyframes
	int i = 0, linead = 0;
	std::string indice, valor, content;
	int index;
	float value;
	std::ifstream fileStream("KeyFrames.txt", std::ios::in);

	if (!fileStream.is_open()) {
		printf("Failed to read %s! File doesn't exist.", "KeyFrames.txt");
		content = "";
	}

	std::string line = "";
	while (!fileStream.eof()) {
		std::getline(fileStream, line);

		if (linead < 10) indice = line.substr(9, 1);
		else indice = line.substr(9, 2);
		index = std::stoi(indice);
		switch (i) {
		case 0:	//posicion en X
			if (linead < 10) valor = line.substr(19, line.size() - 21);
			else valor = line.substr(20, line.size() - 22);
			value = std::stof(valor);
			KeyFrame[index].posX = value;
			std::cout << "KeyFrame[" << index << "].posX = " << value << ";" << std::endl;
			i++;
			break;
		case 1: //posicion en y
			if (linead < 10) valor = line.substr(19, line.size() - 21);
			else valor = line.substr(20, line.size() - 22);
			value = std::stof(valor);
			KeyFrame[index].posY = value;
			std::cout << "KeyFrame[" << index << "].posY = " << value << ";" << std::endl;
			i++;
			break;
		case 2:
			if (linead < 10) valor = line.substr(19, line.size() - 21);
			else valor = line.substr(20, line.size() - 22);
			value = std::stof(valor);
			KeyFrame[index].posZ = value;
			std::cout << "KeyFrame[" << index << "].posZ = " << value << ";" << std::endl;
			i++;
			break;
		case 3: //rotacion
			if (linead < 10) valor = line.substr(24, line.size() - 26);
			else valor = line.substr(25, line.size() - 27);
			value = std::stof(valor);
			KeyFrame[index].rotRodIzq = value;
			std::cout << "KeyFrame[" << index << "].rotRodIzq = " << value << ";\n" << std::endl;
			i = 0;
			linead++;
			break;
		}
	}
	fileStream.close();
}

int main()
{
	// Init GLFW
	glfwInit();




	// Set all the required options for GLFW
	/*(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Practica 12", nullptr, nullptr);

	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);

	// Set the required callback functions
	glfwSetKeyCallback(window, KeyCallback);
	glfwSetCursorPosCallback(window, MouseCallback);
	printf("%f", glfwGetTime());

	// GLFW Options
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	if (GLEW_OK != glewInit())
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Define the viewport dimensions
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	// OpenGL options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	Shader lightingShader("Shaders/lighting.vs", "Shaders/lighting.frag");
	Shader lampShader("Shaders/lamp.vs", "Shaders/lamp.frag");
	Shader SkyBoxshader("Shaders/SkyBox.vs", "Shaders/SkyBox.frag");
	Shader Anim("Shaders/anim.vs", "Shaders/anim.frag");

	Model Castillo((char*)"Models/Diorama/Diorama.obj");
	Model Jardin((char*)"Models/Diorama/Jardin.obj");
	Model VentanaTransparente((char*)"Models/Castillo Proyecto final/Ventana.obj");
	Model Puerta1((char*)"Models/Castillo Proyecto final/Puerta1.obj");
	Model Puerta2((char*)"Models/Castillo Proyecto final/Puerta2.obj");
	Model Trono((char*)"Models/Castillo Proyecto final/Modelos_Recreados/Trono/TronoReal.obj");
	Model Arbol((char*)"Models/Arboles/Arbol.obj");
	Model Cubo((char*)"Models/Castillo Proyecto final/Modelos_Recreados/Question Mark Block/QuestionBlock.obj");
	Model Vacio((char*)"Models/Castillo Proyecto final/Modelos_Recreados/Question Mark Block/EmptyBlock.obj");
	Model Champi((char*)"Models/Castillo Proyecto final/Modelos_Recreados/Question Mark Block/Champi.obj");
	Model FloreroAzul((char*)"Models/Castillo Proyecto final/Modelos_Recreados/Florero/FloreroAzul.obj");
	Model Star((char*)"Models/Castillo Proyecto final/Modelos_Recreados/Star/Star.obj");
	Model Rampa((char*)"Models/Rampa/Rampa.obj");
	Model Flecha((char*)"Models/Diorama/Flecha.obj");
	Model Poste((char*)"Models/Diorama/Poste.obj");
	Model Estrellitas((char*)"Models/Diorama/EstrellasLuz.obj");

	Model BolsaDeAgua((char*)"Models/CheepCheep/BolsaPlastico.obj");
	Model CheepCheep((char*)"Models/CheepCheep/CheepCheep.obj");
	Model CheepIzquierda((char*)"Models/CheepCheep/AlaIzquierda.obj");
	Model CheepDerecha((char*)"Models/CheepCheep/AlaDerecha.obj");

	Model PuroHuesos((char*)"Models/Grim/grim_cuerpo.obj");
	Model Oz((char*)"Models/Grim/grim_oz.obj");
	Model Antebrazo((char*)"Models/Grim/grim_antebrazo.obj");
	Model Espatula((char*)"Models/Grim/grim_mano.obj");
	Model Cabeza((char*)"Models/Grim/grim_cabeza.obj");
	Model Parrilla((char*)"Models/parrilla/parrilla.obj");
	Model CarneHamburguesa((char*)"Models/parrilla/Hamburguesa.obj");

	Model Monedas((char*)"Models/Coin/Coin.obj");
	Model Peach((char*)"Models/Peach/Peach.obj");

	Model torch((char*)"Models/torch/torch.obj");
	Model Spot((char*)"Models/Spot/Lamp.obj");
	Model Foco((char*)"Models/Spot/Foco.obj");

	Model PiesKoopa((char*)"Models/KoopaTroopa/Pies.obj");
	Model CaparazonVerde((char*)"Models/KoopaTroopa/Caparazon.obj");
	Model DerechaKoopa((char*)"Models/KoopaTroopa/Derecha.obj");
	Model IzquierdaKoopa((char*)"Models/KoopaTroopa/Izquierda.obj");
	Model CabezaKoopa((char*)"Models/KoopaTroopa/Cabeza.obj");

	Model FlyGuy((char*)"Models/Fly Guy/FlyGuy.obj");
	Model Helices((char*)"Models/Fly Guy/Helices.obj");

	Model KoopaClown((char*)"Models/1.AvatarBowser/KoopaClown.obj");
	Model KoopaClownHelices((char*)"Models/1.AvatarBowser/KoopaClownHelices.obj");
	Model BowserCuerpo((char*)"Models/1.AvatarBowser/BowserCuerpo.obj");
	Model BowserBrazoIzquierdo((char*)"Models/1.AvatarBowser/BowserBrazoIzquierdo.obj");
	Model BowserBrazoDerecho((char*)"Models/1.AvatarBowser/BowserBrazoDerecho.obj");
	Model BowserCabeza((char*)"Models/1.AvatarBowser/BowserCabeza.obj");
	Model BowserMandibula((char*)"Models/1.AvatarBowser/BowserMandibula.obj");
	Model BowserCodoIzquierdo((char*)"Models/1.AvatarBowser/BowserCodoIzquierdo.obj");
	Model BowserCodoDerecho((char*)"Models/1.AvatarBowser/BowserCodoDerecho.obj");
	Model BowserManoIzquierda((char*)"Models/1.AvatarBowser/BowserManoIzquierda.obj");
	Model BowserManoDerecha((char*)"Models/1.AvatarBowser/BowserManoDerecha.obj");

	Model Tubo((char*)"Models/PlantaPiraña/Tubo.obj");
	Model Tallo((char*)"Models/PlantaPiraña/Tallo.obj");
	Model piranha_plant_cabeza_sup((char*)"Models/PlantaPiraña/piranha_plant_cabeza_sup.obj");
	Model piranha_plant_cabeza_inf((char*)"Models/PlantaPiraña/piranha_plant_cabeza_inf.obj");

	Model Mario((char*)"Models/Mario/Mario.obj");
	Model Colita((char*)"Models/Mario/Colita.obj");

	Model ArbustoPeach((char*)"Models/Arbustos/ArbustoPeach/ArbustoPeach.obj");
	Model ArbustoMario((char*)"Models/Arbustos/ArbustoPeach/ArbustoMario.obj");
	Model Arbusto((char*)"Models/Arbustos/Arbusto/ArbustoGrande.obj");
	Model Flor((char*)"Models/Castillo Proyecto final/Modelos_Recreados/Fire Flower/fireflower.obj");
	Model FlorGrande((char*)"Models/Castillo Proyecto final/Modelos_Recreados/Fire Flower/Tallfireflower.obj");

	Model CuerpoToad((char*)"Models/Castillo Proyecto final/Modelos_Recreados/Toad/ToadCuerpo.obj");
	Model Zapatos((char*)"Models/Castillo Proyecto final/Modelos_Recreados/Toad/ToadZapato.obj");
	Model BrazoDer((char*)"Models/Castillo Proyecto final/Modelos_Recreados/Toad/BrazoDer.obj");
	Model BrazoIzq((char*)"Models/Castillo Proyecto final/Modelos_Recreados/Toad/BrazoIzq.obj");

	Model GoombaCabeza((char*)"Models/Castillo Proyecto final/Modelos_Recreados/Goomba/GoombaCabeza.obj");
	Model GoombaPieDer((char*)"Models/Castillo Proyecto final/Modelos_Recreados/Goomba/GoombaPieDer.obj");
	Model GoombaPieIzq((char*)"Models/Castillo Proyecto final/Modelos_Recreados/Goomba/GoombaPieIzq.obj");

	Model Bobomb((char*)"Models/Bob-omb/Bobomb.obj");
	Model PieDerBob((char*)"Models/Bob-omb/Rigth.obj");
	Model PieIzqBob((char*)"Models/Bob-omb/Left.obj");
	Model Llave((char*)"Models/Bob-omb/windup.obj");

	Model PiesLuigi((char*)"Models/LuiguiJugando/PiesLuigi.obj");
	Model BrazosLuigi((char*)"Models/LuiguiJugando/BrazosLuigi.obj");
	Model CabezaLuigi((char*)"Models/LuiguiJugando/CabezaLuigi.obj");

	Model KartLadyBug((char*)"Models/Corredores/Karts/Ladybug/Ladybug.obj");
	Model LlantaNormal((char*)"Models/Corredores/Llantas/LlantaNormal/LlantaNormal.obj");
	Model Paracaidas((char*)"Models/Corredores/Planeadores/Paracaidas/Paracaidas.obj");
	Model KartBobEsponja((char*)"Models/Corredores/Karts/Bob Esponja/BobEsponja.obj");
	Model Pepinillos((char*)"Models/Corredores/Llantas/Pepinillo/Pepinillo.obj");
	Model Papel((char*)"Models/Corredores/Planeadores/AvionPapel/Papel.obj");
	Model KartGoku((char*)"Models/Corredores/Karts/Goku/Goku.obj");
	Model Rojas((char*)"Models/Corredores/Llantas/LlantaRoja/LlantaRoja.obj");
	Model Ardilla((char*)"Models/Corredores/Planeadores/Ardilla/Ardilla.obj");
	Model ColitaArdilla((char*)"Models/Corredores/Planeadores/Ardilla/Colita.obj");
	Model KartMulan((char*)"Models/Corredores/Karts/Mulan/Mulan.obj");
	Model Monster((char*)"Models/Corredores/Llantas/Monster/Llanta.obj");
	Model Mushu((char*)"Models/Corredores/Planeadores/Mushu/Mushu.obj");
	Model ChillyWilly((char*)"Models/Corredores/Karts/ChillyWilly/ChillyWilly.obj");
	Model LlantaNegra((char*)"Models/Corredores/Llantas/LlantaNegraRoja/LlantaNegraRoja.obj");

	Model ChainChompSup((char*)"Models/ChainChomp/MandibulaSup.obj");
	Model ChainChompInf((char*)"Models/ChainChomp/MandibulaInf.obj");

	Model Pintura((char*)"Models/Castillo Proyecto final/Modelos_Recreados/Pintura/Pintura.obj");
	Model Marco((char*)"Models/Castillo Proyecto final/Modelos_Recreados/Pintura/Marco.obj");
	Model Paratroopa((char*)"Models/Paratroopa/Paratroopa.obj");
	Model AlaDerecha((char*)"Models/Paratroopa/AlaDerecha.obj");
	Model AlaIzquierda((char*)"Models/Paratroopa/AlaIzquierda.obj");

	Model Roca((char*)"Models/Espada/Piedra.obj");
	Model Mango((char*)"Models/Espada/Mango.obj");
	Model Espada((char*)"Models/Espada/Espada.obj");

	// Build and compile our shader program

	//Inicialización de KeyFrames

	for (int i = 0; i < MAX_FRAMES; i++)
	{
		KeyFrame[i].posX = 0;
		KeyFrame[i].incX = 0;
		KeyFrame[i].incY = 0;
		KeyFrame[i].incZ = 0;
		KeyFrame[i].rotRodIzq = 0;
		KeyFrame[i].rotInc = 0;
	}



	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] =
	{
		// Positions            // Normals              // Texture Coords
		-0.5f, -0.5f, -0.5f,    0.0f,  0.0f, -1.0f,     0.0f,  0.0f,
		0.5f, -0.5f, -0.5f,     0.0f,  0.0f, -1.0f,     1.0f,  0.0f,
		0.5f,  0.5f, -0.5f,     0.0f,  0.0f, -1.0f,     1.0f,  1.0f,
		0.5f,  0.5f, -0.5f,     0.0f,  0.0f, -1.0f,     1.0f,  1.0f,
		-0.5f,  0.5f, -0.5f,    0.0f,  0.0f, -1.0f,     0.0f,  1.0f,
		-0.5f, -0.5f, -0.5f,    0.0f,  0.0f, -1.0f,     0.0f,  0.0f,

		-0.5f, -0.5f,  0.5f,    0.0f,  0.0f,  1.0f,     0.0f,  0.0f,
		0.5f, -0.5f,  0.5f,     0.0f,  0.0f,  1.0f,     1.0f,  0.0f,
		0.5f,  0.5f,  0.5f,     0.0f,  0.0f,  1.0f,     1.0f,  1.0f,
		0.5f,  0.5f,  0.5f,     0.0f,  0.0f,  1.0f,  	1.0f,  1.0f,
		-0.5f,  0.5f,  0.5f,    0.0f,  0.0f,  1.0f,     0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f,    0.0f,  0.0f,  1.0f,     0.0f,  0.0f,

		-0.5f,  0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    1.0f,  1.0f,
		-0.5f, -0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    0.0f,  1.0f,
		-0.5f, -0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    1.0f,  0.0f,

		0.5f,  0.5f,  0.5f,     1.0f,  0.0f,  0.0f,     1.0f,  0.0f,
		0.5f,  0.5f, -0.5f,     1.0f,  0.0f,  0.0f,     1.0f,  1.0f,
		0.5f, -0.5f, -0.5f,     1.0f,  0.0f,  0.0f,     0.0f,  1.0f,
		0.5f, -0.5f, -0.5f,     1.0f,  0.0f,  0.0f,     0.0f,  1.0f,
		0.5f, -0.5f,  0.5f,     1.0f,  0.0f,  0.0f,     0.0f,  0.0f,
		0.5f,  0.5f,  0.5f,     1.0f,  0.0f,  0.0f,     1.0f,  0.0f,

		-0.5f, -0.5f, -0.5f,    0.0f, -1.0f,  0.0f,     0.0f,  1.0f,
		0.5f, -0.5f, -0.5f,     0.0f, -1.0f,  0.0f,     1.0f,  1.0f,
		0.5f, -0.5f,  0.5f,     0.0f, -1.0f,  0.0f,     1.0f,  0.0f,
		0.5f, -0.5f,  0.5f,     0.0f, -1.0f,  0.0f,     1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,    0.0f, -1.0f,  0.0f,     0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,    0.0f, -1.0f,  0.0f,     0.0f,  1.0f,

		-0.5f,  0.5f, -0.5f,    0.0f,  1.0f,  0.0f,     0.0f,  1.0f,
		0.5f,  0.5f, -0.5f,     0.0f,  1.0f,  0.0f,     1.0f,  1.0f,
		0.5f,  0.5f,  0.5f,     0.0f,  1.0f,  0.0f,     1.0f,  0.0f,
		0.5f,  0.5f,  0.5f,     0.0f,  1.0f,  0.0f,     1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,    0.0f,  1.0f,  0.0f,     0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,    0.0f,  1.0f,  0.0f,     0.0f,  1.0f
	};


	GLfloat skyboxVertices[] = {
		// Positions
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f,  1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f,  1.0f
	};


	GLuint indices[] =
	{  // Note that we start from 0!
		0,1,2,3,
		4,5,6,7,
		8,9,10,11,
		12,13,14,15,
		16,17,18,19,
		20,21,22,23,
		24,25,26,27,
		28,29,30,31,
		32,33,34,35
	};

	// Positions all containers
	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	readFile();

	// First, set the container's VAO (and VBO)
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Normals attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// Texture Coordinate attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0);

	// Then, we set the light's VAO (VBO stays the same. After all, the vertices are the same for the light object (also a 3D cube))
	GLuint lightVAO;
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	// We only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// Set the vertex attributes (only position data for the lamp))
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0); // Note that we skip over the other data in our buffer object (we don't need the normals/textures, only positions).
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);


	//SkyBox
	GLuint skyboxVBO, skyboxVAO;
	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1, &skyboxVBO);
	glBindVertexArray(skyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

	// Load textures 
	//Texturas para SkyBox
	vector<const GLchar*> facesDias, facesNoche;

	facesDias.push_back("SkyBox/right.tga");
	facesDias.push_back("SkyBox/left.tga");
	facesDias.push_back("SkyBox/top.tga");
	facesDias.push_back("SkyBox/bottom.tga");
	facesDias.push_back("SkyBox/back.tga");
	facesDias.push_back("SkyBox/front.tga");
	
	facesNoche.push_back("SkyBox(Noche)/right.tga");
	facesNoche.push_back("SkyBox(Noche)/left.tga");
	facesNoche.push_back("SkyBox(Noche)/top.tga");
	facesNoche.push_back("SkyBox(Noche)/bottom.tga");
	facesNoche.push_back("SkyBox(Noche)/back.tga");
	facesNoche.push_back("SkyBox(Noche)/front.tga");

	GLuint cubemapTexture = TextureLoading::LoadCubemap(facesDias);

	glm::mat4 projection = glm::perspective(camera.GetZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 1000.0f);

	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		if (EstadoDia) GLuint cubemapTexture = TextureLoading::LoadCubemap(facesDias);
		else GLuint cubemapTexture = TextureLoading::LoadCubemap(facesNoche);

		if (!camera.getIsometric()) {
			projection = glm::perspective(camera.GetZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 1000.0f);
			pointLightPositions[0] = glm::vec3(6.766, 0.670, 24.985);
			pointLightPositions[1] = glm::vec3(0.0f, 9.751f, 6.016f);
			pointLightPositions[2] = glm::vec3(0, 1.0, 19.892);
		}
		else {
			projection = glm::ortho(-camera.getIsoZoom(), camera.getIsoZoom(), -camera.getIsoZoom(), camera.getIsoZoom(), -30.0f, 40.f);
			glm::mat4 model(1);
			model = camera.ConfIsometric(model);
			pointLightPositions[0] = glm::vec3(model * glm::vec4(6.766, 0.670, 24.985, 1.0f));
			pointLightPositions[1] = glm::vec3(model * glm::vec4(0.0f, 9.751f, 6.016f, 1.0f));
			pointLightPositions[2] = glm::vec3(model * glm::vec4(0, 1.0, 19.892, 1.0f));
		}
		// Calculate deltatime of current frame
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		
		if (First)
		{
			deltaTime = 0;
			First = false;
		}
		DoMovement();
		animacion();
		animateKeyFrame();
		// Clear the colorbuffer
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// Use cooresponding shader when setting uniforms/drawing objects
		lightingShader.Use();
		GLint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");
		glUniform3f(viewPosLoc, camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
		// Set material properties
		glUniform1f(glGetUniformLocation(lightingShader.Program, "material.shininess"), 32.0f);
		// == ==========================
		// Here we set all the uniforms for the 5/6 types of lights we have. We have to set them manually and index
		// the proper PointLight struct in the array to set each uniform variable. This can be done more code-friendly
		// by defining light types as classes and set their values in there, or by using a more efficient uniform approach
		// by using 'Uniform buffer objects', but that is something we discuss in the 'Advanced GLSL' tutorial.
		// == ==========================
		// Directional light
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), 0.0f, -directionalAmbiental, -directionalAmbiental/2);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), ambiental1, ambiental1, ambiental2);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.2f, 0.2f, 0.2f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.1f, 0.1f, 0.1f);


		// Point light 1
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].position"), pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].ambient"), 0.05f, 0.05f, 0.05f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].diffuse"), 0.0f * PointlightTrue, 1.0f * PointlightTrue, 1.0f * PointlightTrue);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].specular"), 0.0f * PointlightTrue, 1.0f * PointlightTrue, 1.0f * PointlightTrue);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].constant"), 1.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].linear"), 0.054f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].quadratic"), 0.0192f);



		// Point light 2
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[1].position"), pointLightPositions[1].x, pointLightPositions[1].y, pointLightPositions[1].z);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[1].ambient"), 0.05f, 0.05f, 0.05f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[1].diffuse"), 1.0f * PointlightTrue, 1.0f * PointlightTrue, 1.0f * PointlightTrue);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[1].specular"), 1.0f * PointlightTrue, 1.0f * PointlightTrue, 0.0f * PointlightTrue);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[1].constant"), 1.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[1].linear"), 0.054f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[1].quadratic"), 0.0192f);

		// Point light 3
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[2].position"), pointLightPositions[2].x, pointLightPositions[2].y, pointLightPositions[2].z);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[2].ambient"), 0.0f, 0.0, 0.0f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[2].diffuse"), 1.0f * PointlightTrue, 0.0f * PointlightTrue, 0.0f * PointlightTrue);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[2].specular"), 1.0f * PointlightTrue, 0.0f * PointlightTrue, 0.0f * PointlightTrue);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[2].constant"), 1.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[2].linear"), 5.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[2].quadratic"), 3.0f);
		
		// SpotLight1
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight[0].position"), 6.766f, 5.0f, 24.985f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight[0].direction"), 0.0f, -1.0f, 0.0f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight[0].ambient"), espadaLuz, espadaLuz, espadaLuz);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight[0].diffuse"), espadaLuz * 0.1f, espadaLuz * 0.1f, espadaLuz * 0.1f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight[0].specular"), 1.0f, 0.0f, 0.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight[0].constant"), 1.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight[0].linear"), 0.1f);//0.09
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight[0].quadratic"), 0.01f);//0.032
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight[0].cutOff"), glm::cos(glm::radians(12.5f)));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight[0].outerCutOff"), glm::cos(glm::radians(15.0f)));
		// SpotLight2
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight[1].position"), 8.099f, 1.002f, 21.799f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight[1].direction"), -8.099f, 2.909f, 3.455f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight[1].ambient"), Reflectores, Reflectores, Reflectores);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight[1].diffuse"), Reflectores * 0.1f, Reflectores * 0.1f, Reflectores * 0.1f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight[1].specular"), 1.0f, 0.0f, 0.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight[1].constant"), 1.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight[1].linear"), 0.1f);//0.09
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight[1].quadratic"), 0.01f);//0.032
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight[1].cutOff"), glm::cos(glm::radians(12.5f)));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight[1].outerCutOff"), glm::cos(glm::radians(15.0f)));
		// SpotLight3
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight[2].position"), -8.099f, 1.002f, 21.799f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight[2].direction"), 8.099f, 2.909f, 3.455f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight[2].ambient"), Reflectores, Reflectores, Reflectores);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight[2].diffuse"), Reflectores * 0.1f, Reflectores * 0.1f, Reflectores * 0.1f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight[2].specular"), 1.0f, 0.0f, 0.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight[2].constant"), 1.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight[2].linear"), 0.1f);//0.09
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight[2].quadratic"), 0.01f);//0.032
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight[2].cutOff"), glm::cos(glm::radians(12.5f)));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight[2].outerCutOff"), glm::cos(glm::radians(15.0f)));
		// Set material properties										   
		glUniform1f(glGetUniformLocation(lightingShader.Program, "material.shininess"), 32.0f);
		
		// Create camera transformations
		glm::mat4 view;
		view = camera.GetViewMatrix();

		// Get the uniform locations
		GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
		GLint projLoc = glGetUniformLocation(lightingShader.Program, "projection");

		// Pass the matrices to the shader
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		// Bind diffuse map
		//glBindTexture(GL_TEXTURE_2D, texture1);*/

		// Bind specular map
		/*glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);*/

		//Carga de modelo 
		// Castillo////////////////////////////////////////////////////////////////////////////////////////////////////////////
		view = camera.GetViewMatrix();
		glm::mat4 modelaux(1);
		glm::mat4 modelauxCabeza(1);
		glm::mat4 modelauxIzquierda(1);
		glm::mat4 modelauxIzquierda2(1);
		glm::mat4 modelauxDerecha(1);
		glm::mat4 modelauxDerecha2(1);
		glm::mat4 model(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Castillo.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(1.362f, 1.417f, 5.059f));
		model = glm::rotate(model, glm::radians(-RotPuerta), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Puerta2.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-1.495f, 1.417f, 5.059f));
		model = glm::rotate(model, glm::radians(RotPuerta), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Puerta1.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 22.503f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Jardin.Draw(lightingShader);

		//Arboles////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(17.137f, -0.051f, -3.08f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Arbol.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(12.152f, -0.051f, 6.455f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Arbol.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(17.699f, -0.051f, 16.877f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Arbol.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(10.537f, -0.051f, 20.174f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Arbol.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(16.341f, -0.051f, 26.934f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Arbol.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-15.959f, -0.051f, 26.953f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Arbol.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-10.569f, -0.051f, 20.174f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Arbol.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-17.286f, -0.051f, 13.042f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Arbol.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-6.216f, -0.051f, 11.462f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Arbol.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-12.416f, -0.051f, -4.057f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Arbol.Draw(lightingShader);
		//Flores////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(4.224f, -0.029f + FlorBrinco, 7.360f));
		model = glm::rotate(model, glm::radians(-3 * FlorGiro / 20), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Flor.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(3.441f, -0.029f + FlorBrinco, 7.360f));
		model = glm::rotate(model, glm::radians(-3 * FlorGiro / 20), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Flor.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(2.587f, -0.029f + FlorBrinco, 7.360f));
		model = glm::rotate(model, glm::radians(-3 * FlorGiro / 20), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Flor.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(3.727f, -0.029f + FlorBrinco, 8.156f));
		model = glm::rotate(model, glm::radians(3 * FlorGiro / 20), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Flor.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(2.944f, -0.029f + FlorBrinco, 8.156f));
		model = glm::rotate(model, glm::radians(3 * FlorGiro / 20), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Flor.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-4.224f, -0.029f + FlorBrinco, 7.360f));
		model = glm::rotate(model, glm::radians(3 * FlorGiro / 20), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Flor.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-3.441f, -0.029f + FlorBrinco, 7.360f));
		model = glm::rotate(model, glm::radians(3 * FlorGiro / 20), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Flor.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-2.587f, -0.029f + FlorBrinco, 7.360f));
		model = glm::rotate(model, glm::radians(3 * FlorGiro / 20), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Flor.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-3.727f, -0.029f + FlorBrinco, 8.156));
		model = glm::rotate(model, glm::radians(-3 * FlorGiro / 20), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Flor.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-2.944f, -0.029f + FlorBrinco, 8.156));
		model = glm::rotate(model, glm::radians(-3 * FlorGiro / 20), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Flor.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(1.349f, 2.609f, -5.227f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		FlorGrande.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-1.231f, 2.609f, -5.227f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		FlorGrande.Draw(lightingShader);
		//Arbustos////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(2.355f, 0.58f, 25.033f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Arbusto.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-2.355f, 0.58f, 25.033f));
		model = glm::rotate(model, glm::radians(-127.333f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Arbusto.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(7.704f, 0.58f, 20.023f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Arbusto.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-7.704f, 0.58f, 20.023f));
		model = glm::rotate(model, glm::radians(-127.333f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Arbusto.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f, 0.551f, 25.27f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		ArbustoPeach.Draw(lightingShader);
		//Postes////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(8.854f, -0.024f, 27.501f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Poste.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(8.854f, -0.024f, 18.199f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Poste.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-8.854f, -0.024f, 18.199f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Poste.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-8.854f, -0.024f, 27.501f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Poste.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(16.421f, -0.024f, 14.483f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Poste.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(12.483f, -0.024f, 14.483f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Poste.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-16.421f, -0.024f, 14.483f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Poste.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-12.483f, -0.024f, 14.483f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Poste.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(10.003f, 0.486f, 7.400f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Poste.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-10.003f, 0.486f, 7.400f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Poste.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(10.003f, 0.486f, -6.716f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Poste.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-10.003f, 0.486f, -6.716f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Poste.Draw(lightingShader);
		//Flechas////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-17.384f, -0.056f, -9.762f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Flecha.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(17.354f, -0.039f, -9.491f));
		model = glm::rotate(model, glm::radians(-90.000f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Flecha.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(13.479f, 0.331f, 14.417f));
		model = glm::rotate(model, glm::radians(-90.000f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Flecha.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(14.072f, 2.163f, 24.398f));
		model = glm::rotate(model, glm::radians(180.000f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Flecha.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-15.741f, 2.163f, 22.418f));
		model = glm::rotate(model, glm::radians(90.000f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Flecha.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-15.393f, 2.794f, 18.901f));
		model = glm::rotate(model, glm::radians(51.138f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Flecha.Draw(lightingShader);
		//Spot////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(8.213f, 0.595f, 21.701f));
		model = glm::scale(model, glm::vec3(-1.0f, 1.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Spot.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-8.213f, 0.595f, 21.701f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Spot.Draw(lightingShader);
		//Foco////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if (Reflectores>0) {
			glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), 0.0f, 0.0f, 0.0f);
			glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), 2.0f, 2.0f, 2.0f);
			glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.7f, 0.7f, 0.7f);
			glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.9f, 0.9f, 0.9f);
		}
		if (Reflectores < 1.0) {
			glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), 0.0f, -directionalAmbiental, -directionalAmbiental / 2);
			glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), ambiental1, ambiental1, ambiental2);
			glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.2f, 0.2f, 0.2f);
			glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.1f, 0.1f, 0.1f);
		}
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(8.213f, 0.595f, 21.701f));
		model = glm::scale(model, glm::vec3(-1.0f, 1.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Foco.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-8.213f, 0.595f, 21.701f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Foco.Draw(lightingShader);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), 0.0f, -directionalAmbiental, -directionalAmbiental / 2);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), ambiental1, ambiental1, ambiental2);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.2f, 0.2f, 0.2f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.1f, 0.1f, 0.1f);
		//Antorcha////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(2.637f, 0.743f, 5.580f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		torch.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-2.637f, 0.743f, 5.580f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		torch.Draw(lightingShader);
		//Trono////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f, 2.188f, -5.236f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Trono.Draw(lightingShader);
		//Floreros////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(1.372, 2.187f, -5.217f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		FloreroAzul.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-1.218f, 2.187f, -5.217f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		FloreroAzul.Draw(lightingShader);
		//Estrella////////////////////////////////////////////////////////////////////////////////////////////////////////////
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), 0.0f, 0.0f, 0.0f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), 0.9f, 0.9f, 0.9f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.7f, 0.7f, 0.7f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.9f, 0.9f, 0.9f);
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f, 9.751f + (auxilar1 / 2000), 6.016f));
		model = glm::rotate(model, glm::radians(Rotacion2), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Star.Draw(lightingShader);
		//Estrellas////////////////////////////////////////////////////////////////////////////////////////////////////////////
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), 0.0f, 0.0f, 0.0f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), PosteLuzRG, PosteLuzRG, PosteLuzB);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.7f, 0.7f, 0.7f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.9f, 0.9f, 0.9f);
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(8.854f, 2.559f, 27.501f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Estrellitas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(8.854f, 2.559f, 18.199f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Estrellitas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-8.854f, 2.559f, 18.199f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Estrellitas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-8.854f, 2.559f, 27.501f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Estrellitas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(16.421f, 2.559f, 14.483f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Estrellitas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(12.483f, 2.559f, 14.483f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Estrellitas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-16.421f, 2.559f, 14.483f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Estrellitas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-12.483f, 2.559f, 14.483f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Estrellitas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(10.003f, 3.069f, 7.400f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Estrellitas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-10.003f, 3.069f, 7.400f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Estrellitas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(10.003f, 3.069f, -6.716f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Estrellitas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-10.003f, 3.069f, -6.716f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Estrellitas.Draw(lightingShader);
		//Cubo////////////////////////////////////////////////////////////////////////////////////////////////////////////
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), 0.0f, -directionalAmbiental, -directionalAmbiental / 2);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), ambiental1, ambiental1, ambiental2);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.2f, 0.2f, 0.2f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.1f, 0.1f, 0.1f);
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-12.739f, 1.956f + Golpe, 6.117f));
		model = glm::scale(model, glm::vec3(EscalaCubo, EscalaCubo, EscalaCubo));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Cubo.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-12.739f, 1.956f + Golpe, 6.117f));
		model = glm::scale(model, glm::vec3(EscalaVacia, EscalaVacia, EscalaVacia));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Vacio.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-12.739f, 1.956f + TiroVertical + Golpe, 6.117f));
		model = glm::rotate(model, glm::radians(RoatChampi), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Champi.Draw(lightingShader);
		//FlyGuy////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		modelaux = model;
		model = glm::translate(model, glm::vec3(-8.162f, 2.224f + (auxilar1 / 2000), 0.0f + TrasladoFlyguy));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-20.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, glm::radians(-RoatFlyGuy), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		FlyGuy.Draw(lightingShader);

		modelaux = model;
		model = modelaux;
		model = glm::rotate(model, glm::radians(Rotacion2 * 10), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Helices.Draw(lightingShader);
		//PlantaPiraña////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-15.822f, 2.288f, 19.786f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Tubo.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-15.822f, 2.108f, 19.786f));
		model = glm::scale(model, glm::vec3(1.0f, 1.0f* piranaPlant/ 1.013, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Tallo.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-15.822f, 2.352f+ piranaPlant, 19.786f));
		model = glm::rotate(model, glm::radians(AnguloMorida), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		piranha_plant_cabeza_sup.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-15.822f, 2.352f + piranaPlant, 19.786f));
		model = glm::rotate(model, glm::radians(-AnguloMorida), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		piranha_plant_cabeza_inf.Draw(lightingShader);
		//Goomba////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(12.695f + CaminataGoomba, -0.026, 27.057f));
		model = glm::rotate(model, glm::radians(rotCabezaGoomba), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		GoombaCabeza.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(12.695f + CaminataGoomba, -0.026, 27.057f));
		model = glm::rotate(model, glm::radians(2 * rotPieDerGoomba), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		GoombaPieDer.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(12.695f + CaminataGoomba, -0.026, 27.057f));
		model = glm::rotate(model, glm::radians(2 * rotPieIzqGoomba), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		GoombaPieIzq.Draw(lightingShader);
		//Bobomb////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-13.966f, 0.075f, 26.597f));
		model = glm::rotate(model, glm::radians(RoatBomba), glm::vec3(0.0f, 1.0f, 0.0f));
		modelaux = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Bobomb.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.0f, 0.244f, -0.203f));
		model = glm::rotate(model, glm::radians(RoatLlave), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Llave.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-13.969f, -0.022f + pieDerBomba, 26.606f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		PieDerBob.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-13.969f, -0.022f + pieIzqBomba, 26.606f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		PieIzqBob.Draw(lightingShader);
		//KartLadybug//////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-10.663f + LadyBugmovKitX, 0.08f + LadyBugmovKitY, -8.877f + LadyBugmovKitZ));
		model = glm::rotate(model, glm::radians(LadyBugrotKit + 90), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-LadyBugGiroExtremo), glm::vec3(1.0f, 0.0f, 0.0f));
		modelaux = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		KartLadyBug.Draw(lightingShader);

		model = modelaux;
		model = glm::translate(model, glm::vec3(0.257f, 0.0f, 0.329f));
		model = glm::rotate(model, glm::radians(Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		LlantaNormal.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.235f, 0.0f, -0.234f));
		model = glm::rotate(model, glm::radians(Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		LlantaNormal.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.257f, 0.0f, 0.329f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		LlantaNormal.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.259f, 0.0f, -0.234f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		LlantaNormal.Draw(lightingShader);

		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.028f, 0.180f, -0.300f));
		model = glm::scale(model, glm::vec3(LadyBugXscale, LadyBugYscale, LadyBugZscale));
		model = glm::rotate(model, glm::radians(Viento), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Paracaidas.Draw(lightingShader);
		//KartBobesponja//////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-10.663f + BobEsponjamovKitX, 0.04f + BobEsponjamovKitY, -8.877f + BobEsponjamovKitZ));
		model = glm::rotate(model, glm::radians(BobEsponjarotKit + 90), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-BobEsponjaGiroExtremo), glm::vec3(1.0f, 0.0f, 0.0f));
		modelaux = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		KartBobEsponja.Draw(lightingShader);

		model = modelaux;
		model = glm::translate(model, glm::vec3(0.206f, 0.0f, 0.155f));
		model = glm::rotate(model, glm::radians(Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Pepinillos.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.206f, 0.0f, -0.136f));
		model = glm::rotate(model, glm::radians(Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Pepinillos.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.289f, 0.0f, 0.155f));
		model = glm::rotate(model, glm::radians(Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Pepinillos.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.281f, 0.0f, -0.136f));
		model = glm::rotate(model, glm::radians(Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Pepinillos.Draw(lightingShader);

		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.028f, 0.386f, -0.217f));
		model = glm::scale(model, glm::vec3(BobEsponjaXscale, BobEsponjaYscale, BobEsponjaZscale));
		model = glm::rotate(model, glm::radians(Viento), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Papel.Draw(lightingShader);
		//Goku////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-10.663f + GokumovKitX, 0.08f + GokumovKitY, -8.877f + GokumovKitZ));
		model = glm::rotate(model, glm::radians(GokurotKit + 90), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-GokuGiroExtremo), glm::vec3(1.0f, 0.0f, 0.0f));
		modelaux = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		KartGoku.Draw(lightingShader);

		model = modelaux;
		model = glm::translate(model, glm::vec3(0.313f, 0.0f, 0.224f));
		model = glm::rotate(model, glm::radians(Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Rojas.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.313f, 0.0f, -0.137f));
		model = glm::rotate(model, glm::radians(Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Rojas.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.324f, 0.0f, 0.224f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Rojas.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.324f, 0.0f, -0.137f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Rojas.Draw(lightingShader);

		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.005f, 0.386f, -0.258f));
		model = glm::scale(model, glm::vec3(GokuXscale, GokuYscale, GokuZscale));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Ardilla.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.0f, 0.911f, -0.478f));
		model = glm::scale(model, glm::vec3(GokuXscale, GokuYscale, GokuZscale));
		model = glm::rotate(model, glm::radians(3 * Viento), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		ColitaArdilla.Draw(lightingShader);
		//Mulan////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-10.663f + MulanmovKitX, 0.1f + MulanmovKitY, -8.877f + MulanmovKitZ));
		model = glm::rotate(model, glm::radians(MulanrotKit + 90), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-MulanGiroExtremo), glm::vec3(1.0f, 0.0f, 0.0f));
		modelaux = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		KartMulan.Draw(lightingShader);

		model = modelaux;
		model = glm::translate(model, glm::vec3(0.273f, 0.0f, 0.318f));
		model = glm::rotate(model, glm::radians(Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Monster.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.273f, 0.0f, 0.015f));
		model = glm::rotate(model, glm::radians(Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Monster.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.273f, 0.047f, -0.460f));
		model = glm::scale(model, glm::vec3(1.271f, 1.271f, 1.271f));
		model = glm::rotate(model, glm::radians(Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Monster.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.332f, 0.0f, 0.318f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Monster.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.332f, 0.0f, 0.015f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Monster.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.332f, 0.047f, -0.460f));
		model = glm::scale(model, glm::vec3(1.271f, 1.271f, 1.271f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Monster.Draw(lightingShader);

		model = modelaux;
		model = glm::translate(model, glm::vec3(0.000f, 0.244f, -0.489f));
		model = glm::scale(model, glm::vec3(MulanXscale, MulanYscale, MulanZscale));
		model = glm::rotate(model, glm::radians(Viento), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Mushu.Draw(lightingShader);
		//ChillyWilly Vueltas locas////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f + TraslacionXChilly, 0.0f, 15.607f + TraslacionZChilly));
		model = glm::rotate(model, glm::radians(-VariableRadioGiros * 180), glm::vec3(0.0f, 1.0f, 0.0f));
		modelaux = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		ChillyWilly.Draw(lightingShader);

		model = modelaux;
		model = glm::translate(model, glm::vec3(0.122f, 0.037f, 0.167f));
		model = glm::rotate(model, glm::radians(Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		LlantaNegra.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.122f, 0.037f, -0.115f));
		model = glm::rotate(model, glm::radians(Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		LlantaNegra.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.137f, 0.037f, 0.167f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		LlantaNegra.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.137f, 0.037f, -0.115f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-Rotacion1), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		LlantaNegra.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 15.607f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		ArbustoMario.Draw(lightingShader);
		//ChainChomp////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f + TraslacionXChainChomp, 0.5f + (0.4 * TraslacionYChainChomp), 15.607f + TraslacionZChainChomp));
		model = glm::rotate(model, glm::radians(120.0f - VariableRadioGiros * 180), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-40.0f * TraslacionYChainChomp), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		ChainChompSup.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f + TraslacionXChainChomp, 0.5f + (0.4 * TraslacionYChainChomp), 15.607f + TraslacionZChainChomp));
		model = glm::rotate(model, glm::radians(120.0f - VariableRadioGiros * 180), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(40.0f * TraslacionYChainChomp), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		ChainChompInf.Draw(lightingShader);
		//Monedas////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-6.240f + TraslacionXMonedas, 0.579f, 24.198f + TraslacionZMonedas));
		model = glm::rotate(model, glm::radians(-VariableMonedasGiros * 720), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Monedas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-6.240f + TraslacionXMonedas1, 0.579f, 24.198f + TraslacionZMonedas1));
		model = glm::rotate(model, glm::radians(-VariableMonedasGiros * 720), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Monedas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-6.240f + TraslacionXMonedas2, 0.579f, 24.198f + TraslacionZMonedas2));
		model = glm::rotate(model, glm::radians(-VariableMonedasGiros * 720), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Monedas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-6.240f + TraslacionXMonedas3, 0.579f, 24.198f + TraslacionZMonedas3));
		model = glm::rotate(model, glm::radians(-VariableMonedasGiros * 720), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Monedas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-6.240f + TraslacionXMonedas4, 0.579f, 24.198f + TraslacionZMonedas4));
		model = glm::rotate(model, glm::radians(-VariableMonedasGiros * 720), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Monedas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-6.240f + TraslacionXMonedas5, 0.579f, 24.198f + TraslacionZMonedas5));
		model = glm::rotate(model, glm::radians(-VariableMonedasGiros * 720), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Monedas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-6.240f + TraslacionXMonedas6, 0.579f, 24.198f + TraslacionZMonedas6));
		model = glm::rotate(model, glm::radians(-VariableMonedasGiros * 720), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Monedas.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-6.240f + TraslacionXMonedas7, 0.579f, 24.198f + TraslacionZMonedas7));
		model = glm::rotate(model, glm::radians(-VariableMonedasGiros * 720), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Monedas.Draw(lightingShader);
		//Peach////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-6.240f + TraslacionXPeach, 0.619f, 24.198f + TraslacionZPeach));
		model = glm::rotate(model, glm::radians(VariablePeachGiros * 360), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Peach.Draw(lightingShader);
		//Paratroopa////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		modelaux = model;
		model = glm::translate(model, glm::vec3(3.422f, 1.257 + (auxilar1 / 2000), -4.794f + VueloParatroopa));
		model = glm::rotate(model, glm::radians(RoatParatroopa), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Paratroopa.Draw(lightingShader);
		modelaux = model;
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.061f, 0.085f, -0.042f));
		model = glm::rotate(model, glm::radians(RotBrazo * 4), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		AlaDerecha.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.061f, 0.085f, -0.042f));
		model = glm::rotate(model, glm::radians(-RotBrazo * 4), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		AlaIzquierda.Draw(lightingShader);
		//Toad////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		modelaux = model;
		model = glm::translate(model, glm::vec3(-1.247f, 0.609f + (IDLE * 1.7), -0.619f));
		model = glm::rotate(model, glm::radians(38.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CuerpoToad.Draw(lightingShader);
		modelaux = model;
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.044f, 0.175f, 0.0f));
		model = glm::rotate(model, glm::radians(RotBrazo), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BrazoDer.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.044f, 0.175f, 0.0f));
		model = glm::rotate(model, glm::radians(-RotBrazo), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BrazoIzq.Draw(lightingShader);
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-1.247f, 0.576f + IDLE, -0.619f));
		model = glm::rotate(model, glm::radians(38.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(IDLE * 800), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Zapatos.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		modelaux = model;
		model = glm::translate(model, glm::vec3(1.247f, 0.609f + (IDLE * 1.7), -0.619f));
		model = glm::rotate(model, glm::radians(-38.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CuerpoToad.Draw(lightingShader);
		modelaux = model;
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.044f, 0.175f, 0.0f));
		model = glm::rotate(model, glm::radians(RotBrazo), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BrazoDer.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.044f, 0.175f, 0.0f));
		model = glm::rotate(model, glm::radians(-RotBrazo), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BrazoIzq.Draw(lightingShader);
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(1.247f, 0.576f + IDLE, -0.619f));
		model = glm::rotate(model, glm::radians(-38.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(IDLE * 800), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Zapatos.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		modelaux = model;
		model = glm::translate(model, glm::vec3(12.822f, 2.206f + (Brinco * 1.7), 19.465f));
		model = glm::rotate(model, glm::radians(38.0f + (Giro / 4)), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CuerpoToad.Draw(lightingShader);
		modelaux = model;
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.044f, 0.175f, 0.0f));
		model = glm::rotate(model, glm::radians(25.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, glm::radians(Giro), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BrazoDer.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.044f, 0.175f, 0.0f));
		model = glm::rotate(model, glm::radians(-25.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, glm::radians(Giro), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BrazoIzq.Draw(lightingShader);
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(12.822f, 2.178f + Brinco, 19.465f));
		model = glm::rotate(model, glm::radians(38.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(Brinco * 800), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Zapatos.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		modelaux = model;
		model = glm::translate(model, glm::vec3(-17.786f, 0.011f, 10.428f));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(RotBrazo - 10), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CuerpoToad.Draw(lightingShader);
		modelaux = model;
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.059f, 0.165f, 0.0f));
		model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(4 * RotBrazo - 20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BrazoDer.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.044f, 0.175f, 0.0f));
		model = glm::rotate(model, glm::radians(-25.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BrazoIzq.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-17.786f, -0.022f, 10.428f));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Zapatos.Draw(lightingShader);
		//Purohueso Hamburguesas////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f, 0.603f, 19.482f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		PuroHuesos.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f, 1.053f, 19.487f));
		model = glm::rotate(model, glm::radians(26.367f - 98.1f * (HamburVuelo)), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Cabeza.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.229f, 1.041f, 19.593f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Oz.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-0.063f, 0.973f, 19.525f));
		model = glm::rotate(model, glm::radians(11.791f - roatAnteBrazo), glm::vec3(1.0f, 0.0f, 0.0f));
		modelaux = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Antebrazo.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.029f, -0.005f, 0.105f));
		model = glm::rotate(model, glm::radians(-8.0f - roatAnteBrazo / 4), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Espatula.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f, 0.749f, 19.892f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Parrilla.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.108f, 0.940f, 19.860f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CarneHamburguesa.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.035f, 0.940f, 19.955f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CarneHamburguesa.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-0.020f, 0.940f, 19.843f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CarneHamburguesa.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-0.092f, 0.940f + HamburVuelo, 19.88f));
		model = glm::rotate(model, glm::radians(438.27664f * (TiempovueloHamburguesa)), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CarneHamburguesa.Draw(lightingShader);
		//KoopaTroopas////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f, 0.606f+IDLE*0.3, 20.438f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(RotCaparazon/10), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		PiesKoopa.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f, 0.772f + IDLE*0.6, 20.482f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-20+RotCaparazon), glm::vec3(1.0f, 0.0f, 0.0f));
		modelaux = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CaparazonVerde.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.034f, 0.112f, 0.034f));
		model = glm::rotate(model, glm::radians(RotCaparazon * 3), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, glm::radians(-RotCaparazon), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-47.497f), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		DerechaKoopa.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.034f, 0.112f, 0.034f));
		model = glm::rotate(model, glm::radians(-RotCaparazon * 3), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, glm::radians(RotCaparazon), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-47.497f), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		IzquierdaKoopa.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.0f, 0.141f, 0.034f));
		model = glm::rotate(model, glm::radians(-RotCaparazon), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CabezaKoopa.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.4f, 0.606f + IDLE * 0.3, 20.388f));
		model = glm::rotate(model, glm::radians(210.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(RotCaparazon / 10), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		PiesKoopa.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.400f, 0.772f + IDLE * 0.6, 20.432f));
		model = glm::rotate(model, glm::radians(210.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-20 + RotCaparazon), glm::vec3(1.0f, 0.0f, 0.0f));
		modelaux = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CaparazonVerde.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.034f, 0.112f, 0.034f));
		model = glm::rotate(model, glm::radians(-RotCaparazon * 3), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, glm::radians(RotCaparazon), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-47.497f), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		DerechaKoopa.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.034f, 0.112f, 0.034f));
		model = glm::rotate(model, glm::radians(RotCaparazon * 3), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, glm::radians(-RotCaparazon), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-47.497f), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		IzquierdaKoopa.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.0f, 0.141f, 0.034f));
		model = glm::rotate(model, glm::radians(-RotCaparazon), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CabezaKoopa.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-0.4, 0.606f + IDLE * 0.3, 20.388f));
		model = glm::rotate(model, glm::radians(150.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(RotCaparazon / 10), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		PiesKoopa.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-0.4f, 0.772f + IDLE * 0.6, 20.432f));
		model = glm::rotate(model, glm::radians(150.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-20 + RotCaparazon), glm::vec3(1.0f, 0.0f, 0.0f));
		modelaux = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CaparazonVerde.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.034f, 0.112f, 0.034f));
		model = glm::rotate(model, glm::radians(-RotCaparazon * 3), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, glm::radians(RotCaparazon), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-47.497f), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		DerechaKoopa.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.034f, 0.112f, 0.034f));
		model = glm::rotate(model, glm::radians(RotCaparazon * 3), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, glm::radians(-RotCaparazon), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-47.497f), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		IzquierdaKoopa.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.0f, 0.141f, 0.034f));
		model = glm::rotate(model, glm::radians(-RotCaparazon), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CabezaKoopa.Draw(lightingShader);
		//Mario Tanooki////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f, 8.861f + VueloAltura / 2, -5.78f));
		model = glm::rotate(model, glm::radians(10 * (auxilar1 / 100)), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Mario.Draw(lightingShader);
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f, 8.861f + VueloAltura / 2, -5.78f));
		model = glm::rotate(model, glm::radians(10 * (auxilar1 / 100)), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(20.0f * (Viento / 3)), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Colita.Draw(lightingShader);
		//Luigi////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-2.704f, 0.577f + IDLE/2, -2.092f));
		modelaux = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		PiesLuigi.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.012f, 0.343f, 0.001f));
		model = glm::rotate(model, glm::radians(MovimientoJuego), glm::vec3(0.0f, 0.0f, 1.0f));
		modelauxCabeza = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BrazosLuigi.Draw(lightingShader);
		model = modelauxCabeza;
		model = glm::translate(model, glm::vec3(0.0f, 0.091f, -0.032f));
		model = glm::rotate(model, glm::radians(20.0f-MovimientoCabezaLuigi), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CabezaLuigi.Draw(lightingShader);
		//Marco////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(3.422f, 1.282f, -3.993f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Marco.Draw(lightingShader);
		//CheepCheep////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-17.787f, 0.070f + AlturaNadado, 9.991f));
		modelaux = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CheepCheep.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.035f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(AletasCheep), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CheepIzquierda.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.035f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(-AletasCheep), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CheepDerecha.Draw(lightingShader);
		//Bowser////////////////////////////////////////////////////////////////////////////////////////////////////////////
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f, 7.0f + (auxilar1 / 2000), 0.0f));
		modelaux = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		KoopaClown.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.0f, -0.22f, 0.0f));
		model = glm::rotate(model, glm::radians(-Rotacion1), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		KoopaClownHelices.Draw(lightingShader);
		model = modelaux;
		model = glm::translate(model, glm::vec3(0.0f, 0.232f, 0.1f));
		model = glm::rotate(model, glm::radians(2.5f+ IDLEBowserCuerpo), glm::vec3(1.0f, 0.0f, 0.0f));
		modelaux = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BowserCuerpo.Draw(lightingShader);

		model = modelaux;
		model = glm::translate(model, glm::vec3(0.161f, 0.344f, 0.120f));
		model = glm::rotate(model, glm::radians(-23.0f + 3* IDLEBowserBrazos), glm::vec3(0.0f, 0.0f, 1.0f));
		modelauxIzquierda = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BowserBrazoIzquierdo.Draw(lightingShader);

		model = modelauxIzquierda;
		model = glm::translate(model, glm::vec3(0.096f, 0.0f, 0.002f));
		model = glm::rotate(model, glm::radians(-25.0f + 3 * IDLEBowserCodos), glm::vec3(0.0f, 0.0f, 1.0f));
		modelauxIzquierda2 = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BowserCodoIzquierdo.Draw(lightingShader);
		/////////////////////////////////////////////
		model = modelauxIzquierda2;
		model = glm::translate(model, glm::vec3(0.096f, 0.003f, -0.045f));
		model = glm::rotate(model, glm::radians(5* IDLEBowserManos), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BowserManoIzquierda.Draw(lightingShader);

		model = modelaux;
		model = glm::translate(model, glm::vec3(-0.171f, 0.328f, 0.093f));
		model = glm::rotate(model, glm::radians(23.0f - 3* IDLEBowserBrazos), glm::vec3(0.0f, 0.0f, 1.0f));
		modelauxDerecha = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BowserBrazoDerecho.Draw(lightingShader);

		model = modelauxDerecha;
		model = glm::translate(model, glm::vec3(-0.082f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(25.0f - 3 * IDLEBowserCodos), glm::vec3(0.0f, 0.0f, 1.0f));
		modelauxDerecha2 = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BowserCodoDerecho.Draw(lightingShader);
		/////////////////////////////////////////////////
		model = modelauxDerecha2;
		model = glm::translate(model, glm::vec3(-0.112f, 0.0f, 0.008f));
		model = glm::rotate(model, glm::radians(5* IDLEBowserManos), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BowserManoDerecha.Draw(lightingShader);

		model = modelaux;
		model = glm::translate(model, glm::vec3(0.0f, 0.379f, 0.174f));
		model = glm::rotate(model, glm::radians(IDLEBowserCabeza), glm::vec3(0.0f, 1.0f, 1.0f));
		model = glm::rotate(model, glm::radians(5.0f+ 2*IDLEBowserCuerpo), glm::vec3(1.0f, 0.0f, 0.0f));
		modelauxCabeza = model;
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BowserCabeza.Draw(lightingShader);
		model = modelauxCabeza;
		model = glm::translate(model, glm::vec3(0.0f, -0.036f, 0.096f));
		model = glm::rotate(model, glm::radians(3.0f - 3 * IDLEBowserMandibula), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BowserMandibula.Draw(lightingShader);
		model = glm::mat4(1);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(6.766f, 0.57f, 24.985f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Roca.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(6.766f + posX, 1.893f + posY, 24.985f + posZ));
		model = glm::rotate(model, glm::radians(rotRodIzq), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Mango.Draw(lightingShader);

		
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), 0.0f, 0.0f, 0.0f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), PosteLuzB, PosteLuzRG * 1.5f, PosteLuzRG * 1.5f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.7f, 0.7f, 0.7f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.9f, 0.9f, 0.9f);
		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);
		model = glm::translate(model, glm::vec3(0.0f, 0.352f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Espada.Draw(lightingShader);

		glBindVertexArray(0);

		Anim.Use();
		times = glfwGetTime() * 12;
		// Get location objects for the matrices on the lamp shader (these could be different on a different shader)
		modelLoc = glGetUniformLocation(Anim.Program, "model");
		viewLoc = glGetUniformLocation(Anim.Program, "view");
		projLoc = glGetUniformLocation(Anim.Program, "projection");
		// Set matrices
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(3.422f, 1.282f, -3.993f));

		glUniform4f(glGetUniformLocation(lightingShader.Program, "transparencia"), 1.0f, 1.0f, 1.0f, 0.1f);

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(Anim.Program, "times"), times);
		glUniform1f(glGetUniformLocation(Anim.Program, "Redu"), Reducir);
		glUniform1f(glGetUniformLocation(Anim.Program, "Ilum"), ambiental1);
		Pintura.Draw(Anim);
		glBindVertexArray(0);

		// Also draw the lamp object, again binding the appropriate shader
		lampShader.Use();
		// Get location objects for the matrices on the lamp shader (these could be different on a different shader)
		modelLoc = glGetUniformLocation(lampShader.Program, "model");
		viewLoc = glGetUniformLocation(lampShader.Program, "view");
		projLoc = glGetUniformLocation(lampShader.Program, "projection");

		// Set matrices
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		model = glm::mat4(1);
		model = glm::translate(model, lightPos);
		//model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		// Draw the light object (using light's vertex attributes)
		glBindVertexArray(lightVAO);
		for (GLuint i = 0; i < 4; i++)
		{
			model = glm::mat4(1);
			model = glm::translate(model, pointLightPositions[i]);
			model = glm::scale(model, glm::vec3(0.0001f)); // Make it a smaller cube
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}
		glBindVertexArray(0);


		// Draw skybox as last
		glDepthFunc(GL_LEQUAL);  // Change depth function so depth test passes when values are equal to depth buffer's content
		SkyBoxshader.Use();
		view = glm::mat4(glm::mat3(camera.GetViewMatrix()));	// Remove any translation component of the view matrix
		glUniformMatrix4fv(glGetUniformLocation(SkyBoxshader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(glGetUniformLocation(SkyBoxshader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

		// skybox cube
		glBindVertexArray(skyboxVAO);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);
		glDepthFunc(GL_LESS); // Set depth function back to default
		glBindVertexArray(0);
		lightingShader.Use();
		//Ventanas Translucidas
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), 0.0f, -directionalAmbiental, -directionalAmbiental / 2);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), ambiental1, ambiental1, ambiental2);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.2f, 0.2f, 0.2f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.1f, 0.1f, 0.1f);
		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		glEnable(GL_BLEND);//Avtiva la funcionalidad para trabajar el canal alfa
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		model = glm::translate(model, glm::vec3(4.407f, 2.77f, -5.787f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "colorAlpha"), 1.0f, 1.0f, 1.0f, 1.0f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		VentanaTransparente.Draw(lightingShader);
		glDisable(GL_BLEND);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		glEnable(GL_BLEND);//Avtiva la funcionalidad para trabajar el canal alfa
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		model = glm::translate(model, glm::vec3(2.077f, 2.77f, -5.787f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "colorAlpha"), 1.0f, 1.0f, 1.0f, 1.0f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		VentanaTransparente.Draw(lightingShader);
		glDisable(GL_BLEND);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		glEnable(GL_BLEND);//Avtiva la funcionalidad para trabajar el canal alfa
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		model = glm::translate(model, glm::vec3(-1.945f, 2.77f, -5.857f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "colorAlpha"), 1.0f, 1.0f, 1.0f, 1.0f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		VentanaTransparente.Draw(lightingShader);
		glDisable(GL_BLEND);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		glEnable(GL_BLEND);//Avtiva la funcionalidad para trabajar el canal alfa
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		model = glm::translate(model, glm::vec3(-4.266f, 2.77f, -5.867f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "colorAlpha"), 1.0f, 1.0f, 1.0f, 1.0f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		VentanaTransparente.Draw(lightingShader);
		glDisable(GL_BLEND);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		glEnable(GL_BLEND);//Avtiva la funcionalidad para trabajar el canal alfa
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		model = glm::translate(model, glm::vec3(-6.407f, 1.346f, 3.309f));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "colorAlpha"), 1.0f, 1.0f, 1.0f, 1.0f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		VentanaTransparente.Draw(lightingShader);
		glDisable(GL_BLEND);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		glEnable(GL_BLEND);//Avtiva la funcionalidad para trabajar el canal alfa
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		model = glm::translate(model, glm::vec3(-6.407f, 1.346f, 1.428f));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "colorAlpha"), 1.0f, 1.0f, 1.0f, 1.0f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		VentanaTransparente.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		glEnable(GL_BLEND);//Avtiva la funcionalidad para trabajar el canal alfa
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		model = glm::translate(model, glm::vec3(-6.407f, 2.745f, -2.662));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "colorAlpha"), 1.0f, 1.0f, 1.0f, 1.0f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		VentanaTransparente.Draw(lightingShader);
		glDisable(GL_BLEND);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		glEnable(GL_BLEND);//Avtiva la funcionalidad para trabajar el canal alfa
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		model = glm::translate(model, glm::vec3(6.328f, 2.745f, -2.478f));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "colorAlpha"), 1.0f, 1.0f, 1.0f, 1.0f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		VentanaTransparente.Draw(lightingShader);
		glDisable(GL_BLEND);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		glEnable(GL_BLEND);//Avtiva la funcionalidad para trabajar el canal alfa
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		model = glm::translate(model, glm::vec3(6.328f, 1.346f, 1.612f));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "colorAlpha"), 1.0f, 1.0f, 1.0f, 1.0f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		VentanaTransparente.Draw(lightingShader);
		glDisable(GL_BLEND);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		glEnable(GL_BLEND);//Avtiva la funcionalidad para trabajar el canal alfa
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		model = glm::translate(model, glm::vec3(6.328f, 1.346f, 3.473f));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "colorAlpha"), 1.0f, 1.0f, 1.0f, 1.0f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		VentanaTransparente.Draw(lightingShader);

		model = glm::mat4(1);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		glEnable(GL_BLEND);//Avtiva la funcionalidad para trabajar el canal alfa
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		model = glm::translate(model, glm::vec3(-17.786f, 0.070f, 9.986f));
		glUniform4f(glGetUniformLocation(lightingShader.Program, "colorAlpha"), 1.0f, 1.0f, 1.0f, 0.5f);
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BolsaDeAgua.Draw(lightingShader);
		glDisable(GL_BLEND);
		
		glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}




	glDeleteVertexArrays(1, &VAO);
	glDeleteVertexArrays(1, &lightVAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &skyboxVAO);
	glDeleteBuffers(1, &skyboxVBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();




	return 0;
}


void animacion()
{
	//Dia y noche ///////////////////////////////////////////////////////////////////////////
	LaHora += deltaTime;
	if (EstadoDia)
	{
		//if (LaHora > 62.5651092)
		if (LaHora > 1.0f)
		{
			LaHora = 0.0f;
			EstadoDia = false;
			PointlightTrue = 1.0f;
			ambiental1 = 0.6f;
			ambiental2 = 0.8f;
			directionalAmbiental = 0.0f;
			PosteLuzB = 0.0f;
			PosteLuzRG = 1.0f;
		}
	}
	if (!EstadoDia)
	{
		//if (LaHora > 80.0921935)
		if (LaHora > 80.0921935)
		{
			LaHora = 0.0f;
			EstadoDia = true;
			PointlightTrue = 0.0f;
			ambiental1 = 0.9f;
			ambiental2 = 0.9f;
			directionalAmbiental = 1.0f;
			PosteLuzB = 0.9f;
			PosteLuzRG = 0.9f;
		}
	}
	//Goomba///////////////////////////////////////////////////////////////////////////
	if (AnimacionGoomba)
	{
		if (SentidoGoomba == false)
		{
			CaminataGoomba += 0.2f * deltaTime;
			if (CaminataGoomba > 0.647f)
			{
				SentidoGoomba = true;
			}
		}

		if (SentidoGoomba == true)
		{
			CaminataGoomba -= 0.2f * deltaTime;
			if (CaminataGoomba < -0.936f)
			{
				SentidoGoomba = false;
			}
		}

		if (RotSentidoGoomba == false)
		{
			rotCabezaGoomba += 30.0f * deltaTime;

			if (rotCabezaGoomba < 0)
			{
				rotPieDerGoomba = rotCabezaGoomba;
			}
			if (rotCabezaGoomba > 0)
			{
				rotPieIzqGoomba = rotCabezaGoomba;
			}

			if (rotCabezaGoomba > 10.0f)
			{
				RotSentidoGoomba = true;
			}
		}
		if (RotSentidoGoomba == true)
		{
			rotCabezaGoomba -= 30.0f * deltaTime;
			if (rotCabezaGoomba < 0)
			{
				rotPieDerGoomba = rotCabezaGoomba;
			}
			if (rotCabezaGoomba > 0)
			{
				rotPieIzqGoomba = rotCabezaGoomba;
			}
			if (rotCabezaGoomba < -10.0f)
			{
				RotSentidoGoomba = false;
			}
		}
	}
	if (!AnimacionGoomba)
	{
		if (RotSentidoGoomba == false)
		{
			rotCabezaGoomba += 30.0f * deltaTime;
			if (rotCabezaGoomba > 10.0f)
			{
				RotSentidoGoomba = true;
			}
		}
		if (RotSentidoGoomba == true)
		{
			rotCabezaGoomba -= 30.0f * deltaTime;
			if (rotCabezaGoomba < -10.0f)
			{
				RotSentidoGoomba = false;
			}
		}
	}
	if (keys[GLFW_KEY_G])
	{
		AnimacionGoomba = true;
	}
	
	//Vueltas locas Chilly willy//////////////////////////////////////////////////////
	VariableRadioGiros += 0.6 * deltaTime;
	VariableRadioBrincos += 2.4 * deltaTime;
	if (VariableRadioGiros > 2)
	{
		VariableRadioGiros = 0.0;
	}
	if (VariableRadioBrincos > 1)
	{
		VariableRadioBrincos = 0.0;
	}
	TraslacionXChilly = 2 * cos(VariableRadioGiros * 3.14159);
	TraslacionZChilly = 2 * sin(VariableRadioGiros * 3.14159);
	TraslacionXChainChomp = 2 * cos((VariableRadioGiros - 0.3) * 3.14159);
	TraslacionZChainChomp = 2 * sin((VariableRadioGiros - 0.3) * 3.14159);
	TraslacionYChainChomp = sin(VariableRadioBrincos * 3.14159);
	//KARTLADYBUG///////////////////////////////////////////////////////////////////////////7
	if (LadyBugrecorrido1)
	{
		LadyBugmovKitX += 7.0f * deltaTime;
		if (LadyBugmovKitX > 21.326f)
		{
			LadyBugrecorrido2 = true;
			LadyBugrecorrido1 = false;
		}
	}
	if (LadyBugrecorrido2)
	{
		LadyBugTiempoDelta += 0.7 * deltaTime;
		LadyBugmovKitX = 21.326f + 3.776f * (1 - (LadyBugTiempoDelta - 1) * (LadyBugTiempoDelta - 1));
		LadyBugmovKitZ = 2.847f * (LadyBugTiempoDelta * LadyBugTiempoDelta);
		LadyBugrotKit = -90.0f * (LadyBugTiempoDelta);
		if (LadyBugTiempoDelta > 0.999)
		{
			LadyBugmovKitX = 25.102f;
			LadyBugmovKitZ = 2.847f;
			LadyBugTiempoDelta = 0.0f;
			LadyBugrecorrido3 = true;
			LadyBugrecorrido2 = false;
		}
	}
	if (LadyBugrecorrido3)
	{
		LadyBugmovKitZ += 7.0f * deltaTime;
		if (LadyBugmovKitZ > 23.105f)
		{
			LadyBugrecorrido3Subida = true;
			LadyBugrecorrido3 = false;
		}
	}
	if (LadyBugrecorrido3Subida)
	{
		LadyBugmovKitZ += 4.7f * deltaTime;
		if (LadyBugmovKitY < 2.282)
		{
			LadyBugmovKitY += 0.023f;
		}
		if (LadyBugGiroExtremo < 30 && LadyBugmovKitY < 1.1415)
		{
			LadyBugGiroExtremo += 100.0f * deltaTime;
		}
		if (LadyBugGiroExtremo > 1 && LadyBugmovKitY > 2)
		{
			LadyBugGiroExtremo -= 367.624f * deltaTime;
		}
		if (LadyBugmovKitZ > 28.093f)
		{
			LadyBugrecorrido4 = true;
			LadyBugmovKitY = 2.283;
			LadyBugGiroExtremo = 0.0;
			LadyBugrecorrido3Subida = false;
		}
	}
	if (LadyBugrecorrido4)
	{
		LadyBugTiempoDelta += 0.7 * deltaTime;
		LadyBugmovKitX = 25.102f - 1.922f * (LadyBugTiempoDelta * LadyBugTiempoDelta);
		LadyBugmovKitZ = 28.093f + 3.566 * (1 - (LadyBugTiempoDelta - 1) * (LadyBugTiempoDelta - 1));
		LadyBugrotKit = -90.0f - 90 * (LadyBugTiempoDelta);
		if (LadyBugTiempoDelta > 0.999)
		{
			LadyBugmovKitX = 23.18f;
			LadyBugmovKitZ = 31.659f;
			LadyBugTiempoDelta = 0.0f;
			LadyBugrecorrido5 = true;
			LadyBugrecorrido4 = false;
		}
	}
	if (LadyBugrecorrido5)
	{
		LadyBugmovKitX -= 4.2f * deltaTime;
		LadyBugmovKitY = 2.283 - 0.02233919 * LadyBugmovKitX * LadyBugmovKitX + 0.47640569 * LadyBugmovKitX + 0.96004303;
		if (LadyBugGiroExtremo < 380.0 && LadyBugDescender == false && LadyBugmovKitX < 22.68f)
		{
			LadyBugGiroExtremo += 500.0f * deltaTime;

		}
		if (LadyBugapertura)
		{
			LadyBugXscale += 5 * deltaTime;
			LadyBugYscale += 5 * deltaTime;
			LadyBugZscale += 5 * deltaTime;
			if (LadyBugYscale > 0.99)
			{
				LadyBugapertura = false;
			}
		}
		if (LadyBugGiroExtremo > 376.0)
		{
			LadyBugDescender = true;
			LadyBugapertura = true;
		}
		if (LadyBugDescender)
		{
			LadyBugmovKitX -= 2.8f * deltaTime;
			LadyBugGiroExtremo = 350 + (30 * ((LadyBugmovKitX + 1.853f) / 25.033));
		}
		if (LadyBugmovKitX < -1.853f)
		{
			LadyBugmovKitY = 2.283f;
			LadyBugmovKitX = -1.854f;
			LadyBugGiroExtremo = 0.0;
			LadyBugCierre = true;
			LadyBugrecorrido6 = true;
			LadyBugrecorrido5 = false;
		}
	}
	if (LadyBugrecorrido6)
	{
		if (LadyBugCierre)
		{
			LadyBugXscale -= 10 * deltaTime;
			LadyBugYscale -= 10 * deltaTime;
			LadyBugZscale -= 10 * deltaTime;
			if (LadyBugYscale < 0.01)
			{
				LadyBugCierre = false;
			}
		}
		LadyBugTiempoDelta += 0.7 * deltaTime;
		LadyBugmovKitX = -1.854f - 1.922f * (1 - (LadyBugTiempoDelta - 1) * (LadyBugTiempoDelta - 1));
		LadyBugmovKitZ = 31.659f - 3.566 * (LadyBugTiempoDelta * LadyBugTiempoDelta);
		LadyBugrotKit = -180.0f - 90 * (LadyBugTiempoDelta);
		if (LadyBugTiempoDelta > 0.999)
		{
			LadyBugTiempoDelta = 0.0f;
			LadyBugDescender = false;
			LadyBugrecorrido6Descenso = true;
			LadyBugrecorrido6 = false;
		}
	}
	if (LadyBugrecorrido6Descenso)
	{
		LadyBugmovKitZ -= 7 * deltaTime;
		LadyBugTiempoDelta += 0.7 * deltaTime;
		LadyBugmovKitY = 2.283 - 4.905 * LadyBugTiempoDelta * LadyBugTiempoDelta;
		LadyBugGiroExtremo += 4.2 * deltaTime;
		if (LadyBugmovKitY < 0)
		{
			LadyBugmovKitY = 0.0f;
			LadyBugGiroExtremo = 0.0;
			LadyBugTiempoDelta = 0.0f;
			LadyBugrecorrido7 = true;
			LadyBugrecorrido6Descenso = false;
		}
	}
	if (LadyBugrecorrido7)
	{
		LadyBugmovKitZ -= 7.0f * deltaTime;
		if (LadyBugmovKitZ < 2.847f)
		{
			LadyBugmovKitZ = 2.847f;
			LadyBugrecorrido8 = true;
			LadyBugrecorrido7 = false;
		}
	}
	if (LadyBugrecorrido8)
	{
		LadyBugTiempoDelta += 0.7 * deltaTime;
		LadyBugmovKitX = -3.776 + 3.776f * (LadyBugTiempoDelta * LadyBugTiempoDelta);
		LadyBugmovKitZ = 2.847f - 2.847f * (1 - (LadyBugTiempoDelta - 1) * (LadyBugTiempoDelta - 1));
		LadyBugrotKit = -270.0f - 90 * (LadyBugTiempoDelta);
		if (LadyBugTiempoDelta > 0.999)
		{
			LadyBugrotKit = 0;
			LadyBugmovKitX = 0;
			LadyBugmovKitZ = 0;
			LadyBugTiempoDelta = 0.0f;
			LadyBugrecorrido1 = true;
			LadyBugrecorrido8 = false;
		}
	}
	//KARTGOKU///////////////////////////////////////////////////////////////////////////7
	if (Gokurecorrido1)
	{
		GokumovKitX += 7.0f * deltaTime;
		if (GokumovKitX > 21.326f)
		{
			Gokurecorrido2 = true;
			Gokurecorrido1 = false;
		}
	}
	if (Gokurecorrido2)
	{
		GokuTiempoDelta += 0.7 * deltaTime;
		GokumovKitX = 21.326f + 3.776f * (1 - (GokuTiempoDelta - 1) * (GokuTiempoDelta - 1));
		GokumovKitZ = 2.847f * (GokuTiempoDelta * GokuTiempoDelta);
		GokurotKit = -90.0f * (GokuTiempoDelta);
		if (GokuTiempoDelta > 0.999)
		{
			GokumovKitX = 25.102f;
			GokumovKitZ = 2.847f;
			GokuTiempoDelta = 0.0f;
			Gokurecorrido3 = true;
			Gokurecorrido2 = false;
		}
	}
	if (Gokurecorrido3)
	{
		GokumovKitZ += 7.0f * deltaTime;
		if (GokumovKitZ > 23.105f)
		{
			Gokurecorrido3Subida = true;
			Gokurecorrido3 = false;
		}
	}
	if (Gokurecorrido3Subida)
	{
		GokumovKitZ += 4.7f * deltaTime;
		if (GokumovKitY < 2.282)
		{
			GokumovKitY += 0.023f;
		}
		if (GokuGiroExtremo < 30 && GokumovKitY < 1.1415)
		{
			GokuGiroExtremo += 100.0f * deltaTime;
		}
		if (GokuGiroExtremo > 1 && GokumovKitY > 2)
		{
			GokuGiroExtremo -= 367.624f * deltaTime;
		}
		if (GokumovKitZ > 28.093f)
		{
			Gokurecorrido4 = true;
			GokumovKitY = 2.283;
			GokuGiroExtremo = 0.0;
			Gokurecorrido3Subida = false;
		}
	}
	if (Gokurecorrido4)
	{
		GokuTiempoDelta += 0.7 * deltaTime;
		GokumovKitX = 25.102f - 1.922f * (GokuTiempoDelta * GokuTiempoDelta);
		GokumovKitZ = 28.093f + 3.566 * (1 - (GokuTiempoDelta - 1) * (GokuTiempoDelta - 1));
		GokurotKit = -90.0f - 90 * (GokuTiempoDelta);
		if (GokuTiempoDelta > 0.999)
		{
			GokumovKitX = 23.18f;
			GokumovKitZ = 31.659f;
			GokuTiempoDelta = 0.0f;
			Gokurecorrido5 = true;
			Gokurecorrido4 = false;
		}
	}
	if (Gokurecorrido5)
	{
		GokumovKitX -= 4.2f * deltaTime;
		GokumovKitY = 2.283 - 0.02233919 * GokumovKitX * GokumovKitX + 0.47640569 * GokumovKitX + 0.96004303;
		if (GokuGiroExtremo < 380.0 && GokuDescender == false && GokumovKitX < 22.68f)
		{
			GokuGiroExtremo += 500.0f * deltaTime;

		}
		if (Gokuapertura)
		{
			GokuXscale += 5 * deltaTime;
			GokuYscale += 5 * deltaTime;
			GokuZscale += 5 * deltaTime;
			if (GokuYscale > 0.99)
			{
				Gokuapertura = false;
			}
		}
		if (GokuGiroExtremo > 376.0)
		{
			GokuDescender = true;
			Gokuapertura = true;
		}
		if (GokuDescender)
		{
			GokumovKitX -= 2.8f * deltaTime;
			GokuGiroExtremo = 350 + (30 * ((GokumovKitX + 1.853f) / 25.033));
		}
		if (GokumovKitX < -1.853f)
		{
			GokumovKitY = 2.283f;
			GokumovKitX = -1.854f;
			GokuGiroExtremo = 0.0;
			GokuCierre = true;
			Gokurecorrido6 = true;
			Gokurecorrido5 = false;
		}
	}
	if (Gokurecorrido6)
	{
		if (GokuCierre)
		{
			GokuXscale -= 10 * deltaTime;
			GokuYscale -= 10 * deltaTime;
			GokuZscale -= 10 * deltaTime;
			if (GokuYscale < 0.01)
			{
				GokuCierre = false;
			}
		}
		GokuTiempoDelta += 0.7 * deltaTime;
		GokumovKitX = -1.854f - 1.922f * (1 - (GokuTiempoDelta - 1) * (GokuTiempoDelta - 1));
		GokumovKitZ = 31.659f - 3.566 * (GokuTiempoDelta * GokuTiempoDelta);
		GokurotKit = -180.0f - 90 * (GokuTiempoDelta);
		if (GokuTiempoDelta > 0.999)
		{
			GokuTiempoDelta = 0.0f;
			GokuDescender = false;
			Gokurecorrido6Descenso = true;
			Gokurecorrido6 = false;
		}
	}
	if (Gokurecorrido6Descenso)
	{
		GokumovKitZ -= 7 * deltaTime;
		GokuTiempoDelta += 0.7 * deltaTime;
		GokumovKitY = 2.283 - 4.905 * GokuTiempoDelta * GokuTiempoDelta;
		GokuGiroExtremo += 4.2 * deltaTime;
		if (GokumovKitY < 0)
		{
			GokumovKitY = 0.0f;
			GokuGiroExtremo = 0.0;
			GokuTiempoDelta = 0.0f;
			Gokurecorrido7 = true;
			Gokurecorrido6Descenso = false;
		}
	}
	if (Gokurecorrido7)
	{
		GokumovKitZ -= 7.0f * deltaTime;
		if (GokumovKitZ < 2.847f)
		{
			GokumovKitZ = 2.847f;
			Gokurecorrido8 = true;
			Gokurecorrido7 = false;
		}
	}
	if (Gokurecorrido8)
	{
		GokuTiempoDelta += 0.7 * deltaTime;
		GokumovKitX = -3.776 + 3.776f * (GokuTiempoDelta * GokuTiempoDelta);
		GokumovKitZ = 2.847f - 2.847f * (1 - (GokuTiempoDelta - 1) * (GokuTiempoDelta - 1));
		GokurotKit = -270.0f - 90 * (GokuTiempoDelta);
		if (GokuTiempoDelta > 0.999)
		{
			GokurotKit = 0;
			GokumovKitX = 0;
			GokumovKitZ = 0;
			GokuTiempoDelta = 0.0f;
			Gokurecorrido1 = true;
			Gokurecorrido8 = false;
		}
	}
	//KARTBOBESPONJA///////////////////////////////////////////////////////////////////////////7
	if (BobEsponjarecorrido1)
	{
		BobEsponjamovKitX += 7.0f * deltaTime;
		if (BobEsponjamovKitX > 21.326f)
		{
			BobEsponjarecorrido2 = true;
			BobEsponjarecorrido1 = false;
		}
	}
	if (BobEsponjarecorrido2)
	{
		BobEsponjaTiempoDelta += 0.7 * deltaTime;
		BobEsponjamovKitX = 21.326f + 3.776f * (1 - (BobEsponjaTiempoDelta - 1) * (BobEsponjaTiempoDelta - 1));
		BobEsponjamovKitZ = 2.847f * (BobEsponjaTiempoDelta * BobEsponjaTiempoDelta);
		BobEsponjarotKit = -90.0f * (BobEsponjaTiempoDelta);
		if (BobEsponjaTiempoDelta > 0.999)
		{
			BobEsponjamovKitX = 25.102f;
			BobEsponjamovKitZ = 2.847f;
			BobEsponjaTiempoDelta = 0.0f;
			BobEsponjarecorrido3 = true;
			BobEsponjarecorrido2 = false;
		}
	}
	if (BobEsponjarecorrido3)
	{
		BobEsponjamovKitZ += 7.0f * deltaTime;
		if (BobEsponjamovKitZ > 23.105f)
		{
			BobEsponjarecorrido3Subida = true;
			BobEsponjarecorrido3 = false;
		}
	}
	if (BobEsponjarecorrido3Subida)
	{
		BobEsponjamovKitZ += 4.7f * deltaTime;
		if (BobEsponjamovKitY < 2.282)
		{
			BobEsponjamovKitY += 0.023f;
		}
		if (BobEsponjaGiroExtremo < 30 && BobEsponjamovKitY < 1.1415)
		{
			BobEsponjaGiroExtremo += 100.0f * deltaTime;
		}
		if (BobEsponjaGiroExtremo > 1 && BobEsponjamovKitY > 2)
		{
			BobEsponjaGiroExtremo -= 367.624f * deltaTime;
		}
		if (BobEsponjamovKitZ > 28.093f)
		{
			BobEsponjarecorrido4 = true;
			BobEsponjamovKitY = 2.283;
			BobEsponjaGiroExtremo = 0.0;
			BobEsponjarecorrido3Subida = false;
		}
	}
	if (BobEsponjarecorrido4)
	{
		BobEsponjaTiempoDelta += 0.7 * deltaTime;
		BobEsponjamovKitX = 25.102f - 1.922f * (BobEsponjaTiempoDelta * BobEsponjaTiempoDelta);
		BobEsponjamovKitZ = 28.093f + 3.566 * (1 - (BobEsponjaTiempoDelta - 1) * (BobEsponjaTiempoDelta - 1));
		BobEsponjarotKit = -90.0f - 90 * (BobEsponjaTiempoDelta);
		if (BobEsponjaTiempoDelta > 0.999)
		{
			BobEsponjamovKitX = 23.18f;
			BobEsponjamovKitZ = 31.659f;
			BobEsponjaTiempoDelta = 0.0f;
			BobEsponjarecorrido5 = true;
			BobEsponjarecorrido4 = false;
		}
	}
	if (BobEsponjarecorrido5)
	{
		BobEsponjamovKitX -= 4.2f * deltaTime;
		BobEsponjamovKitY = 2.283 - 0.02233919 * BobEsponjamovKitX * BobEsponjamovKitX + 0.47640569 * BobEsponjamovKitX + 0.96004303;
		if (BobEsponjaGiroExtremo < 380.0 && BobEsponjaDescender == false && BobEsponjamovKitX < 22.68f)
		{
			BobEsponjaGiroExtremo += 500.0f * deltaTime;

		}
		if (BobEsponjaapertura)
		{
			BobEsponjaXscale += 5 * deltaTime;
			BobEsponjaYscale += 5 * deltaTime;
			BobEsponjaZscale += 5 * deltaTime;
			if (BobEsponjaYscale > 0.99)
			{
				BobEsponjaapertura = false;
			}
		}
		if (BobEsponjaGiroExtremo > 376.0)
		{
			BobEsponjaDescender = true;
			BobEsponjaapertura = true;
		}
		if (BobEsponjaDescender)
		{
			BobEsponjamovKitX -= 2.8f * deltaTime;
			BobEsponjaGiroExtremo = 350 + (30 * ((BobEsponjamovKitX + 1.853f) / 25.033));
		}
		if (BobEsponjamovKitX < -1.853f)
		{
			BobEsponjamovKitY = 2.283f;
			BobEsponjamovKitX = -1.854f;
			BobEsponjaGiroExtremo = 0.0;
			BobEsponjaCierre = true;
			BobEsponjarecorrido6 = true;
			BobEsponjarecorrido5 = false;
		}
	}
	if (BobEsponjarecorrido6)
	{
		if (BobEsponjaCierre)
		{
			BobEsponjaXscale -= 10 * deltaTime;
			BobEsponjaYscale -= 10 * deltaTime;
			BobEsponjaZscale -= 10 * deltaTime;
			if (BobEsponjaYscale < 0.01)
			{
				BobEsponjaCierre = false;
			}
		}
		BobEsponjaTiempoDelta += 0.7 * deltaTime;
		BobEsponjamovKitX = -1.854f - 1.922f * (1 - (BobEsponjaTiempoDelta - 1) * (BobEsponjaTiempoDelta - 1));
		BobEsponjamovKitZ = 31.659f - 3.566 * (BobEsponjaTiempoDelta * BobEsponjaTiempoDelta);
		BobEsponjarotKit = -180.0f - 90 * (BobEsponjaTiempoDelta);
		if (BobEsponjaTiempoDelta > 0.999)
		{
			BobEsponjaTiempoDelta = 0.0f;
			BobEsponjaDescender = false;
			BobEsponjarecorrido6Descenso = true;
			BobEsponjarecorrido6 = false;
		}
	}
	if (BobEsponjarecorrido6Descenso)
	{
		BobEsponjamovKitZ -= 7 * deltaTime;
		BobEsponjaTiempoDelta += 0.7 * deltaTime;
		BobEsponjamovKitY = 2.283 - 4.905 * BobEsponjaTiempoDelta * BobEsponjaTiempoDelta;
		BobEsponjaGiroExtremo += 4.2 * deltaTime;
		if (BobEsponjamovKitY < 0)
		{
			BobEsponjamovKitY = 0.0f;
			BobEsponjaGiroExtremo = 0.0;
			BobEsponjaTiempoDelta = 0.0f;
			BobEsponjarecorrido7 = true;
			BobEsponjarecorrido6Descenso = false;
		}
	}
	if (BobEsponjarecorrido7)
	{
		BobEsponjamovKitZ -= 7.0f * deltaTime;
		if (BobEsponjamovKitZ < 2.847f)
		{
			BobEsponjamovKitZ = 2.847f;
			BobEsponjarecorrido8 = true;
			BobEsponjarecorrido7 = false;
		}
	}
	if (BobEsponjarecorrido8)
	{
		BobEsponjaTiempoDelta += 0.7 * deltaTime;
		BobEsponjamovKitX = -3.776 + 3.776f * (BobEsponjaTiempoDelta * BobEsponjaTiempoDelta);
		BobEsponjamovKitZ = 2.847f - 2.847f * (1 - (BobEsponjaTiempoDelta - 1) * (BobEsponjaTiempoDelta - 1));
		BobEsponjarotKit = -270.0f - 90 * (BobEsponjaTiempoDelta);
		if (BobEsponjaTiempoDelta > 0.999)
		{
			BobEsponjarotKit = 0;
			BobEsponjamovKitX = 0;
			BobEsponjamovKitZ = 0;
			BobEsponjaTiempoDelta = 0.0f;
			BobEsponjarecorrido1 = true;
			BobEsponjarecorrido8 = false;
		}
	}
	//KARTMULAN///////////////////////////////////////////////////////////////////////////7
	if (Mulanrecorrido1)
	{
		MulanmovKitX += 7.0f * deltaTime;
		if (MulanmovKitX > 21.326f)
		{
			Mulanrecorrido2 = true;
			Mulanrecorrido1 = false;
		}
	}
	if (Mulanrecorrido2)
	{
		MulanTiempoDelta += 0.7 * deltaTime;
		MulanmovKitX = 21.326f + 3.776f * (1 - (MulanTiempoDelta - 1) * (MulanTiempoDelta - 1));
		MulanmovKitZ = 2.847f * (MulanTiempoDelta * MulanTiempoDelta);
		MulanrotKit = -90.0f * (MulanTiempoDelta);
		if (MulanTiempoDelta > 0.999)
		{
			MulanmovKitX = 25.102f;
			MulanmovKitZ = 2.847f;
			MulanTiempoDelta = 0.0f;
			Mulanrecorrido3 = true;
			Mulanrecorrido2 = false;
		}
	}
	if (Mulanrecorrido3)
	{
		MulanmovKitZ += 7.0f * deltaTime;
		if (MulanmovKitZ > 23.105f)
		{
			Mulanrecorrido3Subida = true;
			Mulanrecorrido3 = false;
		}
	}
	if (Mulanrecorrido3Subida)
	{
		MulanmovKitZ += 4.7f * deltaTime;
		if (MulanmovKitY < 2.282)
		{
			MulanmovKitY += 0.023f;
		}
		if (MulanGiroExtremo < 30 && MulanmovKitY < 1.1415)
		{
			MulanGiroExtremo += 100.0f * deltaTime;
		}
		if (MulanGiroExtremo > 1 && MulanmovKitY > 2)
		{
			MulanGiroExtremo -= 367.624f * deltaTime;
		}
		if (MulanmovKitZ > 28.093f)
		{
			Mulanrecorrido4 = true;
			MulanmovKitY = 2.283;
			MulanGiroExtremo = 0.0;
			Mulanrecorrido3Subida = false;
		}
	}
	if (Mulanrecorrido4)
	{
		MulanTiempoDelta += 0.7 * deltaTime;
		MulanmovKitX = 25.102f - 1.922f * (MulanTiempoDelta * MulanTiempoDelta);
		MulanmovKitZ = 28.093f + 3.566 * (1 - (MulanTiempoDelta - 1) * (MulanTiempoDelta - 1));
		MulanrotKit = -90.0f - 90 * (MulanTiempoDelta);
		if (MulanTiempoDelta > 0.999)
		{
			MulanmovKitX = 23.18f;
			MulanmovKitZ = 31.659f;
			MulanTiempoDelta = 0.0f;
			Mulanrecorrido5 = true;
			Mulanrecorrido4 = false;
		}
	}
	if (Mulanrecorrido5)
	{
		MulanmovKitX -= 4.2f * deltaTime;
		MulanmovKitY = 2.283 - 0.02233919 * MulanmovKitX * MulanmovKitX + 0.47640569 * MulanmovKitX + 0.96004303;
		if (MulanGiroExtremo < 380.0 && MulanDescender == false && MulanmovKitX < 22.68f)
		{
			MulanGiroExtremo += 500.0f * deltaTime;

		}
		if (Mulanapertura)
		{
			MulanXscale += 5 * deltaTime;
			MulanYscale += 5 * deltaTime;
			MulanZscale += 5 * deltaTime;
			if (MulanYscale > 0.99)
			{
				Mulanapertura = false;
			}
		}
		if (MulanGiroExtremo > 376.0)
		{
			MulanDescender = true;
			Mulanapertura = true;
		}
		if (MulanDescender)
		{
			MulanmovKitX -= 2.8f * deltaTime;
			MulanGiroExtremo = 350 + (30 * ((MulanmovKitX + 1.853f) / 25.033));
		}
		if (MulanmovKitX < -1.853f)
		{
			MulanmovKitY = 2.283f;
			MulanmovKitX = -1.854f;
			MulanGiroExtremo = 0.0;
			MulanCierre = true;
			Mulanrecorrido6 = true;
			Mulanrecorrido5 = false;
		}
	}
	if (Mulanrecorrido6)
	{
		if (MulanCierre)
		{
			MulanXscale -= 10 * deltaTime;
			MulanYscale -= 10 * deltaTime;
			MulanZscale -= 10 * deltaTime;
			if (MulanYscale < 0.01)
			{
				MulanCierre = false;
			}
		}
		MulanTiempoDelta += 0.7 * deltaTime;
		MulanmovKitX = -1.854f - 1.922f * (1 - (MulanTiempoDelta - 1) * (MulanTiempoDelta - 1));
		MulanmovKitZ = 31.659f - 3.566 * (MulanTiempoDelta * MulanTiempoDelta);
		MulanrotKit = -180.0f - 90 * (MulanTiempoDelta);
		if (MulanTiempoDelta > 0.999)
		{
			MulanTiempoDelta = 0.0f;
			MulanDescender = false;
			Mulanrecorrido6Descenso = true;
			Mulanrecorrido6 = false;
		}
	}
	if (Mulanrecorrido6Descenso)
	{
		MulanmovKitZ -= 7 * deltaTime;
		MulanTiempoDelta += 0.7 * deltaTime;
		MulanmovKitY = 2.283 - 4.905 * MulanTiempoDelta * MulanTiempoDelta;
		MulanGiroExtremo += 4.2 * deltaTime;
		if (MulanmovKitY < 0)
		{
			MulanmovKitY = 0.0f;
			MulanGiroExtremo = 0.0;
			MulanTiempoDelta = 0.0f;
			Mulanrecorrido7 = true;
			Mulanrecorrido6Descenso = false;
		}
	}
	if (Mulanrecorrido7)
	{
		MulanmovKitZ -= 7.0f * deltaTime;
		if (MulanmovKitZ < 2.847f)
		{
			MulanmovKitZ = 2.847f;
			Mulanrecorrido8 = true;
			Mulanrecorrido7 = false;
		}
	}
	if (Mulanrecorrido8)
	{
		MulanTiempoDelta += 0.7 * deltaTime;
		MulanmovKitX = -3.776 + 3.776f * (MulanTiempoDelta * MulanTiempoDelta);
		MulanmovKitZ = 2.847f - 2.847f * (1 - (MulanTiempoDelta - 1) * (MulanTiempoDelta - 1));
		MulanrotKit = -270.0f - 90 * (MulanTiempoDelta);
		if (MulanTiempoDelta > 0.999)
		{
			MulanrotKit = 0;
			MulanmovKitX = 0;
			MulanmovKitZ = 0;
			MulanTiempoDelta = 0.0f;
			Mulanrecorrido1 = true;
			Mulanrecorrido8 = false;
		}
	}
	//Todos los coches
	Rotacion1 += 1600.0f * deltaTime;
	if (Rotacion1 > 360.0f)
	{
		Rotacion1 = 16.0f;
	}
	if (SentidoViento == true)
	{
		Viento += 50.0f * deltaTime;
		if (Viento > 3)
		{
			SentidoViento = false;
		}
	}
	if (SentidoViento == false)
	{
		Viento -= 50.f * deltaTime;
		if (Viento < -3)
		{
			SentidoViento = true;
		}
	}
	//Toad///////////////////////////////////////////////////////////////////////////7
	if (sentidoIDLE)
	{
		IDLE += 0.06 * deltaTime;
		if (IDLE > 0.025)
		{
			sentidoIDLE = false;
		}
	}
	if (!sentidoIDLE)
	{
		IDLE -= 0.06 * deltaTime;
		if (IDLE < 0)
		{
			sentidoIDLE = true;
		}
	}
	if (sentidoBrazo)
	{
		RotBrazo += 40 * deltaTime;
		if (RotBrazo > 20)
		{
			sentidoBrazo = false;
		}
	}
	if (!sentidoBrazo)
	{
		RotBrazo -= 40 * deltaTime;
		if (RotBrazo < 0)
		{
			sentidoBrazo = true;
		}
	}
	if (Sentido1)
	{
		auxilar1 += 200 * deltaTime;
		if (auxilar1 > 99)
		{
			Sentido1 = false;
		}
	}
	if (!Sentido1)
	{
		auxilar1 -= 200 * deltaTime;
		if (auxilar1 < -99)
		{
			Sentido1 = true;
		}
	}
	if (auxilar1 > 0)
	{
		Giro = 20 * log10(auxilar1 + 1);
		Brinco = 0.025 * (Giro / 40);
	}
	if (auxilar1 < 0)
	{
		Giro = -20 * log10(-auxilar1 + 1);
		Brinco = 0.025 * (-Giro / 40);

	}
	Rotacion2 += 100.0f * deltaTime;
	if (Rotacion2 > 359.0f)
	{
		Rotacion2 = 0.0f;
	}
	//Flor///////////////////////////////////////////////////////////////////////////
	if (FlorSentido)
	{
		FlorGiro += 400 * deltaTime;
		if (FlorGiro > 99)
		{
			FlorSentido = !FlorSentido;
		}
	}
	if (!FlorSentido)
	{
		FlorGiro -= 400 * deltaTime;
		if (FlorGiro < -99)
		{
			FlorSentido = !FlorSentido;
		}
	}
	if (FlorGiro > 0)
	{
		FlorBrinco = 0.025 * (100 - FlorGiro) / 100;
	}
	if (FlorGiro < 0)
	{
		FlorBrinco = 0.025 * (100 + FlorGiro) / 100;
	}
	//Monedas//////////////////////////////////////////////////////
	VariableMonedasGiros += 0.3 * deltaTime;
	if (VariableMonedasGiros > 2)
	{
		VariableMonedasGiros = 0.0;
	}
	TraslacionXMonedas = 2 * cos(VariableMonedasGiros * 3.14159);
	TraslacionZMonedas = 2 * sin(VariableMonedasGiros * 3.14159);
	TraslacionXMonedas1 = 2 * cos((VariableMonedasGiros + 0.25) * 3.14159);
	TraslacionZMonedas1 = 2 * sin((VariableMonedasGiros + 0.25) * 3.14159);
	TraslacionXMonedas2 = 2 * cos((VariableMonedasGiros + 0.5) * 3.14159);
	TraslacionZMonedas2 = 2 * sin((VariableMonedasGiros + 0.5) * 3.14159);
	TraslacionXMonedas3 = 2 * cos((VariableMonedasGiros + 0.75) * 3.14159);
	TraslacionZMonedas3 = 2 * sin((VariableMonedasGiros + 0.75) * 3.14159);
	TraslacionXMonedas4 = 2 * cos((VariableMonedasGiros + 1) * 3.14159);
	TraslacionZMonedas4 = 2 * sin((VariableMonedasGiros + 1) * 3.14159);
	TraslacionXMonedas5 = 2 * cos((VariableMonedasGiros + 1.25) * 3.14159);
	TraslacionZMonedas5 = 2 * sin((VariableMonedasGiros + 1.25) * 3.14159);
	TraslacionXMonedas6 = 2 * cos((VariableMonedasGiros + 1.5) * 3.14159);
	TraslacionZMonedas6 = 2 * sin((VariableMonedasGiros + 1.5) * 3.14159);
	TraslacionXMonedas7 = 2 * cos((VariableMonedasGiros + 1.75) * 3.14159);
	TraslacionZMonedas7 = 2 * sin((VariableMonedasGiros + 1.75) * 3.14159);
	//Peach//////////////////////////////////////////////////////
	VariablePeachGiros += 0.4 * deltaTime;
	if (VariablePeachGiros > 2)
	{
		VariablePeachGiros = 0.0;
	}
	TraslacionXPeach = 1.4 * sin(VariablePeachGiros * 3.14159);
	TraslacionZPeach = 0.3 * cos(VariablePeachGiros * 3.14159);
	//Bobomba//////////////////////////////////////////////////////////////////////////////
	if (keys[GLFW_KEY_B])
	{
		AnimacionBomba = true;
	}
	if (AnimacionBomba)
	{
		RoatLlave += 300 * deltaTime;
		if (MarchaBomba && TiempoanimaiconBomba < 12)
		{
			RoatBomba += 40 * deltaTime;
			pieDerBomba += 0.0008;
			if (pieIzqBomba > 0)
			{
				pieIzqBomba -= 0.08 * deltaTime;
			}
			if (RoatBomba > 15)
			{
				MarchaBomba = false;
				TiempoanimaiconBomba += 100 * deltaTime;
			}
		}
		if (!MarchaBomba && TiempoanimaiconBomba < 12)
		{
			RoatBomba -= 40 * deltaTime;
			pieIzqBomba += 0.08 * deltaTime;
			if (pieDerBomba > 0)
			{
				pieDerBomba -= 0.08 * deltaTime;
			}
			if (RoatBomba < -15)
			{
				MarchaBomba = true;
				TiempoanimaiconBomba += 100 * deltaTime;
			}
		}
		if (TiempoanimaiconBomba > 11)
		{
			RoatBomba += 40 * deltaTime;
			pieIzqBomba -= 0.09 * deltaTime;
			if (RoatBomba > -0.01)
			{
				AnimacionBomba = false;
				TiempoanimaiconBomba = 0;
				pieIzqBomba = 0;
				pieDerBomba = 0;
				RoatLlave = 0;
			}
		}

	}

	//Paratroopa///////////////////////////////////////////////////////////////////////////
	if (Sentido2)
	{
		VueloParatroopa = 1.5 * log10(auxilar2 + 1);
		auxilar2 += 9 * deltaTime;
		Reducir += deltaTime/3;
		if (auxilar2 > 79.91)
		{
			RoatParatroopa += 81 * deltaTime;
		}
		if (Reducir > 1)
		{
			Reducir = 1.0f;
		}
		if (auxilar2 > 99.91)
		{
			Sentido2 = false;
		}
	}
	if (!Sentido2)
	{
		if (VueloParatroopa > 0.3)
		{
			VueloParatroopa -= 1 * deltaTime;
			if (VueloParatroopa < 1)
			{
				Reducir -= 2*deltaTime;
				if (Reducir < 0)
				{
					Reducir = 0.0f;
				}
			}
		}

		if (VueloParatroopa < 0.3 && VueloParatroopa>0)
		{
			VueloParatroopa -= 0.05 * deltaTime;
			Reducir += deltaTime;
			if (Reducir > 1)
			{
				Reducir = 1.0f;
			}
		}

		if (VueloParatroopa < 0)
		{
			RoatParatroopa = 0.0;
			auxilar2 = 0.0;
			Sentido2 = true;
			Reducir = 0.0f;
		}
	}
	//Puerta///////////////////////////////////////////////////////////////////////////
	if (keys[GLFW_KEY_P])
	{
		AnimPuerta = true;
	}
	if (AnimPuerta)
	{
		if (Puerta)
		{
			if (RotPuerta < 90)
			{
				RotPuerta += 20 * deltaTime;
			}
			else
			{
				Puerta = false;
				AnimPuerta = false;
			}
		}
		if (!Puerta)
		{
			if (RotPuerta > 0)
			{
				RotPuerta -= 20 * deltaTime;
			}
			else
			{
				Puerta = true;
				AnimPuerta = false;
			}
		}
	}
	//Cubo-Champiñon///////////////////////////////////////////////////////////////////////////
	if (keys[GLFW_KEY_C])
	{
		AnimCubo = true;
	}
	if (AnimCubo)
	{
		if (EstadoCubo)
		{
			if (Golpe < 0.3)
			{
				Golpe += 4 * deltaTime;
			}
			else
			{
				EscalaVacia = 1.00;
				EscalaCubo = 0.5;
				EstadoCubo = !EstadoCubo;
			}

		}
		if (!EstadoCubo)
		{
			auxilar3 += 0.6 * deltaTime;
			RoatChampi += 200 * deltaTime;
			TiroVertical = 5.5 * auxilar3 - 0.5 * 9.81 * auxilar3 * auxilar3;
			if (Golpe > 0.05)
			{
				Golpe -= 5 * deltaTime;
			}
			if (auxilar3 > 1.12)
			{
				EscalaCubo = 1.00f;
				EscalaVacia = 0.5f;
				auxilar3 = 0.0f;
				RoatChampi = 0.0f;
				TiroVertical = 0.0f;
				EstadoCubo = !EstadoCubo;
				AnimCubo = false;
			}
		}


	}
	//Flyguy
	if (SentidoFlyGuy)
	{
		TrasladoFlyguy += 0.01;
		if (RoatFlyGuy < 20.0)
		{
			RoatFlyGuy += 0.5;
		}
		if (TrasladoFlyguy > 2)
		{
			SentidoFlyGuy = false;
		}
	}
	if (!SentidoFlyGuy)
	{
		TrasladoFlyguy -= 0.01;
		if (RoatFlyGuy > -20.0)
		{
			RoatFlyGuy -= 0.5;
		}
		if (TrasladoFlyguy < -2)
		{
			SentidoFlyGuy = true;
		}
	}
	//Koopa
	if (sentidoCaparazon)
	{
		RotCaparazon += 80.0f * deltaTime;
		if (RotCaparazon > 19.6)
		{
			sentidoCaparazon=false;
		}
	}
	if (!sentidoCaparazon)
	{
		RotCaparazon -= 80.0f * deltaTime;
		if (RotCaparazon < 0.4)
		{
			sentidoCaparazon = true;
		}
	}
	//PlantaPiraña///////////////////////////////////////////////////////////////////////////
	if (AnimPlantaPriaña)
	{
		tiempoMordida += 8.0f * deltaTime;
		if (tiempoMordida > 1)
		{
			tiempoMordida = 0.0f;
			if (AnguloMorida > 0.0)
			{
				AnguloMorida = 0.0f;
			}
			else
			{
				AnguloMorida = 45.0f;
			}
		}
		if (PiranaplantSentido)
		{
			piranaPlant += deltaTime;
			if (piranaPlant > 1.013)
			{
				PiranaplantSentido = false;
			}
		}
		if (!PiranaplantSentido)
		{
			piranaPlant -= deltaTime;
			if (piranaPlant < 0.001)
			{
				PiranaplantSentido = true;
				AnimPlantaPriaña = false;
				AnguloMorida = 0.0f;
			}
		}
	}
	if (!AnimPlantaPriaña)
	{
		piranaPlant = IDLE;
	}
	if (keys[GLFW_KEY_O] && !AnimPlantaPriaña)
	{
		AnimPlantaPriaña = true;
	}
	//CheepCheep///////////////////////////////////////////////////////////////////////////
	CheepFloat += 0.5f * deltaTime;
	if (CheepFloat >2) {
		CheepFloat = 0;
	}
		AlturaNadado=0.052 * sin(CheepFloat * 3.1416);
		AletasCheep=25 * sin(CheepFloat * 3.1416);
	//Mario Tanooki///////////////////////////////////////////////////////////////////////////

	Tanooki += deltaTime;
	if (Tanooki > 2)
	{
		Tanooki = 0.0f;
	}
	VueloAltura = 1 * sin(Tanooki * 3.1416);
	//Luigi
	VariableJuego += deltaTime*2;
	if (VariableJuego > 6.2831)
	{
		VariableJuego = 0;
	}
	MovimientoJuego= 20 * sin(VariableJuego);
	VariableCabezaLuigi += deltaTime * 1.1;
	if (VariableCabezaLuigi > 6.2831)
	{
		VariableCabezaLuigi = 0;
	}
	MovimientoCabezaLuigi = 10 * sin(VariableCabezaLuigi);
	//PuroHuesos///////////////////////////////////////////////////////////////////////////
	if (!Hamburguesa)
	{
		espera += 2 * deltaTime;
		if (espera > 6)
		{
			espera = 0.0;
			Hamburguesa = true;
		}
	}
	if (Hamburguesa)
	{
		if (SentidoHamburguesa)
		{
			roatAnteBrazo += 200 * deltaTime;
			if (roatAnteBrazo > 30)
			{
				SentidoHamburguesa = false;
			}
		}
		if (!SentidoHamburguesa)
		{
			espera += 10 * deltaTime;
			if (espera > 10)
			{
				if (roatAnteBrazo > 0.02)
				{
					roatAnteBrazo -= 200 * deltaTime;
				}
				else
				{
					espera = 0.0;
					roatAnteBrazo = 0.0;
					TiempovueloHamburguesa = 0.0;
					SentidoHamburguesa = true;
					Hamburguesa = false;
				}
			}
		}
	}
	if (roatAnteBrazo > 0 && TiempovueloHamburguesa<0.821399271)
	{
		TiempovueloHamburguesa += 0.74 * deltaTime;
	}
	HamburVuelo = 4 * TiempovueloHamburguesa - 0.5 * 9.81 * TiempovueloHamburguesa * TiempovueloHamburguesa;
	if (HamburVuelo < 0)
	{
		HamburVuelo = 0.0;
	}
	//Bowser///////////////////////////////////////////////////////////////////////////////////////////
	AxuiliarBowser3 += 0.5f * deltaTime;
	if (AxuiliarBowser3 > 1.99)
	{
		AxuiliarBowser3 = 0;
	}
	IDLEBowserCabeza = 10 * sin(AxuiliarBowser3 * 3.1416);
	if (!AnimacionBowser)
	{
		AxuiliarBowser1 += deltaTime;
		if (AxuiliarBowser1 > 1.99)
		{
			AxuiliarBowser1 = 0;
		}
		AxuiliarBowser2 += 0.5f * deltaTime;
		if (AxuiliarBowser2 > 1.999)
		{
			AxuiliarBowser2 = 0;
		}
		IDLEBowserMandibula = 10 * sin(AxuiliarBowser2 * 3.1416);
		IDLEBowserCuerpo = 3 * sin(AxuiliarBowser1 * 3.1416);
		IDLEBowserBrazos = IDLEBowserCuerpo;
		IDLEBowserCodos = IDLEBowserCuerpo;
		IDLEBowserManos = IDLEBowserCuerpo;
		
	}
	if (AnimacionBowser)
	{
		if (Rugidetapa1)
		{
			AxuiliarBowser1 += 2 * deltaTime;
			if (AxuiliarBowser1 > 1.49)
			{
				AxuiliarBowser1 = 1.4;
				TiempoRugido += 10 * deltaTime;
				if (TiempoRugido > 4)
				{
					Rugidetapa1 = false;
				}
			}
		}
		if (!Rugidetapa1)
		{
			AxuiliarBowser1 += 0.75 * deltaTime;
			if (AxuiliarBowser1 > 1.99)
			{
				AxuiliarBowser1 = 0.0;
				AxuiliarBowser2 = 0;
				Rugidetapa1 = true;
				TiempoRugido = 0.0;
				AnimacionBowser = false;
			}
		}
		if (AxuiliarBowser1 > 1)
		{
			IDLEBowserCuerpo = 25 * sin(AxuiliarBowser1 * 3.1416);
			IDLEBowserMandibula = 10 * sin(AxuiliarBowser1 * 3.1416);
			IDLEBowserBrazos = 7 * sin(AxuiliarBowser1 * 3.1416);;
			IDLEBowserCodos = -14 * sin(AxuiliarBowser1 * 3.1416);
			IDLEBowserManos = 18 * sin(AxuiliarBowser1 * 3.1416);
		}
		if (AxuiliarBowser1 < 1)
		{
			IDLEBowserCuerpo = 25 * sin(AxuiliarBowser1 * 3.1416);
			IDLEBowserMandibula = 15 * sin(AxuiliarBowser1 * 3.1416);
			IDLEBowserBrazos = 14 * sin(AxuiliarBowser1 * 3.1416);;
			IDLEBowserCodos = -20 * sin(AxuiliarBowser1 * 3.1416);
			IDLEBowserManos = 18 * sin(AxuiliarBowser1 * 3.1416);
		}
	}
	if (keys[GLFW_KEY_R] && !AnimacionBowser)
	{
		AnimacionBowser = true;
		AxuiliarBowser1 = 0.0;
	}
}


// Is called whenever a key is pressed/released via GLFW
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	//if (keys[GLFW_KEY_L]) {
	//	if (play == false && (FrameIndex > 1)) {

	//		resetElements();
	//		//First Interpolation				
	//		interpolation();

	//		play = true;
	//		playIndex = 0;
	//		i_curr_steps = 0;
	//	}
	//	else{
	//		play = false;
	//	}

	//}
	if (keys[GLFW_KEY_2]) {
		Reflectores = 1.0f;
	}
	if (keys[GLFW_KEY_3]) {
		Reflectores = 0.0f;
	}
	if (keys[GLFW_KEY_1]) {
		if (reproduciranimacion < 1) {
			if (play == false && (FrameIndex > 1)) {
				espadaLuz = 1.0f;
				resetElements();
				//First Interpolation				
				interpolation();
				play = true;
				playIndex = 0;
				i_curr_steps = 0;
				reproduciranimacion++;
				printf("\n presiona 0 para habilitar reproducir de nuevo la animación'\n");
				habilitaranimacion = 0;
			}
			else play = false;
		}
	}
	if (keys[GLFW_KEY_0]) {
		if (habilitaranimacion < 1) reproduciranimacion = 0;
	}

	if (keys[GLFW_KEY_K])
	{
		if (FrameIndex < MAX_FRAMES)
		{
			saveFrame();
		}

		rot = -25.0f;//Variable que maneja el giro de la camara

	}


	if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			keys[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			keys[key] = false;
		}
	}

	if (keys[GLFW_KEY_SPACE])
	{
		active = !active;
		if (active)
			LightP1 = glm::vec3(1.0f, 0.0f, 0.0f);
		else
			LightP1 = glm::vec3(1.0f, 0.0f, 0.0f);
	}
}

void MouseCallback(GLFWwindow* window, double xPos, double yPos)
{

	if (firstMouse)
	{
		lastX = xPos;
		lastY = yPos;
		firstMouse = false;
	}

	GLfloat xOffset = xPos - lastX;
	GLfloat yOffset = lastY - yPos;  // Reversed since y-coordinates go from bottom to left

	lastX = xPos;
	lastY = yPos;

	camera.ProcessMouseMovement(xOffset, yOffset);
}

// Moves/alters the camera positions based on user input
void DoMovement()
{
	// Camera controls
	if (keys[GLFW_KEY_W])
	{
		camera.ProcessKeyboard(FORWARD, deltaTime);
	}

	if (keys[GLFW_KEY_S])
	{
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	}

	if (keys[GLFW_KEY_A])
	{
		camera.ProcessKeyboard(LEFT, deltaTime);
	}

	if (keys[GLFW_KEY_D])
	{
		camera.ProcessKeyboard(RIGHT, deltaTime);
	}
	if (keys[GLFW_KEY_I]) camera.setIsometric(true);
	if (keys[GLFW_KEY_U]) camera.setIsometric(false);
	if (keys[GLFW_KEY_DOWN]) {
		camera.setZoom(camera.getIsoZoom() + 0.5f);
		if (camera.getIsoZoom() >= 35.0f) camera.setZoom(35.0f);
	}
	if (keys[GLFW_KEY_UP]) {
		camera.setZoom(camera.getIsoZoom() - 0.5f);
		if (camera.getIsoZoom() <= 2.0f) camera.setZoom(2.0f);
	}
}