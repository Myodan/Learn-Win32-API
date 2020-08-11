#include "framework.h"

bool Application::playing = true;

Application::Application() {

}

Application::~Application() {

}

bool Application::isPlaying() {
	return playing;
}

void Application::quit() {
	playing = false;
}
