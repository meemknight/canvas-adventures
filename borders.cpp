#include "entities.h"
#include "headerfiles/declarations.h"

extern int WIDE;
extern int HEIGHT;



   int getminx(entities& entity)
    {
        if(entity.x/32>Gamelenght-WIDE/64-1){return Gamelenght-WIDE/32-1;}

    if(entity.x/32>WIDE/64+2){return entity.x/32-WIDE/64-1;}else{return 0;};
    }

   int getminy(entities& entity)
    {
        if(entity.y/32>Gameheight-HEIGHT/64-1){return Gameheight-HEIGHT/32-1;}

    if(entity.y/32>HEIGHT/64+2){return entity.y/32-HEIGHT/64-1;}else{return 0;};

    };

   int getmaxx(entities& entity)
    {
                if(entity.x/32<WIDE/64+1){return WIDE/32+1;}

    if(entity.x/32<Gamelenght-WIDE/64-4){return entity.x/32+WIDE/64+3;}else{return Gamelenght;};
    }
int getmaxy(entities& entity)
    {
        if(entity.y/32<HEIGHT/64+1){return HEIGHT/32+1;}

    if(entity.y/32<Gameheight-HEIGHT/64-3){return entity.y/32+HEIGHT/64+2;}else{return Gameheight;};
    }



