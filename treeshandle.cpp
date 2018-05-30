#include "blocks.h"
#include "enum.h"
#include <memory>
#include "headerfiles/declarations.h"
extern bl::blocks world[Gamelenght][Gameheight];

std::unique_ptr<bl::blocks> woodblock(new bl::normalblocks(bl::type::wood));
std::unique_ptr<bl::blocks> leafblock(new bl::normalblocks(bl::type::leafs));


void growtreee(uint8_t lenght,int xpos,int ypos)
{
int i;
for(i=0;i<lenght;i++)
    {
    world[xpos][ypos-i]= *woodblock;
    }
if(i<=3)
    {
    world[xpos][ypos-i]=*leafblock;
    world[xpos][ypos-i-1]=*leafblock;
    world[xpos-1][ypos-i]=*leafblock;
    world[xpos+1][ypos-i]=*leafblock;


    }
else if(i<7){ world[xpos][ypos-i]=*leafblock;
    world[xpos][ypos-i-1]=*leafblock;
    world[xpos-1][ypos-i]=*leafblock;
    world[xpos+1][ypos-i]=*leafblock;
    world[xpos-1][ypos-i+1]=*leafblock;
    world[xpos+1][ypos-i+1]=*leafblock;
      world[xpos][ypos-i-2]=*leafblock;
    world[xpos-1][ypos-i-1]=*leafblock;
    world[xpos+1][ypos-i-1]=*leafblock;
    }else
    {
    world[xpos][ypos-i]=*leafblock;
    world[xpos][ypos-i-1]=*leafblock;
    world[xpos-1][ypos-i]=*leafblock;
    world[xpos+1][ypos-i]=*leafblock;
    world[xpos-1][ypos-i+1]=*leafblock;
    world[xpos+1][ypos-i+1]=*leafblock;
    world[xpos][ypos-i-2]=*leafblock;
    world[xpos][ypos-i-3]=*leafblock;
    world[xpos+1][ypos-i-2]=*leafblock;
    world[xpos-1][ypos-i-2]=*leafblock;
    world[xpos-1][ypos-i-1]=*leafblock;
    world[xpos+1][ypos-i-1]=*leafblock;
    world[xpos-2][ypos-i+1]=*leafblock;
    world[xpos+2][ypos-i+1]=*leafblock;;
    world[xpos-3][ypos-i+1]=*leafblock;
    world[xpos+3][ypos-i+1]=*leafblock;
    world[xpos+2][ypos-i-1]=*leafblock;
    world[xpos-2][ypos-i-1]=*leafblock;
 world[xpos+2][ypos-i]=*leafblock;
    world[xpos-2][ypos-i]=*leafblock;


    }



}

