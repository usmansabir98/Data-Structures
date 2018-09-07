#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<iostream>
#include<conio.h>
#include<cstring>
using namespace std;

// Q! Lab Manual 10
/*You are given a string which comprises of lower case alphabets (a-z),
upper case alphabets (A-Z), numbers, (0-9) and special 
characters like !, -.; etc.
You are supposed to find out which character occurs the 
maximum number of times and the number of its occurrence, in the given 
string. If two characters occur equal number of times, you have to output 
the character with the lower ASCII value.

For example, if your string was: 
aaaaAAAA, your output would be: A 4, 
because A has lower ASCII value than a.

Input format:
The input will contain a string.

Output format:
You've to output two things which will be separated by a space:
i) The character which occurs the maximum number of times.
ii) The number of its occurrence.*/
 

unsigned int hash(unsigned int x)
{
	return x-32;
}

class node
{
	public:
		int val;
		int count;
		node * next;
		
		node(): val(0), count(0)
		{	}
};

node *table[95]= {NULL}; //126 - 32 + 1 (see ASCII chart)

node * create(int value)
{
	node *list;
	list = (node *)malloc(sizeof(node));
	if(list!=NULL)
	{
		list->val= value;
		list->count = 1;
		list->next=NULL;
	}
	return list;
}

node * insert(node *head, int value)
{
	node * newNode;
	newNode = (node *)malloc(sizeof(node));
	if(newNode!=NULL)
	{
		newNode->val= value;
		newNode->next=head;
	}
	return newNode;
}

int main()
{
	char str[] = "AAAaaaaA";
	int x;
	
	for(int i=0; i<strlen(str); i++)
	{
		x = hash(str[i]);
		if(table[x]==NULL)
			table[x] = create(str[i]);
		
		else
			table[x]->count++;
		
	}
	int Max = 0;
	int key = 0;
	for(int j=1; j<95; j++)
	{
		if(table[j]!=NULL)
		{
			if((table[j]->count)>Max)
			{

				Max = table[j]->count;
				key = j;

			}
		}
				
	}
	cout << (char)table[key]->val << " " << table[key]->count << endl;
	
}
