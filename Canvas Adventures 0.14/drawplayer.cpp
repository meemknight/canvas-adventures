#include <SFML/Graphics.hpp>
#include "headerfiles/declarations.h"
#include <vector>

extern playerentity player;
extern items* inventory[INVENTORY_SIZE];
extern int slot;
extern float deltatime;
extern sf::RenderWindow window;


extern sf::Texture player_head_texture;
extern sf::Texture player_feet_texture;
extern sf::Texture player_back_texture;
extern sf::Texture player_front_texture;

extern std::vector<sf::Texture*> clothes;
extern int armour_inventory[3];


void setcolour()
{
    if(player.invurnerabilitytime>0)
        {
        player.sprite.setColor(sf::Color::Red);
        }

}


void drawplayer()
{

    sf::Texture *p_back=&player_back_texture;
    sf::Texture *p_head=&player_head_texture;
    sf::Texture *p_feet=&player_feet_texture;
    sf::Texture *p_front=&player_front_texture;

    if(armour_inventory[0])
        {
        p_head=clothes[armour_inventory[0]-items::copper_armour];
        }

    if(armour_inventory[1])
        {
        p_front=&(clothes[armour_inventory[1]-items::copper_armour])[0];
        p_back=&(clothes[armour_inventory[1]-items::copper_armour])[1];
        }

    if(armour_inventory[2])
        {
        p_feet=clothes[armour_inventory[2]-items::copper_armour];
        }




        if(inventory[slot]->type&&!inventory[slot]->placeble())
            {
                player.sprite.setTexture(*p_back);
            setcolour();
                 player.draw(window,deltatime,3); /// !
                player.sprite.setTexture(*p_head);
                setcolour();
                 player.draw(window,deltatime); /// !
                player.sprite.setTexture(*p_feet);
                setcolour();
                 player.draw(window,deltatime); /// !

                  drawitem();

                player.sprite.setTexture(*p_front);
                setcolour();
                 player.draw(window,deltatime); /// !
                 player.updatedraw();
            }else
            {
                player.sprite.setTexture(*p_back);
                setcolour();
                 player.draw(window,deltatime); /// !
                player.sprite.setTexture(*p_head);
                setcolour();
                 player.draw(window,deltatime); /// !
                player.sprite.setTexture(*p_feet);
                setcolour();
                 player.draw(window,deltatime); /// !
                player.sprite.setTexture(*p_front);
                setcolour();
                 player.draw(window,deltatime); /// !

                 player.updatedraw();
            }
}
