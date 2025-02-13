#include "GL\glew.h"
#include "GLFW/glfw3.h"
#include <math.h>

#include <iostream>

#define _USE_MATH_DEFINES
#define GLEW_DLL
#define GLFW_DLL

int main() {

    if (!glfwInit()) {
        fprintf(stderr, "ERROR\n");
        return 1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
   // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  //  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(600, 600, "lab1", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;

    GLenum ret = glewInit();
    if (GLEW_OK != ret) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(ret));
        return 1;
    }
    while (!glfwWindowShouldClose(window)) {
        float pi = 3.14;
        float x, y;
        float cnt = 100;
        float r = 0.5;
        float angle = pi * 2/cnt;
        glClearColor(0.3f, 1.0f, 0.4f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLE_FAN);
        for (int i(0); i < cnt; i++) {
            y = sin(angle * i) * r;
            x = cos(angle * i) * (r+0.2);
            glVertex2f(x,y);
        }
        glColor3f(1.0f, 0.2f, 1.0f);
        
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}
