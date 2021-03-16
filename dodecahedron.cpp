// be sure to include GLAD before other header files that require OpenGL (like GLFW). 

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);



// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;



// Vertex Shader code in GLSL
// At end of the main fxn, whatever we set gl_Position to will be used as the output of the vertex shader.
// location=0 sets the location of the position vertex attribute to 0. used when we link vertex attribs
const char *vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"    gl_Position = vec4(aPos, 1.0);\n"
		"}\0";


// Fragment Shader code in GLSL
// we declare output values with the out keyword, that we here promptly named FragColor.
const char *fragmentShaderSource = "#version 330 core\n"
	    "out vec4 FragColor;\n"
	    "void main()\n"
	    "{\n"
	    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 0.6f);\n"
	    "}\n\0";






int main()
{

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

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);

	if (window == NULL)
	{
	    std::cout << "Failed to create GLFW window" << std::endl;
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
	    std::cout << "Failed to initialize GLAD" << std::endl;
	    return -1;
	}    
	// In GLAD fxn, we load address of the OpenGL fxn pointers which is OS-specific. GLFW's glfwGetProcAddress helps in get that.



	// Enabling the alpha vals
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
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
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
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
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }


    // deleting shader objects!
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);  





	// Creating VAO(Vertex Array Object) & sending Input
	// ---------------------------------------------------------------------------------------------


	float vertices[] = {
        0.309, 0.309, 0.309,
        0.309, 0.309, -0.309,
        0.309, -0.309, 0.309,
        0.309, -0.309, -0.309,
        -0.309, 0.309, 0.309,
        -0.309, 0.309, -0.309,
        -0.309, -0.309, 0.309,
        -0.309, -0.309, -0.309,
        0.0f, 0.191f, 0.5f,
        0.0f, 0.191f, -0.5f,
        0.0f, -0.191f, 0.5f,
        0.0f, -0.191f, -0.5f,
        0.191f, 0.5f, 0.0f,
        0.191f, -0.5f, 0.0f,
        -0.191f, 0.5f, 0.0f,
        -0.191f, -0.5f, 0.0f,
        0.5f, 0.0f, 0.191f,
        0.5f, 0.0f, -0.191f,
        -0.5f, 0.0f, 0.191f,
        -0.5f, 0.0f, -0.191f
    };



	unsigned int indices[] = {		
        0, 16, 2, 
        0, 2, 10,
        0, 10, 8,

        0, 8, 4,
        0, 4, 14,
        0, 14, 12,

        16, 17, 1,
        16, 1, 12,
        16, 12, 0,

        1, 9, 11,
        1, 11, 3,
        1, 3, 17,

        1, 12, 14,
        1, 14, 5,
        1, 5, 9,

        2, 13, 15,
        2, 15, 6,
        2, 6, 10,

        13, 3, 17,
        13, 17, 16,
        13, 16, 2,

        3, 11, 7,
        3, 7, 15,
        3, 15, 13,

        4, 8, 10,
        4, 10, 6,
        4, 6, 18,

        14, 5, 19,
        14, 19, 18,
        14, 18, 4,

        5, 19, 7,
        5, 7, 11,
        5, 11, 9,

        15, 7, 19,
        15, 19, 18,
        15, 18, 6
    };







	unsigned int VAO, EBO, VBO;
	glGenVertexArrays(1, &VAO);  
	glGenBuffers(1, &VBO);  
	glGenBuffers(1, &EBO);  

	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

	// binding VBO/EBO to its buffer type. now any buffer calls made, will configure currently bound buffer - EBO.
	// copies vertex data to currently bound buffer's memory
	// 4th arg tells how to manage data: in our case the data is set only once and used many times.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);  
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);  
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);




	// Linking Vertex Attributes
	// ---------------------------------------------------------------------------------------------

	// how to interpret vertex data (per vertex attribute)
	// args meaning: 1st-> index of vertex attrib, 2nd -> no of components per vertex, 3rd -> data type of components of array
	// 4th -> whether to normalize or not, 5th -> stride: byte offset b/w start of consecutive vertex attribs, 6th -> offset of 1st component of 1st array
	// takes data from VBO currently bound to GL_ARRAY_BUFFER
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// enabling vertex attributes 
	glEnableVertexAttribArray(0);  



	// Unbinding VBO since its we've already registered it
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

	// unbinding VAO(so that other VAO calls don't accidentally modify this one) but not really needed!
    glBindVertexArray(0); 




    // use this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);




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
		glClear(GL_COLOR_BUFFER_BIT);



		// =================================================================================================
		// Drawing our Object
		// =================================================================================================

	    // activating shader program object: this object will be used for all shader/rendering calls
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO); // since we've only 1 VAO, this isn't really needed..

		// args: 2nd-> 6 is the no of indices/vertices, 3rd-> type of indices, 4th-> offset
		glDrawElements(GL_TRIANGLES, 108, GL_UNSIGNED_INT, 0);





		// glfw: swap buffers and poll IO events
	    glfwSwapBuffers(window);
	    glfwPollEvents();    
	}




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
}