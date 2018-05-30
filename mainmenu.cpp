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
extern int curentbiome;
extern playerentity player;
extern uint8_t states;
//sf::Vector2i pl;
extern float deltatime;
extern int maploaded;


static void load1f()
{
states=gamestates::game;
maploaded=1;
 loadmap(1);///loads the map
}

static void load2f()
{
states=gamestates::game;
maploaded=2;
 loadmap(2);///loads the map
}

static void load3f()
{
states=gamestates::game;
maploaded=3;
 loadmap(3);///loads the map
}


void mainmenuf()
{
   // pl={player.x,player.y};


    player.x=1000;
    player.y=1000;

   buttonclass loadworld1;   ////////////////
   buttonclass loadworld2;   ////////////////
   buttonclass loadworld3;   ////////////////

    handle_background();
    view.setCenter(1000,1000);


     loadworld1.scale=2;
     loadworld2.scale=2;
     loadworld3.scale=2;
    loadworld1.seposrelevanttothecenter(0,150);
    loadworld2.seposrelevanttothecenter(0,250);
    loadworld3.seposrelevanttothecenter(0,350);
    loadworld1.nroftiles=4;
    loadworld2.nroftiles=4;
    loadworld3.nroftiles=4;

    loadworld1.title="Load world 1";
    loadworld2.title="Load world 2";
    loadworld3.title="Load world 3";
    loadworld1.onclick=load1f;
    loadworld2.onclick=load2f;
    loadworld3.onclick=load3f;

    loadworld1.update();
    loadworld2.update();
    loadworld3.update();

  window.setView(view);
  window.display();
    window.clear(sf::Color(11,107,237));

   // player.x=pl.x;
//player.y=pl.y;

}
