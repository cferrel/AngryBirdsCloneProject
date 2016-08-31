/**
 Authors: William Greer, Alonso Cadenas, Joe Flowers, Cassidy Ferrel
 Team Name: Big Ball of Hack
 Title: Angry Birds Rip Off
 Description: Creates a Pig object
 Date created: 02/15/2012
 Due date: 04/25/2012
 Date last modified: 04/22/2012
    With assitance from : http://lazyfoo.net,   http://www.libsdl.org/,     Professor Booth
*/


#include "Pig.h"

/**
description: class constructor

pre-condition: none

post-condition: class object has been created

return: nothing
**/
 Pig::Pig()
 {
    type           = PIG;
    id             = counter++;
    shape          = CIRCLE;
    mass           = PIG_MASS;
    line.direction = 1.5*PI;
    line.force     = mass*GRAVITY;
    score          = 1000;
    img            = load_image( "Pig.bmp" );
    loc.x          = 100;
    loc.y          = 80;
    dead           = false;
    hitCount       = 0;

    SDL_SetColorKey(img,SDL_SRCCOLORKEY,0xFF00FF);

}
