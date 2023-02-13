#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow* window);

int main()
{
	// ��ʼ��GLFW
	glfwInit();
	// 3.3�汾
	// ���汾��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	// �ΰ汾��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// ʹ�ú���ģʽCore-profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	// ���ô��ڳߴ�
	glViewport(0, 0, 800, 600);
	// �����ô��ڳߴ纯���Ļص�
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// ��ѭ��
	while (!glfwWindowShouldClose(window))
	{
		// ��������
		processInput(window);
		
		// ��Ⱦ
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// ����������
		glfwSwapBuffers(window);
		// ��ⴥ���¼�
		glfwPollEvents();
	}

	// �ͷ���Դ
	glfwTerminate();
	return 0;


	return 0;
}



void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}