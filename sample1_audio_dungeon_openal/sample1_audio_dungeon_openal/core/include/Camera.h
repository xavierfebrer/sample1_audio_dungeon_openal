#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

class Camera {
public:
	static const float DEFAULT_YAW;
	static const float DEFAULT__PITCH;
	static const float DEFAULT_ZOOM;

	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
		float yaw = DEFAULT_YAW, float pitch = DEFAULT__PITCH);

	Camera(float posX, float posY, float posZ,
		float upX, float upY, float upZ,
		float yaw, float pitch);

	void updateCameraVectors();

	glm::mat4 getModelMatrix();
	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();
	void setPosition(glm::vec3 position);
	void setPosition(float x, float y, float z);
	const glm::vec3 & getPosition();
	const glm::vec3 & getFront();
	void setYaw(float yaw);
	float getYaw();
	void setPitch(float pitch);
	float getPitch();
	void setZoom(float zoom);
	float getZoom();
	void enableExperimentalCameraMovement(double deltaTime);
private:
	glm::mat4 modelMatrix;
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;
	float yaw;
	float pitch;
	float zoom;
};