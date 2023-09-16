#include<iostream>
using namespace std;
class ll;
class node
{
	public:
	friend void join(node*,node*);
	friend node* copy(node*);
	friend node* revrec(node*);
	friend class ll;
	int data;
	node* next;	
	public:
		node(int x)
		{
			data=x;
			next=NULL;
		}
};
class ll
{
	friend void join(node*,node*);
	friend node* copy(node*);
	friend node* revrec(node*);
	node* head;
	public:
	ll()
	{
		head=NULL;
	}
	void in(int ele)
	{
		node* nn=new node(ele);
		node* temp=head;
		if(temp==NULL)
		{
			head=nn;
			nn->next=NULL;
		}
		else
		{
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=nn;
			nn->next=NULL;
		}
	}
	void dis()
	{
		node* temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL\n";
	}
	void in_before(int ce,int ne)
	{
		if(head==NULL)
		{
			cout<<"empty\n";
			return;
		}
		node* nn=new node(ne);
		node* curr=head;
		if(head->data==ce)
		{
			nn->next=head;
			head=nn;
			return;
		}
		while(curr->next!=NULL&& curr->next->data!=ce )
		{
			curr=curr->next;
		}
		if(curr->next==NULL)
		{
			cout<<"ele not found\n";
			cout<<"insertion at the end\n";
			curr->next=nn;
			nn->next=NULL;
		}
		else if(curr->next->data==ce)
		{
			nn->next=curr->next;
			curr->next=nn;
		}
	}	
	void in_after(int ce,int ne)
	{
		if(head==NULL)
		{
			cout<<"empty\n";
			return;
		}
		node* nn=new node(ne);
		node* curr=head;
		while(curr->next!=NULL && curr->data!=ce)
		{
			curr=curr->next;
		}
		if(curr->next==NULL && curr->data==ce)
		{
			curr->next=nn;
			nn->next=NULL;
		}
		else if(curr->next==NULL && curr->data!=ce)
		{
			cout<<"ele not found & insert at the end\n";
			curr->next=nn;
			nn->next=NULL;
		}
		else if(curr->data==ce)
		{
			nn->next=curr->next;
			curr->next=nn;
		}
	}
	void del_before(int ce)
	{
		if(head==NULL)
		{
			return;
		}
		node* curr=head;
		node* temp;
		if(head->data==ce)
		{
			cout<<"no ele before\n";
			return;
		}
		if(head->next->data==ce)
		{
			cout<<"delete at head\n";
			temp=head;
			head=head->next;
			delete temp;
			return;
		}
		while(curr->next->next!=NULL && curr->next->next->data!=ce)
		{
			curr=curr->next;
		}
		if(curr->next->next==NULL)
		{
			cout<<"ele not found\n";
			return;
		}
		if(curr->next->next->data==ce)
		{
			temp=curr->next;
			curr->next=temp->next;
			delete temp;
		}
	}
	void del_after(int ele)
	{
		node* temp;
		node* curr=head;
		if(head==NULL)
		{
			return;
		}
		while(curr->next!=NULL && curr->data!=ele)
		{
			curr=curr->next;
		}
		if(curr->next==NULL && curr->data==ele)
		{
			cout<<"no after ele\n";
			return;
		}
		if(curr->next==NULL && curr->data!=ele)
		{
			cout<<"no ele found\n";
			return;
		}
		if(curr->data==ele)
		{
			temp=curr->next;
			curr->next=temp->next;
			delete temp;
		}
	}
	void rev()
	{
		node* curr=head;
		node* next=NULL;
		node* prev=NULL;
		if(head==NULL)
		{
			cout<<"ll is empty\n";
			return;
		}
		while(curr!=NULL)
		{
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
		head=prev;
		
	}
	void allthedup()
	{
		node* temp;
		node* curr=head;
		if(head==NULL)
		{
			return;
		}
		while(curr!=NULL)
		{
			while(curr->next!=NULL && curr->data==curr->next->data )
			{
				temp=curr->next;
				curr->next=temp->next;
				delete temp;
			}
			curr=curr->next;
		}
	}
	int len()
	{
		int l=0;
		node* curr=head;
		while(curr!=NULL)
		{
			l++;
			curr=curr->next;
		}
		return(l);
	}
	/*void sort(int n)
	{
		node* curr=head;
		for(node* t1=curr;t1->next!=NULL;t1=t1->next)
		{
			for(node* t2=curr->next;t2!=NULL;t2=t2->next)
			{
				if(t1->data > t2->data)
				{
					int temp=t1->data;
					t1->data=t2->data;
					t2->data=temp;
				}
			}
		}
	}*/
	void sethead(node* t)
	{
		head=t;
	}
	node* gethead()
	{
		return(head);
	}
	void in_atind(int n,int val)
	{
		node* nn=new node(val);
		node* curr=head;
		int c=1;
		if(head==NULL)
		{
			return;
		}
		if(n==1)
		{
			nn->next=head;
			head=nn;
			return;
		}
		while(curr->next!=NULL && c!=n-1)
		{
			c++;
			curr=curr->next;
		}
		if(c==n-1)
		{
		
		nn->next=curr->next;
		curr->next=nn;
		return;
		}
		if(curr->next==NULL && c!=n-1)
		{
			cout<<"inserting at the end\n";
			curr->next=nn;
			nn->next=NULL;
		}
	}
	void change(int in,int val)
	{
		int c=0;
		node* curr=head;
		while(curr->next!=NULL && c!=in)
		{
			c++;
			curr=curr->next;
		}
		if(c==in)
		{
			curr->data=val;
			return;
		}
		if(curr->next==NULL)
		{
			cout<<"ind does not exist\n";
			return;
		}
	}
	void alternative()
	{
		node* temp;
		head=head->next;
		node* curr=head;
		while(curr!=NULL && curr->next!=NULL)
		{
			temp=curr->next;
			curr->next=temp->next;
			delete temp;
			curr=curr->next;
		}
	}
	void delentire()
	{
		node* temp;
		while(head!=NULL)
		{
			temp=head;
			head=head->next;
			delete temp;
		}
	}
	void sort()
	{
		node* t1=head;
		while(t1->next!=NULL)
		{
			node* t2=head->next;
			while(t2!=NULL)
			{
				if(t1->data>t2->data)
				{
					int temp=t1->data;
					t1->data=t2->data;
					t2->data=temp;
				}
				t2=t2->next;
			}
			t1=t1->next;

		}
	}
	
};

node* revrec(node* head)
{
	if(head==NULL || head->next==NULL)
	{
		return(head);
	}
	node* newhead=revrec(head->next);
	node* temp=head->next;
	temp->next=head;
	head->next=NULL;
	return(newhead);
}
node* copy(node* h1)
{
	node*h2=NULL;
	node* c1;
	node* c2;
	if(h1==NULL)
	{
		return(h1);
	}
	node* nn=new node(h1->data);
	h2=nn;
	nn->next=NULL;
	c1=h1->next;
	c2=h2;
	while(c1!=NULL)
	{
		node* nn=new node(c1->data);
		c2->next=nn;
		nn->next=NULL;
		c2=c2->next;
		c1=c1->next;
	}
	return(h2);
}
void join (node* h1,node* h2)
{
	node* curr=h1;
	if(h1==NULL)
	{
		h1=h2;
		//return(h1);
	}
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	curr->next=h2;
	//return(h1);
}
node* inrec(node* head,int ele)
{
	if(head==NULL)
	{
		head=new node(ele);
		return head;
	}
	else
	{
		head->next=inrec(head->next,ele);
	}
}
void disrec(node* head)
{
	if(head==NULL)
	{
		return;
	}
	else
	{
		cout<<head->data<<"->";
		disrec(head->next);
	}
}
void funn(node* head)
{
	if(head==NULL)
	return;
	cout<<head->data;
	funn(head->next);
	cout<<head->data;
}

int main()
{
	ll l1;
	l1.in(1);
	l1.in(2);
	l1.in(3);
	l1.in(4);
	l1.in(5);
	l1.in(6);
	l1.in(7);
	l1.in(8);
	l1.in(9);
	l1.in(10);
	//l1.in_before(1,999);
	//l1.in_before(2,999);
	//l1.in_before(6,999);
	//l1.in_before(8,999);
	//l1.in_before(9,999);
	//l1.dis();
	/*l1.in_after(1,999);
	l1.in_after(3,999);
	l1.in_after(8,999);
	l1.in_after(9,999);
	l1.dis();*/
	//l1.del_before(1);
	//l1.del_before(2);
	//l1.del_before(5);
	//l1.del_before(8);
	//l1.del_before(9);
	//l1.dis();
	/*l1.del_after(1);
	l1.del_after(4);
	l1.del_after(8);
	l1.del_after(9);
	l1.dis();*/
	
	//int len=l1.len();
	//l1.allthedup();
	//l1.sort(len);
	//l1.rev();
	//cout<<"len="<<len<<endl;
	//node* temp=revrec(l1.gethead());
	//l1.sethead(temp);
	//l1.in_atind(3,3);
	//l1.in_atind(9,9);
	//l1.in_atind(20,10);
	//l1.in_atind(5,999);
	//l1.change(25,888);
	//l1.alternative();
	l1.dis();
	node* c=copy(l1.gethead());
	ll l2;
	l2.sethead(c);
	l2.dis();
	join(l1.gethead(),l2.gethead());
	l1.dis();
	l1.rev();
	l1.dis();
	node* tempp=inrec(l1.gethead(),7777);
	l1.sethead(tempp);
	disrec(l1.gethead());
	l1.delentire();
	l1.dis();
	//node* temp2=inrec(l1.gethead(),7777);
	//l1.sethead(temp2);
	l1.dis();
	l1.in(47);
	l1.in(45);
	l1.in(84);
	l1.in(487);
	l1.in(5);
	l1.in(64);
	//funn(l1.gethead());
	l1.sort();
	l1.dis();
	return 0;
}

