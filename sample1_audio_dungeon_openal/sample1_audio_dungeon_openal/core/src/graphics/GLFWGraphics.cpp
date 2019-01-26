#include "..\..\include\GLFWGraphics.h"
#include "..\..\include\Hack3dEngine.h"
#include "..\..\include\GLFWInput.h"

GLFWGraphics::GLFWGraphics() {
}

GLFWGraphics::~GLFWGraphics() {
	window.reset();
	glfwTerminate();
}

bool GLFWGraphics::init() {
	if (!initialized) {
		if (glfwInit() != GLFW_TRUE) {
			return false;
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		initialized = true;
	}
	return true;
}

BaseComponentReadiness GLFWGraphics::isReady() {
	return isInitialized() ? BaseComponentReadiness::READY : BaseComponentReadiness::NOT_READY;
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

bool GLFWGraphics::initWindow(int width, int height, const std::string & title, int windowPosLeftX, int windowPosUpY) {
	window = std::shared_ptr<GLFWwindow>(glfwCreateWindow(width, height, title.c_str(), NULL, NULL),
		[=](GLFWwindow* window){glfwDestroyWindow(window);});
	if (window.get() == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		return false;
	}
	glfwMakeContextCurrent(window.get());
	if (!initGLAD()) {
		return false;
	}
	glfwSetWindowPos(window.get(), windowPosLeftX, windowPosUpY);
	glViewport(0, 0, width, height);	// left x, bottom y, w, h
	glfwSetFramebufferSizeCallback(window.get(), framebufferSizeCallback);
	((GLFWInput*)(Hack3dEngine::get()->input.get()))->setCallbacks();
	return true;
}

bool GLFWGraphics::initGLAD() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}
	return true;
}

void GLFWGraphics::startRender(double deltaTime) {
}

void GLFWGraphics::clearScreen(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void GLFWGraphics::clearScreen(const MyColor & color) {
	clearScreen(color.getR(), color.getG(), color.getB(), color.getA());
}

void GLFWGraphics::render(const TextureRegion2D & textureRegion2D, double x, double y, double w, double h, double rotationDegrees, double alpha) {
}

void GLFWGraphics::endRender(double deltaTime) {
	glfwSwapBuffers(window.get());
}

bool GLFWGraphics::hasRequestExit() {
	return glfwWindowShouldClose(window.get());
}

Vec2<int> GLFWGraphics::getWindowSize() {
	Vec2<int> windowSize;
	glfwGetWindowSize(window.get(), &windowSize.x, &windowSize.y);
	return windowSize;
}
