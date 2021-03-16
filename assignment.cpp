// be sure to include GLAD before other header files that require OpenGL (like GLFW). 

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <bits/stdc++.h>
using namespace std;


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);



// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


const float objTranslationSpeed = 0.01f;
const float objRotationSpeed = 1.0f;
const float cameraSpinSpeed = 0.02f;
const float cameraSpeed = 0.01f;


float cameraSpin = 0.0f;
float objZRotation = 0.0f;
glm::vec3 objTranslation = glm::vec3(0.0f,0.0f,0.0f);


glm::vec3 cameraPosition = glm::vec3(0.0f,0.0f,3.0f);
glm::vec3 cameraTarget = glm::vec3(0.0f,0.0f,0.0f);
glm::vec3 cameraFront = cameraTarget - cameraPosition;
glm::vec3 upVec = glm::vec3(0.0, 1.0, 0.0);




// Vertex Shader code in GLSL
// At end of the main fxn, whatever we set gl_Position to will be used as the output of the vertex shader.
// location=0 sets the location of the position vertex attribute to 0. used when we link vertex attribs
const char *vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aColor;\n"
		"out vec3 ourColor;\n"
		"uniform mat4 model;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"
		"void main()\n"
		"{\n"
		"	 gl_Position = projection * view * model * vec4(aPos, 1.0);\n" 
		"	 ourColor = aColor;\n"
		"}\0";


// Fragment Shader code in GLSL
// we declare output values with the out keyword, that we here promptly named FragColor.
const char *fragmentShaderSource = "#version 330 core\n"
	    "out vec4 FragColor;\n"
	    "in vec3 ourColor;\n"
	    "void main()\n"
	    "{\n"
	    "    FragColor = vec4(ourColor, 1.0f);\n"
	    "}\n\0";






int main()
{
	int dd_type;
	cout << "Please enter Dodecahedron type: ";
	cin >> dd_type;

	// Vertex 
	vector<float> theVertices;

	int vertexCount = 0;
	const char *dd_name = "DODECAHEDRON";

	if(dd_type == 1)
	{
		dd_name = "DECAGONAL PRISM"; 
		vertexCount = 108;
		float vertices[] = {
			0.40f, -0.29f, 0.50f,   0.87f, 0.64f, 0.22f,
			0.40f, -0.29f, -0.50f,   0.87f, 0.64f, 0.22f,
			0.50f, 0.00f, 0.50f,   0.87f, 0.64f, 0.22f,
			0.40f, -0.29f, -0.50f,   0.87f, 0.64f, 0.22f,
			0.50f, 0.00f, 0.50f,   0.87f, 0.64f, 0.22f,
			0.50f, 0.00f, -0.50f,   0.87f, 0.64f, 0.22f,
			0.50f, 0.00f, 0.50f,   0.75f, 0.49f, 0.06f,
			0.50f, 0.00f, -0.50f,   0.75f, 0.49f, 0.06f,
			0.40f, 0.29f, 0.50f,   0.75f, 0.49f, 0.06f,
			0.50f, 0.00f, -0.50f,   0.75f, 0.49f, 0.06f,
			0.40f, 0.29f, 0.50f,   0.75f, 0.49f, 0.06f,
			0.40f, 0.29f, -0.50f,   0.75f, 0.49f, 0.06f,
			0.40f, 0.29f, 0.50f,   0.03f, 0.83f, 0.89f,
			0.40f, 0.29f, -0.50f,   0.03f, 0.83f, 0.89f,
			0.15f, 0.48f, 0.50f,   0.03f, 0.83f, 0.89f,
			0.40f, 0.29f, -0.50f,   0.03f, 0.83f, 0.89f,
			0.15f, 0.48f, 0.50f,   0.03f, 0.83f, 0.89f,
			0.15f, 0.48f, -0.50f,   0.03f, 0.83f, 0.89f,
			0.15f, 0.48f, 0.50f,   0.27f, 0.70f, 0.46f,
			0.15f, 0.48f, -0.50f,   0.27f, 0.70f, 0.46f,
			-0.15f, 0.48f, 0.50f,   0.27f, 0.70f, 0.46f,
			0.15f, 0.48f, -0.50f,   0.27f, 0.70f, 0.46f,
			-0.15f, 0.48f, 0.50f,   0.27f, 0.70f, 0.46f,
			-0.15f, 0.48f, -0.50f,   0.27f, 0.70f, 0.46f,
			-0.15f, 0.48f, 0.50f,   1.00f, 0.63f, 0.10f,
			-0.15f, 0.48f, -0.50f,   1.00f, 0.63f, 0.10f,
			-0.40f, 0.29f, 0.50f,   1.00f, 0.63f, 0.10f,
			-0.15f, 0.48f, -0.50f,   1.00f, 0.63f, 0.10f,
			-0.40f, 0.29f, 0.50f,   1.00f, 0.63f, 0.10f,
			-0.40f, 0.29f, -0.50f,   1.00f, 0.63f, 0.10f,
			-0.40f, 0.29f, 0.50f,   0.24f, 0.18f, 0.62f,
			-0.40f, 0.29f, -0.50f,   0.24f, 0.18f, 0.62f,
			-0.50f, 0.00f, 0.50f,   0.24f, 0.18f, 0.62f,
			-0.40f, 0.29f, -0.50f,   0.24f, 0.18f, 0.62f,
			-0.50f, 0.00f, 0.50f,   0.24f, 0.18f, 0.62f,
			-0.50f, 0.00f, -0.50f,   0.24f, 0.18f, 0.62f,
			-0.50f, 0.00f, 0.50f,   0.76f, 0.43f, 0.03f,
			-0.50f, 0.00f, -0.50f,   0.76f, 0.43f, 0.03f,
			-0.40f, -0.29f, 0.50f,   0.76f, 0.43f, 0.03f,
			-0.50f, 0.00f, -0.50f,   0.76f, 0.43f, 0.03f,
			-0.40f, -0.29f, 0.50f,   0.76f, 0.43f, 0.03f,
			-0.40f, -0.29f, -0.50f,   0.76f, 0.43f, 0.03f,
			-0.40f, -0.29f, 0.50f,   0.70f, 0.97f, 0.32f,
			-0.40f, -0.29f, -0.50f,   0.70f, 0.97f, 0.32f,
			-0.15f, -0.48f, 0.50f,   0.70f, 0.97f, 0.32f,
			-0.40f, -0.29f, -0.50f,   0.70f, 0.97f, 0.32f,
			-0.15f, -0.48f, 0.50f,   0.70f, 0.97f, 0.32f,
			-0.15f, -0.48f, -0.50f,   0.70f, 0.97f, 0.32f,
			-0.15f, -0.48f, 0.50f,   0.75f, 0.12f, 0.99f,
			-0.15f, -0.48f, -0.50f,   0.75f, 0.12f, 0.99f,
			0.15f, -0.48f, 0.50f,   0.75f, 0.12f, 0.99f,
			-0.15f, -0.48f, -0.50f,   0.75f, 0.12f, 0.99f,
			0.15f, -0.48f, 0.50f,   0.75f, 0.12f, 0.99f,
			0.15f, -0.48f, -0.50f,   0.75f, 0.12f, 0.99f,
			0.15f, -0.48f, 0.50f,   0.31f, 0.39f, 0.58f,
			0.15f, -0.48f, -0.50f,   0.31f, 0.39f, 0.58f,
			0.40f, -0.29f, 0.50f,   0.31f, 0.39f, 0.58f,
			0.15f, -0.48f, -0.50f,   0.31f, 0.39f, 0.58f,
			0.40f, -0.29f, 0.50f,   0.31f, 0.39f, 0.58f,
			0.40f, -0.29f, -0.50f,   0.31f, 0.39f, 0.58f,
			0.50f, 0.00f, 0.50f,   0.69f, 0.48f, 0.74f,
			0.40f, 0.29f, 0.50f,   0.69f, 0.48f, 0.74f,
			0.15f, 0.48f, 0.50f,   0.69f, 0.48f, 0.74f,
			0.50f, 0.00f, 0.50f,   0.69f, 0.48f, 0.74f,
			0.15f, 0.48f, 0.50f,   0.69f, 0.48f, 0.74f,
			-0.15f, 0.48f, 0.50f,   0.69f, 0.48f, 0.74f,
			0.50f, 0.00f, 0.50f,   0.69f, 0.48f, 0.74f,
			-0.15f, 0.48f, 0.50f,   0.69f, 0.48f, 0.74f,
			-0.40f, 0.29f, 0.50f,   0.69f, 0.48f, 0.74f,
			0.50f, 0.00f, 0.50f,   0.69f, 0.48f, 0.74f,
			-0.40f, 0.29f, 0.50f,   0.69f, 0.48f, 0.74f,
			-0.50f, 0.00f, 0.50f,   0.69f, 0.48f, 0.74f,
			0.50f, 0.00f, 0.50f,   0.69f, 0.48f, 0.74f,
			-0.50f, 0.00f, 0.50f,   0.69f, 0.48f, 0.74f,
			-0.40f, -0.29f, 0.50f,   0.69f, 0.48f, 0.74f,
			0.50f, 0.00f, 0.50f,   0.69f, 0.48f, 0.74f,
			-0.40f, -0.29f, 0.50f,   0.69f, 0.48f, 0.74f,
			-0.15f, -0.48f, 0.50f,   0.69f, 0.48f, 0.74f,
			0.50f, 0.00f, 0.50f,   0.69f, 0.48f, 0.74f,
			-0.15f, -0.48f, 0.50f,   0.69f, 0.48f, 0.74f,
			0.15f, -0.48f, 0.50f,   0.69f, 0.48f, 0.74f,
			0.50f, 0.00f, 0.50f,   0.69f, 0.48f, 0.74f,
			0.15f, -0.48f, 0.50f,   0.69f, 0.48f, 0.74f,
			0.40f, -0.29f, 0.50f,   0.69f, 0.48f, 0.74f,
			0.50f, 0.00f, -0.50f,   0.70f, 0.04f, 0.07f,
			0.40f, 0.29f, -0.50f,   0.70f, 0.04f, 0.07f,
			0.15f, 0.48f, -0.50f,   0.70f, 0.04f, 0.07f,
			0.50f, 0.00f, -0.50f,   0.70f, 0.04f, 0.07f,
			0.15f, 0.48f, -0.50f,   0.70f, 0.04f, 0.07f,
			-0.15f, 0.48f, -0.50f,   0.70f, 0.04f, 0.07f,
			0.50f, 0.00f, -0.50f,   0.70f, 0.04f, 0.07f,
			-0.15f, 0.48f, -0.50f,   0.70f, 0.04f, 0.07f,
			-0.40f, 0.29f, -0.50f,   0.70f, 0.04f, 0.07f,
			0.50f, 0.00f, -0.50f,   0.70f, 0.04f, 0.07f,
			-0.40f, 0.29f, -0.50f,   0.70f, 0.04f, 0.07f,
			-0.50f, 0.00f, -0.50f,   0.70f, 0.04f, 0.07f,
			0.50f, 0.00f, -0.50f,   0.70f, 0.04f, 0.07f,
			-0.50f, 0.00f, -0.50f,   0.70f, 0.04f, 0.07f,
			-0.40f, -0.29f, -0.50f,   0.70f, 0.04f, 0.07f,
			0.50f, 0.00f, -0.50f,   0.70f, 0.04f, 0.07f,
			-0.40f, -0.29f, -0.50f,   0.70f, 0.04f, 0.07f,
			-0.15f, -0.48f, -0.50f,   0.70f, 0.04f, 0.07f,
			0.50f, 0.00f, -0.50f,   0.70f, 0.04f, 0.07f,
			-0.15f, -0.48f, -0.50f,   0.70f, 0.04f, 0.07f,
			0.15f, -0.48f, -0.50f,   0.70f, 0.04f, 0.07f,
			0.50f, 0.00f, -0.50f,   0.70f, 0.04f, 0.07f,
			0.15f, -0.48f, -0.50f,   0.70f, 0.04f, 0.07f,
			0.40f, -0.29f, -0.50f,   0.70f, 0.04f, 0.07f
		};
		theVertices.assign(vertices, vertices+6*vertexCount);

	}
	else if(dd_type == 2)
	{
		dd_name = "HEXAGONAL DIPYRAMID"; 
		vertexCount = 36;
		float vertices[] = {
			0.25f, -0.43f, 0.00f,   0.90f, 0.38f, 0.92f,
			0.50f, 0.00f, 0.00f,   0.90f, 0.38f, 0.92f,
			0.00f, 0.00f, 0.50f,   0.90f, 0.38f, 0.92f,
			0.25f, -0.43f, 0.00f,   0.03f, 0.78f, 0.15f,
			0.50f, 0.00f, 0.00f,   0.03f, 0.78f, 0.15f,
			0.00f, 0.00f, -0.50f,   0.03f, 0.78f, 0.15f,
			0.50f, 0.00f, 0.00f,   0.90f, 0.07f, 0.03f,
			0.25f, 0.43f, 0.00f,   0.90f, 0.07f, 0.03f,
			0.00f, 0.00f, 0.50f,   0.90f, 0.07f, 0.03f,
			0.50f, 0.00f, 0.00f,   0.36f, 0.35f, 0.10f,
			0.25f, 0.43f, 0.00f,   0.36f, 0.35f, 0.10f,
			0.00f, 0.00f, -0.50f,   0.36f, 0.35f, 0.10f,
			0.25f, 0.43f, 0.00f,   0.62f, 0.35f, 0.84f,
			-0.25f, 0.43f, 0.00f,   0.62f, 0.35f, 0.84f,
			0.00f, 0.00f, 0.50f,   0.62f, 0.35f, 0.84f,
			0.25f, 0.43f, 0.00f,   0.44f, 0.87f, 0.36f,
			-0.25f, 0.43f, 0.00f,   0.44f, 0.87f, 0.36f,
			0.00f, 0.00f, -0.50f,   0.44f, 0.87f, 0.36f,
			-0.25f, 0.43f, 0.00f,   0.88f, 0.55f, 0.23f,
			-0.50f, 0.00f, 0.00f,   0.88f, 0.55f, 0.23f,
			0.00f, 0.00f, 0.50f,   0.88f, 0.55f, 0.23f,
			-0.25f, 0.43f, 0.00f,   0.71f, 0.16f, 0.62f,
			-0.50f, 0.00f, 0.00f,   0.71f, 0.16f, 0.62f,
			0.00f, 0.00f, -0.50f,   0.71f, 0.16f, 0.62f,
			-0.50f, 0.00f, 0.00f,   0.87f, 0.50f, 0.40f,
			-0.25f, -0.43f, 0.00f,   0.87f, 0.50f, 0.40f,
			0.00f, 0.00f, 0.50f,   0.87f, 0.50f, 0.40f,
			-0.50f, 0.00f, 0.00f,   0.70f, 0.72f, 0.57f,
			-0.25f, -0.43f, 0.00f,   0.70f, 0.72f, 0.57f,
			0.00f, 0.00f, -0.50f,   0.70f, 0.72f, 0.57f,
			-0.25f, -0.43f, 0.00f,   0.53f, 0.79f, 0.91f,
			0.25f, -0.43f, 0.00f,   0.53f, 0.79f, 0.91f,
			0.00f, 0.00f, 0.50f,   0.53f, 0.79f, 0.91f,
			-0.25f, -0.43f, 0.00f,   0.43f, 0.95f, 0.95f,
			0.25f, -0.43f, 0.00f,   0.43f, 0.95f, 0.95f,
			0.00f, 0.00f, -0.50f,   0.43f, 0.95f, 0.95f
		};
		theVertices.assign(vertices, vertices+6*vertexCount);

	}
	else if(dd_type == 3)
	{

		dd_name = "UNDECAGONAL PYRAMID"; 
		vertexCount = 60;
		float vertices[] = {
			0.42f, -0.27f, 0.00f,   0.88f, 0.34f, 0.87f,
			0.50f, 0.00f, 0.00f,   0.88f, 0.34f, 0.87f,
			0.00f, 0.00f, 0.50f,   0.88f, 0.34f, 0.87f,
			0.50f, 0.00f, 0.00f,   0.68f, 0.35f, 0.07f,
			0.42f, 0.27f, 0.00f,   0.68f, 0.35f, 0.07f,
			0.00f, 0.00f, 0.50f,   0.68f, 0.35f, 0.07f,
			0.42f, 0.27f, 0.00f,   0.38f, 0.52f, 0.98f,
			0.21f, 0.45f, 0.00f,   0.38f, 0.52f, 0.98f,
			0.00f, 0.00f, 0.50f,   0.38f, 0.52f, 0.98f,
			0.21f, 0.45f, 0.00f,   0.30f, 0.35f, 0.34f,
			-0.07f, 0.49f, 0.00f,   0.30f, 0.35f, 0.34f,
			0.00f, 0.00f, 0.50f,   0.30f, 0.35f, 0.34f,
			-0.07f, 0.49f, 0.00f,   0.25f, 0.70f, 0.07f,
			-0.33f, 0.38f, 0.00f,   0.25f, 0.70f, 0.07f,
			0.00f, 0.00f, 0.50f,   0.25f, 0.70f, 0.07f,
			-0.33f, 0.38f, 0.00f,   0.09f, 0.62f, 0.85f,
			-0.48f, 0.14f, 0.00f,   0.09f, 0.62f, 0.85f,
			0.00f, 0.00f, 0.50f,   0.09f, 0.62f, 0.85f,
			-0.48f, 0.14f, 0.00f,   0.98f, 0.95f, 1.00f,
			-0.48f, -0.14f, 0.00f,   0.98f, 0.95f, 1.00f,
			0.00f, 0.00f, 0.50f,   0.98f, 0.95f, 1.00f,
			-0.48f, -0.14f, 0.00f,   0.34f, 0.42f, 0.65f,
			-0.33f, -0.38f, 0.00f,   0.34f, 0.42f, 0.65f,
			0.00f, 0.00f, 0.50f,   0.34f, 0.42f, 0.65f,
			-0.33f, -0.38f, 0.00f,   0.40f, 0.43f, 0.13f,
			-0.07f, -0.49f, 0.00f,   0.40f, 0.43f, 0.13f,
			0.00f, 0.00f, 0.50f,   0.40f, 0.43f, 0.13f,
			-0.07f, -0.49f, 0.00f,   0.84f, 0.86f, 0.25f,
			0.21f, -0.45f, 0.00f,   0.84f, 0.86f, 0.25f,
			0.00f, 0.00f, 0.50f,   0.84f, 0.86f, 0.25f,
			0.21f, -0.45f, 0.00f,   0.97f, 0.03f, 0.41f,
			0.42f, -0.27f, 0.00f,   0.97f, 0.03f, 0.41f,
			0.00f, 0.00f, 0.50f,   0.97f, 0.03f, 0.41f,
			0.50f, 0.00f, 0.00f,   0.80f, 0.69f, 0.96f,
			0.42f, 0.27f, 0.00f,   0.80f, 0.69f, 0.96f,
			0.21f, 0.45f, 0.00f,   0.80f, 0.69f, 0.96f,
			0.50f, 0.00f, 0.00f,   0.80f, 0.69f, 0.96f,
			0.21f, 0.45f, 0.00f,   0.80f, 0.69f, 0.96f,
			-0.07f, 0.49f, 0.00f,   0.80f, 0.69f, 0.96f,
			0.50f, 0.00f, 0.00f,   0.80f, 0.69f, 0.96f,
			-0.07f, 0.49f, 0.00f,   0.80f, 0.69f, 0.96f,
			-0.33f, 0.38f, 0.00f,   0.80f, 0.69f, 0.96f,
			0.50f, 0.00f, 0.00f,   0.80f, 0.69f, 0.96f,
			-0.33f, 0.38f, 0.00f,   0.80f, 0.69f, 0.96f,
			-0.48f, 0.14f, 0.00f,   0.80f, 0.69f, 0.96f,
			0.50f, 0.00f, 0.00f,   0.80f, 0.69f, 0.96f,
			-0.48f, 0.14f, 0.00f,   0.80f, 0.69f, 0.96f,
			-0.48f, -0.14f, 0.00f,   0.80f, 0.69f, 0.96f,
			0.50f, 0.00f, 0.00f,   0.80f, 0.69f, 0.96f,
			-0.48f, -0.14f, 0.00f,   0.80f, 0.69f, 0.96f,
			-0.33f, -0.38f, 0.00f,   0.80f, 0.69f, 0.96f,
			0.50f, 0.00f, 0.00f,   0.80f, 0.69f, 0.96f,
			-0.33f, -0.38f, 0.00f,   0.80f, 0.69f, 0.96f,
			-0.07f, -0.49f, 0.00f,   0.80f, 0.69f, 0.96f,
			0.50f, 0.00f, 0.00f,   0.80f, 0.69f, 0.96f,
			-0.07f, -0.49f, 0.00f,   0.80f, 0.69f, 0.96f,
			0.21f, -0.45f, 0.00f,   0.80f, 0.69f, 0.96f,
			0.50f, 0.00f, 0.00f,   0.80f, 0.69f, 0.96f,
			0.21f, -0.45f, 0.00f,   0.80f, 0.69f, 0.96f,
			0.42f, -0.27f, 0.00f,   0.80f, 0.69f, 0.96f
		};
		theVertices.assign(vertices, vertices+6*vertexCount);

	}
	else
	{
		cout << "Please enter 1,2 or 3";
		return 0; 
	}
	

	// =================================================================================================
	// Instantiating the GLFW window: initialize & configure
	// =================================================================================================
 
    glfwInit();
	
	// 1st arg of glfwWindowHint is the option(prefixed by GLFW_) we want to configure, the 2nd arg sets value for our option 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);




	// =================================================================================================
	// GLF Window Creation: creating a window object that holds all windowing data (required by other GLFW fxns)
	// =================================================================================================

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, dd_name, NULL, NULL);

	if (window == NULL)
	{
	    cout << "Failed to create GLFW window" << endl;
	    glfwTerminate();
	    return -1;
	}

	// makes context of our window the main context on the current thread.
	glfwMakeContextCurrent(window);
  
	// call fxn on every window resize (sends window width,height also)
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    




	// =================================================================================================
	// Initializing GLAD: load all OpenGL function pointers
	// =================================================================================================

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
	    cout << "Failed to initialize GLAD" << endl;
	    return -1;
	}    
	// In GLAD fxn, we load address of the OpenGL fxn pointers which is OS-specific. GLFW's glfwGetProcAddress helps in get that.



	glEnable(GL_DEPTH_TEST); 



	// =================================================================================================
	// GRAPHICS PIPELINE
	// =================================================================================================



	// Building & Compiling Vertex Shader: 
	// ---------------------------------------------------------------------------------------------

	// shader object
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	// bind and compile the shader
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	// check for shader compile errors
    int success;
    char infoLog[512];

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
    }



	// Building & Compiling Fragment Shader: 
	// ---------------------------------------------------------------------------------------------

	// shader object
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	// bind and compile the shader
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
    }



	// Shader Program: linking the above shaders 
	// ---------------------------------------------------------------------------------------------

    unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	// attach each shader and then link them
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
    }


    // deleting shader objects!
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);  




	unsigned int VAO, VBO;
	glGenVertexArrays(1, &VAO);  
	glGenBuffers(1, &VBO);  

	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

	// binding VBO to its buffer type. now any buffer calls made, will configure currently bound buffer - VBO.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);  
	// copies vertex data to currently bound buffer's memory
	// 4th arg tells how to manage data: in our case the data is set only once and used many times.
	// glBufferData(GL_ARRAY_BUFFER, sizeof(theVertices), &theVertices, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, theVertices.size() * sizeof(float), &theVertices[0], GL_STATIC_DRAW);



	// Linking Vertex Attributes
	// ---------------------------------------------------------------------------------------------

	// how to interpret vertex data (per vertex attribute)
	// args meaning: 1st-> index of vertex attrib, 2nd -> no of components per vertex, 3rd -> data type of components of array
	// 4th -> whether to normalize or not, 5th -> stride: byte offset b/w start of consecutive vertex attribs, 6th -> offset of 1st component of 1st array
	// takes data from VBO currently bound to GL_ARRAY_BUFFER
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	// enabling vertex attributes 
	glEnableVertexAttribArray(0);  


	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
	// enabling vertex attributes 
	glEnableVertexAttribArray(1);  

	// Unbinding VBO since its we've already registered it
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

	// unbinding VAO(so that other VAO calls don't accidentally modify this one) but not really needed!
    glBindVertexArray(0); 




    // use this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);




	// =================================================================================================
	// TRANSFORMATION MATRICES
	// =================================================================================================



	// Projection Matrix
	glm::mat4 projection;
	projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);





	// =================================================================================================
	// Render Loop:  keeps running till we tell GLFW to stop
	// =================================================================================================

	while(!glfwWindowShouldClose(window))
	{

		// input
		processInput(window);



		// =================================================================================================
		// Rendering 
		// =================================================================================================

		// specify color to clear(fill) screen with, and clear the color buffer. so color buffer is filled with color as configured by glClearColor
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// Model Matrix
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, objTranslation);
		model = glm::rotate(model, glm::radians(objZRotation), glm::vec3(0.0, 0.0, 1.0));

		// View Matrix
		glm::mat4 view = glm::mat4(1.0f);

		view = glm::lookAt(cameraPosition, cameraTarget, upVec);


		int modelLocation = glGetUniformLocation(shaderProgram, "model");
		int viewLocation = glGetUniformLocation(shaderProgram, "view");
		int projectionLocation = glGetUniformLocation(shaderProgram, "projection");
	    // activating shader program object: this object will be used for all shader/rendering calls
		glUseProgram(shaderProgram);
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));



		// =================================================================================================
		// Drawing our Object
		// =================================================================================================

		glBindVertexArray(VAO); // since we've only 1 VAO, this isn't really needed..
		// 3 is the no of vertices of triangle(only 1 triangle here)
		glDrawArrays(GL_TRIANGLES, 0, vertexCount);

		// TO make other shapes, just divide that shape into multiple triangles, and draw them. But don't store single vertex multiple times in input vertexData. instead use EBO
		// Remember to update no of vertices in glDrawArrays fxn




		// =================================================================================================
		// glfw: swap buffers and poll IO events
		// =================================================================================================
	    glfwSwapBuffers(window);
	    glfwPollEvents();    
	}



	// optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);




	// =================================================================================================
	// Terminate GLFW: clearing all previously allocated GLFW resources.
	// =================================================================================================

	glfwTerminate();

    return 0;
}





// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
// whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{

	// Tell OpenGL size of rendering window. first 2 prams set location of lower left corner
    glViewport(0, 0, width, height);
    // make sure the viewport matches the new window dimensions;
	// We could actually set the viewport dimensions at values smaller than GLFW's dimensions; then all the OpenGL rendering would be displayed in a smaller window and we could for example display other elements outside the OpenGL viewport
}




// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    	objTranslation += objTranslationSpeed * glm::vec3(0.0f, 1.0f, 0.0f);

    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    	objTranslation -= objTranslationSpeed * glm::vec3(0.0f, 1.0f, 0.0f);

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    	objTranslation -= objTranslationSpeed * glm::vec3(1.0f, 0.0f, 0.0f);

    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    	objTranslation += objTranslationSpeed * glm::vec3(1.0f, 0.0f, 0.0f);

    if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    	objTranslation += objTranslationSpeed * glm::vec3(0.0f, 0.0f, -1.0f);

    if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    	objTranslation += objTranslationSpeed * glm::vec3(0.0f, 0.0f, 1.0f);

    if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
    	objZRotation += objRotationSpeed;

    if(glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
    	objZRotation += -objRotationSpeed;


    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
    	cameraPosition += cameraSpeed * cameraFront;
    	cameraTarget = cameraPosition + cameraFront;
    }

    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
    	cameraPosition -= cameraSpeed * cameraFront;
    	cameraTarget = cameraPosition + cameraFront;
    }

    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
    	cameraPosition += cameraSpeed * glm::normalize(glm::cross(cameraFront, upVec));
    	cameraTarget += cameraSpeed * glm::normalize(glm::cross(cameraFront, upVec));
    }

    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
    	cameraPosition -= cameraSpeed * glm::normalize(glm::cross(cameraFront, upVec));
    	cameraTarget -= cameraSpeed * glm::normalize(glm::cross(cameraFront, upVec));
    }

    if(glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
    {
    	cameraPosition += cameraSpeed * glm::normalize(glm::cross(glm::normalize(glm::cross(cameraFront, upVec)), cameraFront));
    	cameraTarget += cameraSpeed * glm::normalize(glm::cross(glm::normalize(glm::cross(cameraFront, upVec)), cameraFront));
    }

    if(glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
    {
    	cameraPosition -= cameraSpeed * glm::normalize(glm::cross(glm::normalize(glm::cross(cameraFront, upVec)), cameraFront));
    	cameraTarget -= cameraSpeed * glm::normalize(glm::cross(glm::normalize(glm::cross(cameraFront, upVec)), cameraFront));
    }

    if(glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
    {
    	cameraPosition -= objTranslation;
    	cameraTarget -= objTranslation;
    	objTranslation -= objTranslation;
    	
    	float x = cameraPosition.x;
    	float z = cameraPosition.z;
    	float x1 = cameraTarget.x;
    	float z1 = cameraTarget.z;

		cameraPosition.x = x*cos(0.05f) - z*sin(0.05f);
		cameraPosition.z = x*sin(0.05f) + z*cos(0.05f);
		cameraTarget.x = x1*cos(0.05f) - z1*sin(0.05f);
		cameraTarget.z = x1*sin(0.05f) + z1*cos(0.05f);

    }

    if(glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
    {
    	cameraPosition -= objTranslation;
    	cameraTarget -= objTranslation;
    	objTranslation -= objTranslation;
    	
    	float x = cameraPosition.x;
    	float z = cameraPosition.z;
    	float x1 = cameraTarget.x;
    	float z1 = cameraTarget.z;

		cameraPosition.x = x*cos(0.05f) + z*sin(0.05f);
		cameraPosition.z = -x*sin(0.05f) + z*cos(0.05f);
		cameraTarget.x = x1*cos(0.05f) + z1*sin(0.05f);
		cameraTarget.z = -x1*sin(0.05f) + z1*cos(0.05f);
    }

    
    if(glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
    {
	    cameraPosition = glm::vec3(0.0f,0.0f,3.0f);
		cameraTarget = glm::vec3(0.0f,0.0f,0.0f);
		cameraFront = cameraTarget - cameraPosition;
    }
    
    if(glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
    {
	    cameraPosition = glm::vec3(3.0f,0.0f,0.0f);
		cameraTarget = glm::vec3(0.0f,0.0f,0.0f);
		cameraFront = cameraTarget - cameraPosition;
    }
    
    if(glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
    {
	    cameraPosition = glm::vec3(-3.0f,0.0f,0.0f);
		cameraTarget = glm::vec3(0.0f,0.0f,0.0f);
		cameraFront = cameraTarget - cameraPosition;
    }

}


