#include<SFML/Graphics.hpp>
#include "headerfiles/declarations.h"
#include "items.h"
#include "entities.h"

#define INVENTORY_SIZE 30

extern playerentity player;
extern int WIDE;
extern int HEIGHT;
extern sf::Texture textures;
extern sf::View view;
extern sf::RenderWindow window;
extern  uint8_t curentblock;
extern sf::Text text;
extern sf::Sprite blocks_sprite;
extern sf::Sprite items_sprite;
extern sf::Sprite heart_sprite;

void showhearts()
{
    //heart_sprite.setScale();
changetexture(heart_sprite,0,0);


    if(player.life/player.maxlife>=1)
        {changetexture(heart_sprite,0,0);}
    else if(player.life/player.maxlife>=0.9) {changetexture(heart_sprite,1,0);}
    else{changetexture(heart_sprite,2,0);}
        heart_sprite.setPosition(view.getCenter().x+WIDE/2-32*5,view.getCenter().y-HEIGHT/2);
     window.draw(heart_sprite);


    if(player.life/player.maxlife>0.7)
        {changetexture(heart_sprite,0,0);}
    else if(player.life/player.maxlife>=0.6) {changetexture(heart_sprite,1,0);}
    else{changetexture(heart_sprite,2,0);}
        heart_sprite.setPosition(view.getCenter().x+WIDE/2-32*4,view.getCenter().y-HEIGHT/2);
     window.draw(heart_sprite);


    if(player.life/player.maxlife>0.5)
        {changetexture(heart_sprite,0,0);}
    else if(player.life/player.maxlife>=0.4) {changetexture(heart_sprite,1,0);}
    else{changetexture(heart_sprite,2,0);}
        heart_sprite.setPosition(view.getCenter().x+WIDE/2-32*3,view.getCenter().y-HEIGHT/2);
     window.draw(heart_sprite);


    if(player.life/player.maxlife>0.3)
        {changetexture(heart_sprite,0,0);}
    else if(player.life/player.maxlife>=0.2) {changetexture(heart_sprite,1,0);}
    else{changetexture(heart_sprite,2,0);}
        heart_sprite.setPosition(view.getCenter().x+WIDE/2-32*2,view.getCenter().y-HEIGHT/2);
     window.draw(heart_sprite);


    if(player.life/player.maxlife>0.1)
        {changetexture(heart_sprite,0,0);}
    else if(player.life/player.maxlife>0) {changetexture(heart_sprite,1,0);}
    else{changetexture(heart_sprite,2,0);}
        heart_sprite.setPosition(view.getCenter().x+WIDE/2-32*1,view.getCenter().y-HEIGHT/2);
     window.draw(heart_sprite);

}
