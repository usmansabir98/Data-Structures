#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<conio.h>
using namespace std;

map<char, int> skip;

void preprocessing(char *P)
{
	int m = strlen(P);
	for(int j=0; j<m-1; j++)
	{
		skip[P[j]] = m-j-1;
	}
}

void BMH(char *P, char *T)
{
	preprocessing(P);
	
	int n = strlen(T);
	int m = strlen(P);
	
	int pos=0,j;
	while(pos<=n-m)
	{
		j=m-1; //setting j to the last index of pattern P
		
		//matching pattern from right of substring T[pos:j]
		while(j>=0 && T[pos+j]==P[j]) 
			j--;
			
		// if all character matches
		if(j==-1) cout << "Found at "<< pos << endl; 
		
		/* Shift the pattern so that the next 
               character in text aligns with the last 
               occurrence of it in pattern*/
		if(skip.count(T[pos+m-1]))
			pos += skip[T[pos+m-1]];
			
		// Default value in skip table is m
		else
			pos+=m;
	}
}

int main()
{
	char *P = "BREFBE";
	char *T = "TQEABEAYFBREFBADQERBEAYFBREFBE";
	BMH(P,T);
	
	
}
