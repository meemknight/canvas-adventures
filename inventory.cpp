#include<SFML/Graphics.hpp>
#include "headerfiles/declarations.h"
#include "Craftingrecepies.h"
#include "items.h"
#include <iostream>
#include <cstdlib>

#define INVENTORY_SIZE 30

#define xview (view.getCenter().x-WIDE/2)
#define yview (view.getCenter().y-HEIGHT/2)


using std::cout;
using std::endl;
extern uint8_t states;
extern sf::View view;
extern int numberofitemslots;
extern int WIDE;
extern int HEIGHT;
//extern sf::Texture textures;
extern sf::RenderWindow window;
extern  uint8_t curentblock;

sf::Vector2i currentchest={-1,-1};


extern items* inventory[INVENTORY_SIZE];
extern items* chestbuffer[CHEST_SIZE];

       // items* inventoryhold=new normalitems();

extern sf::Sprite blocks_sprite;
extern sf::Sprite items_sprite;


       sf::Sprite inventory_meniu_sprite;
       sf::Texture inventory_meniu_texture;

extern sf::Text text;

extern bool rightreleased;
extern bool leftreleased;


static int numberofitemslotsb;
items* typehold=new normalitems;
items* typeholdcppy=new normalitems;
items* trash=new normalitems;

static int counting;
static sf::Vector2i pointingto;

static int getpos(sf::Vector2i vect);

void inventorystate()
{

    text.setScale(1,1);
    blocks_sprite.setScale(2,2);
    items_sprite.setScale(2,2);
    inventory_meniu_sprite.setScale(2,2);


    //for(int i=0;i<INVENTORY_SIZE;i++)
      //  {
       // inventory[i]->maxnumber=225;
      //  }


    numberofitemslotsb=numberofitemslots;
    counting=0;

    pointingto.x=sf::Mouse::getPosition(window).x/64;
    pointingto.y=sf::Mouse::getPosition(window).y/64;
    pointingto.x-=3;
    pointingto.y-=1;


      ///check buttons
    {   if(leftreleased)
        {
        if(getpos(pointingto)==-3){states=gamestates::crafting_state;return;}
        if(getpos(pointingto)==-4&&currentchest.x!=-1){states=gamestates::chest_state;return;}
        if(getpos(pointingto)==-5){states=gamestates::invent;return;}

        }
    }


    //text.setString("64");

//cout<<pointingto.x;
 //   system("cls");
   // text.setScale(,);

    //text.setColor(sf::Color::Red);
                                                    /// draw  buttons

    inventory_meniu_sprite.setPosition(64*3+xview,0+yview);
    changetexture(inventory_meniu_sprite,0,0);
    window.draw(inventory_meniu_sprite);

    inventory_meniu_sprite.setPosition(64*4+xview,0+yview);
    window.draw(inventory_meniu_sprite);

    changetexture(inventory_meniu_sprite,3,0);
    window.draw(inventory_meniu_sprite);

    inventory_meniu_sprite.setPosition(64*3+xview,0+yview);
    changetexture(inventory_meniu_sprite,2,0);
    window.draw(inventory_meniu_sprite);

    if(currentchest.x!=-1)
        {
            inventory_meniu_sprite.setPosition(64*5+xview,0+yview);
    changetexture(inventory_meniu_sprite,0,0);
    window.draw(inventory_meniu_sprite);

        inventory_meniu_sprite.setPosition(64*5+xview,0+yview);
    changetexture(inventory_meniu_sprite,14,0);
    window.draw(inventory_meniu_sprite);

        }

    if(getpos(pointingto)==-2){changetexture(blocks_sprite,0,2);}else{changetexture(blocks_sprite,0,3);}

        blocks_sprite.setPosition(64*3+xview,64*7+yview);
    window.draw(blocks_sprite);

    inventory_meniu_sprite.setPosition(64*3+xview,64*7+yview);
    changetexture(inventory_meniu_sprite,1,0);
    window.draw(inventory_meniu_sprite);


    for(int y=0;y<6;y++)   ///drawing
    {
      for(int x=0;x<5;x++)
        {
            if(pointingto.x==x&&pointingto.y==y){changetexture(blocks_sprite,0,2);numberofitemslotsb--;}else
            if(numberofitemslotsb>0)
            {
                changetexture(blocks_sprite,0,1);
                numberofitemslotsb--;
            }else{changetexture(blocks_sprite,0,3);}

            blocks_sprite.setPosition((32*3+x*32)*2+xview,(32*1+y*32)*2+yview);
            window.draw(blocks_sprite);

            if(inventory[counting]->placeble())
                {
            changetexture(blocks_sprite,inventory[counting]->type,4); ///draw items
            window.draw(blocks_sprite);
                }else
                {
            items_sprite.setPosition((32*3+x*32)*2+xview,(32*1+y*32)*2+yview);  /// draw tools
            changetexture(items_sprite,inventory[counting]->type,0);
            window.draw(items_sprite);

                }



            if(inventory[getpos(sf::Vector2i(x,y))]->number>1&&inventory[getpos(sf::Vector2i(x,y))]->type)
                {
            text.setPosition((32*3+x*32)*2+xview,(32*1+y*32+16)*2+yview);
            text.setString(inttostring(inventory[getpos(sf::Vector2i(x,y))]->number));
            window.draw(text);
                }

            counting++;
        }

    }                   ///drawing

    if(currentchest.x!=-1&&states==gamestates::chest_state)                                          ///draw chest
        {counting=0;
                          for(int y=0;y<4;y++)   ///drawing
                    {
                      for(int x=0;x<5;x++)
                        {
                            if(pointingto.x==x&&pointingto.y==y){changetexture(blocks_sprite,0,2);numberofitemslotsb--;}else
                            if(numberofitemslotsb>0)
                            {
                                changetexture(blocks_sprite,0,1);
                                numberofitemslotsb--;
                            }else{changetexture(blocks_sprite,0,3);}

                            blocks_sprite.setPosition((32*9+x*32)*2+xview,(32*1+y*32)*2+yview);
                            window.draw(blocks_sprite);

                            if(chestbuffer[counting]->placeble())
                                {
                            changetexture(blocks_sprite,chestbuffer[counting]->type,4); ///draw items
                            window.draw(blocks_sprite);
                                }else
                                {
                            items_sprite.setPosition((32*9+x*32)*2+xview,(32*1+y*32)*2+yview);  /// draw tools
                            changetexture(items_sprite,chestbuffer[counting]->type,0);
                            window.draw(items_sprite);

                                }



                            if(chestbuffer[getpos(sf::Vector2i(x,y))]->number>1&&chestbuffer[getpos(sf::Vector2i(x,y))]->type)
                                {
                            text.setPosition((32*9+x*32)*2+xview,(32*1+y*32+16)*2+yview);
                            text.setString(inttostring(chestbuffer[getpos(sf::Vector2i(x,y))]->number));
                            window.draw(text);
                                }

                            counting++;
                        }

                    }                   ///drawing


        }                             ///draw chest



    if(typehold->type)
        {

            if(typehold->placeble()) ///draw blocks on mouse
            {
        changetexture(blocks_sprite,typehold->type,4);
        blocks_sprite.setPosition(sf::Mouse::getPosition(window).x-32+xview,sf::Mouse::getPosition(window).y-32+yview);
        window.draw(blocks_sprite);
            }else
            {                        ///draw items on mouse
              changetexture(items_sprite,typehold->type,0);
        items_sprite.setPosition(sf::Mouse::getPosition(window).x-32+xview,sf::Mouse::getPosition(window).y-32+yview);
        window.draw(items_sprite);
            }



        if(typehold->number>1)
            {
            text.setString(inttostring(typehold->number));
        text.setPosition(sf::Mouse::getPosition(window).x-32+xview,sf::Mouse::getPosition(window).y+yview);
        window.draw(text);
            }

                        if(states!=gamestates::chest_state)
                            drawitemstats(Craftebleitem(typehold->placeble(),typehold->type,typehold->number),typehold);

                    text.setScale(1,1);
                     text.setColor(sf::Color::Black);
                    text.setOutlineColor(sf::Color::White);

        }



    if(getpos(pointingto)>=0)
        {
        if(pointingto.x<5)
        {

            if(leftreleased)
            {
            if(typehold->type)                                  ///place
            {

            if(typehold->type==inventory[getpos(pointingto)]->type&&typehold->placeble()==inventory[getpos(pointingto)]->placeble()&&inventory[getpos(pointingto)]->number!=inventory[getpos(pointingto)]->maxnumber)
                {
                    if(inventory[getpos(pointingto)]->number+typehold->number<=inventory[getpos(pointingto)]->maxnumber)
                    {
                    inventory[getpos(pointingto)]->number+=typehold->number;
                    delete typehold;
                    typehold=new normalitems();
                    }else
                    {
                         typehold->number-=(typehold->maxnumber-inventory[getpos(pointingto)]->number);
                    inventory[getpos(pointingto)]->number=inventory[getpos(pointingto)]->maxnumber;    ///when filled
                    }


                }else                                                   ///change
                {  if(typehold->placeble()==inventory[getpos(pointingto)]->placeble())   /// same class
                    {
                    *typeholdcppy = *inventory[getpos(pointingto)];
                    *inventory[getpos(pointingto)] = *typehold;
                    *typehold = *typeholdcppy;
                    inventory[getpos(pointingto)]->setmaxnumber();
                    typehold->setmaxnumber();

                    }else
                    {
                    typeholdcppy = inventory[getpos(pointingto)];
                    if(typehold->placeble())
                        {
                        inventory[getpos(pointingto)] =new normalitems(typehold->type,typehold->number);
                        }else
                        {
                        inventory[getpos(pointingto)] =new nonplaceble(typehold->type,typehold->number);
                        inventory[getpos(pointingto)]->setmaxnumber();
                        }
                    delete typehold;
                    if(typeholdcppy->placeble())
                    {
                     typehold =new normalitems(typeholdcppy->type,typeholdcppy->number);

                    }else
                    {
                      typehold =new nonplaceble(typeholdcppy->type,typeholdcppy->number);
                      typehold->setmaxnumber();
                    }


                    }
                }

            }else
            if(inventory[getpos(pointingto)]->type)                            ///take
                {

                    typehold = inventory[getpos(pointingto)];


                    //delete inventory[getpos(pointingto)];
                    inventory[getpos(pointingto)] = new normalitems(0,0);
                }

            }

                    ///////////////////////////////////////////////////////////////////////////////////////////////

             if(rightreleased&&getpos(pointingto)!=-1&&getpos(pointingto)!=-2)
     {
      if(inventory[getpos(pointingto)]->type&&!typehold->type)  ///take
        {
            int a=inventory[getpos(pointingto)]->number/2;
        if(a)
            {if(inventory[getpos(pointingto)]->placeble()) ///take block dreapta
                {
                 *typehold= *inventory[getpos(pointingto)];
                inventory[getpos(pointingto)]->number-=a;
                typehold->number=a;
                }else                                     ///take item dreapta
                {
                typehold= inventory[getpos(pointingto)];
                inventory[getpos(pointingto)]=new nonplaceble(inventory[getpos(pointingto)]->type,inventory[getpos(pointingto)]->number-=a);
                typehold->number=a;
                typehold->setmaxnumber();
                }

            }

        }else if(typehold->type&&typehold->type==inventory[getpos(pointingto)]->type&&typehold->placeble()==inventory[getpos(pointingto)]->placeble()&&getpos(pointingto)!=-2)    ///place
        {
            typehold->number--;
            inventory[getpos(pointingto)]->number++;
            inventory[getpos(pointingto)]->setmaxnumber();
            if(typehold->number<=0)
                {
                  delete typehold;
                    typehold=new normalitems();
                }

        }else if(typehold->type&&inventory[getpos(pointingto)]->type==0&&getpos(pointingto)!=-2)   /// place over air  dreapta
            {
                typehold->number--;

                if(typehold->placeble())
                {
                 *inventory[getpos(pointingto)]= *typehold;
                 inventory[getpos(pointingto)]->setmaxnumber();
                }else
                {
                    delete inventory[getpos(pointingto)];
                inventory[getpos(pointingto)]=new nonplaceble(typehold->type,1);
                 inventory[getpos(pointingto)]->setmaxnumber();
                }
                        inventory[getpos(pointingto)]->number=1;
                        //inventory[getpos(pointingto)]->maxnumber=64;


             if(typehold->number<=0)
                {
                  delete typehold;
                    typehold=new normalitems();
                }
            }


     }

        }else
        {               ///chest/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                  if(leftreleased)
            {
            if(typehold->type)                                  ///place
            {

            if(typehold->type==chestbuffer[getpos(pointingto)]->type&&typehold->placeble()==chestbuffer[getpos(pointingto)]->placeble()&&chestbuffer[getpos(pointingto)]->number!=chestbuffer[getpos(pointingto)]->maxnumber)
                {
                    if(chestbuffer[getpos(pointingto)]->number+typehold->number<=chestbuffer[getpos(pointingto)]->maxnumber)
                    {
                    chestbuffer[getpos(pointingto)]->number+=typehold->number;
                    delete typehold;
                    typehold=new normalitems();
                    }else
                    {
                         typehold->number-=(typehold->maxnumber-chestbuffer[getpos(pointingto)]->number);
                    chestbuffer[getpos(pointingto)]->number=chestbuffer[getpos(pointingto)]->maxnumber;    ///when filled
                    }


                }else                                                   ///change
                {  if(typehold->placeble()==chestbuffer[getpos(pointingto)]->placeble())   /// same class
                    {
                    *typeholdcppy = *chestbuffer[getpos(pointingto)];
                    *chestbuffer[getpos(pointingto)] = *typehold;
                    *typehold = *typeholdcppy;
                    chestbuffer[getpos(pointingto)]->setmaxnumber();
                    typehold->setmaxnumber();

                    }else
                    {
                    typeholdcppy = chestbuffer[getpos(pointingto)];
                    if(typehold->placeble())
                        {
                        chestbuffer[getpos(pointingto)] =new normalitems(typehold->type,typehold->number);
                        }else
                        {
                        chestbuffer[getpos(pointingto)] =new nonplaceble(typehold->type,typehold->number);
                        chestbuffer[getpos(pointingto)]->setmaxnumber();
                        }
                    delete typehold;
                    if(typeholdcppy->placeble())
                    {
                     typehold =new normalitems(typeholdcppy->type,typeholdcppy->number);

                    }else
                    {
                      typehold =new nonplaceble(typeholdcppy->type,typeholdcppy->number);
                      typehold->setmaxnumber();
                    }


                    }
                }

            }else
            if(chestbuffer[getpos(pointingto)]->type)                            ///take
                {

                    typehold = chestbuffer[getpos(pointingto)];


                    //delete chestbuffer[getpos(pointingto)];
                    chestbuffer[getpos(pointingto)] = new normalitems(0,0);
                }

            }

                    ///////////////////////////////////////////////////////////////////////////////////////////////

             if(rightreleased&&getpos(pointingto)!=-1&&getpos(pointingto)!=-2)
     {
      if(chestbuffer[getpos(pointingto)]->type&&!typehold->type)  ///take
        {
            int a=chestbuffer[getpos(pointingto)]->number/2;
        if(a)
            {if(chestbuffer[getpos(pointingto)]->placeble()) ///take block dreapta
                {
                 *typehold= *chestbuffer[getpos(pointingto)];
                chestbuffer[getpos(pointingto)]->number-=a;
                typehold->number=a;
                }else                                     ///take item dreapta
                {
                typehold= chestbuffer[getpos(pointingto)];
                chestbuffer[getpos(pointingto)]=new nonplaceble(chestbuffer[getpos(pointingto)]->type,chestbuffer[getpos(pointingto)]->number-=a);
                typehold->number=a;
                typehold->setmaxnumber();
                }

            }

        }else if(typehold->type&&typehold->type==chestbuffer[getpos(pointingto)]->type&&typehold->placeble()==chestbuffer[getpos(pointingto)]->placeble()&&getpos(pointingto)!=-2)    ///place
        {
            typehold->number--;
            chestbuffer[getpos(pointingto)]->number++;
            chestbuffer[getpos(pointingto)]->setmaxnumber();
            if(typehold->number<=0)
                {
                  delete typehold;
                    typehold=new normalitems();
                }

        }else if(typehold->type&&chestbuffer[getpos(pointingto)]->type==0&&getpos(pointingto)!=-2)   /// place over air  dreapta
            {
                typehold->number--;

                if(typehold->placeble())
                {
                 *chestbuffer[getpos(pointingto)]= *typehold;
                 chestbuffer[getpos(pointingto)]->setmaxnumber();
                }else
                {
                    delete chestbuffer[getpos(pointingto)];
                chestbuffer[getpos(pointingto)]=new nonplaceble(typehold->type,1);
                 chestbuffer[getpos(pointingto)]->setmaxnumber();
                }
                        chestbuffer[getpos(pointingto)]->number=1;
                        //chestbuffer[getpos(pointingto)]->maxnumber=64;


             if(typehold->number<=0)
                {
                  delete typehold;
                    typehold=new normalitems();
                }
            }


     }

        }           ///chest////////////////////////chest    ^^^^


    }



     ///    trash
     if(getpos(pointingto)==-2)
        {
        if(leftreleased)
            {
            typehold->type=0;
            typehold->number=0;
            }else
        if(rightreleased)
            {
           // typehold->type=0;
            typehold->number--;
            if(typehold->number<=0)
                {
                    typehold->type=0;
            typehold->number=0;
                }

            }


        }


    blocks_sprite.setScale(1,1);
    items_sprite.setScale(1,1);

//  system("cls");
//    cout<<getpos(pointingto)<<endl<<flush;



}

static int getpos(sf::Vector2i vect)
{
    if(vect.y==6&&vect.x==0){return -2;}
    if(vect.y==-1&&vect.x==1){return -3;}//crafting
    if(vect.y==-1&&vect.x==2){return -4;}//chest
    if(vect.y==-1&&vect.x==0){return -5;}//inventory
    if(vect.x==5){return -1;}///no
    if(vect.x>5&&vect.y>3){return -1;}
    if(vect.x>10){return -1;}///no
    if(vect.y>5){return -1;}
    if(vect.x<0){return -1;}///no
    if(vect.y<0){return -1;}


    if(vect.x>5)
        {
        return vect.x-6+vect.y*5;
        }

return vect.x+vect.y*5;



};


