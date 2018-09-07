//Write an independent method public static void removeDownTo (StackADT stack, Object ob): It pops all values off
// the stack down to but not including the first element it sees that is equal to the second parameter. If none are equal, leav
//e the stack empty. The ob parameter could be null.
 #include<string.h>
#include<cstdlib>
#include<iomanip>
#include<cmath>
#include<iostream>
using namespace std;
class Stack
{
private:
enum { MAX = 5 }; 
int st[MAX]; //stack: array of integers
int top; //number of top of stack
public:
Stack() //constructor
{ top = -1; }
void push(int var) //put number on stack
{ if(top>=MAX-1)
cout<<"overflow\n";
else
 st[++top] = var; }
int pop() //take number off stack
{ if(top<=-1)
{cout<<"Underflow\n";
exit(0);}
else
return st[top--]; }
int tp(){
	if(top!=-1)
		return st[top];
	return 0;
}
int gettop(){
	return top;
}
int getsec( ){
 int sec= top-1;

 return sec;
	
}

bool empty(){
	if (top==-1)
	return true;
	else return false;
}
};

void interchange(Stack *s1, Stack *s2)
{
	Stack temp;
	while(!s1->empty())
	{
		temp.push(s1->pop());
		temp.push(s2->pop());
	}
	while(!temp.empty())
	{
		s1->push(temp.pop());
		s2->push(temp.pop());
		
	}
}

int main()
{
	Stack s1, s2;
	
	s1.push(7); s1.push(5); s1.push(3); s1.push(1);
	s2.push(8); s2.push(6); s2.push(4); s2.push(2);
	// s1 has 1,3,5,7
	// s2 has 2,4,6,8
	
	interchange(&s1, &s2);
	// after interchange
	cout << "Interchanged"<< endl;
	cout << "s1" <<setw(10)<< "s2" << endl;
	cout << s1.pop() <<setw(10)<< s2.pop() << endl;
	cout << s1.pop() <<setw(10)<< s2.pop() << endl;
	cout << s1.pop() <<setw(10)<< s2.pop() << endl;
	cout << s1.pop() <<setw(10)<< s2.pop() << endl;
}
