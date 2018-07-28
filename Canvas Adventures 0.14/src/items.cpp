#include "items.h"
#include "blocks.h"
#include "enum.h"
#include "entities.h"

#include "../headerfiles/declarations.h"

#define INVENTORY_SIZE 30

extern float deltatime;
extern bl::blocks world[Gamelenght][Gameheight];
extern playerentity player;
extern items* inventory[INVENTORY_SIZE];


normalitems::normalitems()
{
    type=0;
    maxnumber=225;
    number=0;
}
/*

normalitems::normalitems(int type_)
{
    type=type_;
    maxnumber=225;
    number=100;

}*/

normalitems::normalitems(int type_,int number_)
{
    type=type_;
    maxnumber=225;
    number=number_;

}




nonplaceble::nonplaceble()
{
    type=0;
   // maxnumber=225;
   setmaxnumber();
  // maxnumber=64;
    number=0;
}
/*
nonplaceble::nonplaceble(int type_)
{
    type=type_;
   // maxnumber=225;
      setmaxnumber();
    number=1;
}*/

nonplaceble::nonplaceble(int type_,int number_)
{
    type=type_;
   // maxnumber=225;
      setmaxnumber();
        // maxnumber=64;

    number=number_;
}

int nonplaceble::getpickaxepower()
{
    switch(type)
    {
    case items::name::wodden_pickaxe: return 20; break;
    case items::name::stone_pickaxe: return 40; break;
    case items::name::copper_pickaxe: return 60; break;
    case items::name::steel_pickaxe: return 70; break;
    case items::name::gold_pickaxe: return 100; break;
    default: return 0;
    }
}

int nonplaceble::getaxepower()
{
     switch(type)
    {
    case items::name::wodden_axe: return 20; break;
    case items::name::stone_axe: return 40; break;
    case items::name::copper_axe: return 70; break;
    case items::name::steel_axe: return 90; break;
   case items::name::gold_axe: return 140; break;
       default: return 0;

    }
}
int nonplaceble::gethammerpower()
{
       switch(type)
    {
    case items::name::wodden_hammer: return 20; break;
    case items::name::stone_hammer: return 40; break;
    case items::name::copper_hammer: return 60; break;
    case items::name::steel_hammer: return 70; break;
   case items::name::gold_hammer: return 100; break;
       default: return 0;

    }

}
float nonplaceble::getfreeztime()
{
    switch(type)
    {
    case items::name::icemace: return 2;break;
    case items::name::frost_dagger: return 1;break;
    default: return 0;
    }

}

float nonplaceble::getspeed()
{
        switch(type)
        {

         case items::name::wodden_pickaxe: return 3; break;
    case items::name::stone_pickaxe: return 3; break;
    case items::name::copper_pickaxe: return 3; break;
    case items::name::steel_pickaxe: return 3; break;
    case items::name::gold_pickaxe: return 3; break;

    case items::name::wodden_hammer: return 4; break;
    case items::name::stone_hammer: return 4; break;
    case items::name::copper_hammer: return 4; break;
    case items::name::steel_hammer: return 4; break;
   case items::name::gold_hammer: return 4; break;

      case items::name::wodden_axe: return 3; break;
    case items::name::stone_axe: return 3; break;
    case items::name::copper_axe: return 3; break;
    case items::name::steel_axe: return 3; break;
   case items::name::gold_axe: return 3; break;

     case items::name::wodden_sword: return 3; break;
    case items::name::stone_sword: return 3; break;
    case items::name::copper_sword: return 1; break;
    case items::name::iron_sword: return 1; break;
   case items::name::gold_sword: return 1; break;

    case items::name::copper_spear:return 4; break;
   case items::name::iron_spear:return 4; break;
   case items::name::golden_spear:return 3; break;

    case items::name::icemace: return 4;break;

    case items::name::copper_dagger: return 1;break;
    case items::name::iron_dagger: return 1;break;
    case items::name::frost_dagger: return 1;break;

        default: return 2;
        }


};

int nonplaceble::getattackpower()
{
      switch(type)
    {
    case items::name::wodden_pickaxe: return 1; break;
    case items::name::stone_pickaxe: return 3; break;
    case items::name::copper_pickaxe: return 5; break;
    case items::name::steel_pickaxe: return 6; break;
    case items::name::gold_pickaxe: return 9; break;

    case items::name::wodden_hammer: return 2; break;
    case items::name::stone_hammer: return 4; break;
    case items::name::copper_hammer: return 6; break;
    case items::name::steel_hammer: return 7; break;
   case items::name::gold_hammer: return 10; break;

      case items::name::wodden_axe: return 2; break;
    case items::name::stone_axe: return 4; break;
    case items::name::copper_axe: return 6; break;
    case items::name::steel_axe: return 7; break;
   case items::name::gold_axe: return 10; break;

     case items::name::wodden_sword: return 4; break;
    case items::name::stone_sword: return 7; break;
    case items::name::copper_sword: return 10; break;
    case items::name::iron_sword: return 12; break;
   case items::name::gold_sword: return 14; break;

    case items::name::copper_spear:return 9; break;
   case items::name::iron_spear:return 11; break;
   case items::name::golden_spear:return 13; break;

    case items::name::icemace: return 7;break;

    case items::name::copper_dagger: return 5;break;
    case items::name::iron_dagger: return 7;break;
    case items::name::frost_dagger: return 7;break;


       default: return 0;
    }


}

bool nonplaceble::splashattack()
{
  switch(type)
    {
    case items::name::wodden_pickaxe: return 1; break;
    case items::name::stone_pickaxe: return 1; break;
    case items::name::copper_pickaxe: return 1; break;
    case items::name::steel_pickaxe: return 1; break;
    case items::name::gold_pickaxe: return 1; break;

    case items::name::wodden_hammer: return 1; break;
    case items::name::stone_hammer: return 1; break;
    case items::name::copper_hammer: return 1; break;
    case items::name::steel_hammer: return 1; break;
   case items::name::gold_hammer: return 1; break;

      case items::name::wodden_axe: return 1; break;
    case items::name::stone_axe: return 1; break;
    case items::name::copper_axe: return 1; break;
    case items::name::steel_axe: return 1; break;
   case items::name::gold_axe: return 1; break;

     case items::name::wodden_sword: return 1; break;
    case items::name::stone_sword: return 1; break;
    case items::name::copper_sword: return 1; break;
    case items::name::iron_sword: return 1; break;
   case items::name::gold_sword: return 1; break;

    case items::name::icemace: return 0;break;


       default: return 0;

    }
}

int nonplaceble::getknockback()
{
      switch(type)
    {
    case items::name::wodden_pickaxe: return 2; break;
    case items::name::stone_pickaxe: return 3; break;
    case items::name::copper_pickaxe: return 4; break;
    case items::name::steel_pickaxe: return 5; break;
    case items::name::gold_pickaxe: return 6; break;

    case items::name::wodden_hammer: return 4; break;
    case items::name::stone_hammer: return 5; break;
    case items::name::copper_hammer: return 6; break;
    case items::name::steel_hammer: return 7; break;
   case items::name::gold_hammer: return 8; break;

      case items::name::wodden_axe: return 3; break;
    case items::name::stone_axe: return 4; break;
    case items::name::copper_axe: return 5; break;
    case items::name::steel_axe: return 6; break;
   case items::name::gold_axe: return 7; break;

     case items::name::wodden_sword: return 4; break;
    case items::name::stone_sword: return 5; break;
    case items::name::copper_sword: return 5; break;
    case items::name::iron_sword: return 6; break;
   case items::name::gold_sword: return 7; break;

   case items::name::copper_spear:return 7; break;
   case items::name::iron_spear:return 8; break;
   case items::name::golden_spear:return 9; break;

    case items::name::icemace: return 5;break;

      case items::name::copper_dagger: return 2;break;
    case items::name::iron_dagger: return 2;break;
    case items::name::frost_dagger: return 2;break;


       default: return 0;
    }


}


float nonplaceble::range()
{
      switch(type)
    {
    case items::name::wodden_pickaxe: return 2; break;
    case items::name::stone_pickaxe: return 2; break;
    case items::name::copper_pickaxe: return 2; break;
    case items::name::steel_pickaxe: return 2; break;
    case items::name::gold_pickaxe: return 2; break;

    case items::name::wodden_hammer: return 2; break;
    case items::name::stone_hammer: return 2; break;
    case items::name::copper_hammer: return 2; break;
    case items::name::steel_hammer: return 2; break;
   case items::name::gold_hammer: return 2; break;

      case items::name::wodden_axe: return 2; break;
    case items::name::stone_axe: return 2; break;
    case items::name::copper_axe: return 2; break;
    case items::name::steel_axe: return 2; break;
   case items::name::gold_axe: return 2; break;

     case items::name::wodden_sword: return 3; break;
    case items::name::stone_sword: return 3; break;
    case items::name::copper_sword: return 3; break;
    case items::name::iron_sword: return 3; break;
   case items::name::gold_sword: return 3; break;

    case items::name::copper_spear:return 5; break;
   case items::name::iron_spear:return 5; break;
   case items::name::golden_spear:return 5; break;

   case items::name::icemace: return 3;break;

     case items::name::copper_dagger: return 2;break;
    case items::name::iron_dagger: return 2;break;
    case items::name::frost_dagger: return 3;break;

       default: return 0;
    }


}

  void nonplaceble::setmaxnumber()
    {
        switch(type)
        {
        case items::name::goo:maxnumber=64;break;
        case items::name::copper_bar:maxnumber=64;break;
        case items::name::steel_bar:maxnumber=64;break;
        case items::name::gold_bar:maxnumber=64;break;
        case items::name::ruby:maxnumber=64;break;
        case items::name::healthbottle:maxnumber=30;break;
        case items::name::misseltoe:maxnumber=64;break;
        case items::name::apple:maxnumber=64;break;
        case items::name::paper:maxnumber=64;break;
        case items::name::book:maxnumber=64;break;
        case items::name::bone:maxnumber=64;break;
        case items::name::slime_skull:maxnumber=64;break;
        case items::name::shuriken:maxnumber=64;break;
      //  case items::name::goo: maxnumber=64;



        default: maxnumber=1;
        }

    }

    int nonplaceble::wearable()
        {
            switch(type)
            {
            case items::name::copper_helmet: return 1;break;
            case items::name::copper_armour: return 2;break;
            case items::name::copper_leggings: return 3;break;
            case items::name::iron_helmet: return 1;break;
            case items::name::iron_armour: return 2;break;
            case items::name::iron_leggings: return 3;break;
            case items::name::gold_helmet: return 1;break;
            case items::name::gold_armour: return 2;break;
            case items::name::gold_leggings: return 3;break;
            case items::name::party_hat: return 1;break;
            case items::name::sun_glasses: return 1;break;
             case items::name::ice_helmet: return 1;break;
            case items::name::ice_armour: return 2;break;
            case items::name::ice_leggings: return 3;break;
            case items::name::slime_shoes:return 3;break;
            default: return 0;
            }
        }

    int nonplaceble::getarmour()
    {
        return ::getarmour(type);
    }

    int getarmour(int type)
    {
        switch(type)
            {
            case items::name::copper_helmet: return 1;break;
            case items::name::copper_armour: return 1;break;
            case items::name::copper_leggings: return 1;break;
            case items::name::iron_helmet: return 2;break;
            case items::name::iron_armour: return 3;break;
            case items::name::iron_leggings: return 2;break;
            case items::name::gold_helmet: return 3;break;
            case items::name::gold_armour: return 4;break;
            case items::name::gold_leggings: return 3;break;
            case items::name::ice_helmet: return 3;break;
            case items::name::ice_armour: return 3;break;
            case items::name::ice_leggings: return 2;break;
            default: return 0;
            }
    }

    int nonplaceble::getfalldamagerezistance()
    {
        return ::getfalldamagerezistance(type);
    }

    int getfalldamagerezistance(int type)
    {
         switch(type)
            {
            case items::name::copper_helmet: return 2;break;
            case items::name::copper_armour: return 2;break;
            case items::name::copper_leggings: return 4;break;
            case items::name::iron_helmet: return 3;break;
            case items::name::iron_armour: return 3;break;
            case items::name::iron_leggings: return 6;break;
            case items::name::gold_helmet: return 4;break;
            case items::name::gold_armour: return 4;break;
            case items::name::gold_leggings: return 8;break;
            case items::name::ice_helmet: return 6;break;
            case items::name::ice_armour: return 6;break;
            case items::name::ice_leggings: return 12;break;
            case items::name::slime_shoes: return -1;break;
            default: return 0;
            }
    }


droppeditem::droppeditem(bool placeble, int type_)
{

    if(placeble)
    {
    item=new normalitems(type_,1);
    }else
    {
    item=new nonplaceble(type_,1);
    }
time=100;

}

droppeditem::droppeditem(bool placeble, int type_, int x, int y,int number)
{
    if(placeble)
    {
    item=new normalitems(type_,number);
    }else
    {
    item=new nonplaceble(type_,number);
    }

    position.x=x;
    position.y=y;
    time=100;
}

droppeditem::droppeditem(bool placeble, int type_, sf::Vector2i position_,int number)
{
     if(placeble)
    {
    item=new normalitems(type_,number);
    }else
    {
    item=new nonplaceble(type_,number);
    }
    position=position_;
    time=100;
}

bool droppeditem::handlegravity()
{
           // entity.velocity.y=entity.velocity.y+GRAVITY*32*deltatime*2;
           // entity.velocity.y=std::min(entity.velocity.y,(float)((GRAVITY*32)));
          // entity.x=entity.x+entity.velocity.x*deltatime;
          // entity.y=entity.y+entity.velocity.y*deltatime;


         position.y+=GRAVITY*32*deltatime;

    if(world[position.x/32][position.y/32+1].family()==bl::blocy||world[position.x/32][position.y/32+1].family()==bl::platform_family)
        {
            position.y=(position.y/32)*32;

        }

                //check pick up
        if(player.x+32>position.x-16&&player.x<position.x+48&&player.y+64>position.y-16&&player.y<position.y+48)
            {
                if(item->maxnumber>1)
                for(int i=0;i<INVENTORY_SIZE;i++)   ///non epty spaces
                {

                 if(inventory[i]->type==item->type&&inventory[i]->placeble()==item->placeble()&&inventory[i]->number<inventory[i]->maxnumber)
                    {
                        int temp=inventory[i]->number+item->number;
                        if(temp>inventory[i]->maxnumber)
                            {
                            item->number-=(inventory[i]->maxnumber-inventory[i]->number);
                            inventory[i]->number=inventory[i]->maxnumber;
                            }else
                            {
                            inventory[i]->number+=item->number;
                            return 0;
                            }


                    }

                }


                for(int i=0;i<INVENTORY_SIZE;i++)   ///empty spaces
                    {
                    if(!inventory[i]->type)
                        {
                        if(item->placeble())
                            {delete inventory[i];
                            inventory[i]=new normalitems(item->type,item->number);
                            }else
                            {delete inventory[i];
                            inventory[i]=new nonplaceble(item->type,item->number);
                            }

                      return 0;   ///  delete item
                        }

                    }

                return 1;

            }

            else return 1;



}
  droppeditem::~droppeditem()
            {
            //delete item;
            }

//               entity.y=y*32-entity.sizeofentity.y;


bool isconsumabl(int type)
{
    switch (type)
    {
        case items::apple:return 1;
        case items::healthbottle:return 1;
        case items::battle_potion:return 1;
        case items::recall_potion:return 1;
        case items::spawn_set_potion:return 1;

        return 0;
    }

}

bool isconsumable(int type)
{
    switch (type)
    {
    case items::apple: return 1;
    case items::healthbottle: return 1;

    return 0;
    }

}







