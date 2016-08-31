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



/// hey guys dont edit this file///
///     -lmingw32 -lSDLmain -lSDL      ////

#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

using namespace std;

//#include "SDL/SDL.h"
#include "SDL/SDL.h"

//#include "SDL/SDL_TTF.h"
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>



const double GRAVITY = 10.0;
const double PI = 3.14;

const int CIRCLE = 0;
const int SQUARE = 1;
const int RECTANGLE = 2;

const int BIRD  = 0;
const int BRICK = 1;
const int PIG   = 2;

const double BIRD_MASS = 0.5;
const double BRICK_MASS = 0.2;
const double PIG_MASS = 0.1;

//The attributes of the screen
const int SCREEN_WIDTH =  1280; // 640
const int SCREEN_HEIGHT = 960; // 480
const int SCREEN_BPP = 32;






struct point{
    int x;
    int y;
};

struct circle{
    point p;
    double radius; /// radius wont be too big umm 15 pixels? or an int

};

struct vector{
    double force; /// goes from 0.0 to 1.0
    double direction; /// goes from 0.0 to 6.28 (AKA 2PI)

};

static int counter = 0;



    SDL_Surface* load_image(string filename );

    void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );

class Object{
protected:

    int shape;
    int id;
    int type;

    int imgcount;

    double mass; /// goes from 0.0 to 1.0
    vector line;
    int score;   /// value if destroyed


    SDL_Surface * img;



public:

    point loc;
    bool dead;
    int hitCount;

    void setShape(int);
    void setId(int);
    void setType(int);
    int  getShape();
    int  getId();
    int  getType();


    void draw(int x,int y, SDL_Surface *screen);


    void update();
    void update(Object *ob, int size);
    void setMass(double);
    void setScore(int);
    void setLine(double,double);
    double getMass();
    int getScore();
    vector getLine();

    SDL_Surface* getimg();



    void impart_Force(double radian, double force);

    bool hasHit(Object obj);


};

#endif // OBJECT_H_INCLUDED

