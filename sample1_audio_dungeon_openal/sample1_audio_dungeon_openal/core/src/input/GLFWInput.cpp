#include "..\..\include\GLFWInput.h"
#include "..\..\include\Hack3dEngine.h"
#include "..\..\include\GLFWGraphics.h"

GLFWInput::GLFWInput() {
}

GLFWInput::~GLFWInput() {
	glfwTerminate();
}

static GLFWInput* input;

void onMousePosCallback(GLFWwindow * window, double xpos, double ypos) {
	input->mousePosCallback(window, xpos, ypos);
}

void onMouseButtonCallback(GLFWwindow * window, int button, int action, int mods) {
	input->mouseButtonCallback(window, button, action, mods);
}

void onKeyCallback(GLFWwindow * window, int key, int scancode, int action, int mods) {
	input->keyCallback(window, key, scancode, action, mods);
}

bool GLFWInput::init() {
	if (!initialized) {
		if (glfwInit() != GLFW_TRUE) {
			return false;
		}
		initialized = true;
	}
	return true;
}

void GLFWInput::mousePosCallback(GLFWwindow * window, double xpos, double ypos) {
	pointers[0].x = xpos;
	pointers[0].y = ypos;
}

void GLFWInput::mouseButtonCallback(GLFWwindow * window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_1) {
		if (action == GLFW_PRESS) {
			pointers[0].pressed = true;
		} else if (action == GLFW_RELEASE) {
			pointers[0].pressed = false;
		}
	}
}

void GLFWInput::keyCallback(GLFWwindow * window, int key, int scancode, int action, int mods) {
	if (keyMap.find(key) == keyMap.end()) {
		keyMap[key] = KeyInfo();
	}
	if (action == GLFW_PRESS) {
		keyMap[key].pressed = true;
	} else if (action == GLFW_RELEASE) {
		keyMap[key].pressed = false;
	}
}

void GLFWInput::setCallbacks() {
	input = this;
	GLFWwindow* window = ((GLFWGraphics*)(Hack3dEngine::get()->graphics.get()))->window.get();
	glfwSetCursorPosCallback(window, onMousePosCallback);
	glfwSetMouseButtonCallback(window, onMouseButtonCallback);
	glfwSetKeyCallback(window, onKeyCallback);
}

BaseComponentReadiness GLFWInput::isReady() {
	return isInitialized() ? BaseComponentReadiness::READY : BaseComponentReadiness::NOT_READY;
}

void MouseButtonCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}


void GLFWInput::startUpdate(double deltaTime) {
	for (int i = 0; i < prevPointers.size(); i++) {
		prevPointers[i] = pointers[i];
	}
	prevKeyMap = keyMap;
	glfwPollEvents();
	GLFWwindow* window = ((GLFWGraphics*)(Hack3dEngine::get()->graphics.get()))->window.get();
	processInput(window);
}

void GLFWInput::processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

void GLFWInput::endUpdate(double deltaTime) {
}
