#include<iostream>
#include<cstring>
using namespace std;

unsigned long
hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

int main()
{
	char str[20];
	int x; 
	
	do{
		cout << "\nEnter string: " ; cin>>str;
		x= hash(str)%100;
		cout << x;
	}while(true);
	return 0;
}
