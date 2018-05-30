#include "headerfiles/declarations.h"
#include "Craftingrecepies.h"
#include <vector>
#include <string>


#define xview (view.getCenter().x-WIDE/2)
#define yview (view.getCenter().y-HEIGHT/2)

extern int WIDE;
extern int HEIGHT;
extern sf::View view;
extern sf::RenderWindow window;
extern sf::Sprite blocks_sprite;
extern sf::Sprite items_sprite;
extern sf::Sprite inventory_meniu_sprite;
static int remainingmaterials[4];
extern sf::Text text;

extern std::vector<std::string> blocks_name;
extern std::vector<std::string> items_name;

extern std::vector<std::string> blocks_description;
extern std::vector<std::string> items_description;


void drawitemstats(Craftebleitem rec,items *item)
{
   if(rec.type)
        {


        if(rec.placeble)
            {
            changetexture(blocks_sprite,rec.type,4);
            blocks_sprite.setPosition(10*64+xview,2*64+yview);
            blocks_sprite.setScale(4,4);
            window.draw(blocks_sprite);
            blocks_sprite.setScale(2,2);


            }else
            {
            changetexture(items_sprite,rec.type,0);
            items_sprite.setPosition(10*64+xview,2*64+yview);
            items_sprite.setScale(4,4);
            window.draw(items_sprite);
            items_sprite.setScale(2,2);
            }
        if(rec.number>1)
            {
            //text.scale(2,2);
            text.setPosition(12*64+xview,4*64+yview);
            text.setString(inttostring(rec.number));
            window.draw(text);
           // text.scale(1,1);
            }
                if(rec.type)
                {
                    text.setOutlineColor(sf::Color::Black);
                    text.setColor(sf::Color::White);

                    if(!rec.placeble)
                        {

                if(item->getattackpower())
                    {if(item->getspeed()==4)
                        {text.setString("Very slow speed");}else if(item->getspeed()==3)
                        {text.setString("Slow speed");}else if(item->getspeed()==2)
                        {text.setString("Average sped");}else if(item->getspeed()==1)
                        {text.setString("Fast sped");}else
                        {text.setString("Insanely fast sped");}

                    if(item->gethammerpower()||
                       item->getpickaxepower()||
                       item->getaxepower()
                       )
                        {text.setPosition(13*64+xview,2*64+yview);}else
                        {text.setPosition(13*64+xview,2.5*64+yview);}

                     //   cout<<item->getspeed()/2;
                        window.draw(text);
                    }


                if(item->getaxepower())
                    {
                     text.setString("Axe power ");
                              text.setString(text.getString()+inttostring(item->getaxepower()));
                            text.setPosition(13*64+xview,2.5*64+yview);
                            window.draw(text);
                    }else if(item->getpickaxepower())
                    {
                    text.setString("Pickaxe power ");
                              text.setString(text.getString()+inttostring(item->getpickaxepower()));
                            text.setPosition(13*64+xview,2.5*64+yview);
                            window.draw(text);
                    }else if(item->gethammerpower())
                    {
                        text.setString("Hammer power ");
                              text.setString(text.getString()+inttostring(item->gethammerpower()));
                            text.setPosition(13*64+xview,2.5*64+yview);
                            window.draw(text);
                    }


                    item->type=rec.type;

                    if(item->getattackpower())
                        {

                            text.setString("Attack damage ");
                              text.setString(text.getString()+inttostring(item->getattackpower()));
                            text.setPosition(13*64+xview,3*64+yview);
                            window.draw(text);

                            if(item->splashattack())
                                {
                                text.setPosition(13*64+xview,3.5*64+yview);
                                text.setString("Multi target attack");
                                window.draw(text);
                                }else
                                {
                                text.setPosition(13*64+xview,3.5*64+yview);
                                text.setString("Single target attack");
                                window.draw(text);
                                }

                             text.setString("Attack range ");
                              text.setString(text.getString()+inttostring(item->range()));
                            text.setPosition(13*64+xview,4*64+yview);
                            window.draw(text);

                             text.setString("Attack knockback ");
                              text.setString(text.getString()+inttostring(item->getknockback()));
                            text.setPosition(13*64+xview,4.5*64+yview);
                            window.draw(text);

                        }

                         text.setString(items_name[rec.type]);
                            text.setPosition(13*64+xview,1.5*64+yview);
                            window.draw(text);


                }else
                 {
                 text.setString("Placeble ");
                            text.setPosition(13*64+xview,2.5*64+yview);
                            window.draw(text);

                    text.setString(blocks_name[rec.type]);
                            text.setPosition(13*64+xview,1.5*64+yview);
                            window.draw(text);


                }

                      ///draw description
                if(rec.placeble)
                    {
                       text.setString(blocks_description[rec.type]);
                    }else
                    {
                       text.setString(items_description[rec.type]);
                    }

                         text.setPosition(10*64+xview,4.5*64+yview);
                            window.draw(text);



                        text.setColor(sf::Color::Black);
                        text.setOutlineColor(sf::Color::White);

                }


        }


}
