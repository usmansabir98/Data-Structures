#include<iostream>
using namespace std

int data[10];
int link[10];
int avail = link[5];
int head = -1;

void insert(int val)
{
	if(avail==-1)
	{
		cout << "Overflow"
	}
}

void traverse()
{
	int ptr = head;
	while(ptr!=-1)
	{
		cout << data[ptr];
		ptr = link[ptr];
	}
}

int main()
{
	random[10] = {2,3,7,1,4,9,6,-1,5,8};
	
	for(int i=0; i<10; i++)
	{
		link[i] =random[i] ;
	}
	
	
}
