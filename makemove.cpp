#include <SFML/Graphics.hpp>
#include "headerfiles/declarations.h"
#include "entities.h"
#include "enum.h"
#include "blocks.h"

extern float deltatime;
extern bl::blocks world[Gamelenght][Gameheight];

int moves=0;
void makemove(humanlikeenemy& ent,entities other)
{
    if(ent.animationstate!=humanlikeenemy::attacking)
        {
         ent.animationstate=0;
        }
    ent.moving=0;


if(ent.frosttime<=0)
    {

    ent.jumpwhaittime-=deltatime;


    if(abs(ent.x-other.x)<ent.lineofsight*32)
        {
                   if(abs(other.x-ent.x)>25)       ///near the player
           {
                         if(other.x>ent.x)
                {
                ent.velocity.x+=ent.speed.x;
                ent.movingright=1;
                ent.headingright=1;
                ent.timemove=randomrange(4,10);
                ent.movedesire=1;
                ent.moving=1;
                }else
                {
                ent.velocity.x-=ent.speed.x;
                ent.movingright=0;
                ent.headingright=0;
                ent.timemove=randomrange(4,10);
                ent.movedesire=1;
                ent.moving=1;
                }
           }

            if(other.y+64<ent.y)   ///jump to player
                {
                   if(ent.canjump&&ent.jumpwhaittime<=0)
                        {
                         ent.velocity.y=-sqrtf(2.0f*9.81*32*ent.jumpheight.x);ent.canjump=0;
                        ent.jumpwhaittime=randomrange(2,5);
                        }
                }



            if(ent.moving)
            if(ent.movingright)     ///jump over gaps
                {
                     if(world[ent.x/32+1][(ent.y+ent.sizeofentity.y)/32].family()==bl::varation::fragile )
                        if(ent.canjump)
                            {
                             ent.velocity.y=-sqrtf(2.0f*9.81*32*ent.jumpheight.x);ent.canjump=0;
                            }
                }else
                {
                    if(world[ent.x/32-1][(ent.y+ent.sizeofentity.y)/32].family()==bl::varation::fragile )
                            if(ent.canjump)
                                {
                                 ent.velocity.y=-sqrtf(2.0f*9.81*32*ent.jumpheight.x);ent.canjump=0;
                                }
                }




            if(ent.y+64<=other.y){ent.down_pressed=1;}else{ent.down_pressed=0;}



            if(world[ent.x/32+1][ent.y/32].family()==bl::varation::blocy|| ///jump over walls
               world[ent.x/32-1][ent.y/32].family()==bl::varation::blocy||
               world[ent.x/32+1][ent.y/32+1].family()==bl::varation::blocy||
               world[ent.x/32-1][ent.y/32+1].family()==bl::varation::blocy
               )
            if(ent.jumpwhaittime<=0)///jump
                {
                    if(ent.canjump)
                        {
                         ent.velocity.y=-sqrtf(2.0f*9.81*32*ent.jumpheight.x);ent.canjump=0;
                        ent.jumpwhaittime=randomrange(2,3);
                        }


                }


        }else   ///no one
        {
               if(ent.moving)
            if(ent.movingright)     ///jump over gaps
                {
                     if(world[ent.x/32+1][(ent.y+ent.sizeofentity.y)/32].family()==bl::varation::fragile )
                        if(ent.canjump)
                            {
                             ent.velocity.y=-sqrtf(2.0f*9.81*32*ent.jumpheight.x);ent.canjump=0;
                            }
                }else
                {
                    if(world[ent.x/32-1][(ent.y+ent.sizeofentity.y)/32].family()==bl::varation::fragile )
                            if(ent.canjump)
                                {
                                 ent.velocity.y=-sqrtf(2.0f*9.81*32*ent.jumpheight.x);ent.canjump=0;

                                }
                }








            if(world[ent.x/32+1][ent.y/32].family()==bl::varation::blocy|| ///jump over walls
               world[ent.x/32-1][ent.y/32].family()==bl::varation::blocy||
               world[ent.x/32+1][ent.y/32+1].family()==bl::varation::blocy||
               world[ent.x/32-1][ent.y/32+1].family()==bl::varation::blocy
               )
            if(ent.jumpwhaittime<=0)///jump
                {
                    if(ent.canjump)
                        {
                         ent.velocity.y=-sqrtf(2.0f*9.81*32*ent.jumpheight.x);ent.canjump=0;
                        ent.jumpwhaittime=randomrange(2,4);
                        }


                }//////jump


            ent.timemove-=deltatime;

            if(ent.movedesire)///move
                {

                    if(ent.headingright)
                        {
                        ent.velocity.x+=ent.speed.x;
                        ent.movingright=1;
                        ent.moving=1;
                        }else
                        {
                        ent.velocity.x-=ent.speed.x;
                        ent.movingright=0;
                        ent.moving=1;
                        }


                    if(ent.timemove<=0)
                        {
                        ent.timemove=randomrange(2,7);
                        ent.movedesire=0;
                        }


                }else
                {
                    if(ent.timemove<=0)
                        {
                        ent.timemove=randomrange(2,12);
                        ent.movedesire=1;
                        ent.headingright=randomrange(0,1);
                        }

                }


        }



    }




        if(ent.animationstate!=humanlikeenemy::attacking)
        {
             if(ent.moving){ent.animationstate=1;}else
            {ent.animationstate=0;}
        }


      if(!ent.canjump){ent.animationstate=humanlikeenemy::jumping;}
}


void makemove(slimeentity& ent,entities other)
{

if(ent.frosttime<=0)
    {

    //if(ent.type==et::slime||ent.type==et::blue_slime||ent.type==et::speedy_green_slime||ent.type==et::speedy_blue_slime)
      //  {
       if(ent.canjump){ent.animationstate=0;}else{ent.animationstate=1;}


    ent.timetillnextmove+=deltatime;
if(ent.timetillnextmove>ent.whaittime)
    {moves++;
          if(other.y>ent.y)
                {
                ent.down_pressed=1;
                }else{ent.down_pressed=0;}


        if(randompercent(30)){if(ent.movingright)ent.movingright=0;else ent.movingright=1;}

        if(ent.canjump)
            {ent.velocity.y=-sqrtf(2.0f*9.81*32*randomrange(ent.jumpheight.x,ent.jumpheight.y));

            }
    ent.timetillnextmove=0;
    ent.tempmovespeed=randomrange(ent.speed.x,ent.speed.y);
           if(std::abs(other.x-ent.x)<32*ent.lineofsight)//check player
            {
            ent.whaittime=randomrange(4,6)/2.f;
if(other.x<ent.x)ent.movingright=0;
if(other.x>ent.x)ent.movingright=1;


            }else{ ent.whaittime=randomrange(8,12)/2.f;}
    }

    ///jump^

    if(!ent.canjump)
    {




           if(ent.movingright){ent.velocity.x+=ent.tempmovespeed;}///move randomly
           else{ent.velocity.x-=ent.tempmovespeed;}



    }
   // }
    }
}
