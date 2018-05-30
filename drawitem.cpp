#include "headerfiles/declarations.h"

extern playerentity player;

extern sf::Texture textures;
extern sf::View view;
extern sf::RenderWindow window;
//extern  uint8_t curentblock;
extern sf::Text text;
extern sf::Sprite blocks_sprite;
extern sf::Sprite items_sprite;

extern items* inventory[INVENTORY_SIZE];
extern int slot;

void drawitem()
{


if(inventory[slot]->placeble())
    {
        if(player.movingright)
            {
            blocks_sprite.setPosition(player.x+20,player.y+20);
            }else
            {
            blocks_sprite.setPosition(player.x-20,player.y+20);
            }

    changetexture(blocks_sprite,inventory[slot]->type,4);
   // window.draw(blocks_sprite);
    }else
    {
          if(player.movingright)
            {    changetexture(items_sprite,inventory[slot]->type,0);

            items_sprite.setPosition(player.x+items_sprite.getLocalBounds().width-10,player.y+10);
            }else
            {    changetexture(items_sprite,inventory[slot]->type,0,1);

            items_sprite.setPosition(player.x-items_sprite.getLocalBounds().width+10,player.y+10);
            }

    window.draw(items_sprite);


    }

}
