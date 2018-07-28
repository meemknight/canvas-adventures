#include <string>
using std::string;
#include "headerfiles/declarations.h"

void inttostring(string& str,int a)
{
	int size = 1;
	int aa = a;
	while(aa>9)
	{
		aa /= 10;
		size++;

	}
	size--;
	str.clear();
	while (size >= 0) {
			str =str + (char)('0'+((a / putere(10,size)) % 10));


		size--;



	}


}
string str;
string inttostring(int a)
{
str.clear();
	int size = 1;
	int aa = a;
	while(aa>9)
	{
		aa /= 10;
		size++;

	}
	size--;
	str.clear();
	while (size >= 0) {
			str =str + (char)('0'+((a / putere(10,size)) % 10));


		size--;
	}
return str;

}


int putere(int a, int b)
{
	if (b == 0) { return 1; }

	int aa = a;
	for (int i = 1;i<b;i++)
	{
		aa *= a;

	}
	return aa;
}
