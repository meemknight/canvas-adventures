#include "headerfiles/declarations.h"

extern playerentity player;

extern int WIDE;
extern int HEIGHT;
extern int curentbiome;
extern int difficulty;

extern std::vector<slimeentity> enemies;
extern std::vector<humanlikeenemy> humanlike_enemies;


//    enemies.push_back(et::getslime(et::green_slime));

void spawnmonster()
{


    int spawnx;
    int spawny;

    if(player.x<WIDE){goto dreapta;}

    if(player.x>Gamelenght*32-WIDE){goto stanga;}


    if(randompercent(50))///dreapta
        {
            dreapta:

            spawnx=(player.x)+randomrange(2,6)*32+WIDE;

            spawny=(player.y)+randomrange(0,4)*32;


        }else
        {
            stanga:

            spawnx=(player.x)-randomrange(2,6)*32-WIDE;
           // if(spawnx<0){;}

            spawny=(player.y)+randomrange(0,4)*32;


        }



        if(randompercent(50))
            {
              int gettype=0;
        if(curentbiome==biome::field)
            {
            if(difficulty==2){gettype=randomrange(1,6);}else{gettype=randomrange(0,6);};

            if(gettype<4)
            {
            enemies.push_back(et::getslime(et::green_slime));
            }else if(gettype==5)
            {
            enemies.push_back(et::getslime(et::speedy_green_slime));
            }else{enemies.push_back(et::getslime(et::blue_slime));}


            }


        if(curentbiome==biome::cave)
            {
             if(difficulty==2){gettype=randomrange(2,6);}else{gettype=randomrange(1,6);};

            if(gettype<4)
            {
            enemies.push_back(et::getslime(et::green_slime));
            }else if(gettype==5)
            {
            enemies.push_back(et::getslime(et::speedy_blue_slime));
            }else{enemies.push_back(et::getslime(et::blue_slime));}



            }


        if(curentbiome==biome::desert)
            {
                if(difficulty==2&&randompercent(40))
                    {
                    enemies.push_back(et::getslime(et::speedy_sand_slime));
                    }
                else
                    { enemies.push_back(et::getslime(et::sand_slime));}



            }


        if(curentbiome==biome::snow)
            {

                if(difficulty==2&&randompercent(40))
                    {
                    enemies.push_back(et::getslime(et::speedy_ice_slime));
                    }
                else
                    { enemies.push_back(et::getslime(et::ice_slime));}



            }

            enemies[enemies.size()-1].x=spawnx;
            enemies[enemies.size()-1].y=spawny;




            }else
            {
                humanlike_enemies.push_back(et::gethumanlikeenemy(et::normal_zombie));

                humanlike_enemies[humanlike_enemies.size()-1].x=spawnx;
                humanlike_enemies[humanlike_enemies.size()-1].y=spawny;
            }



}








