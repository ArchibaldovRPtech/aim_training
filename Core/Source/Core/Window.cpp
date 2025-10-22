#include "Window.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_video.h"


#include <iostream>
#include <assert.h>
#include <vector>

namespace Core {

	Window::Window(const WindowSpecification& specification)
		: m_Specification(specification)
	{
	}

	Window::~Window()
	{
		Destroy();
	}

	void Window::Create()
	{
		// glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		// glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		// glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		// glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
		//
		m_Handle = SDL_CreateWindow(m_Specification.Title.c_str(),m_Specification.Width, m_Specification.Height, 0);

		if (!m_Handle)
		{
			std::cerr << "Failed to create GLFW window!\n";
			assert(false);
		}

	}
	void Window::Destroy()
	{
		if (m_Handle)
			SDL_DestroyWindow(m_Handle);

		m_Handle = nullptr;
	}

	void Window::Update()
	{
		SDL_GL_SwapWindow(m_Handle);
	}

	std::vector<int> Window::GetFramebufferSize()
	{
		int width, height;
	SDL_GetWindowSize(m_Handle, &width, &height);
		return { width, height };
	}

	bool Window::ShouldClose() const
	{
		return SDL_HasEvent(SDL_EVENT_QUIT) != 0;
	}

}

