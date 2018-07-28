#ifndef ITEMS_H
#define ITEMS_H
#include <cstdint>
#include <SFML/Graphics.hpp>

class items
{
    public:
   int type;
   uint8_t number;
   uint8_t maxnumber;
   virtual void getname()=0;
   virtual bool placeble()=0;
   virtual int getpickaxepower()=0;
   virtual int getaxepower()=0;
   virtual int gethammerpower()=0;
   virtual void setmaxnumber(){};
   virtual int getattackpower()=0;
   virtual int getknockback()=0;
   virtual float getfreeztime()=0;
   virtual bool splashattack()=0;
   virtual float range()=0;
   virtual float getspeed()=0;
   virtual int wearable()=0;
   virtual int getarmour()=0;
   virtual int getfalldamagerezistance()=0;
    enum name
    {
    none,
    wodden_pickaxe,
    wodden_axe,
    wodden_hammer,
    stone_pickaxe,
    stone_axe,
    stone_hammer,
    copper_pickaxe,
    copper_axe,
    copper_hammer,
    steel_pickaxe,
    steel_axe,
    steel_hammer,
    gold_pickaxe,
    gold_axe,
    gold_hammer,
    goo,
    copper_bar,
    steel_bar,
    gold_bar,
    wodden_sword,
    stone_sword,
    copper_sword,
    iron_sword,
    gold_sword,
    ruby,
    copper_spear,
    iron_spear,
    golden_spear,
    icegem,
    icemace,
    misseltoe,
    healthbottle,
    apple,
    paper,
    book,
    bone,
    slime_skull,
    shuriken,
    copper_dagger,
    iron_dagger,
    frost_dagger,
    battle_potion,
    recall_potion,
    spawn_set_potion,
    copper_armour,
    copper_helmet,
    copper_leggings,
    iron_armour,
    iron_helmet,
    iron_leggings,
    gold_armour,
    gold_helmet,
    gold_leggings,
    party_hat,
    sun_glasses,
    ice_armour,
    ice_helmet,
    ice_leggings,
    slime_shoes,
    last_item
    };

};


class normalitems:public items
{
    public:
    normalitems();
   // normalitems(int type_);
    normalitems(int type_,int number_);
    void getname(){};
    bool placeble(){return 1;};
    int getpickaxepower(){return 0;};
    int getaxepower(){return 0;};
    int gethammerpower(){return 0;}
    int getattackpower(){return 0;};
    int getknockback(){return 0;};
    bool splashattack(){return 0;};
    float getfreeztime(){return 0;};
    float range(){return 0;};
    float getspeed(){return 0;};
    int wearable(){return 0;}
    int getarmour(){return 0;}
    int getfalldamagerezistance(){return 0;};
};

class nonplaceble:public items
{
    public:
    nonplaceble();
   // nonplaceble(int type_);
    nonplaceble(int type_,int number_);
    void getname(){};
    bool placeble(){return 0;};
    int getpickaxepower();
     int getaxepower();
    int gethammerpower();
    int getattackpower();
        void setmaxnumber();
        int getknockback();
        bool splashattack();
        float getfreeztime();
        float range();
        float getspeed();

        /// 1head 2body 3boots   0none
        int wearable();
        int getarmour();
        int getfalldamagerezistance();
};

class droppeditem
{
    public:
    droppeditem();
    droppeditem(bool placeble,int type_);
    droppeditem(bool placeble,int type_,int x,int y, int number);
    droppeditem(bool placeble,int type_,sf::Vector2i position_,int number);
    sf::Clock clock;
    float time;

    items* item;
    sf::Vector2i position;

    bool handlegravity();

    ~droppeditem();

};

#endif // ITEMS_H
