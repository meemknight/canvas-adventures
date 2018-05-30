#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

#include<SFML/Graphics.hpp>
#include "headerfiles/declarations.h"
#include "items.h"
#include <iostream>

#define INVENTORY_SIZE 30

using std::cout;


extern int numberofitemslots;
extern int WIDE;
extern int HEIGHT;
//extern sf::Texture textures;
extern sf::View view;
extern sf::RenderWindow window;
extern  uint8_t curentblock;
extern sf::Sprite slot_sprite;


items* inventory[INVENTORY_SIZE];

static int numberofitemslotsb;

sf::Sprite slot_sprite;

void inventorystate()
{   numberofitemslotsb=numberofitemslots;

    for(int y=0;y<10;y++)
    {
      for(int x=0;x<10;x++)
        {
            if(numberofitemslotsb>0)
            {
                changetexture(slot_sprite,0,2);
                numberofitemslotsb--;
            }else{changetexture(slot_sprite,0,1);}

            slot_sprite.setPosition(32*3+x*32,32*3+y*32);
            window.draw(slot_sprite);


        }

    }

}


#endif // INVENTORY_H_INCLUDED
