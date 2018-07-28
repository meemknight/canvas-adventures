#ifndef BLOCKS_H
#define BLOCKS_H
#include "../headerfiles/declarations.h"
//#define Gameheight 160
//#define Gamelenght 320


namespace bl{

class blocks
{ public:
     blocks();
    blocks(int type_);
    void randomisevarations();
    int family();

   virtual void update(int x, int y);
    virtual int getbreakvalue();
    virtual int getminbreakvalue();
int type;
int varation;

};

class normalblocks:public blocks
{public:
normalblocks();
normalblocks(int type_);

};

}
#endif // BLOCKS_H
