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




              int gettype=0;
        if(curentbiome==biome::field)
            {
            if(difficulty==2){gettype=randomrange(1,6);}else{gettype=randomrange(0,6);};

            if(gettype<4)
            {
            enemies.push_back(et::getslime(et::green_slime));
            enemies[enemies.size()-1].x=spawnx;
            enemies[enemies.size()-1].y=spawny;
            }else if(gettype==5)
            {
            enemies.push_back(et::getslime(et::speedy_green_slime));
            enemies[enemies.size()-1].x=spawnx;
            enemies[enemies.size()-1].y=spawny;
            }else{enemies.push_back(et::getslime(et::blue_slime));
                    enemies[enemies.size()-1].x=spawnx;
                    enemies[enemies.size()-1].y=spawny;
                 }


            }


        if(curentbiome==biome::cave)
            {
             if(difficulty==2){gettype=randomrange(2,7);}else{gettype=randomrange(1,7);};

            if(gettype<4)
            {
            enemies.push_back(et::getslime(et::green_slime));
            enemies[enemies.size()-1].x=spawnx;
            enemies[enemies.size()-1].y=spawny;
            }else if(gettype==5)
            {
            enemies.push_back(et::getslime(et::speedy_blue_slime));
            enemies[enemies.size()-1].x=spawnx;
            enemies[enemies.size()-1].y=spawny;
            }else if(gettype==6)
            {enemies.push_back(et::getslime(et::blue_slime));
            enemies[enemies.size()-1].x=spawnx;
            enemies[enemies.size()-1].y=spawny;
            }else if(gettype==7)
            {
            humanlike_enemies.push_back(et::gethumanlikeenemy(et::normal_zombie));
            humanlike_enemies[humanlike_enemies.size()-1].x=spawnx;
            humanlike_enemies[humanlike_enemies.size()-1].y=spawny;
            }



            }


        if(curentbiome==biome::desert)
            {
                if(difficulty==2)
                    {
                    gettype=randomrange(2, 5);
                    }else
                    {
                    gettype=randomrange(1, 5);
                    }

                  if(gettype==1)
                    {
                     enemies.push_back(et::getslime(et::sand_slime));
                    enemies[enemies.size()-1].x=spawnx;
                    enemies[enemies.size()-1].y=spawny;
                    }else if(gettype==2)
                    {
                      enemies.push_back(et::getslime(et::sand_slime));
                    enemies[enemies.size()-1].x=spawnx;
                    enemies[enemies.size()-1].y=spawny;
                    }else if(gettype==3)
                    {
                     enemies.push_back(et::getslime(et::speedy_sand_slime));
                    enemies[enemies.size()-1].x=spawnx;
                    enemies[enemies.size()-1].y=spawny;
                    }else if(gettype==4)
                    {
                     humanlike_enemies.push_back(et::gethumanlikeenemy(et::normal_zombie));
                    humanlike_enemies[humanlike_enemies.size()-1].x=spawnx;
                    humanlike_enemies[humanlike_enemies.size()-1].y=spawny;
                    }else if(gettype==5)
                    {
                     humanlike_enemies.push_back(et::gethumanlikeenemy(et::mumy));
                    humanlike_enemies[humanlike_enemies.size()-1].x=spawnx;
                    humanlike_enemies[humanlike_enemies.size()-1].y=spawny;
                    }



            }


        if(curentbiome==biome::snow)
            {
                if(difficulty==2)
                    {
                    gettype=randomrange(2, 5);
                    }else
                    {
                    gettype=randomrange(1, 5);
                    }


              if(gettype==1)
                {
                { enemies.push_back(et::getslime(et::ice_slime));
                      enemies[enemies.size()-1].x=spawnx;
                      enemies[enemies.size()-1].y=spawny;
                    }

                }else if(gettype==2)
                {
                { enemies.push_back(et::getslime(et::ice_slime));
                      enemies[enemies.size()-1].x=spawnx;
                      enemies[enemies.size()-1].y=spawny;
                    }
                }else if(gettype==3)
                {
                  {
                    enemies.push_back(et::getslime(et::speedy_ice_slime));
                    enemies[enemies.size()-1].x=spawnx;
                    enemies[enemies.size()-1].y=spawny;
                    }
                }else if(gettype==4)
                {
                    humanlike_enemies.push_back(et::gethumanlikeenemy(et::zombie_eschimo));
                    humanlike_enemies[humanlike_enemies.size()-1].x=spawnx;
                    humanlike_enemies[humanlike_enemies.size()-1].y=spawny;
                }
            }




            //humanlike_enemies.push_back(et::gethumanlikeenemy(et::normal_zombie));

            //    humanlike_enemies[humanlike_enemies.size()-1].x=spawnx;
             //   humanlike_enemies[humanlike_enemies.size()-1].y=spawny;





}








