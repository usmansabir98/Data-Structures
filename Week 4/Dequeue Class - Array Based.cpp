#include<iostream>
using namespace std;

class dequeue
{
	private:
		enum {MAX=3};
		int A[MAX], front, rear;
		
	public:
		dequeue(): front(-1), rear(-1)
		{ }
		
		bool isEmpty()
		{
			if(front==-1 && rear== -1)
				return true;
			return false;
		}
		
		bool isFull()
		{
			if((rear+1)%MAX==front)
				return true;
			return false;
		}
		
		void addFirst(int val)
		{
			if(isFull())
			{
				cout << "Overflow" <<endl;
				return;
			}
			
			else if(isEmpty())
				front=rear=0;
			
			else
				front=(front-1)%MAX;
				
			A[front]=val;
			cout << val << " enqueued" <<endl;
		}
		
		void addLast(int val)
		{
			if(isFull())
			{
				cout << "Overflow" <<endl;
				return;
			}
			
			else if(isEmpty())
				front=rear=0;
			
			else
				rear=(rear+1)%MAX;
				
			A[rear]=val;
			cout << val << " enqueued" <<endl;
		}
		
		int removeFirst()
		{
			int ret;
			if(isEmpty())
			{
				cout << "Underflow" <<endl;
				return 0; 
			}
			ret = A[front];
			if(front==rear)
				front=rear=-1;
			
			else
				front=(front+1)%MAX; 
				
			return ret;
		}
};

int main()
{
	queue q;
	q.enqueue(1); q.enqueue(2); q.enqueue(3); 
	cout << q.dequeue() << endl;
	q.enqueue(4);
	
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
}
