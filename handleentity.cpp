#include "blocks.h"
#include "enum.h"
#include "entities.h"
#include "headerfiles/declarations.h"
#include <SFML/Graphics.hpp>



extern bl::blocks world[Gamelenght][Gameheight];
extern float deltatime;

   inline static int getminxb(entities& entity);
   inline static int getminyb(entities& entity);
   inline static int getmaxxb(entities& entity);
   inline static int getmaxyb(entities& entity);

   static void checkfall(entities& entity);





            int deltax;
            int deltay;
            int intersectx;
            int intersecty;

void handleentity(entities& entity,float gravity)
{
    int minx,maxx,miny,maxy;

    minx=getminxb(entity);
    miny=getminyb(entity);
    maxx=getmaxxb(entity);
    maxy=getmaxyb(entity);




     entity.velocity.y=entity.velocity.y+gravity*32*deltatime*2;
            entity.velocity.y=std::min(entity.velocity.y,(float)((gravity*32)));
            entity.x=entity.x+(int)(entity.velocity.x*deltatime);
           entity.y=entity.y+entity.velocity.y*deltatime;


    if(entity.lastpos.x<entity.x){entity.movingright=1;}else{if(entity.lastpos.x>entity.x)entity.movingright=0;}
    if(entity.lastpos.y<entity.y){entity.movingdown=1;}else{entity.movingdown=0;}

  entity.canjump=0;
  if(entity.movingdown)
    {

          ///////////////////////////////platforms              ///////
        for(int y=miny;y<maxy;y++)
        {

          for(int x=minx;x<maxx;x++)
            {
            if(world[x][y].family()==bl::platform_family&&!entity.down_pressed){

            deltax=x*32+16-entity.getcenterx();
            deltay=y*32+8-entity.getcentery();
            intersectx=abs(deltax)-(16+entity.sizeofentity.x/2);
            intersecty=abs(deltay)-(8+entity.sizeofentity.y/2);

             if(intersectx<0.0f&&intersecty<0.0f&&entity.y+entity.sizeofentity.y<y*32+28)
                {
               entity.y=y*32-entity.sizeofentity.y;
                      //      entity.canjump=1;
                }


                }
            }

        }

        ///////////////////////////////////////////////platforms


    for(int y=miny;y<maxy;y++)
        {




        if(entity.movingright)
            {
            for(int x=minx;x<maxx;x++)
                {
   if(world[x][y].family()==bl::blocy)
                {

            deltax=x*32+16-entity.getcenterx();
            deltay=y*32+16-entity.getcentery();
            intersectx=abs(deltax)-(16+entity.sizeofentity.x/2);
            intersecty=abs(deltay)-(16+entity.sizeofentity.y/2);




            if(intersectx<0.0f&&intersecty<0.0f)
                {
                if(abs(intersectx)<=abs(intersecty))/// move on x
                    {  entity.canjump=0;
                        if(deltax<0)
                            {

                           if(!entity.movingright) entity.x=x*32+32;
                                                            ///stanga
                            }else
                            {

                            if(entity.movingright)entity.x=x*32-entity.sizeofentity.x;   ///dreapta

                            }



                    }else
                    {///move on y
                        if(deltay<0)
                            {

                            entity.y=y*32+32;

                            }else

                            {
                            entity.y=y*32-entity.sizeofentity.y;
                            entity.canjump=1;
                            checkfall(entity);
                            }


                    }


                }
            }
                }
            }else
            {
             for(int x=maxx;x>=minx;x--)
                {
   if(world[x][y].family()==bl::blocy)
                {
            deltax=x*32+16-entity.getcenterx();
            deltay=y*32+16-entity.getcentery();
            intersectx=abs(deltax)-(16+entity.sizeofentity.x/2);
            intersecty=abs(deltay)-(16+entity.sizeofentity.y/2);



            if(intersectx<0.0f&&intersecty<0.0f)
                {
                if(abs(intersectx)<=abs(intersecty))/// move on x
                    {  entity.canjump=0;
                        if(deltax<0)
                            {

                           if(!entity.movingright) entity.x=x*32+32;
                                                            ///stanga
                            }else
                            {

                            if(entity.movingright)entity.x=x*32-entity.sizeofentity.x;   ///dreapta

                            }



                    }else
                    {///move on y
                        if(deltay<0)
                            {

                            entity.y=y*32+32;

                            }else

                            {
                            entity.y=y*32-entity.sizeofentity.y;
                            entity.canjump=1;
                              checkfall(entity);
                            }


                    }


                }
            }

                }
            }

        }
        ///////////////////////////////platforms              ///////
        for(int y=miny;y<maxy;y++)
        {

          for(int x=minx;x<maxx;x++)
            {
            if(world[x][y].family()==bl::platform_family&&!entity.down_pressed){

            deltax=x*32+16-entity.getcenterx();
            deltay=y*32+8-entity.getcentery();
            intersectx=abs(deltax)-(16+entity.sizeofentity.x/2);
            intersecty=abs(deltay)-(8+entity.sizeofentity.y/2);

             if(intersectx<0.0f&&intersecty<=0.0f&&entity.y+entity.sizeofentity.y<y*32+28)
                {
                entity.y=y*32-entity.sizeofentity.y;
                            entity.canjump=1;
                              checkfall(entity);
                }


                }
            }

        }

        ///////////////////////////////////////////////platforms




    }else               /////////////////////////////////////moving up
    {
     for(int y=maxy;y>=miny;y--)
        {
        if(entity.movingright)
            {
            for(int x=minx;x<maxx;x++)
                {
   if(world[x][y].family()==bl::blocy)
                {
            deltax=x*32+16-entity.getcenterx();
            deltay=y*32+16-entity.getcentery();
            intersectx=abs(deltax)-(16+entity.sizeofentity.x/2);
            intersecty=abs(deltay)-(16+entity.sizeofentity.y/2);


            if(intersectx<0.0f&&intersecty<0.0f)
                {
                if(abs(intersectx)<=abs(intersecty))/// move on x
                    {  entity.canjump=0;
                        if(deltax<0)
                            {

                           if(!entity.movingright) entity.x=x*32+32;
                                                            ///stanga
                            }else
                            {

                            if(entity.movingright)entity.x=x*32-entity.sizeofentity.x;   ///dreapta

                            }



                    }else
                    {///move on y
                        if(deltay<0)
                            {

                            entity.y=y*32+32;

                            }else

                            {
                            entity.y=y*32-entity.sizeofentity.y;
                            entity.canjump=1;
                              checkfall(entity);
                            }


                    }


                }
            }

                }
            }else
            {
             for(int x=maxx;x>=minx;x--)
                {
   if(world[x][y].family()==bl::blocy)
                {
            deltax=x*32+16-entity.getcenterx();
            deltay=y*32+16-entity.getcentery();
             intersectx=abs(deltax)-(16+entity.sizeofentity.x/2);
            intersecty=abs(deltay)-(16+entity.sizeofentity.y/2);



            if(intersectx<0.0f&&intersecty<0.0f)
                {  entity.canjump=0;
                if(abs(intersectx)<=abs(intersecty))/// move on x
                    {
                        if(deltax<0)
                            {

                           if(!entity.movingright) entity.x=x*32+32;
                                                            ///stanga
                            }else
                            {

                            if(entity.movingright)entity.x=x*32-entity.sizeofentity.x;   ///dreapta

                            }



                    }else
                    {///move on y
                        if(deltay<0)
                            {

                            entity.y=y*32+32;

                            }else

                            {
                            entity.y=y*32-entity.sizeofentity.y;
                            entity.canjump=1;
                              checkfall(entity);
                            }


                    }


                }
            }

                }
            }

        }
    }


                                                            ///fix player position
            if(entity.x<0){entity.x=0;}
            if(entity.x+entity.sizeofentity.x>32*Gamelenght){entity.x=32*Gamelenght-entity.sizeofentity.x;}
            if(entity.y<0){entity.y=0;}
            if(entity.y+entity.sizeofentity.y>32*Gameheight){entity.y=32*Gameheight-entity.sizeofentity.y;entity.canjump=1;
              checkfall(entity);
            }

            if(entity.y<entity.highestpoint){entity.highestpoint=entity.y;}

            entity.lastpos.x=entity.x;
            entity.lastpos.y=entity.y;



}


  inline static int getminxb(entities& entity)
   {
   if(entity.x/32>2){return (entity.x/32)-2;}
    if(entity.x/32>1){return (entity.x/32)-1;}else{return 0;}

   }
  inline static int getminyb(entities& entity)
   {
     if(entity.y/32>2){return (entity.y/32)-2;}
    if(entity.y/32>1){return (entity.y/32)-1;}else{return 0;}

   }


  inline static int getmaxxb(entities& entity)
  {if(entity.x/32<Gamelenght-4){return(entity.x/32)+4;}else{return Gamelenght;}

   //     if(entity.x/32<Gamelenght-4){return (entity.x/32)+4;}
   //     if(entity.x/32<Gamelenght-3){return (entity.x/32)+3;}
  //     if(entity.x/32<Gamelenght-2){return (entity.x/32)+2;}
  //  if(entity.x/32<Gamelenght-1){return (entity.x/32)+1;}else{return Gamelenght;}

  }


  inline static int getmaxyb(entities& entity)
  {

      if(entity.y/32<Gameheight-4){return (entity.y/32)+4;}
      if(entity.y/32<Gameheight-3){return (entity.y/32)+3;}
      if(entity.y/32<Gameheight-2){return (entity.y/32)+2;}
    if(entity.y/32<Gameheight-1){return (entity.y/32)+1;}else{return Gameheight;}


  }


   static void checkfall(entities& entity)
   {
    if(entity.y-entity.highestpoint>entity.falltolerance*32)
        {
        entity.life-=(entity.y-entity.highestpoint-entity.falltolerance*32)/4;
        entity.invurnerabilitytime=1;
        }
        if(entity.life>0)
            {
            entity.highestpoint=entity.y;
            }else
            {
            entity.highestpoint=Gamelenght*32;
            }


   }





