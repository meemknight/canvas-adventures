#include <SFML/Graphics.hpp>
#define gravity 9.81
#define Gameheight 160
#define Gamelenght 320
#include<cmath>
#include "blocks.h"
#include "enum.h"
#include "entities.h"
/*
extern sf::Vector2f playervelocity;
extern bool canjump;
extern playerentity player;
extern sf::Vector2f playerlastpos;
extern float deltatime;
extern bool movingright;
extern bool movingdown;
extern bl::blocks world[Gamelenght][Gameheight];

            int deltax;
            int deltay;
            int intersectx;
            int intersecty;

void moveplayer(){       ///movement
playervelocity.x*=0.1f;
//playervelocity.y*=0.0f;


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&canjump==1){playervelocity.y=-sqrtf(2.0f*gravity*32*150);canjump=0;}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){playervelocity.x=-300;}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){playervelocity.x=+300;}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){playervelocity.y=+300;}

            playervelocity.y=playervelocity.y+gravity*32*deltatime*2;
            playervelocity.y=std::min(playervelocity.y,(float)gravity*32);
           player.x=player.x+playervelocity.x*deltatime;
           player.y=player.y+playervelocity.y*deltatime;

            ///movement


            }
/*
void checkcollision(){
     canjump=0;
if(movingdown==0){
        for(int x=0;x<Gamelenght;x++)                      ///collision
            {
             for(int y=Gameheight;y>=0;y--)
                {
            if(world[x][y].family()!=bl::fragile)
                {
            deltax=x*32+16-player.getcenterx();
            deltay=y*32+16-player.getcentery();
            intersectx=std::abs(deltax)-(16+16);
            intersecty=std::abs(deltay)-(16+32);


canjump=0;
            if(intersectx<0.0f&&intersecty<0.0f)
                {
                if(abs(intersectx)<abs(intersecty))/// move on x
                    {
                        if(deltax<0)
                            {

                            player.x=x*32+32;
                                                                ///stanga
                            }else
                            {

                            player.x=x*32-32;

                            }



                    }else
                    {///move on y
                        if(deltay<0)
                            {

                            player.y=y*32+32;

                            }else

                            {
                            player.y=y*32-64;
                            canjump=1;
                            }


                    }


                }
            }

            }
        }}else
        {
         for(int x=0;x<Gamelenght;x++)                      ///collision
            {
             for(int y=0;y<Gameheight;y++)
                {
            if(world[x][y].family()!=bl::fragile)
                {
            deltax=x*32+16-player.getcenterx();
            deltay=y*32+16-player.getcentery();
            intersectx=std::abs(deltax)-(16+16);
            intersecty=std::abs(deltay)-(16+32);



            if(intersectx<0.0f&&intersecty<0.0f)
                {
                if(abs(intersectx)<abs(intersecty))/// move on x
                    {
                        if(deltax<0)
                            {

                            player.x=x*32+32;
                                                                ///stanga
                            }else
                            {

                            player.x=x*32-32;

                            }



                    }else
                    {///move on y
                        if(deltay<0)
                            {

                            player.y=y*32+32;

                            }else

                            {
                            player.y=y*32-64;
                            canjump=1;
                            }


                    }


                }
            }

            }
        }


        }

}
void fixplayerscreen(){   if(player.x<0){player.x=0;}
            if(player.x+32>32*Gamelenght){player.x=32*Gamelenght-32;}
            if(player.y<-2){player.y=-2;}
            if(player.y+64>32*Gameheight){player.y=32*Gameheight-64;}}
void setplayerlastposition(){ playerlastpos.x=player.x;
            playerlastpos.y=player.y;
}
*/
