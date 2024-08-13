//
// Created by shivaaz on 5/12/23.
//

#include "GLFWApplication.h"
#include "glloader/include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <sys/file.h>
#include <fstream>
#include "cassert"
#include "time.h"
#include "unistd.h"
#include "iostream"
#include "Logger/KSLog.hpp"
#include "KSIO/KSFileStream.h"
#include "Graphics/Shader.h"

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    std::cout<<"keycallback"<<std::endl;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

GLFWApplication::~GLFWApplication() {

}

void GLFWApplication::run() {

    KSApplication::run();
    onWindowInit();
    if(!compileShaders())
    {
        KSPrintF("Shader compile failed %ld %f",__LINE__, __FILE_NAME__);
        exit(-1);
    }
    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.0,1.0,1.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //onDestroy
    glfwDestroyWindow(window);
    glfwTerminate();
}

//https://www.glfw.org/docs/3.3/quick.html
void GLFWApplication::onWindowInit()
{
    glfwSetErrorCallback(error_callback);
    KSApplication::onWindowInit();
    if(!glfwInit())
    {
        assert(false);
    }

   // glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
   // glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(640, 480, "GLFW Application", NULL, NULL);
    if (!window)
    {
        // Window or OpenGL context creation failed
        glfwTerminate();//ondestrou
        assert(false);
    }

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    //load opengl
    gladLoadGL();//other variants.
    glfwSwapInterval(1);


}

void GLFWApplication::onDestroy() {
    KSApplication::onDestroy();
    glfwDestroyWindow(window);//onWindowDestroyed
    glfwTerminate();
}

bool GLFWApplication::compileShaders()
{
    std::string vertexPath = "/Users/shivaaz/Projects/GLFWApp/Assets/Shaders/texture.vert";
    std::string fragPath ="/Users/shivaaz/Projects/GLFWApp/Assets/Shaders/texture.frag";
    std::ifstream vertexfile(vertexPath.c_str() ,std::ios::ate |std::ios::binary);
    if(!vertexfile.is_open())
    {
        return false;
    }
    std::ifstream fragFile(fragPath.c_str() ,std::ios::ate |std::ios::binary);
    if(!fragFile.is_open())
    {
        return false;
    }
    std::string vertexSrc,fragSrc;
    vertexSrc.resize(vertexfile.tellg());
    fragSrc.resize(fragFile.tellg());
    vertexfile.seekg(0);
    fragFile.seekg(0);
    vertexfile.read(const_cast<char *>(vertexSrc.data()), vertexSrc.size());
    fragFile.read(const_cast<char *>(fragSrc.data()), fragSrc.size());
    vertexfile.close();
    fragFile.close();

    GLuint shader = Shader::createProgram(vertexSrc.c_str(),fragSrc.c_str());

    return shader != 0;


}
