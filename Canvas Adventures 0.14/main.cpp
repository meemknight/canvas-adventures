#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>
#include <vector>
#include <memory>
#include <signal.h>

#include "headerfiles/declarations.h"
#include "blocks.h"
#include "enum.h"
#include "entities.h"
#include "Craftingrecepies.h"
#include "buttonclass.h"


//#define Gameheight 160 ///height of the game
//#define Gamelenght 640 ///lenght of the game
#include "items.h"

using namespace std;

HWND wind;

extern int displayed;
extern int moves;

sf::Sprite blocks_sprite;

extern int numberofitemslots;
extern items* inventory[INVENTORY_SIZE];
extern int slot;

uint8_t states=gamestates::mainmenu;

sf::Sprite mouse_sprite;
sf::Sprite player_sprite;
sf::Sprite tree_sprite;
sf::Sprite items_sprite;
sf::Sprite heart_sprite;

sf::Texture treetextures;
sf::Texture textures;
sf::Texture playertexture;

sf::Texture player_head_texture;
sf::Texture player_feet_texture;
sf::Texture player_back_texture;
sf::Texture player_front_texture;

sf::Texture slimetxture;
sf::Texture blueslimetxture;
sf::Texture itemstexture;
sf::Texture hearttexture;
sf::Texture sandslimetexture;
sf::Texture iceslimetexture;
sf::Texture smallblueslimetexture;
sf::Texture zombietexture;
sf::Texture mumytexture;
sf::Texture eschimotexture;

sf::Text text;

extern bool rightreleased;
extern bool leftreleased;
bool Tpressed;


bool zoomed=0;
bool focused=1;

int difficulty=1;

int maploaded;
  sf::Font font;

  extern sf::Vector2i currentchest;



            sf::Vector2u pointingto;    //the block that the player is pointing;


int WIDE=1100;
int HEIGHT=650;  ///pixeli
//int Gameheight=40; ///nr blocuri
//int Gamelenght=40;
bl::blocks world[Gamelenght][Gameheight];
bl::blocks walls[Gamelenght][Gameheight];

sf::Clock breakblocktime;
sf::Clock attacktime;

playerentity player;

//sf::Vector2f playervelocity;

bool touchesentities;

int curentbiome=0;
int lastbiome=0;

extern float whaittime;
extern float spawnwaittime;

sf::View view(sf::FloatRect(0,0,WIDE,HEIGHT));

    extern Craftingrecepies recepies[100];

           // bool movingright;
           // bool movingdown;
            //bool canjump;
           // bool moving;
     float deltatime;

std::vector<slimeentity> enemies;
std::vector<humanlikeenemy> humanlike_enemies;
std::vector<droppeditem> droppedi;

extern items* tempitems;


 sf::RenderWindow window;
 uint8_t curentblock=bl::type::gold;
int main()
{   srand(time(0));

    difficulty=1;

    string mesage;


   // setbuttons();

   // setbuttons();


    tempitems=new nonplaceble(0,1);

        text.setOutlineColor(sf::Color::White);
    text.setOutlineThickness(1);

#ifdef DEBUG
   window.create(sf::VideoMode(WIDE, HEIGHT), "Canvas Adventures!",sf::Style::Titlebar|sf::Style::Close|sf::Style::Resize);
#endif // DEBUG
sf::ContextSettings setting;


#ifdef RELEASE
  window.create(sf::VideoMode(WIDE, HEIGHT), "Canvas Adventures!",sf::Style::Titlebar|sf::Style::Close|sf::Style::Fullscreen);
#endif // RELEASE




    resetnumberofitemslots();

    WIDE=window.getSize().x;
       HEIGHT=window.getSize().y;
view.setSize(sf::Vector2f(WIDE, HEIGHT));

        player.frametime=1.0/20.0;
        player.sizeofentity.x=32;
        player.sizeofentity.y=64;

        text.setColor(sf::Color::Black);
        //text.setStyle(sf::Text::Bold);


        text.setCharacterSize(24);
        text.setFont(font);




    settextures();///sets all the textures

    //setbuttons();

/*
    inventory[0]= new normalitems(bl::type::dirt,225);
    inventory[1]= new normalitems(bl::type::dirt,1);
    inventory[2]= new nonplaceble(items::name::gold_pickaxe,1);
    inventory[3]= new nonplaceble(items::name::gold_hammer,1);
    inventory[4]= new nonplaceble(items::name::copper_bar,32);
    inventory[5]= new normalitems(bl::type::iceblock,1);
    inventory[6]= new normalitems(bl::type::glass,100);
    inventory[7]= new normalitems(bl::type::glass_wall,100);
    inventory[8]= new normalitems(bl::type::platform,10);
    inventory[9]= new nonplaceble(items::name::copper_bar,32);
    for(int i=10;i<INVENTORY_SIZE;i++)
        {
        inventory[i]=new normalitems();
        }
*/

    lastbiome=curentbiome;

    bl::normalblocks* temp;//new bl::normalblocks(bl::type::dirt);
//    sf::Vector2f playervelocity(0,0);

     sf::Clock myclock;


    //sf::Vector2f lastposition;

    //window.setFramerateLimit(120);
        WIDE=window.getSize().x;
        HEIGHT=window.getSize().y;


       // player.maxlife=100;
/*
    enemies.push_back(et::getslime(et::blue_slime));
    enemies.push_back(et::getslime(et::green_slime));
    enemies.push_back(et::getslime(et::blue_slime));
    enemies.push_back(et::getslime(et::blue_slime));
     enemies.push_back(et::getslime(et::blue_slime));
    enemies.push_back(et::getslime(et::blue_slime));
    enemies.push_back(et::getslime(et::blue_slime));
    enemies.push_back(et::getslime(et::blue_slime));
    enemies.push_back(et::getslime(et::sand_slime));
    enemies.push_back(et::getslime(et::sand_slime));
    enemies.push_back(et::getslime(et::ice_slime));
    enemies.push_back(et::getslime(et::ice_slime));
    enemies.push_back(et::getslime(et::blue_slime));
    enemies.push_back(et::getslime(et::green_slime));
    enemies.push_back(et::getslime(et::green_slime));
    enemies.push_back(et::getslime(et::green_slime));

    for(uint8_t i=0;i<enemies.size();i++) ///sets the pos
        {
        enemies[i].x=randomrange(60,102)*32;
        enemies[i].y=7*32;
        }
*/

   // signal(SIGTERM, dosave);
   // signal(SIGABRT, dosave);



  slimeentity slime;
  slime.animationstate=0;

    slime=et::getslime(et::ice_slime);

slime.x=60*32;
slime.y=7*32;

int maxx;
int minx;
int maxy;
int miny;



                                //player.life=100;

            sf::Vector2i mousepos;


            view.setViewport(sf::FloatRect(0,0,1,1));



            window.setView(view);

            for(int i=0;i<Gamelenght;i++) ///radomises blocks
            {
             for(int ii=0;ii<Gameheight;ii++)
                {
                world[i][ii].randomisevarations();
                walls[i][ii].randomisevarations();
                }
            }

            ///playerddddddddddddddddddddddw
           // player.x=2000;
          //  player.y=50;

           // droppedi.push_back(droppeditem(1,items::name::ruby,2064,300,10));
window.setVerticalSyncEnabled(1);


//window.setFramerateLimit(60);

                //player_sprite.setPosition(player.x,player.y); ///loads a position for the player

wind=GetForegroundWindow();


int sandcount=0;
int snowcount=0;
int otherccount=0;




/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    while (window.isOpen())
    {
deltatime=myclock.restart().asSeconds();
deltatime=min(1.f/25.f,deltatime);
//deltatime=1.f/50.f;

        handleevents(window);




        if(focused==1)
        {

if(states!=gamestates::mainmenu)
{



            if(zoomed)
        {
            maxx=Gamelenght;
            maxy=Gameheight;
            minx=0;
            miny=0;
        }else
        {
            maxx=getmaxx(player);
            maxy=getmaxy(player);
            minx=getminx(player);
            miny=getminy(player);
        }

            timehandle();




             sandcount=0;
             snowcount=0;
             otherccount=0;



            for(int x=minx;x<maxx;x++)               ///draw sprites
            {
             for(int y=miny;y<maxy;y++)
                {

                          ////                     walls
                            if((walls[x][y].type!=0)/*&&((zoomed)||(x*32+32>view.getCenter().x-WIDE/2&&x*32<view.getCenter().x+WIDE/2&&y*32<view.getCenter().y+HEIGHT/2&&y*32+32>view.getCenter().y-HEIGHT/2))*/)
                    {
                     changetexture(blocks_sprite,walls[x][y].type,walls[x][y].varation);
                                    blocks_sprite.setPosition(x*32,y*32);
                                    window.draw(blocks_sprite);


                    }




                      if(world[x][y].type!=bl::type::air/*&&((zoomed)||(x*32+32>view.getCenter().x-WIDE/2&&x*32<view.getCenter().x+WIDE/2&&y*32<view.getCenter().y+HEIGHT/2&&y*32+32>view.getCenter().y-HEIGHT/2))*/)///chect if air and optimise
                    {

                    switch(world[x][y].type)
                    {
                    case bl::wood:{
                        if((world[x][y+1].type==bl::grass||world[x][y+1].type==bl::dirt)&&world[x][y-1].type!=bl::type::wood&&world[x][y-1].type!=bl::type::leafs){changetexture(tree_sprite,bl::tree::woodcutdown,world[x][y].varation);}else
                        if(world[x][y+1].type==bl::grass||world[x][y+1].type==bl::dirt){changetexture(tree_sprite,bl::tree::woodground,world[x][y].varation);}else
                        if(world[x][y-1].type!=bl::wood&&world[x][y-1].type!=bl::leafs){changetexture(tree_sprite,bl::tree::woodcut,world[x][y].varation);}else
                        if(world[x-1][y].type==bl::leafs&&world[x+1][y].type==bl::leafs&&world[x][y-1].type==bl::leafs){
                            changetexture(tree_sprite,bl::tree::woodupperleafs,world[x][y].varation);
                        }else

                        if(world[x-1][y].type==bl::leafs&&world[x+1][y].type==bl::leafs){
                        changetexture(tree_sprite,bl::tree::woodrlleaves,world[x][y].varation);}else if(world[x-1][y].type==bl::leafs){
                        changetexture(tree_sprite,bl::tree::woodlleaves,world[x][y].varation);
                        }else if(world[x+1][y].type==bl::leafs)
                        {
                        changetexture(tree_sprite,bl::tree::woodrleaves,world[x][y].varation);
                        }else{changetexture(tree_sprite,bl::tree::normalwood,world[x][y].varation);}

                        tree_sprite.setPosition(x*32,y*32);
                        window.draw(tree_sprite);

                        break;}

                    case bl::wodden_door:
                        {
                        if(y<Gameheight&&world[x][y+1].type==bl::wodden_door)
                            {
                          changetexture(blocks_sprite,bl::wodden_door,0);
                            blocks_sprite.setPosition(x*32,y*32);
                            window.draw(blocks_sprite);
                            }

                        if(y>0&&world[x][y-1].type==bl::wodden_door)
                            {
                             changetexture(blocks_sprite,bl::wodden_door,1);
                            blocks_sprite.setPosition(x*32,y*32);
                            window.draw(blocks_sprite);
                            }

                        break;}

                    default:

                        switch(blocks_sprite,world[x][y].type,world[x][y].type)
                        {
                            case bl::snowblock:{snowcount++;}break;
                            case bl::snow_gem:{snowcount++;}break;
                            case bl::snow_wall:{snowcount++;}break;
                            case bl::iceblock:{snowcount++;}break;
                            case bl::ice_bricks:{snowcount++;}break;
                           // case bl::ice_gem_block:{snowcount++;}break;
                           // case bl::ice_gem_wall:{snowcount++;}break;

                            case bl::sand:{sandcount++;}break;
                            case bl::sandstone:{sandcount++;}break;
                            case bl::sandstone_wall:{sandcount++;}break;
                            case bl::sand_ruby:{sandcount++;}break;
                            case bl::sand_wall:{sandcount++;}break;
                          //  case bl::rubbyblock:{sandcount++;}break;
                          //  case bl::rubby_wall:{sandcount++;}break;
                            case bl::heroglyphics:{sandcount++;}break;

                            case bl::dirt:{otherccount++;}break;
                            case bl::stone:{otherccount++;}break;
                            case bl::clay:{otherccount++;}break;



                        }

                          changetexture(blocks_sprite,world[x][y].type,world[x][y].varation);
                            blocks_sprite.setPosition(x*32,y*32);
                            window.draw(blocks_sprite);
                    }




                    } ///check if air ^

            ///set biome

            if(sandcount>snowcount&&sandcount>otherccount){curentbiome=biome::desert;}else
            if(snowcount>otherccount&&snowcount>sandcount){curentbiome=biome::snow;}else
            {curentbiome=biome::field;}
            if(player.y>135*32){curentbiome=biome::cave;}


             mousepos=sf::Mouse::getPosition(window);

            if(x*32<=mousepos.x+view.getCenter().x-(WIDE/2)&&(x+1)*32>mousepos.x+view.getCenter().x-(WIDE/2)&&y*32<=mousepos.y+view.getCenter().y-(HEIGHT/2)&&(y+1)*32>mousepos.y+view.getCenter().y-(HEIGHT/2)
               &&states==gamestates::game
               )
                            {pointingto.x=x;pointingto.y=y;

                            if(inventory[slot]->gethammerpower())
                                {
                                    if(walls[x][y].type!=bl::air)
                                {
                             mouse_sprite.setPosition(x*32,y*32);
                            window.draw(mouse_sprite);
                                }

                                }else
                                {
                                    if(world[x][y].type!=bl::air)
                                {
                                    if(inventory[slot]->getpickaxepower()||inventory[slot]->getaxepower())
                                        {
                                          mouse_sprite.setPosition(x*32,y*32);
                            window.draw(mouse_sprite);
                                        }

                                }
                            else if(inventory[slot]->placeble())
                                {
                                blocks_sprite.setPosition(x*32,y*32);
                            blocks_sprite.setColor(sf::Color(255,255,255,50));
                            changetexture(blocks_sprite,inventory[slot]->type);
                            window.draw(blocks_sprite);


                            blocks_sprite.setColor(sf::Color(255,255,255,255));
                                }

                                }


                            }

                }
            }

                ///draw sprites /\

                                                            ///keyboard;
    /*
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){view.setCenter(view.getCenter().x+deltatime*1000,view.getCenter().y);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){view.setCenter(view.getCenter().x-deltatime*1000,view.getCenter().y);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){view.setCenter(view.getCenter().x,view.getCenter().y-deltatime*1000);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){view.setCenter(view.getCenter().x,view.getCenter().y+deltatime*1000);}
    */
            ///movement
player.velocity.x*=0.0f;
slime.velocity.x*=0.0f;

    for(uint8_t i=0;i<humanlike_enemies.size();i++)
        {
            humanlike_enemies[i].velocity.x=0.0f;

             if(!humanlike_enemies[i].checktime())
        {
            humanlike_enemies.erase(humanlike_enemies.begin()+i);
            i--;
        }

        }


  for(uint8_t i=0;i<enemies.size();i++)
    {
    enemies[i].velocity.x=0.0f;

    if(!enemies[i].checktime())
        {
            enemies.erase(enemies.begin()+i);
            i--;
        }
    }




    for(int i=0;i<droppedi.size();i++)
        {
       if(!droppedi[i].handlegravity())
        {
            delete droppedi[i].item;
        droppedi.erase(droppedi.begin()+i);
        i--;

        }else
        {
        if(droppedi[i].clock.getElapsedTime().asSeconds()>droppedi[i].time)
            {
            delete droppedi[i].item;
            droppedi.erase(droppedi.begin()+i);
            i--;

            }
        }



        }

 player.moving=0;
//playervelocity.y*=0.0f;

      if(player.frosttime==0)
                {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&player.canjump==1){player.velocity.y=-sqrtf(2.0f*GRAVITY*32*210);player.canjump=0;}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){player.velocity.x=-300;player.moving=1;}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){player.velocity.x=+300;player.moving=1;}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){player.down_pressed=1;}else{player.down_pressed=0;}
                }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&humanlike_enemies[0].canjump==1){humanlike_enemies[0].velocity.y=-sqrtf(2.0f*GRAVITY*32*170);humanlike_enemies[0].canjump=0;}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){humanlike_enemies[0].velocity.x-=200;humanlike_enemies[0].moving=1;}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){humanlike_enemies[0].velocity.x+=200;humanlike_enemies[0].moving=1;}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){humanlike_enemies[0].down_pressed=1;humanlike_enemies[0].moving=1;}else{humanlike_enemies[0].down_pressed=0;}

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&slime.canjump==1){slime.velocity.y=-sqrtf(2.0f*GRAVITY*32*170);slime.canjump=0;}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){slime.velocity.x=-300;slime.moving=1;}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){slime.velocity.x=+300;slime.moving=1;}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){slime.down_pressed=1;slime.moving=1;}else{slime.down_pressed=0;}









      //     makemove(humanlike_enemies[0],player);
       //    handleentity(humanlike_enemies[0],GRAVITY);




            ///movement

touchesentities=0;

for(uint8_t i=0;i<enemies.size();i++)
    {

    if(enemies[i]==pointingto)
        {touchesentities=1;
        if(!enemies[i].invurnerabilitytime&&inventory[slot]->getattackpower()&&sf::Mouse::isButtonPressed(sf::Mouse::Left)
           &&states==gamestates::game
           &&inventory[slot]->range()*32>=sqrt(putere(player.x-enemies[i].x,2)+putere(player.y-enemies[i].y,2))
           &&attacktime.getElapsedTime().asSeconds()>inventory[slot]->getspeed()/2
           )
            {
                attacktime.restart();
            enemies[i].life-=inventory[slot]->getattackpower();
            enemies[i].invurnerabilitytime=0.5;

            enemies[i].frosttime=inventory[slot]->getfreeztime();

            if(player.x>enemies[i].x)                                                   //knockbck
                {
                enemies[i].velocity.x-=inventory[slot]->getknockback()*50;
                enemies[i].velocity.y-=inventory[slot]->getknockback()*50;
                }else
                {
                enemies[i].velocity.x+=inventory[slot]->getknockback()*50;
                enemies[i].velocity.y-=inventory[slot]->getknockback()*50;

                }

                if(!inventory[slot]->splashattack())
                    {
                                     if(enemies[i].life<=0)
                        {
                                                        if(enemies[i].type==et::blue_slime)
                                        {
                                    enemies.push_back(et::getslime(et::small_blue_slime));
                                    enemies.push_back(et::getslime(et::small_blue_slime));

                                    enemies[enemies.size()-1].x=enemies[i].x-10;
                                    enemies[enemies.size()-2].x=enemies[i].x+10;
                                     enemies[enemies.size()-1].y=enemies[i].y;
                                    enemies[enemies.size()-2].y=enemies[i].y;


                                        }else if(enemies[i].type==et::ice_slime)
                                        {
                                            if(randompercent(40))
                                                { droppedi.push_back(droppeditem(0,items::icegem));}else
                                                { droppedi.push_back(droppeditem(0,items::goo));}
                                         droppedi[droppedi.size()-1].position.x=enemies[i].x;
                                            droppedi[droppedi.size()-1].position.y=enemies[i].y;
                                        }else if(enemies[i].type==et::sand_slime)
                                        {
                                                if(randompercent(40))
                                                { droppedi.push_back(droppeditem(0,items::icegem));}else
                                                { droppedi.push_back(droppeditem(0,items::goo));}
                                         droppedi[droppedi.size()-1].position.x=enemies[i].x;
                                            droppedi[droppedi.size()-1].position.y=enemies[i].y;
                                        }else
                                        {
                                         droppedi.push_back(droppeditem(0,items::goo));
                                            droppedi[droppedi.size()-1].position.x=enemies[i].x;
                                            droppedi[droppedi.size()-1].position.y=enemies[i].y;
                                        }




                            enemies[i].type=0;
                            enemies.erase(enemies.begin()+i);
                            i--;
                        }
                    break;
                    }



            }


        }

    if(enemies[i].life<=0)                          /// kill enemy
        {

            if(enemies[i].type==et::blue_slime)
                {
            enemies.push_back(et::getslime(et::small_blue_slime));
            enemies.push_back(et::getslime(et::small_blue_slime));

            enemies[enemies.size()-1].x=enemies[i].x-10;
            enemies[enemies.size()-2].x=enemies[i].x+10;
             enemies[enemies.size()-1].y=enemies[i].y;
            enemies[enemies.size()-2].y=enemies[i].y;


                }else
                {
                   droppedi.push_back(droppeditem(0,items::goo,enemies[i].x,enemies[i].y,1));

                }

            enemies[i].type=0;
            enemies.erase(enemies.begin()+i);
            //enemies
            //i--;
        }

                                if(enemies[i]==player&&enemies[i].frosttime<=0)
                                    {
                                        player.dealdamage(enemies[i].attatc);
                                          if(enemies[i].type==et::ice_slime)
                                                {
                                                player.freeze(3);
                                                }

                                    }
    }


for(uint8_t i=0;i<humanlike_enemies.size();i++)
    {

    if(humanlike_enemies[i]==pointingto)
        {touchesentities=1;
        if(!humanlike_enemies[i].invurnerabilitytime&&inventory[slot]->getattackpower()&&sf::Mouse::isButtonPressed(sf::Mouse::Left)
           &&states==gamestates::game
           &&inventory[slot]->range()*32>=sqrt(putere(player.x-humanlike_enemies[i].x,2)+putere(player.y-humanlike_enemies[i].y,2))
           &&attacktime.getElapsedTime().asSeconds()>inventory[slot]->getspeed()/2
           )
            {
                attacktime.restart();
                humanlike_enemies[i].dealdamage(inventory[slot]->getattackpower());
                humanlike_enemies[i].freeze(inventory[slot]->getfreeztime());



            if(player.x>humanlike_enemies[i].x)
                {
                humanlike_enemies[i].velocity.x-=inventory[slot]->getknockback()*50;        ///knockback
                humanlike_enemies[i].velocity.y-=inventory[slot]->getknockback()*50;
                }else
                {
                humanlike_enemies[i].velocity.x+=inventory[slot]->getknockback()*50;
                humanlike_enemies[i].velocity.y-=inventory[slot]->getknockback()*50;

                }

               // if(!inventory[slot]->splashattack())
               //     {
                //                     if(humanlike_enemies[i].life<=0)
               //         {
                //            droppedi.push_back(droppeditem(0,items::goo,humanlike_enemies[i].x,humanlike_enemies[i].y,1));
                //            humanlike_enemies[i].type=0;
                //            humanlike_enemies.erase(humanlike_enemies.begin()+i);
                 //           i--;
                 //       }
                 //   break;
                  //  }



            }


        }

    if(humanlike_enemies[i].life<=0)                          /// kill enemy
        {
            if(humanlike_enemies[i].type==et::normal_zombie)
                {
                droppedi.push_back(droppeditem(0,items::bone,humanlike_enemies[i].x+randomrange(-16,16),humanlike_enemies[i].y,1));

                }else if(humanlike_enemies[i].type==et::mumy)
                {
                 droppedi.push_back(droppeditem(0,items::bone,humanlike_enemies[i].x+randomrange(-16,16),humanlike_enemies[i].y,1));
                 droppedi.push_back(droppeditem(0,items::paper,humanlike_enemies[i].x+randomrange(-16,16),humanlike_enemies[i].y,randomrange(1,3)));
                }else if(humanlike_enemies[i].type==et::zombie_eschimo)
                {
                 droppedi.push_back(droppeditem(0,items::bone,humanlike_enemies[i].x+randomrange(-16,16),humanlike_enemies[i].y,randomrange(1,2)));
                }


            humanlike_enemies[i].type=0;
            humanlike_enemies.erase(humanlike_enemies.begin()+i);
            //enemies
            //i--;
        }

                                if(humanlike_enemies[i]==player&&humanlike_enemies[i].frosttime<=0)   //attacked by zombie
                                    {
                                        humanlike_enemies[i].animationstate=humanlikeenemy::attacking;

                                        player.dealdamage(humanlike_enemies[i].attatc);

                                    }else
                                    {
                                     humanlike_enemies[i].animationstate=humanlikeenemy::idle;
                                    }
    }




            if(leftreleased&&states==gamestates::game)
                {
                if(isconsumable(inventory[slot]->type)&&!inventory[slot]->placeble())
                    {
                        switch(inventory[slot]->type)
                        {
                            case items::apple:player.life+=30;inventory[slot]->number--;if(player.life>player.maxlife){player.life=player.maxlife;}break;
                            case items::healthbottle:player.life+=70;inventory[slot]->number--;if(player.life>player.maxlife){player.life=player.maxlife;}break;
                            case items::battle_potion:
                                for(int i=0;i<5;i++)spawnmonster();
                                inventory[slot]->number--;break;
                            case items::spawn_set_potion:player.spawnpoint.x=player.x;player.spawnpoint.y=player.y;inventory[slot]->number--;break;
                            case items::recall_potion:player.x=player.spawnpoint.x;player.y=player.spawnpoint.y;inventory[slot]->number--;break;

                        }
                    if(inventory[slot]->number<1)
                        {
                        inventory[slot]->type=0;
                        }
                    }

                }



            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)&&states==gamestates::game){                ///break

            if(world[pointingto.x][pointingto.y].type==bl::plants)
                {
                if(inventory[slot]->getattackpower())
                    {
                     droppedi.push_back(getdroppeditem(world[pointingto.x][pointingto.y].type));
                    droppedi[droppedi.size()-1].position.x=pointingto.x*32+randomrange(-10,10);
                    droppedi[droppedi.size()-1].position.y=pointingto.y*32;
                    world[pointingto.x][pointingto.y].type=0;
                    }
                }

            if(inventory[slot]->getpickaxepower()&&world[pointingto.x][pointingto.y].getminbreakvalue()<=inventory[slot]->getpickaxepower()&&world[pointingto.x][pointingto.y].type!=bl::wood&&world[pointingto.x][pointingto.y].type!=bl::leafs)
            {
                if(breakblocktime.getElapsedTime().asSeconds()>(world[pointingto.x][pointingto.y].getbreakvalue()-inventory[slot]->getpickaxepower())/100)
                    {breakblocktime.restart();

                        droppedi.push_back(getdroppeditem(world[pointingto.x][pointingto.y].type));
                    droppedi[droppedi.size()-1].position.x=pointingto.x*32+randomrange(-10,10);
                    droppedi[droppedi.size()-1].position.y=pointingto.y*32;

            if(getfamilya(world[pointingto.x][pointingto.y].type)==bl::chestfamily){breakchest(pointingto.x, pointingto.y);}

            world[pointingto.x][pointingto.y].type=0;//world[pointingto.x][pointingto.y].randomisevarations();
                     if(pointingto.y>0)world[pointingto.x][pointingto.y-1].update(pointingto.x,pointingto.y-1);
            if(pointingto.y<Gameheight)world[pointingto.x][pointingto.y+1].update(pointingto.x,pointingto.y+1);
            if(pointingto.x<Gamelenght-1)world[pointingto.x+1][pointingto.y].update(pointingto.x+1,pointingto.y);
            if(pointingto.x>0)world[pointingto.x-1][pointingto.y].update(pointingto.x-1,pointingto.y);
                    }

            }else if(inventory[slot]->gethammerpower()&&world[pointingto.x][pointingto.y].getminbreakvalue()<=inventory[slot]->gethammerpower())
            {
                if(breakblocktime.getElapsedTime().asSeconds()>(walls[pointingto.x][pointingto.y].getbreakvalue()-inventory[slot]->gethammerpower())/100)
                    {breakblocktime.restart();
            // delete temp;
           // temp=new bl::normalblocks(bl::air);
           droppedi.push_back(getdroppeditem(walls[pointingto.x][pointingto.y].type));
                    droppedi[droppedi.size()-1].position.x=pointingto.x *32+randomrange(-10,10);
                    droppedi[droppedi.size()-1].position.y=pointingto.y*32;

           walls[pointingto.x][pointingto.y].type=0; //walls[pointingto.x][pointingto.y].randomisevarations();
            if(world[pointingto.x][pointingto.y].type==bl::painting)
            {
                    world[pointingto.x][pointingto.y].type=0;
            droppedi.push_back(getdroppeditem(bl::type::painting));
                    droppedi[droppedi.size()-1].position.x=pointingto.x *32+randomrange(-10,10);
                    droppedi[droppedi.size()-1].position.y=pointingto.y*32;

            }              ///remove paintings

                    }


            }else if(inventory[slot]->getaxepower()&&world[pointingto.x][pointingto.y].type==bl::wood||world[pointingto.x][pointingto.y].type==bl::leafs)
                    {
                        if(breakblocktime.getElapsedTime().asSeconds()>(world[pointingto.x][pointingto.y].getbreakvalue()-inventory[slot]->getaxepower())/100)
                    {breakblocktime.restart();
                    // if(world[pointingto.x][pointingto.y].type!=bl::wodden_door)
                   //     {
                         droppedi.push_back(getdroppeditem(world[pointingto.x][pointingto.y].type));
                    droppedi[droppedi.size()-1].position.x=pointingto.x *32+randomrange(-10,10);
                    droppedi[droppedi.size()-1].position.y=pointingto.y*32;

                     //   }


                    world[pointingto.x][pointingto.y].type=0;//world[pointingto.x][pointingto.y].randomisevarations();
                         if(pointingto.y>0)world[pointingto.x][pointingto.y-1].update(pointingto.x,pointingto.y-1);
            if(pointingto.y<Gameheight)world[pointingto.x][pointingto.y+1].update(pointingto.x,pointingto.y+1);
            if(pointingto.x<Gamelenght-1)world[pointingto.x+1][pointingto.y].update(pointingto.x+1,pointingto.y);
            if(pointingto.x>0)world[pointingto.x-1][pointingto.y].update(pointingto.x-1,pointingto.y);
                    }


                    }


            }else{breakblocktime.restart();}                                       ///       //////////////////////////////////////////////////////////////////////////////// ///break blocks ^

                                    ///mouse !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! place blocks
           if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)&&inventory[slot]->placeble()&&states==gamestates::game)
            {
                if(inventory[slot]->type)  ///place block
                {
                     //delete temp;
                    //  temp=new bl::normalblocks(inventory[slot]->type);
                    if(inventory[slot]->type<bl::type::dirt_wall)
                    {
                        if(world[pointingto.x][pointingto.y].family()==bl::fragile&&((!(player==pointingto))||(getfamilya(inventory[slot]->type)!=bl::blocy))&&!(slime==pointingto)&&!touchesentities&&inventory[slot]->number>0)
                            {
                                if(inventory[slot]->type==bl::sappling&&pointingto.y<Gameheight&&world[pointingto.x][pointingto.y+1].type==bl::grass)
                                    {
                                     world[pointingto.x][pointingto.y].type=inventory[slot]->type;world[pointingto.x][pointingto.y].randomisevarations();
                                    }else
                                if((inventory[slot]->type!=bl::painting||walls[pointingto.x][pointingto.y].type)&&inventory[slot]->type!=bl::sappling)
                                    {
                                        if(inventory[slot]->type==bl::wodden_door)
                                            {
                                            if(pointingto.y<Gamelenght&&pointingto.y>2&&world[pointingto.x][pointingto.y+1].family()==bl::blocy&&world[pointingto.x][pointingto.y-2].family()==bl::blocy&&world[pointingto.x][pointingto.y-1].family()==bl::fragile)
                                                {
                                                world[pointingto.x][pointingto.y].type=inventory[slot]->type;world[pointingto.x][pointingto.y].randomisevarations();
                                            world[pointingto.x][pointingto.y-1].type=inventory[slot]->type;world[pointingto.x][pointingto.y].randomisevarations();
                                             // inventory[slot]->number--;
                                                }
                                            }else
                                            {
                                                if(getfamilya(inventory[slot]->type)==bl::nonstackeble||getfamilya(inventory[slot]->type)==bl::chestfamily)
                                                    {
                                                        if(pointingto.y<Gameheight&&(getfamilya(world[pointingto.x][pointingto.y+1].type)==bl::blocy
                                                           ||getfamilya(world[pointingto.x][pointingto.y+1].type)==bl::platform_family)
                                                           )
                                                            {
                                                                if(getfamilya(inventory[slot]->type)==bl::chestfamily)
                                                                    {
                                                                        placechest(pointingto.x, pointingto.y);
                                                                    }


                                                             world[pointingto.x][pointingto.y].type=inventory[slot]->type;
                                                            world[pointingto.x][pointingto.y].randomisevarations();
                                                             // inventory[slot]->number--;
                                                            }

                                                    }else
                                                    {
                                                     world[pointingto.x][pointingto.y].type=inventory[slot]->type;
                                            world[pointingto.x][pointingto.y].randomisevarations();
                                             // inventory[slot]->number--;

                                                    }


                                            }


                                    }
                            }



                    }
                    else
                    {
                        if(walls[pointingto.x][pointingto.y].type==0)
                        {
                     walls[pointingto.x][pointingto.y].type=inventory[slot]->type;walls[pointingto.x][pointingto.y].randomisevarations();
                       // inventory[slot]->number--;
                        }
                    }

                                if(inventory[slot]->number<=0){delete inventory[slot]; inventory[slot]=new normalitems;}

                }


               }
       //if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)&&world[pointingto.x][pointingto.y].family()==bl::fragile){growtreee(randomrange(2,8),pointingto.x,pointingto.y);}


                if(rightreleased&&getfamilya(world[pointingto.x][pointingto.y].type)==bl::chestfamily)
                    {
                    states=gamestates::chest_state;
                    currentchest.x=pointingto.x;
                    currentchest.y=pointingto.y;
                    loadchest(currentchest.x, currentchest.y);
                    }


        handleentity(player,GRAVITY);

      // slime.makemove(player);
        handleentity(slime,GRAVITY);

  for(uint8_t i=0;i<enemies.size();i++)
    {
    //enemies[i].makemove(player);
    makemove(enemies[i],player);
    handleentity(enemies[i],GRAVITY);
    }

     for(uint8_t i=0;i<humanlike_enemies.size();i++)
    {
    makemove(humanlike_enemies[i],player);
    handleentity(humanlike_enemies[i],GRAVITY);
    }



                                                            ///fix player position

        if(player.life<=0)
            {
            player.life=player.maxlife;
            player.x=player.spawnpoint.x;
            player.y=player.spawnpoint.y;
            }



        ///animate
        if(!player.canjump){
        player.animationstate=2;}else
        if(player.moving){player.animationstate=1;}else{player.animationstate=0;}




        //player_sprite.setPosition(player.x,player.y);




        slime.draw(window,deltatime);
        slime.updatedraw();

          for(uint8_t i=0;i<enemies.size();i++)
        {
            if((abs(enemies[i].x-player.x)<WIDE+32*6)&&
               (abs(enemies[i].y-player.y)<HEIGHT+32*6)
               )
                {
                    enemies[i].livetime=20;
                }
                    enemies[i].draw(window,deltatime);
                    enemies[i].updatedraw();

                   // enemies[i].draw(window,deltatime);


           // if(enemies[i].type==0){cout<<"yes\n";}
        }

         for(uint8_t i=0;i<humanlike_enemies.size();i++)
        {
            if((abs(humanlike_enemies[i].x-player.x)<30*32)&&
               (abs(humanlike_enemies[i].y-player.y)<20*32)
               )
                {
                    humanlike_enemies[i].draw(window,deltatime);
                    humanlike_enemies[i].updatedraw();
                    humanlike_enemies[i].livetime=30;
                }

                   // enemies[i].draw(window,deltatime);


           // if(enemies[i].type==0){cout<<"yes\n";}
        }




for(int i=0;i<droppedi.size();i++) /// draw items dropped
            {
            if(droppedi[i].item->placeble())
                {
                 changetexture(blocks_sprite,droppedi[i].item->type,4);
                            blocks_sprite.setPosition(droppedi[i].position.x,droppedi[i].position.y);
                            window.draw(blocks_sprite);

                }else
                {
                  changetexture(items_sprite,droppedi[i].item->type,0);
                            items_sprite.setPosition(droppedi[i].position.x,droppedi[i].position.y);
                            window.draw(items_sprite);

                }

            }
    ///fix screen position
               view.setCenter((int)player.x,(int)player.y);

                  // handleview(view,player,500);

            if(view.getCenter().x<WIDE/2.f){view.setCenter(WIDE/2.f,view.getCenter().y);}
            if(view.getCenter().x>-(WIDE/2.f)+(32*Gamelenght)){view.setCenter(-(WIDE/2.f)+(32*Gamelenght),view.getCenter().y);}
            if(view.getCenter().y<HEIGHT/2.f){view.setCenter(view.getCenter().x,HEIGHT/2.f);}
            if(view.getCenter().y>-(HEIGHT/2.f)+(32*Gameheight)){view.setCenter(view.getCenter().x,-(HEIGHT/2.f)+(32*Gameheight));}
                                                           ///fix screen position ^



        //message=1/deltatime;

    //inttostring(mesage,1/deltatime);
      //  text.setPosition(view.getCenter().x-400,view.getCenter().y+320);
      //  text.setString(mesage);






           window.setView(view);

          // system("cls");
          // cout<<enemies[0].timetillnextmove<<endl;

#ifdef DEBUG
text.setPosition(player.x-100,player.y+100);
text.setScale(2,2);
text.setString(inttostring(abs(int(humanlike_enemies[0].velocity.x*deltatime))));
       window.draw(text);
       text.setScale(1,1);

#endif // DEBUG


        drawplayer();


        if(states==gamestates::game)
        {
        handleitemslots();
        }
        else if(states==gamestates::crafting_state)
        {
        crafting();
        blocks_sprite.setScale(1,1);
            items_sprite.setScale(1,1);

        }else if(states==gamestates::invent||states==gamestates::chest_state)
        {
        inventorystate();
         blocks_sprite.setScale(1,1);
             items_sprite.setScale(1,1);

        }

        showhearts();


        //window.draw(player_sprite);
        //window.draw(player_sprite);
        window.display();
        window.clear(sf::Color(11,107,237));
        handle_background();

        lastbiome=curentbiome;


           // system("cls");
            //cout<<curentbiome<<endl;


//system("cls");
//cout<<touchesentities<<endl;
//cout<<"pointing to x "<<pointingto.x*32+16<<endl;
//cout<<"player x center "<<player.getcenterx()<<endl;
//cout<<(player==pointingto)<<endl;
//cout<<pointingto.x<<endl;
//cout<<1/deltatime<<endl;
              //  cout<<playervelocity.x<<endl;
                //cout<<(int)player.x/32<<endl;
                //cout<<player.x/32<<endl;
               // cout<<(int)player.y/32<<endl;


          //  cout<<deltax<<endl<<deltay<<endl;
          //  cout<<intersectx<<endl<<intersecty<<endl;


        }else
        {           ///main menu
            mainmenuf();

        whaittime=randomrange(30,60);
        spawnwaittime=randomrange(10,20);



        }

}
       /*
        case gamestates::invent:
            {
                inventorystate();

                view.setCenter(WIDE/2,HEIGHT/2);
                window.setView(view);
                window.display();
                window.clear(sf::Color(10,10,50));
                break;
            }
         case gamestates::crafting_state:
            {
                crafting();

                view.setCenter(WIDE/2,HEIGHT/2);
                window.setView(view);
                window.display();
                window.clear(sf::Color(10,10,50));
                break;
            }
        */
    }

    return 0;
}
