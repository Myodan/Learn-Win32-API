#pragma once

class Application {
private:
	static bool playing;

public:
	Application();
	virtual ~Application();

	static bool isPlaying();

	static void quit();
};

