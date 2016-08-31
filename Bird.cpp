/**
 Authors: William Greer, Alonso Cadenas, Joe Flowers, Cassidy Ferrel
 Team Name: Big Ball of Hack
 Title: Angry Birds Rip Off
 Description:  Creates a Bird object
 Date created: 02/15/2012
 Due date: 04/25/2012
 Date last modified: 04/22/2012
    With assitance from : http://lazyfoo.net,   http://www.libsdl.org/,     Professor Booth
*/


#include "Bird.h"
/**
description: class constructor

pre-condition: none

post-condition: class object has been created

return: nothing
**/
Bird::Bird()
{
    type           = BIRD;
    id             = counter++;
    shape          = CIRCLE;
    mass           = BIRD_MASS;
    line.direction = 0;
    line.force     = 0;//mass*GRAVITY;
    score          = 50;
    img            = load_image( "Bird1.bmp" );
    loc.x          = 100;
    loc.y          = 540;
    dead           = false;
    imgcount       = 1;

    SDL_SetColorKey(img,SDL_SRCCOLORKEY,0xFF00FF);


}
