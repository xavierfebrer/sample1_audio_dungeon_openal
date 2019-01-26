#include "../../../../core/include/Camera.h"
#include "../../../../core/include/Hack3dEngine.h"
#include "../../../../core/include/PointerInfo.h"
#include "../../../../core/include/KeyInfo.h"
#include "../../../../core/include/GLFWGraphics.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

const float Camera::DEFAULT_YAW = -90.0f;
const float Camera::DEFAULT__PITCH = 0.0f;
const float Camera::DEFAULT_ZOOM = 45.0f;

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
	: front(glm::vec3(0.0f, 0.0f, -1.0f)), zoom(DEFAULT_ZOOM) {
	this->position = position;
	this->worldUp = up;
	this->yaw = yaw;
	this->pitch = pitch;
	updateCameraVectors();
}

Camera::Camera(float posX, float posY, float posZ,
	float upX, float upY, float upZ,
	float yaw, float pitch)
	: front(glm::vec3(0.0f, 0.0f, -1.0f)), zoom(DEFAULT_ZOOM) {
	this->position = glm::vec3(posX, posY, posZ);
	this->worldUp = glm::vec3(upX, upY, upZ);
	this->yaw = yaw;
	this->pitch = pitch;
	updateCameraVectors();
}

void Camera::updateCameraVectors() {
	glm::vec3 frontTemp;
	frontTemp.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	frontTemp.y = sin(glm::radians(pitch));
	frontTemp.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(frontTemp);

	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));

	modelMatrix = glm::mat4(1.0f);
	viewMatrix = glm::lookAt(position, position + front, up);
	projectionMatrix = glm::perspective(glm::radians(zoom), (float)(1920 * 0.50) / (float)(1080 * 0.50), 0.1f, 100.0f);
}

glm::mat4 Camera::getModelMatrix() {
	return modelMatrix;
}

glm::mat4 Camera::getViewMatrix() {
	return viewMatrix;
}

glm::mat4 Camera::getProjectionMatrix() {
	return projectionMatrix;
}

void Camera::setPosition(glm::vec3 position) {
	this->position = position;
}

void Camera::setPosition(float x, float y, float z) {
	this->position.x = x;
	this->position.y = y;
	this->position.z = z;
}

const glm::vec3 & Camera::getPosition() {
	return this->position;
}

const glm::vec3 & Camera::getFront() {
	return this->front;
}

void Camera::setYaw(float yaw) {
	this->yaw = yaw;
}

float Camera::getYaw() {
	return yaw;
}

void Camera::setPitch(float pitch) {
	this->pitch = pitch;
}

float Camera::getPitch() {
	return pitch;
}

void Camera::setZoom(float zoom) {
	this->zoom = zoom;
}

float Camera::getZoom() {
	return zoom;
}

void Camera::enableExperimentalCameraMovement(double deltaTime) {


	PointerInfo prevPI = Hack3dEngine::get()->input->getPrevPointerInfo(0);
	PointerInfo currentPI = Hack3dEngine::get()->input->getPointerInfo(0);
	std::map<int, KeyInfo> & prevKI = Hack3dEngine::get()->input->getPrevKeyInfo();
	std::map<int, KeyInfo> & currentKI = Hack3dEngine::get()->input->getKeyInfo();

	GLFWwindow* window = ((GLFWGraphics*)(Hack3dEngine::get()->graphics.get()))->window.get();
	if (currentKI[GLFW_KEY_ENTER].pressed && !prevKI[GLFW_KEY_ENTER].pressed) {
		if (glfwGetInputMode(window, GLFW_CURSOR) != GLFW_CURSOR_DISABLED) {
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		} else {
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}
	}

	


	int distX = currentPI.x - prevPI.x;
	int distY = currentPI.y - prevPI.y;
	float sensitivityX = 200.0f;
	float sensitivityY = 200.0f;
	setYaw(getYaw() + distX * sensitivityX * deltaTime);
	float pitch = getPitch();
	float pitchDelta = - distY * sensitivityY * deltaTime;
	if(pitch + pitchDelta > -89 && pitch + pitchDelta < 89) {
		setPitch(getPitch() + pitchDelta);
	}
	updateCameraVectors();


	float cameraMoveSpeed = currentKI[GLFW_KEY_LEFT_SHIFT].pressed ? 25.0f : 10.0f;
	if (currentKI[GLFW_KEY_W].pressed) {
		setPosition(getPosition() + front * ((float)(cameraMoveSpeed * deltaTime)));
	} else if (currentKI[GLFW_KEY_S].pressed) {
		setPosition(getPosition() - front * ((float)(cameraMoveSpeed * deltaTime)));
	}
	if (currentKI[GLFW_KEY_A].pressed) {
		setPosition(getPosition() - right * ((float)(cameraMoveSpeed * deltaTime)));
	} else if (currentKI[GLFW_KEY_D].pressed) {
		setPosition(getPosition() + right * ((float)(cameraMoveSpeed * deltaTime)));
	}
	if (currentKI[GLFW_KEY_SPACE].pressed) {
		setPosition(getPosition() + up * ((float)(cameraMoveSpeed * deltaTime)));
	} else if (currentKI[GLFW_KEY_LEFT_CONTROL].pressed) {
		setPosition(getPosition() - up * ((float)(cameraMoveSpeed * deltaTime)));
	}








	/*
	setPosition(
		pos.x + (currentKI[GLFW_KEY_D].pressed ? 1 : currentKI[GLFW_KEY_A].pressed ? -1 : 0) * deltaTime * cameraMoveSpeed,
		pos.y + (currentKI[GLFW_KEY_SPACE].pressed ? 1 : currentKI[GLFW_KEY_LEFT_CONTROL].pressed ? -1 : 0) * deltaTime * cameraMoveSpeed,
		pos.z + (currentKI[GLFW_KEY_W].pressed ? 1 : currentKI[GLFW_KEY_S].pressed ? -1 : 0) * deltaTime * cameraMoveSpeed);














	auto pos = getPosition();
	setPosition(
		pos.x + (currentKI[GLFW_KEY_D].pressed ? 1 : currentKI[GLFW_KEY_A].pressed ? -1 : 0) * deltaTime * cameraMoveSpeed,
		pos.y + (currentKI[GLFW_KEY_SPACE].pressed ? 1 : currentKI[GLFW_KEY_LEFT_CONTROL].pressed ? -1 : 0) * deltaTime * cameraMoveSpeed,
		pos.z + (currentKI[GLFW_KEY_W].pressed ? 1 : currentKI[GLFW_KEY_S].pressed ? -1 : 0) * deltaTime * cameraMoveSpeed);

	int distX = currentPI.x - prevPI.x;
	int distY = currentPI.y - prevPI.y;
	float sensitivityX = 500.0f;
	float sensitivityY = 500.0f;

	setYaw(getYaw() + distX * sensitivityX * deltaTime);
	setPitch(getPitch() - distY * sensitivityY * deltaTime);*/
}