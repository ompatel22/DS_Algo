#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node* next;
	node(int d,node* l)
	{
		data=d;
		next=l;
	}
};
class que
{
	node* f;
	node* r;
	public:
		que()
		{
			f=r=NULL;
		}
		/*void en(int ele)
		{
			node* nn=new node(ele);
			if(f==NULL)
			{
				f=nn;
				r=nn;
				return;
			}
			r->next=nn;
			r=nn;
		}*/
		void en(int ele)
		{
			
			if(f==NULL)
			{
				f=r=new node(ele,NULL);
				return;
			}
			r=r->next=new node(ele,NULL);
		}
		int de()
		{
			node* temp;
			if(f==NULL)
			{
				cout<<"empty\n";
				return(0);
			}
	
			int val=f->data;
			temp=f;
			f=f->next;
			delete temp;
			return(val);
		}
		void dis()
		{
			node* curr=f;
			if(f!=NULL)
			{
				while(curr!=NULL)
				{
					cout<<curr->data<<" ";
					curr=curr->next;
				}
				cout<<endl;
			}
		}
};
int main()
{
	que q1;
	for(int i=1;i<=6;i++)
	{
		q1.en(i);
	}
	for(int i=1;i<=6;i++)
	{
		cout<<q1.de()<<endl;
	}
	cout<<endl;
	cout<<"hello\n";
}
