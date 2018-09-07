#include<iostream>
#include<string.h>
#include<math.h>
#define LINEAR 1
#define QUADRATIC 2
#define	DOUBLEHASH 3


using namespace std;

// hash table using open addressing

int probing = DOUBLEHASH;

class dict
{
	public:
		char word[10];
		char meaning[40];
		
		dict(char *w, char* m)
		{
			strcpy(word, w);
			strcpy(meaning, m);
		}
};

dict* table[100]={NULL};

unsigned long hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

void Insert(char* word, char* meaning)
{
	dict *newWord = new dict(word, meaning);
	
	int x = hash(word)%100;
	int original = x;
	
	while(table[x]!=NULL)
	{
		int i=1;
		switch(probing)
		{
			case LINEAR:
				x=(x+1)%100; break;
			
			case QUADRATIC:
				x=(x+int(pow(i++,2)))%100; break;
				
			case DOUBLEHASH:
				x=(x+ i*hash(word))%100; break;
		}
		if(x==original)
			break;
	}
	if(table[x]==NULL)
	{
		table[x] = newWord;
		cout << "\nSuccessfully Entered " << word << " at " << x << endl;
	}
		
	else
		cout << "Error inserting "<< word << endl;
}

char *Delete(char *key)
{
	int x = hash(key)%100;
	//cout << endl<< key << " is being searched at " << x << endl;
	int original = x;
	while(table[x]!=NULL && strcmp(table[x]->word,key)!=0)
	{
		int i=1;
		switch(probing)
		{
			case LINEAR:
				x=(x+1)%100; break;
			
			case QUADRATIC:
				x=(x+int(pow(i++,2)))%100; break;
				
			case DOUBLEHASH:
				x=(x+ i*hash(key))%100; break;
		}
		if(x==original)
			break;
	}
	
	if(table[x]==NULL)
		return "\nNot found \n";
	
	if(strcmp(table[x]->word,key)==0)
	{
		delete table[x];
		table[x] = NULL;
		cout << "\nDeleted " << key << endl;
	}
}

char *Search(char *key)
{
	int x = hash(key)%100;
	//cout << endl<< key << " is being searched at " << x << endl;
	int original = x;
	while(table[x]!=NULL && strcmp(table[x]->word,key)!=0)
	{
		int i=1;
		switch(probing)
		{
			case LINEAR:
				x=(x+1)%100; break;
			
			case QUADRATIC:
				x=(x+int(pow(i++,2)))%100; break;
				
			case DOUBLEHASH:
				x=(x+ i*hash(key))%100; break;
		}
		
		if(x==original)
			break;
	}
	
	if(table[x]==NULL)
		return "\nNot found \n";
	
	if(strcmp(table[x]->word,key)==0)
		return table[x]->meaning;
}

int main()
{
	Insert("apple", "a red color fruit");
	Insert("banana","a yellow color fruit");
	Insert("happy", "emotion");
	Insert("ducky", "my life");
	Insert("Apple", "healthy fruit");
	
	cout << "\napple = " << Search("apple");
	cout << "\nducky = " << Search("ducky");
	cout << "\nbanana = " << Search("banana");
	cout << "\nhappy = " << Search("happy");
	cout << "\nmickey = " << Search("mickey");
	cout << "\napple = " << Search("Apple");
	
	Delete("apple");
	cout << "\napple = " << Search("apple");	
}
