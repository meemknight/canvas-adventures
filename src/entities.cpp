#include "entities.h"
#include <iostream>
int randomrange(int min_val,int max_val);
bool randompercent(float chance);


using namespace std;
extern float deltatime;
extern entities player;

entities::entities()
{
       x=0;y=0;
       totalframetime=0;
     animationposition=0;
    //ctor
}
entities::entities(float x_, float y_)
{
    x=x_;y=y_;
     totalframetime=0;
     animationposition=0;
}



playerentity::playerentity()
{
   x=0;y=0;
    totalframetime=0;
     animationposition=0;
     maxlife=100;
     life=maxlife;
}

playerentity::playerentity(float x_, float y_)
{
    x=x_;y=y_;
     totalframetime=0;
     animationposition=0;
}
///^ctor


float entities::getcenterx()
{
    return x+sizeofentity.x/2;
}

float entities::getcentery()
{
    return y+sizeofentity.y/2;
}



void entities::draw(sf::RenderWindow &window,float deltatime,int add)
{


    if(invurnerabilitytime>0)
        {
        invurnerabilitytime-=deltatime;
        sprite.setColor(sf::Color(255,10,10));
        }else{invurnerabilitytime=0;}

         if(frosttime>0)
        {
        frosttime-=deltatime;
        sprite.setColor(sf::Color(10,10,255));
        }else{frosttime=0;}


        uint8_t numberofframes=sprite.getTexture()->getSize().x/sizeofentity.x;

    if(numberofframes!=1){
totalframetime+=deltatime;
if(totalframetime>frametime)
    {
    animationposition++;
if(animationposition>numberofframes-1){animationposition=0;}
totalframetime=0;
    }
}else{animationposition=0;}
animationstate+=add;
if(movingright)
{
sprite.setTextureRect(sf::IntRect(sizeofentity.x*animationposition,sizeofentity.y*animationstate,sizeofentity.x,sizeofentity.y));
}else
{
sprite.setTextureRect(sf::IntRect(sizeofentity.x*(animationposition+1),sizeofentity.y*animationstate,-sizeofentity.x,sizeofentity.y));
}

    sprite.setPosition(x,y);
    window.draw(sprite);
    sprite.setColor(sf::Color::White);
}



bool entities::operator==(entities other)
{           /*
            int deltax=other.x+other.getcenterx()-getcenterx();
            int deltay=other.y+other.getcentery()-getcentery();
            int intersectx=abs(deltax)-(getcenterx()+other.getcenterx());
            int intersecty=abs(deltay)-(getcentery()+other.getcentery());
            if(intersectx<0.0f&&intersecty<0.0f)return 1;else return 0;
            */

            int deltax=getcenterx()-other.getcenterx();
            int deltay=getcentery()-other.getcentery();
            int intersectx=abs(deltax)-(other.sizeofentity.x/2+sizeofentity.x/2);
            int intersecty=abs(deltay)-(other.sizeofentity.y/2+sizeofentity.y/2);


            if(intersectx<0.0f&&intersecty<0.0f)return 1;else return 0;



}

bool entities::operator==(sf::Vector2u other)
{       /*
        int deltax=other.x*32+16-getcenterx();
        int deltay=other.y*32+16-getcentery();
        int intersectx=abs(deltax)-(getcenterx()+other.x*32+16);
        int intersecty=abs(deltay)-(getcentery()+other.y*32+16);
        if(intersectx<0.0f&&intersecty<0.0f)return 1;else return 0;
        */

        int deltax=getcenterx()-other.x*32-16;
        int deltay=getcentery()-other.y*32-16;
        int intersectx=abs(deltax)-(16+sizeofentity.x/2);
        int intersecty=abs(deltay)-(16+sizeofentity.y/2);

        if(intersectx<0.0f&&intersecty<0.0f)return 1;else return 0;


}

enemy::enemy(){};

bool enemy::checktime()
{if(time.getElapsedTime().asSeconds()>1){time.restart();}
    livetime-=time.getElapsedTime().asSeconds();
    time.restart();
    if(livetime<0){return 0;}else{return 1;}

}


/*
void slimeentity::makemove(entities other)
{
            if(canjump){animationstate=0;}else{animationstate=1;}


    timetillnextmove+=deltatime;
if(timetillnextmove>whaittime)
    {
        if(randompercent(30)){if(movingright)movingright=0;else movingright=1;}

        if(canjump)velocity.y=-sqrtf(2.0f*9.81*32*randomrange(jumpheight.x,jumpheight.y));
    timetillnextmove=0;
    tempmovespeed=randomrange(speed.x,speed.y);
           if(std::abs(other.x-x)<32*lineofsight)//check player
            {
            whaittime=randomrange(4,5)/2.f;
if(other.x<x)movingright=0;
if(other.x>x)movingright=1;

            }else{ whaittime=randomrange(5,6)/2.f;}
    }

    ///jump^

    if(!canjump)
    {
           if(movingright){velocity.x+=tempmovespeed;}///move randomly
           else{velocity.x-=tempmovespeed;}
    }


}
*/
