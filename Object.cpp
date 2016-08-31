/**
 Authors: William Greer, Alonso Cadenas, Joe Flowers, Cassidy Ferrel
 Team Name: Big Ball of Hack
 Title: Angry Birds Rip Off
 Description:  This program creates a physics based game where birds are launched from a slingshot with the intention of destroying all the pigs in the game.
 Date created: 02/15/2012
 Due date: 04/25/2012
 Date last modified: 04/22/2012
    With assitance from : http://lazyfoo.net,   http://www.libsdl.org/,     Professor Booth
*/


#include "Object.h"
#include <typeinfo>

void Object::setShape(int x){
    shape=x;
}

void Object::setId(int x){
    id=x;
}


void Object::setType(int x){
    type=x;
}


int  Object::getShape(){
    return shape;
}


int  Object::getId(){
    return id;
}


int  Object::getType(){
    return type;
}




void Object::draw(int x,int y, SDL_Surface *screen){
/**
  if(x<0||x>SCREEN_WIDTH||y<0||y>SCREEN_HEIGHT)
        return;
*/
    if(!dead){

    if(x<0)
        x=0;
    if(x>SCREEN_WIDTH)
        x=SCREEN_WIDTH ;
  //  if(y<0)
   //     y=-30;
    if(y>SCREEN_HEIGHT-200)
        y=SCREEN_HEIGHT-200;

    if(this->type==BIRD && y==SCREEN_HEIGHT-200 && line.force > 0)
    {
        switch(imgcount%144){
            case 0:  img = load_image( "Bird1.bmp" );  break;
            case 18:  img = load_image( "Bird2.bmp" );  break;
            case 36:  img = load_image( "Bird3.bmp" );  break;
            case 54:  img = load_image( "Bird4.bmp" );  break;
            case 72:  img = load_image( "Bird5.bmp" );  break;
            case 90:  img = load_image( "Bird6.bmp" );  break;
            case 108:  img = load_image( "Bird7.bmp" );  break;
            case 126:  img = load_image( "Bird8.bmp" );  break;
        }

        SDL_SetColorKey(img,SDL_SRCCOLORKEY,0xFF00FF);
        imgcount++;
    }

    apply_surface( x, y, img, screen );

    }
}




void Object::update(){
    /// old never call it

    static double T=.1;
    T+=.01;
    int oldx=loc.x;
    int oldy=loc.y;


    if(type==BIRD){
        loc.x+=ceil( 25*line.force* cos( line.direction ));
        loc.y-=ceil( 1* ( line.force*sin(line.direction)*T    +     9.8*T*T    -     19*T*T*T)   );
        if(loc.y<0)
            loc.y=0;
        if(loc.y>SCREEN_HEIGHT)
            loc.y=SCREEN_HEIGHT;
        line.direction=atan((loc.y-oldy)/(oldx-loc.x));
    }




//come back late, sleep now
}

void Object::update(Object *ob, int size){
    static double T=1;
    T+=.1;


    if(size==100){

        T=1;
        return;
    }

//makes the bird move
    if(type==BIRD){
     //   loc.x+=ceil(150*line.force* cos( line.direction ));
     //   loc.y-=ceil( ( 3* line.force*sin(line.direction)*T    -     .3 * T*T )   -     .3 * T*T*T   );
        if(loc.y>SCREEN_HEIGHT-200)
            line.force = line.force - .01;
        if(line.force < 0)
            line.force = 0;

         loc.x+=ceil(1*line.force* cos( line.direction ));
        loc.y-=ceil(1*line.force*sin(line.direction)*T - .245*T*T);
        // ( 3* line.force*sin(line.direction)*T    -    .3 * T*T ) - .2*T*T*T*T);
        if(loc.y<0)
            loc.y=0;
        if(loc.y>SCREEN_HEIGHT)
            loc.y=SCREEN_HEIGHT;
        //line.direction=atan((oldx-loc.x)/(loc.y-oldy));
    }


//collision detection and destruction, as well as gravity
    for(int i = 1; i < size; i++)
    {
            if(ob[0].loc.x  > ob[i].loc.x+41 )
            {
            if(ob[i].dead && ob[i].loc.y != ob[i+1].loc.y){
                for(int j=i+1;j<size;j++){
                    if(ob[i].loc.x == ob[j].loc.x){
                        ob[j].loc.y+=40;
                    }
                }

            }
        }
    }


}



void Object::setMass(double x){
    mass=x;
}


void Object::setScore(int x){
    score=x;

}


void Object::setLine(double force1,double direction1){
    line.force=force1;
    line.direction=direction1;
}


double Object::getMass(){
    return mass;
}


int Object::getScore(){
    return score;
}


vector Object::getLine(){
    return line;
}



SDL_Surface * Object::getimg(){
    return img;
}




void Object::impart_Force(double radian, double force){

  //double old_Direction    = line.direction;
  //  double old_Force        = line.force;
  //  double new_Direction    = atan(force/old_Force);

    // PI/2;
    // (old_Direction*old_Force)+(force*radian)/2;
    // ( line.direction + radian ) / 2;

   // double new_Force        = pow(force,2)+ pow(old_Force,2) - 2*force*old_Force*cos(new_Direction); // law of cosines

   // while(new_Force>1)
   //     new_Force/=10.0;

   // force*=120;
    line.force = force;
  //  line.force              = new_Force;
// line.direction          = new_Direction;
  //  line.direction = .15*PI;
    line.direction = radian;
}




bool Object::hasHit(Object obj){
    bool hit = false;
    int BX = loc.x;
    int BY = loc.y;
    int OX = obj.loc.x;
    int OY = obj.loc.y;

    if(BX<0)
        BX=0;
    if(BX>SCREEN_WIDTH)
        BX=SCREEN_WIDTH ;
    if(BY<0)
        BY=0;
    if(BY>SCREEN_HEIGHT-200)
        BY=SCREEN_HEIGHT-200;


    if(OX<0)
        OX=0;
    if(OX>SCREEN_WIDTH)
        OX=SCREEN_WIDTH ;
    if(OY<0)
        OY=0;
    if(OY>SCREEN_HEIGHT-200)
        OY=SCREEN_HEIGHT-200;


    if(abs(OX-BX)<=38 && abs(BY-OY)<=38){

        //impart_Force(atan((BY-OY)/(OX-BX)), sqrt(pow(BY-OY,2)+pow(OX-BX,2)));
        obj.dead = true;
        hit = true;

    }


    return hit;

}


SDL_Surface* load_image(string filename )
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





/**


void Object::update(){

    //double velocity=0;
    static double T=.1;
    T+=.01;
   // static double velocity=line.force*T/mass;

    //line.force=((line.force*T/mass)-9.8*T)*mass/T;
    int oldx=loc.x;
    int oldy=loc.y;


/// added mulitpliers and the T cubed and the direction recalaibrate



    loc.x+=ceil(55*line.force* cos( line.direction )*T/2);
    //if(loc.x>1200)
    //loc.x=1200;

//need a function to calculate new y position given our information...................................



    //new pos = old pos  + y change
    //loc.y += -velocity*sin(line.direction)*T + (1/2)*(9.8)*T*T;
    loc.y-=ceil( 30* ( line.force*sin(line.direction)*T    +     9.8*T*T    -     19*T*T*T)   );



    //-line.force/mass acceleration...

    //loc.y + velocity*sin(line.direction)*T - 4.9*T*T;
    //loc.y   +    velocity*sin(line.direction)  -  4.9*T*T;

    line.direction=atan((loc.y-oldy)/(loc.x-oldx));
  //  line.force =
    //=atan((oldy-loc.y)/(oldx-loc.x));
    //+=(velocity)*sin(line.direction)*T -4.9*T*T;
    //= loc.y+velocity - 9.8*T;


//come back late, sleep now
}


*/

