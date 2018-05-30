#ifndef BUTTONCLASS_H
#define BUTTONCLASS_H
#include "../headerfiles/declarations.h"


class buttonclass
{
    public:
        buttonclass();
        sf::Vector2i position;
        int nroftiles=2;
        int scale=1;
        int textscale=1;
        string title;

    void seposrelevanttothecenter(int x,int y);

    void update();

    void(*onclick)()=0;



};



#endif // BUTTONCLASS_H
