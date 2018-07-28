#include<SFML/Graphics.hpp>
#include "headerfiles/declarations.h"
#include "items.h"
#include "entities.h"
#include "Craftingrecepies.h"
#include "blocks.h"
#include <iostream>
#include <cstdlib>

#define INVENTORY_SIZE 30


#define xview (view.getCenter().x-WIDE/2)
#define yview (view.getCenter().y-HEIGHT/2)

using std::cout;
using std::endl;

extern playerentity player;
extern bl::blocks world[Gamelenght][Gameheight];

bool close_to_a_workbench;
bool close_to_a_furnace;



extern int numberofitemslots;
extern int WIDE;
extern int HEIGHT;
//extern sf::Texture textures;
extern sf::View view;
extern sf::RenderWindow window;
extern  uint8_t curentblock;

extern uint8_t states;
extern items* inventory[INVENTORY_SIZE];
       // items* inventoryhold=new normalitems();

extern sf::Sprite blocks_sprite;
extern sf::Sprite items_sprite;


extern sf::Sprite inventory_meniu_sprite;

static int remainingmaterials[4];

extern sf::Text text;

extern bool rightreleased;
extern bool leftreleased;
//extern bool enterreleased;

static sf::Vector2i pointingto;

static int getbutton(sf::Vector2i vect);

Craftingrecepies recepies[100];

static int selecteditem=0;
static int pedding=0;
static int remainingitems;
int nrofrecepies;
bool enoughspace;
bool enoughmaterials;
bool crafingstations;

items* tempitems;

void crafting()
{


    pointingto.x=sf::Mouse::getPosition(window).x/64;
    pointingto.y=sf::Mouse::getPosition(window).y/64;
    pointingto.x-=3;
    pointingto.y-=2;

    text.setScale(1,1);
    blocks_sprite.setScale(2,2);
    items_sprite.setScale(2,2);
    inventory_meniu_sprite.setScale(2,2);


    inventory_meniu_sprite.setPosition(64*3+xview,0+yview);
    changetexture(inventory_meniu_sprite,0,0);
    window.draw(inventory_meniu_sprite);

    inventory_meniu_sprite.setPosition(64*4+xview,0+yview);
    window.draw(inventory_meniu_sprite);

///quick buttons
    inventory_meniu_sprite.setRotation(-90);
     inventory_meniu_sprite.setPosition(64*2+xview,64*3+yview);
   // changetexture(inventory_meniu_sprite,0,0);
    window.draw(inventory_meniu_sprite);

      inventory_meniu_sprite.setPosition(64*2+xview,64*4+yview);
    window.draw(inventory_meniu_sprite);

         inventory_meniu_sprite.setPosition(64*2+xview,64*5+yview);
    window.draw(inventory_meniu_sprite);

         inventory_meniu_sprite.setPosition(64*2+xview,64*6+yview);
    window.draw(inventory_meniu_sprite);

        inventory_meniu_sprite.setPosition(64*2+xview,64*7+yview);
    window.draw(inventory_meniu_sprite);

    inventory_meniu_sprite.setRotation(0);

        changetexture(inventory_meniu_sprite,inventory_sprites::furniture,0);
         inventory_meniu_sprite.setPosition(64*2+xview,64*2+yview);
        window.draw(inventory_meniu_sprite);

            changetexture(inventory_meniu_sprite,inventory_sprites::weapons,0);
         inventory_meniu_sprite.setPosition(64*2+xview,64*3+yview);
        window.draw(inventory_meniu_sprite);


            changetexture(inventory_meniu_sprite,inventory_sprites::blocks,0);
         inventory_meniu_sprite.setPosition(64*2+xview,64*4+yview);
        window.draw(inventory_meniu_sprite);

            changetexture(inventory_meniu_sprite,inventory_sprites::wals,0);
         inventory_meniu_sprite.setPosition(64*2+xview,64*5+yview);
        window.draw(inventory_meniu_sprite);

           changetexture(inventory_meniu_sprite,inventory_sprites::miscelanious,0);
         inventory_meniu_sprite.setPosition(64*2+xview,64*6+yview);
        window.draw(inventory_meniu_sprite);



///quick buttons
        inventory_meniu_sprite.setPosition(64*4+xview,0+yview);
    changetexture(inventory_meniu_sprite,3,0);
    window.draw(inventory_meniu_sprite);

    inventory_meniu_sprite.setPosition(64*3+xview,0+yview);
    changetexture(inventory_meniu_sprite,2,0);
    window.draw(inventory_meniu_sprite);

    changetexture(inventory_meniu_sprite,inventory_sprites::grey,0);
    inventory_meniu_sprite.setPosition(64*4+xview,64+yview);
    window.draw(inventory_meniu_sprite);

   // changetexture(inventory_meniu_sprite,inventory_sprites::grey,0);
    inventory_meniu_sprite.setPosition(64*5+xview,64+yview);
    window.draw(inventory_meniu_sprite);

    //changetexture(inventory_meniu_sprite,inventory_sprites::grey,0);
    inventory_meniu_sprite.setPosition(64*6+xview,64+yview);
    window.draw(inventory_meniu_sprite);

   // changetexture(inventory_meniu_sprite,inventory_sprites::grey,0);
    inventory_meniu_sprite.setPosition(64*7+xview,64+yview);
    window.draw(inventory_meniu_sprite);

      changetexture(inventory_meniu_sprite,inventory_sprites::grey_border,0);
    inventory_meniu_sprite.setPosition(64*9+xview,2*64+yview);
    inventory_meniu_sprite.setRotation(180);
    window.draw(inventory_meniu_sprite);

    //changetexture(inventory_meniu_sprite,inventory_sprites::grey_border,0);
    inventory_meniu_sprite.setPosition(64*3+xview,64+yview);
        inventory_meniu_sprite.setRotation(0);
    window.draw(inventory_meniu_sprite);

     changetexture(inventory_meniu_sprite,inventory_sprites::arrow,0);
             inventory_meniu_sprite.setRotation(180);
    inventory_meniu_sprite.setPosition(64*6.5+xview,64*2+yview);
    window.draw(inventory_meniu_sprite);
             inventory_meniu_sprite.setRotation(0);

              changetexture(inventory_meniu_sprite,inventory_sprites::grey,0);
    inventory_meniu_sprite.setPosition(64*4+xview,64*7+yview);
    window.draw(inventory_meniu_sprite);

   // changetexture(inventory_meniu_sprite,inventory_sprites::grey,0);
    inventory_meniu_sprite.setPosition(64*5+xview,64*7+yview);
    window.draw(inventory_meniu_sprite);

    //changetexture(inventory_meniu_sprite,inventory_sprites::grey,0);
    inventory_meniu_sprite.setPosition(64*6+xview,64*7+yview);
    window.draw(inventory_meniu_sprite);

   // changetexture(inventory_meniu_sprite,inventory_sprites::grey,0);
    inventory_meniu_sprite.setPosition(64*7+xview,64*7+yview);
    window.draw(inventory_meniu_sprite);

      changetexture(inventory_meniu_sprite,inventory_sprites::grey_border,0);
    inventory_meniu_sprite.setPosition(64*9+xview,8*64+yview);
    inventory_meniu_sprite.setRotation(180);
    window.draw(inventory_meniu_sprite);

    //changetexture(inventory_meniu_sprite,inventory_sprites::grey_border,0);
    inventory_meniu_sprite.setPosition(64*3+xview,64*7+yview);
        inventory_meniu_sprite.setRotation(0);
    window.draw(inventory_meniu_sprite);

     changetexture(inventory_meniu_sprite,inventory_sprites::arrow,0);
       //      inventory_meniu_sprite.setRotation(180);
    inventory_meniu_sprite.setPosition(64*5.5+xview,64*7+yview);
    window.draw(inventory_meniu_sprite);
         //    inventory_meniu_sprite.setRotation(0);

    ///draw items
        if(leftreleased&&getbutton(pointingto)>=0){selecteditem=getbutton(pointingto)+pedding;}    ///buttons
        if(leftreleased&&getbutton(pointingto)==-3){if(pedding)pedding--;}    ///buttons
        if(leftreleased&&getbutton(pointingto)==-4){if(pedding+5<nrofrecepies)pedding++;}    ///buttons

        if(leftreleased&&getbutton(pointingto)==-6){pedding=0;}
        if(leftreleased&&getbutton(pointingto)==-7){pedding=23;}   ///quick buttons
        if(leftreleased&&getbutton(pointingto)==-8){pedding=59;}
        if(leftreleased&&getbutton(pointingto)==-9){pedding=70;}
        if(leftreleased&&getbutton(pointingto)==-10){pedding=86;}


    for(int i=pedding;i<pedding+5;i++)  ///draw result
        {
            if(selecteditem==i){changetexture(blocks_sprite,0,2);}else{changetexture(blocks_sprite,0,3);}
            blocks_sprite.setPosition(8*64+xview,(i+2-pedding)*64+yview);
            window.draw(blocks_sprite);

            if(recepies[i].itemcreated.placeble)
                {
                  changetexture(blocks_sprite,recepies[i].itemcreated.type,4);
            blocks_sprite.setPosition(8*64+xview,(i-pedding+2)*64+yview);
            window.draw(blocks_sprite);
                }else {
                  changetexture(items_sprite,recepies[i].itemcreated.type,0);
            items_sprite.setPosition(8*64+xview,(i+2-pedding)*64+yview);
            window.draw(items_sprite);
                }
              changetexture(inventory_meniu_sprite,inventory_sprites::equals,0);
                inventory_meniu_sprite.setPosition(7*64+xview,(i+2-pedding)*64+yview);
                window.draw(inventory_meniu_sprite);

                if(recepies[i].itemcreated.number>1)
                    {
                    text.setPosition(8*64+xview,(i+2.5-pedding)*64+yview);
                    text.setString(inttostring(recepies[i].itemcreated.number));
                    window.draw(text);

                    }

        for(int ii=0;ii<4;ii++)   ///draw materials
            {
            if(recepies[i].materials[ii].type)
                {
                    // changetexture(blocks_sprite,0,3);
                    //blocks_sprite.setPosition((3+ii)*64,(i+2-pedding)*64);
                   // window.draw(blocks_sprite);

                if(recepies[i].materials[ii].placeble)
                    {
                     changetexture(blocks_sprite,recepies[i].materials[ii].type,4);
                    blocks_sprite.setPosition((3+ii)*64+xview,(i+2-pedding)*64+yview);
                    window.draw(blocks_sprite);
                    }else
                    {
                     changetexture(items_sprite,recepies[i].materials[ii].type,0);
                    items_sprite.setPosition((3+ii)*64+xview,(i+2-pedding)*64+yview);
                    window.draw(items_sprite);
                    }


                }

                 if(recepies[i].materials[ii].number>1)
                    {
                    text.setPosition((3+ii)*64+xview,(i+2.5-pedding)*64+yview);
                    text.setString(inttostring(recepies[i].materials[ii].number));
                    window.draw(text);

                    }

            }


        }


              changetexture(inventory_meniu_sprite,inventory_sprites::grey,0);   ///craft button
    inventory_meniu_sprite.setPosition(64*11+xview,64*7+yview);
    window.draw(inventory_meniu_sprite);

      changetexture(inventory_meniu_sprite,inventory_sprites::grey_border,0);
    inventory_meniu_sprite.setPosition(64*10+xview,7*64+yview);
    //inventory_meniu_sprite.setRotation(180);
    window.draw(inventory_meniu_sprite);

    //changetexture(inventory_meniu_sprite,inventory_sprites::grey_border,0);
         inventory_meniu_sprite.setRotation(180);
    inventory_meniu_sprite.setPosition(64*12+xview,64*8+yview);
    window.draw(inventory_meniu_sprite);
        inventory_meniu_sprite.setRotation(0);
        text.setPosition(64*10+16+xview,7*64+16+yview);
        text.setString("CRAFT");
        window.draw(text);
                                                                        ///craft button

                                                                        ///draw item
                drawitemstats(recepies[selecteditem].itemcreated,tempitems);


                    /// draw item
        crafingstations=0;
        enoughspace=0;
        enoughmaterials=0;

        if(recepies[selecteditem].craftingstation==1)
            {
                blocks_sprite.setPosition(64*13+xview,64*7+yview);
                changetexture(blocks_sprite,bl::workbench,4);
                window.draw(blocks_sprite);

                if(close_to_a_workbench)
                    {
                    crafingstations=1;
                    }else
                    {
                    changetexture(inventory_meniu_sprite,8,0);
                inventory_meniu_sprite.setPosition(64*13+xview,64*7+yview);
                window.draw(inventory_meniu_sprite);
                    }



            }else if(recepies[selecteditem].craftingstation==2)
            {
                    blocks_sprite.setPosition(64*13+xview,64*7+yview);
                changetexture(blocks_sprite,bl::furnace,4);
                window.draw(blocks_sprite);

                if(close_to_a_furnace)
                    {
                    crafingstations=1;
                    }else
                    {
                    changetexture(inventory_meniu_sprite,8,0);
                inventory_meniu_sprite.setPosition(64*13+xview,64*7+yview);
                window.draw(inventory_meniu_sprite);
                    }

            }





        //recepies[selecteditem].itemcreated

        remainingmaterials[0]=recepies[selecteditem].materials[0].number;
        remainingmaterials[1]=recepies[selecteditem].materials[1].number;
        remainingmaterials[2]=recepies[selecteditem].materials[2].number;
        remainingmaterials[3]=recepies[selecteditem].materials[3].number;

                                                    ///check enough materials
         for(int i=0;i<INVENTORY_SIZE;i++)
        {
            for(int ii=0;ii<4;ii++)
                {
                if(recepies[selecteditem].materials[ii].placeble==inventory[i]->placeble()&&
                   recepies[selecteditem].materials[ii].type==inventory[i]->type)
                   {
                   remainingmaterials[ii]-=inventory[i]->number;break;
                   }

                }

        }

        if(remainingmaterials[0]<=0&&
           remainingmaterials[1]<=0&&
           remainingmaterials[2]<=0&&
           remainingmaterials[3]<=0
           ){enoughmaterials=1;}


            ///check enough space
        for(int i=0;i<INVENTORY_SIZE;i++)
            {
                if(inventory[i]->type==0){enoughspace=1;break;}
            }

        if(!enoughspace)
        { remainingitems=recepies[selecteditem].itemcreated.number;

            for(int i=0;i<INVENTORY_SIZE;i++)
            {
             if(recepies[selecteditem].itemcreated.placeble==inventory[i]->placeble()
                &&recepies[selecteditem].itemcreated.type==inventory[i]->type
                &&inventory[i]->number<inventory[i]->maxnumber)
                    {
                        remainingitems-=(inventory[i]->maxnumber-inventory[i]->number);
                        if(remainingitems<=0){enoughspace=1;break;}
                    }
            }
        }


        text.setColor(sf::Color::Red);
        text.setOutlineColor(sf::Color::Black);
        if(!enoughmaterials)
            {
             text.setPosition(64*10+16+xview,8*64+16+yview);
            text.setString("NOT ENOUGH MATERIALS");
            window.draw(text);
            }

        if(!enoughspace)
            {
            text.setPosition(64*10+16+xview,9*64+16+yview);
            text.setString("NOT ENOUGH SPACE");
            window.draw(text);
            }
        text.setColor(sf::Color::Black);
        text.setOutlineColor(sf::Color::White);


                    ///push craft


        if(getbutton(pointingto)==-5&&leftreleased)
            {

            if(enoughspace&&enoughmaterials&&crafingstations)
                {
        remainingmaterials[0]=recepies[selecteditem].materials[0].number;
        remainingmaterials[1]=recepies[selecteditem].materials[1].number;
        remainingmaterials[2]=recepies[selecteditem].materials[2].number;
        remainingmaterials[3]=recepies[selecteditem].materials[3].number;
                ///take resourses
             for(int i=0;i<INVENTORY_SIZE;i++)
        {
             for(int ii=0;ii<4;ii++)
                {
                if(recepies[selecteditem].materials[ii].placeble==inventory[i]->placeble()&&
                   recepies[selecteditem].materials[ii].type==inventory[i]->type)
                   {
                       if(inventory[i]->number-remainingmaterials[ii]>=0)
                        {
                         inventory[i]->number-=remainingmaterials[ii];
                         remainingmaterials[ii]=0;break;
                        }else
                        {
                        remainingmaterials[ii]-=inventory[i]->number;
                        inventory[i]->number=0;inventory[i]->type=0;
                       break;
                        }

                   }

                }

        }


                remainingitems=recepies[selecteditem].itemcreated.number;

            for(int i=0;i<INVENTORY_SIZE;i++)
                {
                if(inventory[i]->placeble()==recepies[selecteditem].itemcreated.placeble&&inventory[i]->type==recepies[selecteditem].itemcreated.type)
                    {
                        if(inventory[i]->number+remainingitems<=inventory[i]->maxnumber)
                        {

                            inventory[i]->number+=remainingitems;
                            remainingitems=0;break;
                        }else if(inventory[i]->number<=inventory[i]->maxnumber)
                        {
                            remainingitems-=inventory[i]->maxnumber-inventory[i]->number;
                            inventory[i]->number=inventory[i]->maxnumber;
                          //   cout<<remainingitems<<endl;
                        }

                    }
                    if(remainingitems<=0){break;}

                }

            if(remainingitems>0)
            for(int i=0;i<INVENTORY_SIZE;i++) ///empty spaces
                {
                if(!inventory[i]->type)
                    {
                    delete inventory[i];

                        if(recepies[selecteditem].itemcreated.placeble)
                        {
                         inventory[i]=new normalitems(recepies[selecteditem].itemcreated.type,remainingitems);
                        }else
                        {
                         inventory[i]=new nonplaceble(recepies[selecteditem].itemcreated.type,remainingitems);
                        }
                    break;
                    }


                }

            }
            }





    if(getbutton(pointingto)==-2&&leftreleased){states=gamestates::invent;return;}

    text.setScale(1,1);

     blocks_sprite.setScale(1,1);
    items_sprite.setScale(1,1);
   // inventory_meniu_sprite.setScale(2,2);
}

static int getbutton(sf::Vector2i vect)
{
if(vect.x==0&&vect.y==-2){return -2;}///inventory
if(vect.x>=0&&vect.x<6&&vect.y>=0&&vect.y<5){return vect.y;}
if(vect.x>=0&&vect.x<6&&vect.y==-1){return -3;}
if(vect.x>=0&&vect.x<6&&vect.y==5){return -4;}
if(vect.y==5&&vect.x>=7&&vect.x<=8){return -5;}

if(vect.x==-1&&vect.y==0){return -6;} //quick buttons
if(vect.x==-1&&vect.y==1){return -7;} //quick buttons
if(vect.x==-1&&vect.y==2){return -8;} //quick buttons
if(vect.x==-1&&vect.y==3){return -9;} //quick buttons
if(vect.x==-1&&vect.y==4){return -10;} //quick buttons


return -1;
}

void checkstations()
{int a,b;
a=player.x/32;
b=player.y/32;

close_to_a_workbench=0;
close_to_a_furnace=0;

if(a-2<0){a=3;}
if(b-2<0){b=3;}

if(a+3>Gamelenght){a=Gamelenght-3;}
if(b+3>Gameheight){a=Gameheight-3;}


      for(int x=a-3;x<a+3;x++)
        {
        for(int y=b-3;y<b+3;y++)
            {
            if(world[x][y].type==bl::workbench){close_to_a_workbench=1;}
            else if(world[x][y].type==bl::furnace){close_to_a_furnace=1;}
            }

        }



}



