#include "menupage.h"
#include "../headerfiles/declarations.h"

extern int maploaded;
extern uint8_t states;

menupage::menupage()
{
    //ctor
}

menupage::menupage(sf::Texture texture, sf::RenderWindow &window, sf::Vector2i position_, sf::Vector2i size_, sf::Vector2i croppos1_, sf::Vector2i croppos2_={-1, -1})
{
    create(texture, window, position_, size_, croppos1_, croppos2_);
}

void menupage::create(sf::Texture texture, sf::RenderWindow &window, sf::Vector2i position_, sf::Vector2i size_, sf::Vector2i croppos1_, sf::Vector2i croppos2_={-1, -1})
{
   if(croppos2_.x==-1)
    {
        croppos2_.x=texture.getSize().x-croppos1_.x;
        croppos2_.y=texture.getSize().y-croppos1_.y;
    }

   menu_sprite.setTexture(texture);

}

void menupage::update()
{

    int sizex=size.x;
    int sizey=size.y;
    int xpos=croppos1.x;
    int ypos=0;


    menu_sprite.setPosition(position.x, position.y);
    menu_sprite.setTextureRect(sf::IntRect(0, 0, croppos1.x, croppos1.y));//draw left upper corner
    window.draw(menu_sprite);
    sizex-=croppos1.x;

    while(1)
        {
            if(sizex<=size.x-croppos2.x)
            {
                    menu_sprite.setPosition(position.x+sizex, position.y);
                    menu_sprite.setTextureRect(sf::IntRect(croppos2.x, 0, size.x, croppos1.y));
                    window.draw(menu_sprite);
                    break;
            }else
            {
                if(sizex-(croppos2.x-croppos1.x)>0)
                    {
                       //menu_sprite.setPosition(xpos);



                    }

            }

        }





}

void returnToMainMenu()
{
    savemap(maploaded);

    maploaded=0;
    states=gamestates::mainmenu;

}



