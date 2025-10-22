#pragma once
#include "SDL3/SDL_video.h"
#include <SDL3/SDL.h>


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

		SDL_Window* GetHandle() const { return m_Handle; }
	private:
		WindowSpecification m_Specification;

		SDL_Window* m_Handle = nullptr;

	};

}

