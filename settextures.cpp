#include <SFML/Graphics.hpp>
#include "headerfiles/declarations.h"
#include "entities.h"
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>

extern playerentity player;

extern sf::Sprite blocks_sprite;

extern sf::Sprite player_sprite;
extern sf::Sprite mouse_sprite;
extern sf::Sprite tree_sprite;

extern sf::Sprite inventory_meniu_sprite;
extern sf::Sprite items_sprite;
extern sf::Sprite heart_sprite;


extern sf::Texture textures;
extern sf::Texture playertexture;
extern sf::Texture treetextures;
extern sf::Texture inventory_meniu_texture;

extern sf::Font font;


extern sf::Texture slimetxture;
extern sf::Texture blueslimetxture;

extern sf::Texture itemstexture;
extern sf::Texture hearttexture;

extern sf::Texture sandslimetexture;
extern sf::Texture iceslimetexture;
extern sf::Texture smallblueslimetexture;


extern sf::Texture defaultbackgroundtexture;
extern sf::Texture desetrtexture;
extern sf::Sprite background_sprite;
extern sf::Texture snowbiometexture;
extern sf::Texture cavebiometexture;

extern sf::Texture zombietexture;


extern sf::Sprite secondbackground;

std::vector<std::string> blocks_name;
std::vector<std::string> items_name;

std::vector<std::string> blocks_description;
std::vector<std::string> items_description;


void settextures()
{
  textures=loadfiles("resources\\textures.png");
  treetextures=loadfiles("resources\\treetextures.png");
  inventory_meniu_texture=loadfiles("resources\\inventorytextures.png");
  itemstexture=loadfiles("resources\\items.png");
  hearttexture=loadfiles("resources\\hearts.png");
  sandslimetexture=loadfiles("resources\\desertslime.png");
  iceslimetexture=loadfiles("resources\\iceslime.png");
  smallblueslimetexture=loadfiles("resources\\smallblueslime.png");
  defaultbackgroundtexture=loadfiles("resources\\default_bg.png");
  desetrtexture=loadfiles("resources\\desert_bg.png");
  snowbiometexture=loadfiles("resources\\snow.png");
  cavebiometexture=loadfiles("resources\\cave_bg.png");
  zombietexture=loadfiles("resources\\zombie.png");
  ///load textures ^



if (!font.loadFromFile("resources\\font.ttf"))
{
    ::MessageBoxA(HWND_DESKTOP,"no font","error",MB_OK);
}



  items_sprite.setTexture(itemstexture);

    background_sprite.setTexture(defaultbackgroundtexture);
    background_sprite.setScale(8,8);
    secondbackground .setScale(8,8);


  inventory_meniu_sprite.setTexture(inventory_meniu_texture);

  mouse_sprite.setTexture(textures);
     mouse_sprite.setTextureRect(sf::IntRect(0,0,32,32));
     blocks_sprite.setTexture(textures);
    heart_sprite.setTexture(hearttexture);


    tree_sprite.setTexture(treetextures);


playertexture=loadfiles("resources\\playersprite.png");
player_sprite.setTexture(playertexture);
//player_sprite.setTextureRect(sf::IntRect(0,0,32,64));

player.sprite.setTexture(playertexture);

///entities
slimetxture=loadfiles("resources\\slime.png");
blueslimetxture=loadfiles("resources\\blueslime.png");

/// ////////////////////////////////////////////////////
blocks_name.reserve(bl::type::last_block);
std::ifstream infile("resources\\blocksname.txt");
    if(!infile.is_open()){MessageBoxA(0,"Error oppening the blocksname file","Error",MB_OK);}

    std::string buff;

    while(getline(infile,buff))
        {
        blocks_name.push_back(buff);

        }

    infile.close();

    items_name.reserve(items::name::last_item);
    infile.open("resources\\itemsname.txt");
    if(!infile.is_open()){MessageBoxA(0,"Error oppening the itemsname file","Error",MB_OK);}

    while(getline(infile,buff))
        {
        items_name.push_back(buff);

        }

    infile.close();

    infile.open("resources\\blocksdescription.txt");
    if(!infile.is_open()){MessageBoxA(0,"Error oppening the blocksdescription file","Error",MB_OK);}
    string tempstring;
    char    tempchar;

     blocks_description.reserve(bl::type::last_block);
    while(!infile.eof())
        {
        infile.read(&tempchar,1);
        if(tempchar=='|')
            {
             blocks_description.push_back(tempstring);
             tempstring="";
            }else
            {
             tempstring+=tempchar;
            }
        }
    infile.close();

     infile.open("resources\\itemsdescription.txt");
    if(!infile.is_open()){MessageBoxA(0,"Error oppening the itemsdescription file","Error",MB_OK);}

     items_description.reserve(items::name::last_item);
    while(!infile.eof())
        {
        infile.read(&tempchar,1);
        if(tempchar=='|')
            {
             items_description.push_back(tempstring);
             tempstring="";
            }else
            {
             tempstring+=tempchar;
            }
        }
    infile.close();

}

void changetexture(sf::Sprite& sprite,int blocktype,int blockvaration,bool revers)
{
    if(revers)
        {
        sprite.setTextureRect(sf::IntRect(32*(blocktype+1),32*blockvaration,-32,32));
        }else
sprite.setTextureRect(sf::IntRect(32*blocktype,32*blockvaration,32,32));

}
