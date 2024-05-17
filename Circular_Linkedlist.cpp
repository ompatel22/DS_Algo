#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node* next;
		node(int val)
		{
			data=val;
			next=NULL;
		}
};
class CLL
{
	public:
	node* head;
	CLL()//----------------------------------------------------------------
	{
		head=NULL;
	}
	void insathead(int val)
	{
		node* nn=new node(val);
		if(head==NULL)
		{
			head=nn;
			nn->next=nn;
			return;
		}
		node* curr=head;
		while(curr->next!=head)
		curr=curr->next;
		
		curr->next=nn;
		nn->next=head;
		head=nn;
	}	
	void insatend(int val)
	{
		node* nn=new node(val);
		if(head==NULL)
		{
			head=nn;
			nn->next=nn;
			return;
		}
		node* curr=head;
		while(curr->next!=head)
		curr=curr->next;
		
		curr->next=nn;
		nn->next=head;
	}
	void delathead()
	{
		node* temp;
		node* curr=head;
		if(head==NULL)
		{
			cout<<"empty\n";
			return;
		}
		if(head->next==head)
		{
			temp=head;
			head=NULL;
			delete temp;
			return;
		}
		while(curr->next!=head)
		curr=curr->next;
		
		temp=head;
		curr->next=head->next;
		head=head->next;
		delete temp;//TAKE CARE!!!!!!!!!!!!!!!!!
	}
	void delatend()
	{
		node* temp;
		node* curr=head;
		if(head==NULL)
		{
			cout<<"empty\n";
			return;
		}
		if(head->next==head)
		{
			temp=head;
			head=NULL;
			delete head;
			return;
		}
		while(curr->next->next!=head)
		{
			curr=curr->next;
		}
		temp=curr->next;
		curr->next=head;
		delete temp;
	}
	void dis()
	{
		if(head==NULL)
		{
			cout<<"ll is khali bhai\n";
		}
		node* curr=head;
		do
		{
			cout<<curr->data<<"->";
			curr=curr->next;
		}while(curr!=head);
		
		cout<<"NULL\n";
	}
};
int main()
{
	CLL l1;
	l1.insathead(1);
	l1.insathead(2);
	l1.insathead(3);
	l1.insatend(4);
	l1.insatend(5);
	l1.insatend(6);
	l1.dis();
	l1.delathead();
	l1.delatend();
	l1.dis();
}
