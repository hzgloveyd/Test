#include "TestJni.h"
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

const GLuint WIDTH=800,HEIGHT=600;

JNIEXPORT jint JNICALL Java_TestJni_linux_1main(JNIEnv *env1, jobject obj1)
{
	//初始化GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);

	//创建窗口对象
	GLFWwindow* window=glfwCreateWindow(WIDTH,HEIGHT,"hhk",NULL,NULL);
	if(window == NULL)
	{
		//printf(stderr,"Failed to create GLFW window");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	//注册键盘回调
	//glfwSetKeyCallback(window,key_callback);
	
	//初始化GLEW
	glewExperimental=GL_TRUE;
	if(glewInit()!=GLEW_OK)
	{
		//printf(stderr,"Failed to initialize GLEW");
		return -1;
	}
	
	//告诉OpenGL渲染窗口尺寸大小
	int width,height;
	glfwGetFramebufferSize(window,&width,&height);
	
	glViewport(0,0,width,height);

	//让窗口接受输入并保持运行
	while(!glfwWindowShouldClose(window))
	{
		//检查事件
		glfwPollEvents();
		
		//渲染指令
		glClearColor(0.2f,0.3f,0.3f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		//交换缓冲
		glfwSwapBuffers(window);
	}

	//释放资源
	glfwTerminate();
	return 0;
}

