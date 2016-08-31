


#ifndef SDLS_H_INCLUDED
#define SDLS_H_INCLUDED

using namespace std;

//Include SDL functions and datatypes
#include "SDL/SDL.h"


//The attributes of the screen
const int SCREEN_WIDTH =  1280; // 640
const int SCREEN_HEIGHT = 960; // 480
const int SCREEN_BPP = 32;

/// hey guys dont edit this file///

SDL_Surface *load_image( string filename )
{
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = SDL_LoadBMP( filename.c_str() );

    //If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
        //Return the optimized image
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}





#endif // SDL_H_INCLUDED
