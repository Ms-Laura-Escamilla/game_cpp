#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640, SCREEN_HEIGHT = 480;

// Global window element
SDL_Window* gWindow = NULL;

// Global surface element
SDL_Surface* gScreenSurface = NULL;

// Image to be shown
SDL_Surface* gHelloWorld = NULL;

// Starts up SDL and creates window
bool init() {
    bool success = true;

    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    } else {
        gWindow = SDL_CreateWindow( "Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if ( gWindow == NULL ) {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
        } else {
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

// Loads media
bool loadMedia() {
    bool success = true;
    const char *image_path = "images/sample_image.bmp";

    //Load splash image
    gHelloWorld = SDL_LoadBMP( image_path );
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}

// Frees media and shuts down SDL
void close() {

    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    SDL_Quit();
}

int main( int argc, char* args[]) {

    if ( !init() ) {
        printf( "Failed to initialize!\n" );
    } else {
        if (!loadMedia() ) {
            printf( "Failed to load media!\n" );
        } else {
            SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
            SDL_UpdateWindowSurface( gWindow );

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }

    // Free and close SDL
    close();

    return 0;

}
