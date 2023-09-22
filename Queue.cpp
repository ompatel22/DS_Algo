#include<iostream>
using namespace std;
class queue
{
	int size;
	int* que;
	int f;
	int r;
	public:
		queue(int s)
		{
			size=s;
			f=r=-1;
			que=new int[s];
		}
		void enque(int ele)
		{
			if(r>=size-1)
			{
				cout<<"overflow\n";
				return;
			}
			if(f==-1)
			f++;
			que[++r]=ele;
		}
		int deque()
		{
			if(f==-1 || f>r)
			{
				cout<<"empty\n";
				return 0;
			}
			int val=que[f++];
			return(val);
		}
		int isem()
		{
			if(f=-1 || f>r)
			return 1;
			else
			return 0;
		}
		int isfull()
		{
			if(r>=size-1)
			return 1;
			else
			return 0;
		}
		void dis()
		{
			if(f==-1 || f>r)
			{
				cout<<"NULLL\n";
				return;
			}
			int temp=f;
			while(temp!=r+1)
			{
				cout<<que[temp]<<" ";
				temp++;
			}
			cout<<endl;
		}
};
int main()
{
	queue q1(5);
	q1.enque(1);
	q1.enque(2);
	q1.enque(3);
	q1.enque(4);
	q1.dis();
	q1.enque(5);
	q1.enque(10);
	q1.enque(10);
	q1.dis();
	q1.deque();
	q1.deque();
	q1.dis();
	q1.deque();
	q1.deque();
	q1.deque();
	q1.deque();
	q1.dis();
	q1.enque(777);
}
