#include "buttonclass.h"
#include "../headerfiles/declarations.h"

extern int WIDE;
extern int HEIGHT;
extern bool leftreleased;
extern sf::RenderWindow window;
extern sf::Text text;
extern sf::View view;
#define XVIEW (view.getCenter().x-WIDE/2)
#define YVIEW (view.getCenter().y-HEIGHT/2)

extern  sf::Sprite inventory_meniu_sprite;


buttonclass::buttonclass()
{
position={0,0};
}

void buttonclass::update()
{
    sf::Vector2i mousepos=sf::Mouse::getPosition(window);


    inventory_meniu_sprite.setScale(scale, scale);
    text.setScale(textscale,textscale);


    for(int i=0;i<nroftiles;i++)
        {
            if(i==0)
            {
            changetexture(inventory_meniu_sprite,5,0,0);
            inventory_meniu_sprite.setPosition(position.x+i*32*scale+XVIEW,position.y+YVIEW);
            window.draw(inventory_meniu_sprite);
            }else
            if(i==nroftiles-1)
            {

            inventory_meniu_sprite.setRotation(180);

            changetexture(inventory_meniu_sprite,5,0,0);
            inventory_meniu_sprite.setPosition(position.x+(i+1)*32*scale+XVIEW,position.y+1*32*scale+YVIEW);
            window.draw(inventory_meniu_sprite);

            inventory_meniu_sprite.setRotation(0);

            }else
            {


            changetexture(inventory_meniu_sprite,4,0,0);
            inventory_meniu_sprite.setPosition(position.x+i*32*scale+XVIEW,position.y+YVIEW);
            window.draw(inventory_meniu_sprite);
            }

        }

        text.setString(title);
        text.setPosition(position.x+5+XVIEW,position.y+5+YVIEW);
            window.draw(text);

    text.setScale(1,1);
    inventory_meniu_sprite.setScale(1, 1);

    ///check click
    if(mousepos.x>position.x&&
       mousepos.y>position.y&&
       mousepos.x<position.x+(nroftiles)*32*scale&&
       mousepos.y<position.y+32*scale&&
       leftreleased
       )
        {
        onclick();
        }



}

void buttonclass::seposrelevanttothecenter(int x, int y)
{
    position.x=WIDE/2-nroftiles*32*scale+x;
    position.y=HEIGHT/2-1*32*scale+y;


}
