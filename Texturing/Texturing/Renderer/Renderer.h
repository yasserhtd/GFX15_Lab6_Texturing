#ifndef Renderer_h__
#define Renderer_h__

#include <gl/glew.h>
#include <gl/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>


#include "Shaders/shader.hpp"
#include "Texture/texture.h"
#include "Model/Model.h"
#include "FPCamera/FPCamera.h"
#include "EulerCamera/EulerCamera.h"
#include "Third Person Camera/ThirdPersonCamera.h"
class Renderer
{
	enum RenderingMode
	{
		NO_TEXTURE,
		TEXTURE_ONLY,
		BLEND
	};

    GLuint programID;
    
	// Transformation
	GLuint MatrixID;
	
	std::unique_ptr<Model> myTriangle;
	std::unique_ptr<Model> mySquare;
	//std::unique_ptr<FPCamera> myCamera;
	std::unique_ptr<ThirdPersonCamera> myCamera;

	std::unique_ptr<Texture> mTexture1;
	std::unique_ptr<Texture> mTexture2;

	GLuint mRenderingModeID;
	RenderingMode mRenderingMode;

	glm::mat4 triangle1M;
	glm::mat4 triangle2M;
	glm::mat4 triangle3M;
	glm::mat4 triangle4M;

	glm::mat4 floorM;




public:
    Renderer();
    ~Renderer();
    
    void Initialize();
    void Draw();
	void HandleKeyboardInput(int key);
	void HandleMouse(double deltaX,double deltaY);
	void Update(double deltaTime);
    void Cleanup();
};

#endif // Renderer_h__

