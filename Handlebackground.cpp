#include "headerfiles/declarations.h"

sf::Texture defaultbackgroundtexture;
sf::Sprite background_sprite;
sf::Sprite secondbackground;

sf::Texture desetrtexture;
sf::Texture snowbiometexture;
sf::Texture cavebiometexture;

extern int lastbiome;

extern playerentity player;
extern int curentbiome;

extern sf::RenderWindow window;
extern sf::View view;

extern int WIDE;
extern int HEIGHT;

int displayed=0;

int fade=0;
static int x,y;
void handle_background()
{

    x=(int)(player.x-(background_sprite.getScale().x*background_sprite.getTexture()->getSize().x/3.5)
                                    -((player.x/(WIDE*32.0))*background_sprite.getScale().x*background_sprite.getTexture()->getSize().x*0.8)
                                    );


    y=(int)(player.y-(background_sprite.getScale().y*background_sprite.getTexture()->getSize().y/3.5)
                                    -((player.y/(HEIGHT*32.0))*background_sprite.getScale().y*background_sprite.getTexture()->getSize().y*0.8));

if(player.x>Gamelenght*32-WIDE/2)
    {
x=(int)((Gamelenght*32-WIDE/2)-(background_sprite.getScale().x*background_sprite.getTexture()->getSize().x/3.5)
                                    -(((Gamelenght*32-WIDE/2)/(WIDE*32.0))*background_sprite.getScale().x*background_sprite.getTexture()->getSize().x*0.8));
    }

if(player.x<WIDE/2)
            {
x=(int)((WIDE/2)-(background_sprite.getScale().x*background_sprite.getTexture()->getSize().x/3.5)
                                    -(((WIDE/2)/(WIDE*32.0))*background_sprite.getScale().x*background_sprite.getTexture()->getSize().x*0.8));

            }


if(player.y>Gameheight*32-HEIGHT/2)
    {
    y=(int)((Gameheight*32-HEIGHT/2)-(background_sprite.getScale().y*background_sprite.getTexture()->getSize().y/3.5)
                                    -(((Gameheight*32-HEIGHT/2)/(HEIGHT*32.0))*background_sprite.getScale().y*background_sprite.getTexture()->getSize().y*0.8));

    }

if(player.y<HEIGHT/2)
    {
    y=(int)((HEIGHT/2)-(background_sprite.getScale().y*background_sprite.getTexture()->getSize().y/3.5)
                                    -(((HEIGHT/2)/(HEIGHT*32.0))*background_sprite.getScale().y*background_sprite.getTexture()->getSize().y*0.8));

    }


background_sprite.setPosition(x,y);////////





if(fade<=3)
    {

if(curentbiome==biome::field){background_sprite.setTexture(defaultbackgroundtexture);}else
if(curentbiome==biome::desert){background_sprite.setTexture(desetrtexture);}else
if(curentbiome==biome::snow){background_sprite.setTexture(snowbiometexture);}else
if(curentbiome==biome::cave){background_sprite.setTexture(cavebiometexture);}
displayed=curentbiome;
    }



if(lastbiome!=curentbiome&&fade<=3)
    {

        fade=255;

        if(lastbiome==biome::field){secondbackground.setTexture(defaultbackgroundtexture);}else
        if(lastbiome==biome::desert){secondbackground.setTexture(desetrtexture);}else
        if(lastbiome==biome::snow){secondbackground.setTexture(snowbiometexture);}else
        if(lastbiome==biome::cave){secondbackground.setTexture(cavebiometexture);}
    }

        if(fade>3)
        {
        secondbackground.setColor(sf::Color(255,255,255,fade));
        fade-=2;

        secondbackground.setPosition(background_sprite.getPosition().x,background_sprite.getPosition().y);

        window.draw(secondbackground);

        background_sprite.setColor(sf::Color(255,255,255,255-fade));
        window.draw(background_sprite);

            if(fade<=3&&curentbiome!=displayed)
                {
                fade=255;
                lastbiome=displayed;

                    if(curentbiome==biome::field){background_sprite.setTexture(defaultbackgroundtexture);}else
                    if(curentbiome==biome::desert){background_sprite.setTexture(desetrtexture);}else
                    if(curentbiome==biome::snow){background_sprite.setTexture(snowbiometexture);}else
                    if(curentbiome==biome::cave){background_sprite.setTexture(cavebiometexture);}

                    if(lastbiome==biome::field){secondbackground.setTexture(defaultbackgroundtexture);}else
                    if(lastbiome==biome::desert){secondbackground.setTexture(desetrtexture);}else
                    if(lastbiome==biome::snow){secondbackground.setTexture(snowbiometexture);}else
                    if(lastbiome==biome::cave){secondbackground.setTexture(cavebiometexture);}
                    //lastbiome=curentbiome;
                    displayed=curentbiome;


                }


        }else
        {


                 background_sprite.setColor(sf::Color(255,255,255,255));
                window.draw(background_sprite);




        }


}
