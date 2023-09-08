#ifndef SDL_FUNCTIONS_H
#define SDL_FUNCTIONS_H

#include <SDL2/SDL.h>

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern SDL_Window* gWindow;
extern SDL_Surface* gScreenSurface;
extern SDL_Surface* gHelloWorld;
extern SDL_Surface* gKeyPressSurfaces[];

bool init();
SDL_Surface* loadSurface(const char* path);
bool loadMedia();
void close();

#endif // SDL_FUNCTIONS_H
