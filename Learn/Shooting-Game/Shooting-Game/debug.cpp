#include "Debug.h"

void START_DEBUG_CONSOLE() {
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);
}

void STOP_DEBUG_CONSOLE() {
	FreeConsole();
}