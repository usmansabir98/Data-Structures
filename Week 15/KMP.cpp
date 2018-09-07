#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;

void KMP_prefix(int *table, char *P)
{
	int m = strlen(P);
	table[0] = 0;
	int i=0;
	int j;
	for(j=1; j<m; j++)
	{
		while(i>0 && P[i]!=P[j])
			i=table[i-1];
		if(P[i]==P[j])
			i++;
		table[j]=i;
	}
}

/*void KMP_matcher(char* T, char* P)
{
	int n = strlen(T);
	int m = strlen(P);
	int *table = new int[m];
	KMP_prefix(table, P);
	
	
	int i=0,j;
	
	for(j=0; j<n; j++)
	{
		cout << "j= " << j<<endl;
		while(i>0 && P[i]!=T[j])
		{
			i=table[i-1];
			cout << "\t1. i=" << i <<endl;
			getch();
		}
			
		if(P[i]==T[j])
		{
			i++;
			cout << "\t2. i=" << i <<endl;
			getch();
		}
			
		if(i==m)
		{
			cout << "Pattern matches at "<< j-m+1 <<endl;
			i = table[i];
			cout << "\t3. i=" << i <<endl;
			getch();
		}
		
	}
}*/

void KMP_matcher(char* T, char* P)
{
	int n = strlen(T);
	int m = strlen(P);
	int *table = new int[m];
	KMP_prefix(table, P);	
	
	int i=0,j;
	
	for(j=0; j<n; j++)
	{
		cout << "j= " << j<<endl;	
		if(P[i]==T[j])
		{
			i++;
			cout << "\t2. i=" << i <<endl;
			getch();
		}
		
		else
		{
			if(i>0)
			{
				i = table[i-1];
				if(P[i]==T[j])
					i++;
			}		
		}
			
		if(i==m)
		{
			cout << "Pattern matches at "<< j-m+1 <<endl;
			i = table[i-1];
			cout << "\t3. i=" << i <<endl;
			getch();
		}
	}
}

int main()
{
	char pattern[] =  "ABABCABAB";
	char text[] = "ABABDABACDABABCABABBBBBBBBBBBBBBBBBBBBB";
//	int table[7];
//	KMP_prefix(table,str);
//	
//	for(int i=0; i<strlen(str); i++)
//	{
//		cout << table[i]<< " ";
//	}

	KMP_matcher(text, pattern);	
	
}
