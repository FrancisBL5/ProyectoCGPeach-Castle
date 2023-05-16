#pragma once

#include <glew.h>

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>

#include <glfw3.h>

class Camera
{
public:
	Camera();
	Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed);

	void keyControl(bool* keys, GLfloat deltaTime);
	void mouseControl(GLfloat xChange, GLfloat yChange);

	glm::vec3 getCameraPosition();
	glm::vec3 getCameraDirection();
	void setCameraUp(glm::vec3 vectorUp);
	glm::mat4 calculateViewMatrix();

	glm::mat4 ConfIsometric(glm::mat4 model);

	bool getIsometric() { return isometric; }
	GLfloat getZoom() { return zoom; }

	~Camera();

private:
	glm::vec3 position;
	glm::vec3 iso_position = glm::vec3(-1.0f, 0.0f, 1.0f);
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	GLfloat iso_right = 0.0f;
	GLfloat iso_left;
	GLfloat iso_up = 0.0f;
	GLfloat iso_down;
	glm::vec3 worldUp;
	GLfloat zoom = 16.0f;

	GLfloat yaw;
	GLfloat pitch;

	GLfloat moveSpeed;
	GLfloat turnSpeed;

	bool isometric = false;

	void update();
};

