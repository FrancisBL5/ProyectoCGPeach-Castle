#pragma once

// Std. Includes
#include <vector>

// GL Includes
#define GLEW_STATIC
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

// Default camera values
const GLfloat YAW = -90.0f;
const GLfloat PITCH = 0.0f;
const GLfloat SPEED = 6.0f;
const GLfloat SENSITIVTY = 0.25f;
const GLfloat ZOOM = 45.0f;

// An abstract camera class that processes input and calculates the corresponding Eular Angles, Vectors and Matrices for use in OpenGL
class Camera
{
public:
	// Constructor with vectors
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), GLfloat yaw = YAW, GLfloat pitch = PITCH) : front(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVTY), zoom(ZOOM)
	{
		this->position = position;
		this->worldUp = up;
		this->yaw = yaw;
		this->pitch = pitch;
		this->updateCameraVectors();
	}

	// Constructor with scalar values
	Camera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch) : front(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVTY), zoom(ZOOM)
	{
		this->position = glm::vec3(posX, posY, posZ);
		this->worldUp = glm::vec3(upX, upY, upZ);
		this->yaw = yaw;
		this->pitch = pitch;
		this->updateCameraVectors();
	}

	// Returns the view matrix calculated using Eular Angles and the LookAt Matrix
	glm::mat4 GetViewMatrix()
	{
		if (isometric == false) return glm::lookAt(this->position, this->position + this->front, this->up);
		else return glm::lookAt(iso_position, iso_position + glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	}

	void Recorrido(GLfloat xOffset)//Modifica la rotaci�n recibiendo el �ngulo
	{
		this->yaw = xOffset;
		this->updateCameraVectors();
	}

	void MovimientoAutomatico(GLfloat velocidad) //Realiza un movimiento automatico hacia adelante
	{
		this->position += this->front * velocidad;
	}

	glm::mat4 ConfIsometric(glm::mat4 model) {
		model = glm::rotate(model, glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(35.2644f), glm::vec3(0.0f, 0.0f, 1.0f));
		return model;
	}

	void setIsometric(GLfloat iso) { this->isometric = iso; }

	// Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
	void ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime)
	{
		GLfloat velocity = this->movementSpeed * deltaTime;
		if (!isometric) {
			if (direction == FORWARD) this->position += this->front * velocity;
			if (direction == BACKWARD) this->position -= this->front * velocity;
			if (direction == LEFT) this->position -= this->right * velocity;
			if (direction == RIGHT) this->position += this->right * velocity;
			if (this->position.y < 2.0f) this->position.y = 2.0f;
			if (this->position.y > 40.0f) this->position.y = 40.0f;
			if (this->position.x < -20.0f) this->position.x = -20.0f;
			if (this->position.x > 20.0f) this->position.x = 20.0f;
			if (this->position.z < -15.0f) this->position.z = -15.0f;
			if (this->position.z > 30.0f) this->position.z = 30.0f;
		}
		else {
			if (direction == FORWARD) {
				iso_up += 0.5f;
				if (iso_up >= 20.0f) iso_up = 20.0f;
			}
			if (direction == BACKWARD) {
				iso_up -= 0.5f;
				if (iso_up <= -25.0f) iso_up = -25.0f;
			}
			if (direction == LEFT) {
				iso_right -= 0.5f;
				if (iso_right <= -20.0f) iso_right = -20.0f;
			}
			if (direction == RIGHT) {
				iso_right += 0.5f;
				if (iso_right >= 20.0f) iso_right = 20.0f;
			}
			iso_position = glm::vec3(iso_right, iso_up, iso_right);
		}
	}

	// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
	void ProcessMouseMovement(GLfloat xOffset, GLfloat yOffset, GLboolean constrainPitch = true)
	{
		xOffset *= this->mouseSensitivity;
		yOffset *= this->mouseSensitivity;

		if (!isometric) {
			this->yaw += xOffset;
			this->pitch += yOffset;
		}
		// Make sure that when pitch is out of bounds, screen doesn't get flipped
		if (constrainPitch)
		{
			if (this->pitch > 89.0f)
			{
				this->pitch = 89.0f;
			}

			if (this->pitch < -89.0f)
			{
				this->pitch = -89.0f;
			}
		}

		// Update Front, Right and Up Vectors using the updated Eular angles
		this->updateCameraVectors();
	}

	// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
	void ProcessMouseScroll(GLfloat yOffset){}

	bool getIsometric() { return this->isometric; }
	GLfloat getIsoZoom() { return this->iso_zoom; }
	void setZoom(GLfloat zoom) { this->iso_zoom = zoom; }

	GLfloat GetZoom() { return this->zoom; }
	glm::vec3 GetPosition() { return this->position; }
	glm::vec3 GetFront() { return this->front; }
	GLfloat getYaw() { return this->yaw; }

private:
	// Camera Attributes
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;

	// Eular Angles
	GLfloat yaw;
	GLfloat pitch;

	// Camera options
	GLfloat movementSpeed;
	GLfloat mouseSensitivity;
	GLfloat zoom;

	// variables camara isometrica
	bool isometric = false;
	GLfloat iso_right, iso_up;
	glm::vec3 iso_position;
	GLfloat iso_zoom = 2.0f;

	// Calculates the front vector from the Camera's (updated) Eular Angles
	void updateCameraVectors()
	{
		// Calculate the new Front vector
		glm::vec3 front;
		front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
		front.y = sin(glm::radians(this->pitch));
		front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
		this->front = glm::normalize(front);
		// Also re-calculate the Right and Up vector
		this->right = glm::normalize(glm::cross(this->front, this->worldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		this->up = glm::normalize(glm::cross(this->right, this->front));
	}
};