#include "AppLayer.h"

#include "Core/Application.h"
#include "include/SDL3/SDL_events.h"
#include "include/SDL3/SDL_log.h"
#include "include/SDL3/SDL_oldnames.h"
#include <array>
#include <iostream>
#include <iterator>
#include <memory>

// #include "Core/Renderer/Renderer.h"
// #include "Core/Renderer/Shader.h"

AppLayer::AppLayer()
{
}

AppLayer::~AppLayer()
{
}

void AppLayer::OnUpdate(float ts)
{
	// std::vector<SDL_Event> ev;
	// SDL_PumpEvents();
	const size_t events_num = 20;
	std::array<SDL_Event, events_num> events;
	int res = SDL_PeepEvents(events.data(), events_num, SDL_GETEVENT, SDL_EVENT_KEY_DOWN, SDL_EVENT_MOUSE_MOTION);
	std::cout << res << "\r";
	if(res > 0) {
	for(auto& event: events){
		switch (event.type) {
			case SDL_EVENT_MOUSE_MOTION: 
			std::cout << "switch";
			std::cout << "mouse :"<< event.motion.x << "y :" << event.motion.y<< "\r";
			break;
			
			case SDL_EVENT_KEY_DOWN :
			const char* cha = SDL_GetKeyName(event.key.key);
			std::cout << "key is down " << event.key.key << cha << std::endl;
			break;

		}
	}
	}
	
}

void AppLayer::OnRender()
{
}


