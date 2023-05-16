/*
Semestre 2023-2
Práctica 5: Optimización y Carga de Modelos
*/
//para cargar imagen
#define STB_IMAGE_IMPLEMENTATION

#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <math.h>

#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
//para probar el importer
//#include<assimp/Importer.hpp>

#include "Window.h"
#include "Mesh.h"
#include "Shader_light.h"
#include "Camera.h"
#include "Texture.h"
#include "Sphere.h"
#include"Model.h"
#include "Skybox.h"

const float toRadians = 3.14159265f / 180.0f;

Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;

Camera camera;

Texture brickTexture;
Texture dirtTexture;
Texture plainTexture;
Texture pisoTexture;


Model escenario;
Model castillo;
Model arbustoPeach;
Model flower;
Model arbol;
Model arbustoCH;
Model arbustoG;
Model antorcha;
Model tubo;
Model parrilla;
// Puro hueso
Model grim_antebrazo;
Model grim_cabeza;
Model grim_cuerpo;
Model grim_mano;
Model grim_oz;
// Piranha plant
Model pp_cabeza_inf;
Model pp_cabeza_sup;
Model pp_hoja;
Model pp_tallo;
// Chain chomp
Model cc_cabeza_inf;
Model cc_cabeza_sup;
Model cc_cadena_libre;
Model cc_cadena_principal;
// Goomba
Model Goo_Cabeza;
Model Goo_PieDer;
Model Goo_PieIzq;

Skybox skybox;

//Sphere cabeza = Sphere(0.5, 20, 20);
GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;
static double limitFPS = 1.0 / 60.0;


// Vertex Shader
static const char* vShader = "shaders/shader_light.vert";

// Fragment Shader
static const char* fShader = "shaders/shader_light.frag";





void CreateObjects()
{
	unsigned int indices[] = {
		0, 3, 1,
		1, 3, 2,
		2, 3, 0,
		0, 1, 2
	};

	GLfloat vertices[] = {
		//	x      y      z			u	  v			nx	  ny    nz
			-1.0f, -1.0f, -0.6f,	0.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, -1.0f, 1.0f,		0.5f, 0.0f,		0.0f, 0.0f, 0.0f,
			1.0f, -1.0f, -0.6f,		1.0f, 0.0f,		0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,		0.5f, 1.0f,		0.0f, 0.0f, 0.0f
	};

	unsigned int floorIndices[] = {
		0, 2, 1,
		1, 2, 3
	};

	GLfloat floorVertices[] = {
		-10.0f, 0.0f, -10.0f,	0.0f, 0.0f,		0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, -10.0f,	10.0f, 0.0f,	0.0f, -1.0f, 0.0f,
		-10.0f, 0.0f, 10.0f,	0.0f, 10.0f,	0.0f, -1.0f, 0.0f,
		10.0f, 0.0f, 10.0f,		10.0f, 10.0f,	0.0f, -1.0f, 0.0f
	};

	
	Mesh *obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj1);

	Mesh *obj2 = new Mesh();
	obj2->CreateMesh(vertices, indices, 32, 12);
	meshList.push_back(obj2);

	Mesh *obj3 = new Mesh();
	obj3->CreateMesh(floorVertices, floorIndices, 32, 6);
	meshList.push_back(obj3);


}


void CreateShaders()
{
	Shader *shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);
}



int main()
{
	mainWindow = Window(1366, 768); // 1280, 1024 or 1024, 768
	mainWindow.Initialise();

	CreateObjects();
	CreateShaders();

	// Vista isometrica
	//camera = Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), -60.0f, 0.0f, 5.0f, 0.5f);
	// Vista en perspectiva
	camera = Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -60.0f, 0.0f, 5.0f, 0.5f);

	brickTexture = Texture("Textures/brick.png");
	brickTexture.LoadTextureA();
	dirtTexture = Texture("Textures/dirt.png");
	dirtTexture.LoadTextureA();
	plainTexture = Texture("Textures/plain.png");
	plainTexture.LoadTextureA();
	pisoTexture = Texture("Textures/piso.tga");
	pisoTexture.LoadTextureA();

	escenario = Model();
	escenario.LoadModel("Models/Escenario.obj");
	castillo = Model();
	castillo.LoadModel("Models/CastilloBeta.obj");
	arbustoPeach = Model();
	arbustoPeach.LoadModel("Models/ArbustoPeach.obj");
	flower = Model();
	flower.LoadModel("Models/fireflower.obj");
	arbol = Model();
	arbol.LoadModel("Models/Arbol.obj");
	arbustoCH = Model();
	arbustoCH.LoadModel("Models/ArbustoChico.obj");
	arbustoG = Model();
	arbustoG.LoadModel("Models/ArbustoGrande.obj");
	antorcha = Model();
	antorcha.LoadModel("Models/torch.obj");
	tubo = Model();
	tubo.LoadModel("Models/tubo.obj");
	parrilla = Model();
	parrilla.LoadModel("Models/parrilla.obj");
	
	grim_antebrazo = Model();
	grim_antebrazo.LoadModel("Models/grim_antebrazo.obj");
	grim_cabeza = Model();
	grim_cabeza.LoadModel("Models/grim_cabeza.obj");
	grim_cuerpo = Model();
	grim_cuerpo.LoadModel("Models/grim_cuerpo.obj");
	grim_mano = Model();
	grim_mano.LoadModel("Models/grim_mano.obj");
	grim_oz = Model();
	grim_oz.LoadModel("Models/grim_oz.obj");
	
	pp_cabeza_inf = Model();
	pp_cabeza_inf.LoadModel("Models/piranha plant_cabeza_inf.obj");
	pp_cabeza_sup = Model();
	pp_cabeza_sup.LoadModel("Models/piranha plant_cabeza_sup.obj");
	pp_hoja = Model();
	pp_hoja.LoadModel("Models/piranha plant_hoja.obj");
	pp_tallo = Model();
	pp_tallo.LoadModel("Models/piranha plant_tallo.obj");
	
	cc_cabeza_inf = Model();
	cc_cabeza_inf.LoadModel("Models/chain chomp_cabeza_inf.obj");
	cc_cabeza_sup = Model();
	cc_cabeza_sup.LoadModel("Models/chain chomp_cabeza_sup.obj");
	cc_cadena_libre = Model();
	cc_cadena_libre.LoadModel("Models/chain chomp_cadena_libre.obj");
	cc_cadena_principal = Model();
	cc_cadena_principal.LoadModel("Models/chain chomp_cadena_principal.obj");
	
	Goo_Cabeza = Model();
	Goo_Cabeza.LoadModel("Models/GoombaCabeza.obj");
	Goo_PieDer = Model();
	Goo_PieDer.LoadModel("Models/GoombaPieDer.obj");
	Goo_PieIzq = Model();
	Goo_PieIzq.LoadModel("Models/GoombaPieIzq.obj");
	
	std::vector<std::string> skyboxFaces;
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_rt.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_lf.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_dn.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_up.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_bk.tga");
	skyboxFaces.push_back("Textures/Skybox/cupertin-lake_ft.tga");

	skybox = Skybox(skyboxFaces);

	GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0, uniformEyePosition = 0,
		uniformSpecularIntensity = 0, uniformShininess = 0;
	GLuint uniformColor = 0;

	// Vista en perspectiva:
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 1000.0f);
	
	// vista isometrica
	//glm::mat4 projection = glm::ortho(-20.0f, 20.0f, -20.0f, 20.0f);
	////Loop mientras no se cierra la ventana
	float angulo = 0.0f;
	
	// Variables animacion Goomba
	float CaminataGoomba = 0.0f;
	bool SentidoGoomba = false;
	float rotCabezaGoomba = 0.0f;
	bool RotSentidoGoomba = false;

	while (!mainWindow.getShouldClose())
	{
		// Obtener tipo de camara
		//    Camara normal
		if (camera.getIsometric() == false) {
			projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 1000.0f);
			camera.setCameraUp(glm::vec3(0.0f, 1.0f, 0.0f));
		}
		else {
			projection = glm::ortho(-camera.getZoom(), camera.getZoom(), -camera.getZoom(), camera.getZoom(), -10.0f, 20.f);
			camera.setCameraUp(glm::vec3(0.0f, 1.0f, 0.0f));
		}
		angulo += 0.1f;
		GLfloat now = glfwGetTime();
		deltaTime = now - lastTime;
		deltaTime += (now - lastTime) / limitFPS;
		lastTime = now;

		//Recibir eventos del usuario
		glfwPollEvents();
		camera.keyControl(mainWindow.getsKeys(), deltaTime);
		camera.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());

		// Clear the window
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		skybox.DrawSkybox(camera.calculateViewMatrix(), projection);
		shaderList[0].UseShader();
		uniformModel = shaderList[0].GetModelLocation();
		uniformProjection = shaderList[0].GetProjectionLocation();
		uniformView = shaderList[0].GetViewLocation();
		uniformEyePosition = shaderList[0].GetEyePositionLocation();
		uniformColor = shaderList[0].getColorLocation();
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		glUniform3f(uniformEyePosition, camera.getCameraPosition().x, camera.getCameraPosition().y, camera.getCameraPosition().z);

		glm::mat4 model(1.0);
		glm::mat4 modelaux(1.0);
		glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
		glm::mat4 modelAux(1.0);

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -2.0f, 0.0f));
		model = glm::scale(model, glm::vec3(30.0f, 1.0f, 30.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(color));

		/*pisoTexture.UseTexture();
		meshList[2]->RenderMesh();*/


		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		escenario.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(0.0f, -0.25f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		castillo.RenderModel();

		// arboles
		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-10.122f, 0.0f, -2.011f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-11.05f, 0.0f, -0.024f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-8.267f, 0.0f, 4.124f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-12.495f, 0.0f, 5.783f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-8.642f, 0.0f, 9.62f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-4.259f, 0.328f, 6.188f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-2.127f, 0.487f, 6.235f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(1.906f, -0.26f, 8.924f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(1.547f, 0.054f, 7.111f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(3.999f, -0.072f, 4.667f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(9.098f, 0.06f, 2.2132f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(10.03f, 0.21f, -0.58f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-10.278f, 0.0f, 2.342f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-9.206f, 0.0f, 5.446f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-10.458f, 0.236f, 10.407f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();
		
		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-2.732f, 0.0f, 8.729f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-0.388f, 0.07f, 9.517f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(1.088f, 0.244f, 8.158f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(2.563f, 0.0f, 5.449f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(9.362f, 0.0f, 3.515f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();

		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(9.889f, 0.12f, 1.046f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbol.RenderModel();
		// fin arboles
		
		// Arbustos
		//    Arbusto Peach
		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(9.666f, 0.407f, -3.682f));
		model = glm::rotate(model, toRadians * -70.059f, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbustoPeach.RenderModel();
		
		//    Arbustos chicos
		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(8.571f, 0.386f, -4.797f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbustoCH.RenderModel();
		
		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(9.623f, 0.359f, -2.057f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbustoCH.RenderModel();
		
		// Arbustos grandes
		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(10.344f, 0.644f, -5.164f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbustoG.RenderModel();
		
		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(11.188f, 0.573f, -2.89f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		arbustoG.RenderModel();
		
		// Flores
		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-9.3f, -0.25f, 6.6796f));
		model = glm::rotate(model, toRadians * 60.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		flower.RenderModel();
		
		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-9.2269f, -0.25f, 6.30971f));
		model = glm::rotate(model, toRadians * 90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		flower.RenderModel();
    		
		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-9.3f, -0.25f, 5.97423f));
		model = glm::rotate(model, toRadians * 150.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		flower.RenderModel();
		
		// puro hueso
		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-0.532653f, 0.340787f, 7.11285f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		grim_cuerpo.RenderModel();
		modelAux = model;
		
		model = glm::translate(model, glm::vec3(0.0f, 0.47297f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		grim_cabeza.RenderModel();
		
		model = modelAux;
		model = glm::translate(model, glm::vec3(-0.070037f, 0.368964f, 0.02377f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		grim_antebrazo.RenderModel();
		
		model = modelAux;
		model = glm::translate(model, glm::vec3(-0.100731f, 0.361243f, 0.1412f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		grim_mano.RenderModel();
		
		model = modelAux;
		model = glm::translate(model, glm::vec3(0.225243f, 0.448703f, 0.10315f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		grim_oz.RenderModel();
		
		// antorcha
		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(3.38869f, -0.10469f, 6.8552f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		antorcha.RenderModel();
		
		// tubo
		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-9.94804f, 0.108486f, 6.29916f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		tubo.RenderModel();
		
		// Piranha plant
		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-10.1624f, 0.769539f, 6.29407f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		pp_tallo.RenderModel();
		modelAux = model;
		
		model = glm::translate(model, glm::vec3(0.1888f, 0.211566f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		pp_cabeza_sup.RenderModel();
		
		model = modelAux;
		model = glm::translate(model, glm::vec3(0.1888f, 0.213131f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		pp_cabeza_inf.RenderModel();
		
		model = modelAux;
		model = glm::translate(model, glm::vec3(0.1783f, -0.233368f, -0.02768f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		pp_hoja.RenderModel();
		
		model = modelAux;
		model = glm::translate(model, glm::vec3(0.17586f, -0.253787f, 0.03129f));
		model = glm::rotate(model, toRadians * 90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, toRadians * 180.0f, glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		pp_hoja.RenderModel();
		
		// Parrilla
		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(-0.4493f, 0.434332f, 7.71703f));
		model = glm::rotate(model, toRadians * -90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		parrilla.RenderModel();
		
		// chain chomp
		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::rotate(model, toRadians * -90.0f, glm::vec3(0.0f, 1.0f, 0.0f));	// X+ -> z+ -- z+ -> x-
		//model = glm::translate(model, glm::vec3(-5.0f, 0.358f, 6.3264f));
		model = glm::translate(model, glm::vec3(6.3264f, 0.358f, 5.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		cc_cadena_principal.RenderModel();
		modelAux = model;
		
		//model = glm::translate(model, glm::vec3(0.0f, 0.0f, -0.3264f));
		model = glm::translate(model, glm::vec3(-0.3264f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		cc_cabeza_sup.RenderModel();
		
		model = modelAux;
		//model = glm::translate(model, glm::vec3(0.0f, 0.0f, -0.3264f));
		model = glm::translate(model, glm::vec3(-0.3264f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		cc_cabeza_inf.RenderModel();
		
		model = modelAux;
		//model = glm::translate(model, glm::vec3(-0.02568f, -0.057821f, 0.05779f));
		model = glm::translate(model, glm::vec3(0.05779f, -0.057821f, 0.02568f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		cc_cadena_libre.RenderModel();
		
		// Goomba
		model = glm::mat4(1.0);
		if (camera.getIsometric()) model = camera.ConfIsometric(model);
		model = glm::translate(model, glm::vec3(6.453f + CaminataGoomba, 0.386f - 0.25f, -7.696f));
		modelAux = model;
		model = glm::rotate(model, glm::radians(rotCabezaGoomba), glm::vec3(0.0f, 0.5f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Goo_Cabeza.RenderModel();
		
		model = modelAux;
		model = glm::rotate(model, glm::radians(2*rotCabezaGoomba), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Goo_PieDer.RenderModel();
		
		model = modelAux;
		model = glm::rotate(model, glm::radians(2*rotCabezaGoomba), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		Goo_PieIzq.RenderModel();
		
		//Funciones animacion Goomba

		if(SentidoGoomba==false) {
			CaminataGoomba += 0.005f;
			if (CaminataGoomba > 0.647f) SentidoGoomba = true;
		}    
		if (SentidoGoomba == true) {
			CaminataGoomba -= 0.005f;
			if (CaminataGoomba < -0.936f) SentidoGoomba = false;
		}	    
		if (RotSentidoGoomba == false) {
			rotCabezaGoomba += 0.5f;
			if (rotCabezaGoomba > 10.0f) RotSentidoGoomba = true;
		}
		if (RotSentidoGoomba == true) {
			rotCabezaGoomba -= 0.5f;
			if (rotCabezaGoomba < -10.0f) RotSentidoGoomba = false;
		}
		
		glUseProgram(0);

		mainWindow.swapBuffers();
	}

	return 0;
}
