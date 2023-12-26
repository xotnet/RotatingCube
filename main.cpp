#include <GLFW/glfw3.h>
#include <windows.h>
float cxs = 0.3; // CubeOtherSize = cys // }
float cys = 0.5; // CubeOtherSize = cys // } Sizes
float czs = 0.3; // CubeOtherSize = cys // }
bool toRotate = true;
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_E && action == GLFW_REPEAT && czs < 0.80) {czs += 0.005;}
	else if (key == GLFW_KEY_Q && action == GLFW_REPEAT && czs > 0.03) {czs -= 0.005;}
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {if (toRotate) {toRotate = false;} else {toRotate = true;}} // stop/start cube rotating
}

int main() {
	FreeConsole();
	if (!glfwInit()) { // init glfw for normaly functions work
		return 0;}
	glfwWindowHint(GLFW_SAMPLES, 4); // set 4X antialiasing
	GLFWwindow* window = glfwCreateWindow(1280, 720, "OpenGl cube", NULL, NULL);
	glfwMakeContextCurrent(window); // opening window on system
	glfwSwapInterval(1); // setting fps 60 (1/60)
	glEnable(GL_DEPTH_TEST); // enable deep check
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glMatrixMode(GL_MODELVIEW);
	glFrustum(-0.1, 1, -1, 1, -1, 1);
	glLoadIdentity();
	float CUBE_TEXTRURE[] = {
		1, 0.56, 0.73, 1, 0.56, 0.73, 1, 0.56, 0.73, 
		1, 0.56, 0.73, 1, 0.56, 0.73, 1, 0.56, 0.73,  // face
		0.97, 0.97, 0.87, 0.97, 0.97, 0.87, 0.97, 0.97, 0.87,
		0.97, 0.97, 0.87, 0.97, 0.97, 0.87, 0.97, 0.97, 0.87, // backspace
		0.8, 1, 0.8, 0.8, 1, 0.8, 0.8, 1, 0.8,
		0.8, 1, 0.8, 0.8, 1, 0.8, 0.8, 1, 0.8, // right
		0.54, 0.8, 0.84, 0.54, 0.8, 0.84, 0.54, 0.8, 0.84,
		0.54, 0.8, 0.84, 0.54, 0.8, 0.84, 0.54, 0.8, 0.84, // left
		0.8, 0.7, 1, 0.8, 0.7, 1, 0.8, 0.7, 1,
		0.8, 0.7, 1, 0.8, 0.7, 1, 0.8, 0.7, 1,  // head
	};
	glRotatef(-15, 1, 0, 0);
	bool toSmall = true;
	glfwSetKeyCallback(window, key_callback);
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // setting black backround
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glViewport(0, 0, 1280, 720);
		if (toRotate) {glRotatef(-0.5, 0, 1, 0);}
		glColorPointer(3, GL_FLOAT, 0, CUBE_TEXTRURE); // set cube textrure
		float CUBE[] = { // setting cube mesh as object
			-cxs, cys, czs, cxs, cys, czs, cxs, -cys, czs,       // 
			-cxs, -cys, czs, -cxs, cys, czs, cxs, -cys, czs,     // face
			-cxs, cys, -czs, cxs, cys, -czs, cxs, -cys, -czs,    // 
			-cxs, -cys, -czs, -cxs, cys, -czs, cxs, -cys, -czs,  // backspace
			cxs, cys, czs, cxs, -cys, -czs, cxs, -cys, czs,      //
			cxs, cys, -czs, cxs, cys, czs, cxs, -cys, -czs,      // right
			-cxs, cys, czs, -cxs, -cys, -czs, -cxs, -cys, czs,   //
			-cxs, cys, -czs, -cxs, cys, czs, -cxs, -cys, -czs,   // left
			-cxs, cys, czs, cxs, cys, czs, -cxs, cys, -czs,      //
			-cxs, cys, -czs, cxs, cys, czs, cxs, cys, -czs,      // head
		};
		glVertexPointer(3, GL_FLOAT, 0, CUBE); // creating cube mesh as vertex object
		glDrawArrays(GL_TRIANGLES, 0, 30); // draw cube mesh with textrure
		glfwSwapBuffers(window); // changing frames
	}
}
