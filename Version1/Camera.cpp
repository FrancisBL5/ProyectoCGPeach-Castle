#include "Camera.h"

Camera::Camera() {}

Camera::Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed)
{
	position = startPosition;
	iso_position = startPosition;
	worldUp = startUp;
	yaw = startYaw;
	pitch = startPitch;
	front = glm::vec3(0.0f, 0.0f, -1.0f);

	moveSpeed = startMoveSpeed;
	turnSpeed = startTurnSpeed;

	update();
}

void Camera::keyControl(bool* keys, GLfloat deltaTime)
{
	GLfloat velocity = moveSpeed * deltaTime * 0.05;

	if (isometric == false) {
		if (keys[GLFW_KEY_W]) {
			position += front * velocity;
		}

		if (keys[GLFW_KEY_S]) {
			position -= front * velocity;
		}

		if (keys[GLFW_KEY_A]) {
			position -= right * velocity;
		}

		if (keys[GLFW_KEY_D]) {
			position += right * velocity;
		}
	}
	else {
		if (keys[GLFW_KEY_W]) {
			zoom -= 0.5f;
			if (zoom < 1.0f) zoom = 1.0f;
		}

		if (keys[GLFW_KEY_S]) {
			zoom += 0.5f;
			if (zoom > 15.0f) zoom = 15.0f;
		}
	}
	// cambio de camara
	if (keys[GLFW_KEY_C]) isometric = false;
	if (keys[GLFW_KEY_I]) isometric = true;
}

void Camera::mouseControl(GLfloat xChange, GLfloat yChange)
{
	xChange *= turnSpeed;
	yChange *= turnSpeed;

	if (isometric == false) {
		yaw += xChange;
		pitch += yChange;
	}
	else {
		iso_right = xChange * zoom / 40.0f;
		iso_up = yChange * zoom / 40.0f;
		iso_position += glm::vec3(iso_right, 0.0f, -iso_up);
	}
	
	if (pitch > 89.0f) pitch = 89.0f;
	if (pitch < -89.0f) pitch = -89.0f;

	update();
}

glm::mat4 Camera::calculateViewMatrix()
{
	if (isometric == false) return glm::lookAt(position, position + front, up);
	else return glm::lookAt(iso_position, iso_position + glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
}

glm::vec3 Camera::getCameraPosition()
{
	return position;
}

glm::vec3 Camera::getCameraDirection()
{
	return glm::normalize(front);
}

void Camera::setCameraUp(glm::vec3 vectorUp) {
	worldUp = vectorUp;
}

void Camera::update()
{
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);

	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
}


Camera::~Camera() {}