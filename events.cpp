#include <SFML/Graphics.hpp>
#include "headerfiles/declarations.h"
#include <windows.h>
#include "items.h"
#include "enum.h"
#include "entities.h"
extern bool focused;
extern int HEIGHT;
extern int WIDE;
extern HWND wind;
extern sf::View view;
extern bool zoomed;
extern items* inventory[10];
extern int slot;
extern sf::Vector2u pointingto;
extern bool Tpressed;

extern playerentity player;
extern int maploaded;

bool rightreleased;
bool leftreleased;

  extern sf::Vector2i currentchest;



extern uint8_t states;


  void handleevents(sf::RenderWindow &window)
  {
      rightreleased=0;
      leftreleased=0;



   sf::Event event;
    while (window.pollEvent(event))
        {
        switch (event.type)
            {
        case sf::Event::Closed:window.close();
        savemap(maploaded);
        break;
        case sf::Event::GainedFocus:focused=1;
        //window.setFramerateLimit(120);
        break;
        case sf::Event::LostFocus:focused=0;
       // window.setFramerateLimit(25);
        break;
        case sf::Event::Resized:
            window.setSize(sf::Vector2u((int)window.getSize().x,(int)window.getSize().y));
        WIDE=window.getSize().x;
       HEIGHT=window.getSize().y;
        view.setSize(WIDE,HEIGHT);
        resetnumberofitemslots();
        break;

        case sf::Event::KeyReleased:
        {

         if(event.key.code==sf::Keyboard::Escape)
            {
                    if(states==gamestates::game){states=gamestates::invent;checkstations();}else
            if(states==gamestates::invent||states==gamestates::crafting_state||states==gamestates::chest_state)
            {if(currentchest.x!=-1){deletechest();}
                    states=gamestates::game;currentchest.x=-1;currentchest.y=-1;}
                /*
                if(maploaded)
                savemap(maploaded);
          window.close();
          //  ShowWindow(wind,SW_MINIMIZE);
                */
            }else
        if(event.key.code==sf::Keyboard::Z)
            {
            if(zoomed){zoomed=0;view.zoom(0.25);}else{zoomed=1;view.zoom(4);}
            }else
  if(event.key.code==sf::Keyboard::Q)
            {
           inventory[slot]->type--;
            }else
    if(event.key.code==sf::Keyboard::E)
            {

            inventory[slot]->type++;
            }else
    if(event.key.code==sf::Keyboard::Tab)
            {

            }else
    if(event.key.code==sf::Keyboard::T)
            {
                savemap(maploaded);


            Tpressed=1;

            }else{Tpressed=0;}
        }
        break;



        case sf::Event::MouseButtonReleased:
            {
            if(event.key.code==sf::Mouse::Left){leftreleased=1;}else{leftreleased=0;}
            if(event.key.code==sf::Mouse::Right){rightreleased=1;}else{rightreleased=0;}

            }
            break;
            }
        }
  }
