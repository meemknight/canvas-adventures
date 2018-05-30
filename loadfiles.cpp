#include <windows.h>
#include <fstream>
#include "blocks.h"
#include "enum.h"
#include "entities.h"
#include "headerfiles/declarations.h"
#include "items.h"
#define INVENTORY_SIZE 30
#include "Craftingrecepies.h"
#include <vector>

using namespace std;
extern bl::blocks world[Gamelenght][Gameheight];
extern bl::blocks walls[Gamelenght][Gameheight];

extern std::vector<slimeentity> enemies;
extern std::vector<humanlikeenemy> humanlike_enemies;

extern playerentity player;
extern items* inventory[INVENTORY_SIZE];

extern int curentbiome;



    extern Craftingrecepies recepies[100];
    extern int nrofrecepies;


extern sf::Texture slimetxture;
extern sf::Texture blueslimetxture;
extern sf::Texture sandslimetexture;
extern sf::Texture iceslimetexture;
extern sf::Texture smallblueslimetexture;




void loadmap(int index)
{
     ifstream file;

if(index==1)
    {file.open("map1\\map.txt");}else
    if(index==2)
        {file.open("map2\\map.txt");}
    else if(index==3)
    {file.open("map3\\map.txt");}else{exit(1);}

if(!file.is_open())
{
::MessageBox(HWND_DESKTOP,"Can't find the map file","Error",MB_OK|MB_ICONERROR);
//exit(ERROR_FILE_INVALID);
}
string input;
    int x=0;
    int y=0;

while(file>>input)
    {

    while(x<input.length()&&y<Gameheight)
        {
            if(x<Gamelenght){
        switch(input[x])
            {
        case '0':{world[x][y].type=bl::air;break;}
        case 'a':{world[x][y].type=bl::dirt;break;}
        case 'b':{world[x][y].type=bl::grass;break;}
        case 'c':{world[x][y].type=bl::stone;break;}
        case 'd':{world[x][y].type=bl::plants;break;}
        case 'e':{world[x][y].type=bl::sand;break;}
        case 'f':{world[x][y].type=bl::woodenplank;break;}
        case 'g':{world[x][y].type=bl::stonebricks;break;}
        case 'h':{world[x][y].type=bl::clay;break;}
        case 'i':{world[x][y].type=bl::wood;break;}
        case 'j':{world[x][y].type=bl::leafs;break;}
        case 'k':{world[x][y].type=bl::copper;break;}
        case 'l':{world[x][y].type=bl::iron;break;}
        case 'm':{world[x][y].type=bl::gold;break;}
        case 'n':{world[x][y].type=bl::bricks;break;}
        case 'o':{world[x][y].type=bl::glass;break;}
        case 'q':{world[x][y].type=bl::platform;break;}
        case 'r':{world[x][y].type=bl::workbench;break;}
        case 's':{world[x][y].type=bl::goldblock;break;}
        case 't':{world[x][y].type=bl::ironblock;break;}
        case 'u':{world[x][y].type=bl::copperblock;break;}
        case 'v':{world[x][y].type=bl::snowblock;break;}
        case 'w':{world[x][y].type=bl::iceblock;break;}
        case 'x':{world[x][y].type=bl::furnace;break;}
        case 'y':{world[x][y].type=bl::painting;break;}
        case 'z':{world[x][y].type=bl::sand_ruby;break;}
        case 'A':{world[x][y].type=bl::sandstone;break;}
        case 'B':{world[x][y].type=bl::rubbyblock;break;}
        case 'C':{world[x][y].type=bl::sappling;break;}
        case 'D':{world[x][y].type=bl::snow_gem;break;}
        case 'E':{world[x][y].type=bl::ice_gem_block;break;}
        case 'F':{world[x][y].type=bl::wodden_door;break;}
        case 'G':{world[x][y].type=bl::bottle;break;}
        case 'H':{world[x][y].type=bl::table;break;}
        case 'I':{world[x][y].type=bl::wardrobe;break;}
        case 'J':{world[x][y].type=bl::book_shelf;break;}
        case 'K':{world[x][y].type=bl::ice_bricks;break;}
        case 'L':{world[x][y].type=bl::ice_table;break;}
        case 'M':{world[x][y].type=bl::ice_wardrobe;break;}
        case 'N':{world[x][y].type=bl::ice_book_shelf;break;}
        case 'O':{world[x][y].type=bl::ice_platform;break;}
        case 'P':{world[x][y].type=bl::sand_table;break;}
        case 'Q':{world[x][y].type=bl::sand_wardrobe;break;}
        case 'R':{world[x][y].type=bl::sand_book_shelf;break;}
        case 'S':{world[x][y].type=bl::sand_platform;break;}
        case 'T':{world[x][y].type=bl::chest;break;}
        case 'U':{world[x][y].type=bl::ice_chest;break;}
        case 'V':{world[x][y].type=bl::sand_chest;break;}
        case 'W':{world[x][y].type=bl::dungeon_chest;break;}
        case 'X':{world[x][y].type=bl::dungeon_block;break;}
        case 'Y':{world[x][y].type=bl::dungeon_table;break;}
        case 'Z':{world[x][y].type=bl::dungeon_wordrobe;break;}
        case '1':{world[x][y].type=bl::dungeon_bookshelf;break;}
        case '2':{world[x][y].type=bl::dungeon_platform;break;}


        default:world[x][y].type=0;

            }
        }
        x++;
        }
    x=0;
    y++;
    }


file.close();

//////////////////////////////////////////////////////walls \/
x=0;
y=0;



if(index==1)
    {file.open("map1\\walls.txt");}else
    if(index==2)
        {file.open("map2\\walls.txt");}
    else if(index==3)
    {file.open("map3\\walls.txt");}else{exit(1);}


if(!file.is_open())
{
::MessageBox(HWND_DESKTOP,"Can't find the walls file","Error",MB_OK|MB_ICONERROR);
//exit(ERROR_FILE_INVALID);
}
input.clear();
while(file>>input)
    {

    while(x<input.length()&&y<Gameheight)
        {
            if(x<Gamelenght){
        switch(input[x])
            {
        case '0':{walls[x][y].type=bl::air;break;}
        case 'a':{walls[x][y].type=bl::dirt_wall;break;}
        case 'b':{walls[x][y].type=bl::stone_wall;break;}
        case 'c':{walls[x][y].type=bl::wodden_wall;break;}
        case 'd':{walls[x][y].type=bl::brick_wall;break;}
        case 'e':{walls[x][y].type=bl::glass_wall;break;}
        case 'f':{walls[x][y].type=bl::copper_wall;break;}
        case 'g':{walls[x][y].type=bl::iron_wall;break;}
        case 'h':{walls[x][y].type=bl::gold_wall;break;}
        case 'i':{walls[x][y].type=bl::snow_wall;break;}
        case 'j':{walls[x][y].type=bl::sand_wall;break;}
        case 'k':{walls[x][y].type=bl::stonebricks_wall;break;}
        case 'l':{walls[x][y].type=bl::sandstone_wall;break;}
        case 'm':{walls[x][y].type=bl::rubby_wall;break;}
        case 'n':{walls[x][y].type=bl::heroglyphics;break;}
        case 'o':{walls[x][y].type=bl::ice_gem_wall;break;}
        case 'p':{walls[x][y].type=bl::wodden_stone_wall;break;}
        case 'q':{walls[x][y].type=bl::ice_brick_wall;break;}
        case 'r':{walls[x][y].type=bl::dungeon_wall;break;}



            }
        }
        x++;
        }
    x=0;
    y++;
    }


file.close();

if(index==1)
    {file.open("map1\\playerstats.txt");}else
    if(index==2)
        {file.open("map2\\playerstats.txt");}
    else if(index==3)
    {file.open("map3\\playerstats.txt");}else{exit(1);}


if(!file.is_open())
{
::MessageBox(HWND_DESKTOP,"Can't find the player file","Error",MB_OK|MB_ICONERROR);
//exit(ERROR_FILE_INVALID);
}

file>>player.x>>player.y>>player.spawnpoint.x>>player.spawnpoint.y>>player.life>>curentbiome;
int a,b;

for(int i=0;i<INVENTORY_SIZE;i++)
    {file>>a;
        if(a)
            {
                file>>a;file>>b;
            inventory[i]=new normalitems(a,b);
            }else
            {
                file>>a;file>>b;
            inventory[i]=new nonplaceble(a,b);
            }

    }



file.close();

file.open("resources\\crafting.txt");
 if(!file.is_open())
{
::MessageBox(HWND_DESKTOP,"Can't find the crafting file","Error",MB_OK|MB_ICONERROR);
//exit(ERROR_FILE_INVALID);
}

int w[16];
int count=0;
while(!file.eof())
    {
    for(int i=0;i<16;i++)
        {
        file>>w[i];
        }
        recepies[count].create(Craftebleitem(w[0],w[1],w[2]),Craftebleitem(w[3],w[4],w[5]),Craftebleitem(w[6],w[7],w[8]),Craftebleitem(w[9],w[10],w[11]),Craftebleitem(w[12],w[13],w[14]),w[15]);

    count++;
    }

nrofrecepies=count;
//nrofrecepies--;
file.close();

if(index==1)
    {file.open("map1\\enemies.txt");}else
    if(index==2)
        {file.open("map2\\enemies.txt");}
    else if(index==3)
    {file.open("map3\\enemies.txt");}else{exit(1);}


if(!file.is_open())
{
::MessageBox(HWND_DESKTOP,"Can't the enemies file","Error",MB_OK|MB_ICONERROR);
//exit(ERROR_FILE_INVALID);
}


while(!file.eof())
    { file>>a;

          enemies.push_back(et::getslime(a));

       file>>enemies[enemies.size()-1].x>>enemies[enemies.size()-1].y
        >>enemies[enemies.size()-1].lineofsight>>enemies[enemies.size()-1].frametime>>enemies[enemies.size()-1].jumpheight.x>>enemies[enemies.size()-1].jumpheight.y>>enemies[enemies.size()-1].speed.x
    >>enemies[enemies.size()-1].speed.y>>enemies[enemies.size()-1].maxlife>>enemies[enemies.size()-1].life>>enemies[enemies.size()-1].attatc;
    enemies[enemies.size()-1].timetillnextmove=0;
    enemies[enemies.size()-1].whaittime=randomrange(2,5);
    }

    if(enemies.size()!=0){enemies.pop_back();}


file.close();

    if(index==1)
    {file.open("map1\\humane.txt");}else
    if(index==2)
        {file.open("map2\\humane.txt");}
    else if(index==3)
    {file.open("map3\\humane.txt");}else{exit(1);}


if(!file.is_open())
{
::MessageBox(HWND_DESKTOP,"Can't load the humanlike enemies \nfile","Error",MB_OK|MB_ICONERROR);
//exit(ERROR_FILE_INVALID);
}



while(!file.eof())
    {
         file>>a;
         humanlike_enemies.push_back(et::gethumanlikeenemy(a));

        file>>humanlike_enemies[humanlike_enemies.size()-1].x>>humanlike_enemies[humanlike_enemies.size()-1].y>>
       humanlike_enemies[humanlike_enemies.size()-1].lineofsight>>humanlike_enemies[humanlike_enemies.size()-1].frametime>>humanlike_enemies[humanlike_enemies.size()-1].jumpheight.x>>
        humanlike_enemies[humanlike_enemies.size()-1].jumpheight.y>>humanlike_enemies[humanlike_enemies.size()-1].speed.x>>humanlike_enemies[humanlike_enemies.size()-1].speed.y>>humanlike_enemies[humanlike_enemies.size()-1].maxlife>>
        humanlike_enemies[humanlike_enemies.size()-1].life>>humanlike_enemies[humanlike_enemies.size()-1].attatc>>humanlike_enemies[humanlike_enemies.size()-1].timemove;
    }

  // if(humanlike_enemies.size()!=0){humanlike_enemies.pop_back();}



file.close();



}

void savemap(int index)
{
    ofstream file;

if(index==1)
    {file.open("map1\\map.txt");}else
    if(index==2)
        {file.open("map2\\map.txt");}
    else if(index==3)
    {file.open("map3\\map.txt");}else{exit(1);}



    file.clear();
    for(int ii=0;ii<Gameheight;ii++) ///inaltime
    {
        for(int i=0;i<Gamelenght;i++) ///lungime
        {
            switch (world[i][ii].type)
            {
            case bl::air:file<<'0';
            break;
            case bl::dirt:file<<'a';
            break;
            case bl::grass:file<<'b';
            break;
            case bl::stone:file<<'c';
            break;
            case bl::plants:file<<'d';
            break;
            case bl::sand:file<<'e';
            break;
            case bl::woodenplank:file<<'f';
            break;
            case bl::stonebricks:file<<'g';
            break;
            case bl::clay:file<<'h';
            break;
            case bl::wood:file<<'i';
            break;
            case bl::leafs:file<<'j';
            break;
            case bl::copper:file<<'k';
            break;
            case bl::iron:file<<'l';
            break;
            case bl::gold:file<<'m';
            break;
            case bl::bricks:file<<'n';
            break;
            case bl::glass:file<<'o';
            break;
             case bl::platform:file<<'q';
            break;
            case bl::workbench:file<<'r';
            break;
             case bl::goldblock:file<<'s';
            break;
            case bl::ironblock:file<<'t';
            break;
            case bl::copperblock:file<<'u';
            break;
             case bl::snowblock:file<<'v';
            break;
            case bl::iceblock:file<<'w';
            break;
            case bl::furnace:file<<'x';
            break;
            case bl::painting:file<<'y';
            break;
            case bl::sand_ruby:file<<'z';
            break;
            case bl::sandstone:file<<'A';
            break;
            case bl::rubbyblock:file<<'B';
            break;
             case bl::sappling:file<<'C';
            break;
            case bl::snow_gem:file<<'D';
            break;
             case bl::ice_gem_block:file<<'E';
            break;
             case bl::wodden_door:file<<'F';
            break;
               case bl::bottle:file<<'G';
            break;
               case bl::table:file<<'H';
            break;
              case bl::wardrobe:file<<'I';
            break;
              case bl::book_shelf:file<<'J';
            break;
            case bl::ice_bricks:file<<'K';break;
            case bl::ice_table:file<<'L';break;
            case bl::ice_wardrobe:file<<'M';break;
            case bl::ice_book_shelf:file<<'N';break;
            case bl::ice_platform:file<<'O';break;
            case bl::sand_table:file<<'P';break;
            case bl::sand_wardrobe:file<<'Q';break;
            case bl::sand_book_shelf:file<<'R';break;
            case bl::sand_platform:file<<'S';break;
            case bl::chest:file<<'T';break;
            case bl::ice_chest:file<<'U';break;
            case bl::sand_chest:file<<'V';break;
            case bl::dungeon_chest:file<<'W';break;
            case bl::dungeon_block:file<<'X';break;
            case bl::dungeon_table:file<<'Y';break;
            case bl::dungeon_wordrobe:file<<'Z';break;
            case bl::dungeon_bookshelf:file<<'1';break;
            case bl::dungeon_platform:file<<'2';break;


            }

        }
 file<<endl<<flush;
    }

file.close();
                                        /////////////////////////////// walls  \/


if(index==1)
    {file.open("map1\\walls.txt");}else
    if(index==2)
        {file.open("map2\\walls.txt");}
    else if(index==3)
    {file.open("map3\\walls.txt");}else{exit(1);}


    file.clear();
    for(int ii=0;ii<Gameheight;ii++) ///inaltime
    {
        for(int i=0;i<Gamelenght;i++) ///lungime
        {
            switch (walls[i][ii].type)
            {
            case bl::air:file<<'0';
            break;
            case bl::dirt_wall:file<<'a';
            break;
             case bl::stone_wall:file<<'b';
            break;
             case bl::wodden_wall:file<<'c';
            break;
              case bl::brick_wall:file<<'d';
            break;
              case bl::glass_wall:file<<'e';
            break;
             case bl::copper_wall:file<<'f';
            break;
            case bl::iron_wall:file<<'g';
            break;
             case bl::gold_wall:file<<'h';
            break;
             case bl::snow_wall:file<<'i';
            break;
            case bl::sand_wall:file<<'j';
            break;
             case bl::stonebricks_wall:file<<'k';
            break;
              case bl::sandstone_wall:file<<'l';
            break;
            case bl::rubby_wall:file<<'m';
            break;
            case bl::heroglyphics:file<<'n';
            break;
            case bl::ice_gem_wall:file<<'o';
            break;
             case bl::wodden_stone_wall:file<<'p';
            break;
             case bl::ice_brick_wall:file<<'q';
            break;
            case bl::dungeon_wall:file<<'r';
            break;


            default:file<<'0';

            }

        }
 file<<endl<<flush;
    }

file.close();



if(index==1)
    {file.open("map1\\playerstats.txt");}else
    if(index==2)
        {file.open("map2\\playerstats.txt");}
    else if(index==3)
    {file.open("map3\\playerstats.txt");}else{exit(1);}

if(!file.is_open())
{
::MessageBox(HWND_DESKTOP,"Can't the player stats file","Error",MB_OK|MB_ICONERROR);
//exit(ERROR_FILE_INVALID);
}
file.clear();

file<<player.x<<" "<<player.y<<" "<<player.spawnpoint.x<<" "<<player.spawnpoint.y<<" "<<player.life<<" "<<curentbiome;
file<<endl;

for(int i=0;i<INVENTORY_SIZE;i++)
    {
        file<<inventory[i]->placeble()<<" "<<(int)inventory[i]->type<<" "<<(int)inventory[i]->number;
        file<<endl;
    }


file.close();


if(index==1)
    {file.open("map1\\enemies.txt");}else
    if(index==2)
        {file.open("map2\\enemies.txt");}
    else if(index==3)
    {file.open("map3\\enemies.txt");}else{exit(1);}



if(!file.is_open())
{
::MessageBox(HWND_DESKTOP,"Can't the enemies file","Error",MB_OK|MB_ICONERROR);
//exit(ERROR_FILE_INVALID);
}

file.clear();

for(int i=0;i<enemies.size();i++)
    {

          file<<enemies[i].type<<" "<<enemies[i].x<<" "<<enemies[i].y;
        file<<" "<<(int)enemies[i].lineofsight<<" "<<enemies[i].frametime<<" "<<enemies[i].jumpheight.x<<" "<<enemies[i].jumpheight.y<<" "<<enemies[i].speed.x;
    file<<" "<<enemies[i].speed.y<<" "<<enemies[i].maxlife<<" "<<enemies[i].life<<" "<<enemies[i].attatc
    <<endl<<flush;

    }


file.close();

if(index==1)
    {file.open("map1\\humane.txt");}else
    if(index==2)
        {file.open("map2\\humane.txt");}
    else if(index==3)
    {file.open("map3\\humane.txt");}else{exit(1);}


for(int i=0;i<humanlike_enemies.size();i++)
    {
        file<<humanlike_enemies[i].type<<" "<<humanlike_enemies[i].x<<" "<<humanlike_enemies[i].y<<" "
        <<(int)humanlike_enemies[i].lineofsight<<" "<<humanlike_enemies[i].frametime<<" "<<humanlike_enemies[i].jumpheight.x<<" "
        <<humanlike_enemies[i].jumpheight.y<<" "<<humanlike_enemies[i].speed.x<<" "<<humanlike_enemies[i].speed.y<<" "<<humanlike_enemies[i].maxlife<<" "
        <<humanlike_enemies[i].life<<" "<<humanlike_enemies[i].attatc<<" "<<humanlike_enemies[i].timemove<<endl;
    }




file.close();



}
