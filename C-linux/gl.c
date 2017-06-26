#include <stdio.h>
//GLEW
#define GLEW_STATIC
#include <GL/glew.h>
//GLFW
#include<GLFW/glfw3.h>

const GLuint WIDTH=800,HEIGHT=600;

void key_callback(GLFWwindow* window,int key,int scancode,int action,int mode);

int main()
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
/*void key_callback(GLFWwindow* window,int key,int scancode,int action,int mode)
{	//当用户按下ESC键，我们设置window窗口的WindowShouldClose属性为true
	//关闭应用程序
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window,GL_TRUE);
}*/
