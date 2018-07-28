#include<cstdlib>
#include<ctime>

int randomrange(int min_val,int max_val)
{
return rand()%(max_val-min_val+1)+min_val;
}

bool randompercent(float chance)
{
if(chance>=randomrange(0,100))return 1; else return 0;

}
