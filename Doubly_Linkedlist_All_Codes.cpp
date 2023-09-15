#include<iostream>
using namespace std;
class dl;
class node
{
	public:
	friend class dl;
	int data;
	node* next;
	node* prev;
	public:
		node(int ele)
		{
			data=ele;
			next=prev=NULL;
		}
};
class dl
{
	public:
	node* head;
	public:
		dl()
		{
			head=NULL;
		}
void in(int ele)
{
	node* nn=new node(ele);
	node* curr=head;
	if(head==NULL)
	{
		head=nn;
		return;
	}
	while(curr->next!=NULL)
		curr=curr->next;
	curr->next=nn;
	nn->prev=curr;
}
void inbefore(int ce,int ne)
{
	node* nn=new node(ne);
	node* curr=head;
	if(head==NULL)
	{
		return;
	}
	if(head->data==ce)
	{
		nn->next=head;
		head->prev=nn;
		head=nn;
		return;
	}
	while(curr->next!=NULL && curr->next->data!=ce)
	{
		curr=curr->next;
	}
	if(curr->next==NULL )
	{
		cout<<"ele is not av\n";
		return;
	}
	if(curr->next->data==ce)
	{
		nn->next=curr->next;
		curr->next->prev=nn;
		curr->next=nn;
		nn->prev=curr;
	}
	
}
void dellast()
{
	node* curr=head;
	node* temp;
	if(head==NULL)
	return;
	if(head->next==NULL)
	{
		temp=head;
		head=NULL;
		delete temp;
		return;
	}
	while(curr->next->next!=NULL)
	{
		curr=curr->next;
	}
	temp=curr->next;
	curr->next=NULL;
	delete temp;
}
void dis()
	{
		node* curr=head;
		while(curr!=NULL)
		{
			cout<<curr->data<<"->";
			curr=curr->next;
		}
		cout<<"null\n";
	}
	void delaf(int ce)
	{
		node* curr=head;
		node* temp;
		if(head==NULL)
		{		
			return;
		}
		while(curr->next!=NULL && curr->data!=ce)
		{
			curr=curr->next;
		}
		if(curr->next==NULL && curr->data==ce)
		{
			cout<<"no af ele\n";
			return;
		}
		if(curr->next==NULL && curr->data!=ce)
		{
			cout<<"no ele fo\n";
			return;
		}
		if(curr->data==ce)
		{
			temp=curr->next;
			curr->next=temp->next;
			curr->next->prev=curr;
			delete temp;
		}
	}
	void delbef(int ce)
	{
		node*curr=head;
		node*temp;
		if(head==NULL)
		return;
		if(head->data==ce)
		{
			cout<<"no bef ele\n";
			return;
		}
		if(head->next->data==ce)
		{
			temp=head;
			head=head->next;
			head->prev=NULL;
			delete temp;
			return;
		}
		while(curr->next->next!=NULL && curr->next->next->data!=ce)
		{
			curr=curr->next;
		}
		if(curr->next->next==NULL)
		{
			cout<<"no ele\n";
			return;
		}
		if(curr->next->next->data==ce)
		{
			temp=curr->next;
			curr->next=temp->next;
			curr->prev=curr;
			return;
		}
	}
	void rev()
	{
		node* ptr1=head;
		node* ptr2=ptr1->next;
		
		ptr1->next=NULL;
		ptr1->prev=ptr2;
		while(ptr2!=NULL)
		{
			ptr2->prev=ptr2->next;
			ptr2->next=ptr1;
			ptr1=ptr2;
			ptr2=ptr2->prev;
		}
		head=ptr1;
	}
	void diss()
	{
		node* temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		while(temp->prev!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->prev;
		}
	}
	void deletefromeDL(int ele)
	{
		node* curr=head;
		node* temp;
		if(head==NULL)
		{
			return;
		}
		if(head->data==ele)
		{
			temp=head;
			head=head->next;
			head->prev=NULL;
			delete temp;
			return;
		}
		while(curr->next!=NULL && curr->next->data!=ele)
		{
			curr=curr->next;
		}
		if(curr->next==NULL)
		{
			cout<<"not found\n";
			return;
		}
		if(curr->next->next==NULL && curr->next->data==ele)
		{
			temp=curr->next;
			curr->next=NULL;
			delete temp;
			return;
		}
		if(curr->next->data==ele)
		{
			temp=curr->next;
			curr->next=temp->next;
			temp->next->prev=curr;
			delete temp;
			return;
		}
	}
	
};
void disrec(node* head)
{
	cout<<head->data;
	cout<<head->data;
	if(!head)
	return;
	if(head->next!=NULL)
	{
		disrec(head->next->next);
	}

}
int main()
{
	dl d1;
	d1.in(1);
	d1.in(2);
	d1.in(3);
	d1.in(4);
	d1.in(5);
	d1.in(6);
	d1.dis();
	//d1.inbefore(1,999);
	//d1.inbefore(2,999);
	//d1.inbefore(6,999);
	//d1.inbefore(7,999);
	//d1.dis();
	//d1.dellast();
	//d1.dellast();
	//d1.dis();
	//d1.delaf(1);
	//d1.delaf(2);
	//d1.delaf(6);
	//d1.delaf(8);
	/*d1.delbef(1);
	d1.delbef(2);
	d1.delbef(4);
	d1.delbef(6);
	d1.delbef(7);
	d1.dis();*/
	//d1.rev();
	d1.dis();
	//disrec(d1.head);
	//d1.diss();
	d1.deletefromeDL(1);
	d1.deletefromeDL(3);
	d1.deletefromeDL(6);
	d1.deletefromeDL(7);
	//d1.diss();
	d1.dis();
}
