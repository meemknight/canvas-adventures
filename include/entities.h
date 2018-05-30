#ifndef ENTITIES_H
#define ENTITIES_H
#include <SFML/Graphics.hpp>
#include<iostream>
using std::cout;

class entities
{
    public:
        entities();
        entities(float x_,float y_);

    float invurnerabilitytime=0;
    float frosttime=0;

    float life;
    float maxlife;
    int x;   ///
    int y;
    int highestpoint=320*32;
    int falltolerance=10;
    sf::Vector2f velocity;
    sf::Vector2u sizeofentity;
    sf::Sprite sprite;
    uint8_t animationstate;
    float frametime;
   // void animate(float deltatime);
    bool canjump;
    bool moving;
    bool movingright;
    bool movingdown;
    sf::Vector2i lastpos;   ///
float getcenterx();
    float getcentery();
    bool operator==(entities other);
    bool operator==(sf::Vector2u other);
    bool down_pressed=0;


   virtual void draw(sf::RenderWindow &window,float deltatime,int add=0);


    protected:
    uint8_t animationposition;///=0
    float totalframetime;///=0


};

class playerentity:public entities
{
    public:

    sf::Vector2i spawnpoint;

    playerentity();
    playerentity(float x,float y);


};
class enemy:public entities
{
public:

     sf::Vector2i jumpheight;
    sf::Vector2i speed;
    unsigned int type;
    int lineofsight;
    enemy();
    float attatc;

    float livetime=15;
    sf::Clock time;

    //virtual void makemove(entities other){};
    bool checktime();
};

class slimeentity:public enemy
{
public:slimeentity(){tempmovespeed=0;};


    float whaittime=0;
   // void makemove(entities other);


    float timetillnextmove;
    int tempmovespeed;
};

class humanlikeenemy:public enemy
{
public:

    enum animationstates
    {
    idle,
    walking,
    jumping,
    attacking
    };

    humanlikeenemy(){};

    float jumpwhaittime=0;
    bool headingright=0;
    float timemove=0;
    bool movedesire=0;

};





#endif // ENTITIES_H




