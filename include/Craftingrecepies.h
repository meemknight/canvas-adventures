#ifndef CRAFTINGRECEPIES_H
#define CRAFTINGRECEPIES_H
#include "items.h"

class Craftebleitem
{
public:
    Craftebleitem(){};
    Craftebleitem(bool placeble,int type,int number):placeble(placeble),type(type),number(number){};
    bool placeble;
    int type;
    int number;

};


class Craftingrecepies
{
    public:
        Craftingrecepies();
        Craftingrecepies(Craftebleitem result,Craftebleitem a,Craftebleitem b,Craftebleitem c,Craftebleitem d,int craftingstation_);
      create(Craftebleitem result,Craftebleitem a,Craftebleitem b,Craftebleitem c,Craftebleitem d,int craftingstation_);

      Craftebleitem itemcreated;
      Craftebleitem materials[4];
      int craftingstation;

};

#endif // CRAFTINGRECEPIES_H
