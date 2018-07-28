#include <SFML/Graphics.hpp>
#include <windows.h>
#include "headerfiles/declarations.h"
#include "blocks.h"
#include <thread>

extern bl::blocks world[Gamelenght][Gameheight];
extern bl::blocks walls[Gamelenght][Gameheight];
sf::Clock myclock;
float whaittime;
float spawnwaittime;

extern int difficulty;
extern float deltatime;

extern std::vector<slimeentity> enemies;
extern std::vector<humanlikeenemy> humanlike_enemies;

void timehandle()
{
if(difficulty)
    {
    if(spawnwaittime<0)
        {
            int nrofenemies=enemies.size()+humanlike_enemies.size();


            if(nrofenemies<10)
                {
                spawnmonster();
                if(randompercent(50)){spawnmonster();}
                if(difficulty==2&&randompercent(50)){spawnmonster();}
                }

        spawnwaittime=randomrange(10,60);
        if(difficulty==2){spawnwaittime-=10;}


        }



    spawnwaittime-=deltatime;
    }



    if(myclock.getElapsedTime().asSeconds()>whaittime)
        {   myclock.restart();
            whaittime=randomrange(30,60);

            std::thread t(updatemap);
            t.detach();


        }

}


void updatemap()
{

        for(int x=0;x<Gamelenght;x++)
            {
            for(int y=0;y<Gameheight;y++)
                {
                if(world[x][y].type==bl::type::dirt&&y>0&&(world[x][y-1].type==0||getfamilya(world[x][y-1].type)!=bl::blocy))///grass
                    {
                    if((x>0)&&(world[x-1][y].type==bl::grass)||
                       (x<Gamelenght)&&(world[x+1][y].type==bl::grass)||
                       (x>0)&&(y<Gameheight)&&(world[x-1][y+1].type==bl::grass)||
                       (x<Gamelenght)&&(y<Gameheight)&&(world[x+1][y+1].type==bl::grass)||
                       (x>0)&&(y>0)&&(world[x-1][y-1].type==bl::grass)||
                       (x<Gamelenght)&&(y>0)&&(world[x+1][y-1].type==bl::grass)||
                        (x>0)&&(y<Gameheight-1)&&(world[x-1][y+2].type==bl::grass)||
                       (x<Gamelenght)&&(y<Gameheight-1)&&(world[x+1][y+2].type==bl::grass)||
                       (x>0)&&(y>1)&&(world[x-1][y-2].type==bl::grass)||
                       (x<Gamelenght)&&(y>1)&&(world[x+1][y-2].type==bl::grass)
                       )
                        {
                            if(randompercent(25))
                                {
                          world[x][y].type=bl::type::grass;
                          x++;}
                        }

                    }else if(world[x][y].type==bl::grass&&y>0&&(world[x][y-1].type==0))
                    {
                     if(randompercent(1))
                                {
                          world[x][y-1].type=bl::type::plants;
                          x++;}

                    }else if(world[x][y].type==bl::grass&&y>0&&getfamilya(world[x][y-1].type)==bl::blocy)
                    {if(randompercent(30))world[x][y].type=bl::dirt;}
                    else if(world[x][y].type==bl::sappling)
                    {
                    if
                        (randompercent(25)&&
                        (y>0&&world[x][y-1].type==0)&&
                        (y>1&&world[x][y-2].type==0)&&
                        (y>2&&world[x][y-3].type==0)&&
                        (y>3&&world[x][y-4].type==0)&&

                        (y>0&&x>0&&world[x-1][y-1].type==0)&&
                        (y>1&&x>0&&world[x-1][y-2].type==0)&&
                        (y>2&&x>0&&world[x-1][y-3].type==0)&&
                        (y>3&&x>0&&world[x-1][y-4].type==0)&&
                        (y>0&&x<Gamelenght&&world[x+1][y-1].type==0)&&
                        (y>1&&x<Gamelenght&&world[x+1][y-2].type==0)&&
                        (y>2&&x<Gamelenght&&world[x+1][y-3].type==0)&&
                        (y>3&&x<Gamelenght&&world[x+1][y-4].type==0)&&

                        (y>4&&world[x][y-5].type==0)&&
                        (y>5&&world[x][y-6].type==0)&&
                        (y>6&&world[x][y-7].type==0)&&
                        (y>7&&world[x][y-8].type==0)&&

                        (y>4&&x>0&&world[x-1][y-5].type==0)&&
                        (y>5&&x>0&&world[x-1][y-6].type==0)&&
                        (y>6&&x>0&&world[x-1][y-7].type==0)&&
                        (y>7&&x>0&&world[x-1][y-8].type==0)&&
                        (y>4&&x<Gamelenght&&world[x+1][y-5].type==0)&&
                        (y>5&&x<Gamelenght&&world[x+1][y-6].type==0)&&
                        (y>6&&x<Gamelenght&&world[x+1][y-7].type==0)&&
                        (y>7&&x<Gamelenght&&world[x+1][y-8].type==0)
                        )
                        {growtreee(randomrange(2,4),x,y);}

                    }



                }

            }


}
