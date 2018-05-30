#include<SFML/Graphics.hpp>
#include "headerfiles/declarations.h"
#include "items.h"
#include <iostream>
using std::cout;



int numberofitemslots;
extern int WIDE;
extern sf::Texture textures;
extern sf::View view;
extern sf::RenderWindow window;
extern  uint8_t curentblock;
extern sf::Text text;
extern sf::Sprite blocks_sprite;
extern sf::Sprite items_sprite;


int slot=0;

items* inventory[INVENTORY_SIZE];


//sf::Sprite slot_sprite;

void resetnumberofitemslots()
{
    int i;
    for(i=1;WIDE>(i*64+32*5)&&i<=10;i++);
numberofitemslots=i-1;


}



 void handleitemslots()
{
    int i;
blocks_sprite.setScale(2,2);
items_sprite.setScale(2,2);
text.setScale(1,1);


changetexture(blocks_sprite,0,3);

for(i=0;i<numberofitemslots;i++)
    {
        blocks_sprite.setPosition(i*64+view.getCenter().x-view.getSize().x/2,0+view.getCenter().y-view.getSize().y/2);

        if(slot==i){  changetexture(blocks_sprite,0,2);
      window.draw(blocks_sprite);
      changetexture(blocks_sprite,0,3);
      }else{    window.draw(blocks_sprite);}



    }

for(i=0;i<numberofitemslots;i++)
    {

    if(inventory[i]->placeble())
        {
    changetexture(blocks_sprite,inventory[i]->type,4);
    blocks_sprite.setPosition(i*64+view.getCenter().x-view.getSize().x/2,0+view.getCenter().y-view.getSize().y/2);
        window.draw(blocks_sprite);
        }else
        {
         changetexture(items_sprite,inventory[i]->type,0);
    items_sprite.setPosition(i*64+view.getCenter().x-view.getSize().x/2,0+view.getCenter().y-view.getSize().y/2);
        window.draw(items_sprite);
        }

        if(inventory[i]->number>1&&inventory[i]->type)
        {
            //  text.setScale(0.5,0.5);
            text.setPosition(i*64+view.getCenter().x-view.getSize().x/2,32+view.getCenter().y-view.getSize().y/2);
            text.setString(inttostring(inventory[i]->number));
            window.draw(text);
          //  text.setScale(1,1);
        }
    }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){slot=0;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)&&numberofitemslots>1){slot=1;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)&&numberofitemslots>2){slot=2;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)&&numberofitemslots>3){slot=3;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)&&numberofitemslots>4){slot=4;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)&&numberofitemslots>5){slot=5;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)&&numberofitemslots>6){slot=6;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)&&numberofitemslots>7){slot=7;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)&&numberofitemslots>8){slot=8;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)&&numberofitemslots>9){slot=9;}
        curentblock=inventory[slot]->type;

blocks_sprite.setScale(1,1);
items_sprite.setScale(1,1);
text.setScale(0.5,0.5);

}

