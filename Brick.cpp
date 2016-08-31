/**
 Authors: William Greer, Alonso Cadenas, Joe Flowers, Cassidy Ferrel
 Team Name: Big Ball of Hack
 Title: Angry Birds Rip Off
 Description: Creates a Brick object
 Date created: 02/15/2012
 Due date: 04/25/2012
 Date last modified: 04/22/2012
    With assitance from : http://lazyfoo.net,   http://www.libsdl.org/,     Professor Booth
*/


#include "Brick.h"

/**
description: class constructor

pre-condition: none

post-condition: class object has been created

return: nothing
**/
Brick::Brick()
{
    type           = BRICK;
    id             = counter++;
    shape          = RECTANGLE;
    mass           = BRICK_MASS;
    line.direction = 1.5*PI;
    line.force     = mass*GRAVITY;
    score          = 20;
    img            = load_image( "Brick.bmp" );
    loc.x          = 100;
    loc.y          = 80;
    dead           = false;
    hitCount       = 0;

    SDL_SetColorKey(img,SDL_SRCCOLORKEY,0xFF00FF);


}
