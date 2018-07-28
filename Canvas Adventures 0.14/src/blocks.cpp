#include "blocks.h"
#include "enum.h"
#include <cstdlib>
#include <vector>
#include "items.h"
#include "../headerfiles/declarations.h"



extern bl::blocks world[Gamelenght][Gameheight];
extern std::vector<droppeditem> droppedi;



namespace bl
{
blocks::blocks()
{
type=bl::type::air;
varation=0;
}

blocks::blocks(int type_)
{
    type=type_;
    varation=rand()%4;
}
void blocks::randomisevarations()
{
varation=rand()%4;

}

int blocks::family()
{
    switch(type)
    {
    case bl::air:{return bl::fragile; break;}
    case bl::plants:{return bl::fragile; break;}
    case bl::wood:{return bl::nocollision; break;}
    case bl::leafs:{return bl::nocollision; break;}
    case bl::furnace:{return bl::platform_family; break;}
    case bl::platform:{return bl::platform_family; break;}
    case bl::workbench:{return bl::platform_family; break;}
    case bl::painting:{return bl::nocollision; break;}
    case bl::sappling:{return bl::nocollision; break;}
    case bl::wodden_door:{return bl::door; break;}
    case bl::table:{return bl::platform_family; break;}
    case bl::bottle:{return bl::nonstackeble; break;}
    case bl::wardrobe:{return bl::platform_family; break;}
    case bl::book_shelf:{return bl::nocollision; break;}
    case bl::ice_table:{return bl::platform_family; break;}
    case bl::ice_wardrobe:{return bl::platform_family; break;}
    case bl::ice_book_shelf:{return bl::nocollision; break;}
    case bl::ice_platform:{return bl::platform_family; break;}
    case bl::sand_table:{return bl::platform_family; break;}
    case bl::sand_wardrobe:{return bl::platform_family; break;}
    case bl::sand_book_shelf:{return bl::nocollision; break;}
    case bl::sand_platform:{return bl::platform_family; break;}
    case bl::chest:{return bl::chestfamily;break;}
       case bl::ice_chest:{return bl::chestfamily;break;}
    case bl::sand_chest:{return bl::chestfamily;break;}
    case bl::dungeon_chest:{return bl::chestfamily;break;}

       case bl::dungeon_table:{return bl::platform_family; break;}
    case bl::dungeon_wordrobe:{return bl::platform_family; break;}
    case bl::dungeon_bookshelf:{return bl::nocollision; break;}
    case bl::dungeon_platform:{return bl::platform_family; break;}


    default:{return bl::blocy;}
    }



}





normalblocks::normalblocks()
{
type=bl::type::air;
}

normalblocks::normalblocks(int type_)
{
type=type_;
}

void blocks::update(int x, int y)
{
    if(world[x][y].family()==bl::nonstackeble||world[x][y].family()==bl::chestfamily)
        {
        if(!(y<Gameheight&&world[x][y+1].family()==bl::blocy))
            {
                                    if(world[x][y].family()==bl::chestfamily)
                                        {
                                        breakchest(x, y);
                                        }



                 droppedi.push_back(droppeditem(1,world[x][y].type,x*32,y*32,1));
                world[x][y].type=0;

            if(y<Gameheight) world[x][y+1].update(x,y+1);


            if(y>0) world[x][y-1].update(x,y-1);


            }

        }


    switch(type)
    {
        case bl::type::plants:
            if(x>0&&y<Gameheight)
        if(world[x][y+1].type!=bl::type::grass){world[x][y].type=0;}
        break;

        case bl::type::wodden_door:
          if(y>0&&y<Gameheight)
            {
            if(!((world[x][y-1].family()==bl::blocy&&world[x][y+1].type==bl::wodden_door)
               ||
               (world[x][y+1].family()==bl::blocy&&world[x][y-1].type==bl::wodden_door)
               ))
               {
                   if(world[x][y-1].type==bl::wodden_door||world[x][y+1].type==bl::wodden_door)
                    {
                    droppedi.push_back(droppeditem(1,bl::wodden_door,x*32,y*32,1));
                    }

               world[x][y].type=0;
                world[x][y-1].update(x,y-1);
            world[x][y+1].update(x,y+1);

               }
            }


        break;

        case bl::type::wood:
            if(x>0&&y<Gameheight&&x<Gamelenght&&y>0)
        if(world[x][y+1].type!=bl::type::grass&&world[x][y+1].type!=bl::type::wood&&world[x][y+1].type!=bl::type::leafs&&world[x][y+1].type!=bl::type::dirt)
        { droppedi.push_back(getdroppeditem(bl::wood));
                    droppedi[droppedi.size()-1].position.x=x *32;
                    droppedi[droppedi.size()-1].position.y=y*32;
                world[x][y]=bl::normalblocks(0);
            world[x][y-1].update(x,y-1);
            world[x][y+1].update(x,y+1);
            world[x+1][y].update(x+1,y);
            world[x-1][y].update(x-1,y);


        }
        break;
        case bl::type::leafs:
                        if(x>0&&y<Gameheight&&x<Gamelenght&&y>0)
        if(world[x][y+1].type!=bl::type::grass&&world[x][y+1].type!=bl::type::wood&&world[x][y+1].type!=bl::type::leafs){world[x][y]=bl::normalblocks(0);
            world[x][y-1].update(x,y-1);
            world[x][y+1].update(x,y+1);
            world[x+1][y].update(x+1,y);
            world[x-1][y].update(x-1,y);
            if(randompercent(10))
                {
             droppedi.push_back(getdroppeditem(bl::sappling));
                    droppedi[droppedi.size()-1].position.x=x *32;
                    droppedi[droppedi.size()-1].position.y=y*32;
                }
        }
        break;
        case bl::type::sappling:
            if(x>0&&y<Gameheight)
        if(world[x][y+1].type!=bl::type::grass)
            {world[x][y].type=0;
            droppedi.push_back(getdroppeditem(bl::sappling));
                    droppedi[droppedi.size()-1].position.x=x *32;
                    droppedi[droppedi.size()-1].position.y=y*32;
            }
        break;

    }
}

int blocks::getbreakvalue()
{
    switch(type)
    {
    case bl::type::plants:return 0;break;

    case bl::type::snowblock:return 130;break;
    case bl::type::snow_wall:return 130;break;
    case bl::type::iceblock:return 140;break;

      case bl::type::sand:return 140;break;
    case bl::type::sand_wall:return 140;break;

    case bl::type::stone:return 170;break;
    case bl::type::stone_wall:return 170;break;

    case bl::type::dirt:return 120;break;
    case bl::type::clay:return 130;break;

    case bl::type::woodenplank:return 170;break;
    case bl::type::wodden_wall:return 170;break;

    case bl::type::bricks:return 170;break;
    case bl::type::brick_wall:return 170;break;

    case bl::type::wood:return 270;break;

    case bl::type::sand_ruby:return 150;
    case bl::type::rubbyblock:return 150;
    case bl::type::rubby_wall:return 150;

    case bl::type::ice_gem_block:return 150;
    case bl::type::ice_gem_wall:return 150;
    case bl::type::snow_gem:return 150;

    case bl::type::copper:return 180;break;
    case bl::type::copper_wall:return 180;break;
    case bl::type::copperblock:return 180;break;

    case bl::type::iron:return 190;break;
    case bl::type::iron_wall:return 190;break;
    case bl::type::ironblock:return 190;break;

    case bl::type::gold:return 200;break;
    case bl::type::gold_wall:return 200;break;
    case bl::type::goldblock:return 200;break;

    case bl::type::dungeon_block:return 140;break;
    case bl::type::dungeon_wall:return 140;break;

    case bl::type::ice_bricks:return 170;break;
    case bl::type::ice_brick_wall:return 170;break;

    default: return 120;
    }
}

int blocks::getminbreakvalue()
{
    switch(type)
    {
   // case bl::type::stone:return 10;break;


    case bl::type::sand_ruby:return 40;
    case bl::type::rubbyblock:return 40;
    case bl::type::rubby_wall:return 40;

     case bl::type::ice_gem_block:return 40;
    case bl::type::ice_gem_wall:return 40;
    case bl::type::snow_gem:return 40;

    case bl::type::copper:return 40;break;
    case bl::type::copper_wall:return 40;break;
    case bl::type::copperblock:return 40;break;

    case bl::type::iron:return 60;break;
    case bl::type::iron_wall:return 40;break;
    case bl::type::ironblock:return 40;break;

    case bl::type::gold:return 60;break;
    case bl::type::gold_wall:return 60;break;
    case bl::type::goldblock:return 60;break;

   // case bl::type::dungeon_block:return 80;break;
  //  case bl::type::dungeon_wall:return 80;break;


    default: return 10;
    }
}


}
int getfamilya(int type){
switch(type)
    {
     case bl::air:{return bl::fragile; break;}
    case bl::plants:{return bl::fragile; break;}
    case bl::wood:{return bl::nocollision; break;}
    case bl::leafs:{return bl::nocollision; break;}
    case bl::furnace:{return bl::platform_family; break;}
    case bl::platform:{return bl::platform_family; break;}
    case bl::workbench:{return bl::platform_family; break;}
    case bl::painting:{return bl::nocollision; break;}
    case bl::sappling:{return bl::nocollision; break;}
    case bl::wodden_door:{return bl::door; break;}
    case bl::table:{return bl::platform_family; break;}
    case bl::bottle:{return bl::nonstackeble; break;}
    case bl::wardrobe:{return bl::platform_family; break;}
    case bl::book_shelf:{return bl::nocollision; break;}
    case bl::ice_table:{return bl::platform_family; break;}
    case bl::ice_wardrobe:{return bl::platform_family; break;}
    case bl::ice_book_shelf:{return bl::nocollision; break;}
    case bl::ice_platform:{return bl::platform_family; break;}
    case bl::sand_table:{return bl::platform_family; break;}
    case bl::sand_wardrobe:{return bl::platform_family; break;}
    case bl::sand_book_shelf:{return bl::nocollision; break;}
    case bl::sand_platform:{return bl::platform_family; break;}
    case bl::chest:{return bl::chestfamily;break;}
    case bl::ice_chest:{return bl::chestfamily;break;}
    case bl::sand_chest:{return bl::chestfamily;break;}
    case bl::dungeon_chest:{return bl::chestfamily;break;}

       case bl::dungeon_table:{return bl::platform_family; break;}
    case bl::dungeon_wordrobe:{return bl::platform_family; break;}
    case bl::dungeon_bookshelf:{return bl::nocollision; break;}
    case bl::dungeon_platform:{return bl::platform_family; break;}

    default:{return bl::blocy;}
    }
}
