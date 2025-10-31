#pragma once
#include "SDL3/SDL_video.h"
#include <SDL3/SDL.h>


#include <SDL3/SDL_render.h>
#include <string>
#include <vector>

namespace Core {

	struct WindowSpecification
	{
		std::string Title;
		uint32_t Width = 1280;
		uint32_t Height = 720; bool IsResizeable = true;
		bool VSync = true;
	};
	class Window
	{
	public:
		Window(const WindowSpecification& specification = WindowSpecification());
		~Window();

		void Create();
		void Destroy();

		void Update();

		std::vector<int> GetFramebufferSize();

		bool ShouldClose() const;

		SDL_Window* GetWindowHandle() const { return m_WindowHandle; }
		SDL_Renderer* Get_windowRenderer() const { return m_WindowRenderer; }
	private:
		WindowSpecification m_Specification;

		SDL_Window* m_WindowHandle = nullptr;
		SDL_Renderer* m_WindowRenderer = nullptr;

	};

}

