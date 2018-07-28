#include "headerfiles/declarations.h"
#include <math.h>

extern float deltatime;

void handleview(sf::View &view, entities ent, float speed)
{
  /*  if(abs(ent.x-view.getCenter().x)>32*30||
      abs(ent.y-view.getCenter().y)>32*30
       )
        {
        view.setCenter(ent.x,ent.y);
        }


    if(view.getCenter().x>ent.x)
        {
        view.setCenter(view.getCenter().x-speed*deltatime,view.getCenter().y);
            if(view.getCenter().x<ent.x){view.setCenter(ent.x,view.getCenter().y);}
        }

    if(view.getCenter().x<ent.x)
        {
         view.setCenter(view.getCenter().x+speed*deltatime,view.getCenter().y);
            if(view.getCenter().x>ent.x){view.setCenter(ent.x,view.getCenter().y);}
        }

     if(view.getCenter().y>ent.y)
        {
        view.setCenter(view.getCenter().x,view.getCenter().y-speed*deltatime);
            if(view.getCenter().y<ent.y){view.setCenter(view.getCenter().x,ent.y);}
        }

    if(view.getCenter().y<ent.y)
        {
                view.setCenter(view.getCenter().x,view.getCenter().y+speed*deltatime);
            if(view.getCenter().y>ent.y){view.setCenter(view.getCenter().x,ent.y);}
        }

  //  view.setCenter((int)view.getCenter().x,(int)view.getCenter().y);
    //system("cls");
    //cout<<view.getCenter().x<<" "<<view.getCenter().y<<endl;
*/
}
