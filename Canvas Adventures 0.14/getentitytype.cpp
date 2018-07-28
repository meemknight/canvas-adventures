#include <SFML/Graphics.hpp>
#include "entities.h"
#include "enum.h"
#include "headerfiles/declarations.h"
extern sf::Texture slimetxture;
extern sf::Texture blueslimetxture;
extern sf::Texture iceslimetexture;
extern sf::Texture sandslimetexture;
extern sf::Texture smallblueslimetexture;
extern sf::Texture zombietexture;
extern sf::Texture mumytexture;
extern sf::Texture eschimotexture;

namespace et{

humanlikeenemy gethumanlikeenemy(uint8_t type)
{
    humanlikeenemy ent;

    switch(type)
    {
    case et::normal_zombie:
    ent.type=et::normal_zombie;
        ent.sprite.setTexture(zombietexture);
        ent.sizeofentity.x=32;
        ent.sizeofentity.y=64;
        ent.lineofsight=randomrange(12,16);
        ent.frametime=1.0/10.0;
        ent.jumpheight.x=randomrange(110,130);
        ent.jumpheight.y=0;
        ent.speed.x=randomrange(90,120);
        ent.speed.y=0;
        ent.maxlife=randomrange(40,80);
        ent.life=ent.maxlife;
        ent.attatc=randomrange(8,12);
    break;

    case et::mumy:
        ent.type=et::mumy;
        ent.sprite.setTexture(mumytexture);
        ent.sizeofentity.x=32;
        ent.sizeofentity.y=64;
        ent.lineofsight=randomrange(12,18);
        ent.frametime=1.0/10.0;
        ent.jumpheight.x=randomrange(110,130);
        ent.jumpheight.y=0;
        ent.speed.x=randomrange(100,140);
        ent.speed.y=0;
        ent.maxlife=randomrange(60,120);
        ent.life=ent.maxlife;
        ent.attatc=randomrange(10,22);
    break;

     case et::zombie_eschimo:
        ent.type=et::zombie_eschimo;
        ent.sprite.setTexture(eschimotexture);
        ent.sizeofentity.x=32;
        ent.sizeofentity.y=64;
        ent.lineofsight=randomrange(14,19);
        ent.frametime=1.0/10.0;
        ent.jumpheight.x=randomrange(110,130);
        ent.jumpheight.y=0;
        ent.speed.x=randomrange(100,140);
        ent.speed.y=0;
        ent.maxlife=randomrange(70,120);
        ent.life=ent.maxlife;
        ent.attatc=randomrange(12,20);


    break;

    }

return ent;
}





slimeentity getslime(uint8_t type)
{
    slimeentity ent;

switch(type)
    {
    case et::slime:
        {

        }break;

    case et::green_slime:
        {
        ent.type=et::green_slime;
      //  ent.whaittime=2;
        ent.sprite.setTexture(slimetxture);
        ent.sizeofentity.x=32;
        ent.sizeofentity.y=32;
        ent.lineofsight=10;
        ent.frametime=1.0/10.0;
        ent.jumpheight.x=120;
        ent.jumpheight.y=160;
        ent.speed.x=50;
        ent.speed.y=300;
        ent.maxlife=randomrange(20,40);
        ent.life=ent.maxlife;
        ent.attatc=6;

        }break;

    case et::speedy_green_slime:{
        ent.type=et::speedy_green_slime;
       // ent.whaittime=2;
        ent.sprite.setTexture(slimetxture);
        ent.sizeofentity.x=32;
        ent.sizeofentity.y=32;
        ent.lineofsight=20;
        ent.frametime=1.0/30.0;
        ent.jumpheight.x=120;
        ent.jumpheight.y=160;
        ent.speed.x=100;
        ent.speed.y=600;
        ent.maxlife=randomrange(30,50);
        ent.life=ent.maxlife;
        ent.attatc=7;
        }break;

   case et::ice_slime:
        {
        ent.type=et::ice_slime;
      //  ent.whaittime=2;
        ent.sprite.setTexture(iceslimetexture);
        ent.sizeofentity.x=32;
        ent.sizeofentity.y=32;
        ent.lineofsight=12;
        ent.frametime=1.0/5.0;
        ent.jumpheight.x=100;
        ent.jumpheight.y=120;
        ent.speed.x=10;
        ent.speed.y=400;
        ent.maxlife=randomrange(60,100);
        ent.life=ent.maxlife;
        ent.attatc=2;
        }break;

    case et::speedy_ice_slime:
        {
        ent.type=et::ice_slime;
      //  ent.whaittime=2;
        ent.sprite.setTexture(iceslimetexture);
        ent.sizeofentity.x=32;
        ent.sizeofentity.y=32;
        ent.lineofsight=16;
        ent.frametime=1.0/10.0;
        ent.jumpheight.x=100;
        ent.jumpheight.y=140;
        ent.speed.x=10;
        ent.speed.y=500;
        ent.maxlife=randomrange(60,110);
        ent.life=ent.maxlife;
        ent.attatc=3;
        }break;


         case et::small_blue_slime:
        {
        ent.type=et::small_blue_slime;
      //  ent.whaittime=2;
        ent.sprite.setTexture(smallblueslimetexture);
        ent.sizeofentity.x=32;
        ent.sizeofentity.y=32;
        ent.lineofsight=12;
        ent.frametime=1.0/10.0;
        ent.jumpheight.x=90;
        ent.jumpheight.y=110;
        ent.speed.x=100;
        ent.speed.y=350;
        ent.maxlife=randomrange(20,25);
        ent.life=ent.maxlife;
        ent.attatc=4;
        }break;

    case et::blue_slime:
        {
        ent.type=et::blue_slime;
      //  ent.whaittime=2;
        ent.sprite.setTexture(blueslimetxture);
        ent.sizeofentity.x=48;
        ent.sizeofentity.y=48;
        ent.lineofsight=12;
        ent.frametime=1.0/10.0;
        ent.jumpheight.x=100;
        ent.jumpheight.y=120;
        ent.speed.x=50;
        ent.speed.y=400;
        ent.maxlife=randomrange(30,60);
        ent.life=ent.maxlife;
        ent.attatc=10;
        }break;

        case et::sand_slime:
        {
        ent.type=et::sand_slime;
      //  ent.whaittime=2;
        ent.sprite.setTexture(sandslimetexture);
        ent.sizeofentity.x=32;
        ent.sizeofentity.y=32;
        ent.lineofsight=12;
        ent.frametime=1.0/8.0;
        ent.jumpheight.x=90;
        ent.jumpheight.y=110;
        ent.speed.x=50;
        ent.speed.y=300;
        ent.maxlife=randomrange(10,25);
        ent.life=ent.maxlife;
        ent.attatc=10;
        }break;

    case et::speedy_sand_slime:
        {
        ent.type=et::sand_slime;
      //  ent.whaittime=2;
        ent.sprite.setTexture(sandslimetexture);
        ent.sizeofentity.x=32;
        ent.sizeofentity.y=32;
        ent.lineofsight=16;
        ent.frametime=1.0/8.0;
        ent.jumpheight.x=90;
        ent.jumpheight.y=150;
        ent.speed.x=50;
        ent.speed.y=300;
        ent.maxlife=randomrange(15,30);
        ent.life=ent.maxlife;
        ent.attatc=10;
        }break;

    case et::speedy_blue_slime:
        {

        ent.type=et::blue_slime;
       // ent.whaittime=2;
        ent.sprite.setTexture(blueslimetxture);
        ent.sizeofentity.x=48;
        ent.sizeofentity.y=48;
        ent.lineofsight=20;
        ent.frametime=1.0/20.0;
        ent.jumpheight.x=120;
        ent.jumpheight.y=140;
        ent.speed.x=100;
        ent.speed.y=400;
        ent.maxlife=randomrange(40,70);
        ent.life=ent.maxlife;
        ent.attatc=14;
        }break;
    }
    return ent;
}

};
/*
        slime.whaittime=2;
        slimetxture=loadfiles("slime.png");
        slime.sprite.setTexture(slimetxture);
slime.x=60*32;
slime.y=7*32;
slime.animationstate=0;
slime.sizeofentity.x=32;
slime.sizeofentity.y=32;
slime.lineofsight=8;

slime.frametime=1.0/15.0;

*/
