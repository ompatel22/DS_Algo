#include<iostream>
using namespace std;
class poly
{
	public:
	int co;
	int exp;
	poly* next;
	
	poly(int c,int e)
	{
		co=c;exp=e;next=NULL;
	}	
};
/*void addathead(poly* &head,int c,int e)
{
	poly* p=new poly(c,e);
	p->next=head;
	head=p;
}*/
void addele(poly* &head,int c,int e)
{
	poly* p=new poly(c,e);
	poly* temp=head;
	if(head==NULL)
	{
		head=p;
		head->next=NULL;
	}
	else
	{
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	
	temp->next=p;
	p->next=NULL;
	}
}
void display(poly* head)
{
	poly* temp=head;
	while(temp!=NULL)
	{
		cout<<"("<<temp->co<<"x^"<<temp->exp<<")";
		if(temp->next==NULL)
		cout<<endl;
		else
		cout<<"+";
		temp=temp->next;
	}
}
void input(poly* &head)
{
	int n,c,e;
	cout<<"enter total no. of ele of poly\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter co & exp of term:"<<i+1<<endl;
		cin>>c>>e;
		addele(head,c,e);
	}
	
}
poly* add(poly* h1,poly* h2)
{
	poly* h3=NULL;
	poly *t1=h1,*t2=h2;
	while(t1!=NULL && t2!=NULL)
	{
		if(t1->exp==t2->exp)
		{
			addele(h3,(t1->co+t2->co),t1->exp);
			t1=t1->next;t2=t2->next;
		}
		else if(t1->exp > t2->exp)
		{
			addele(h3,t1->co,t1->exp);
			t1=t1->next;
		}
		else
		{
			addele(h3,t2->co,t2->exp);
			t2=t2->next;
		}
		
	}
	while(t1!=NULL)
	{
		addele(h3,t1->co,t1->exp);
		t1=t1->next;
	}
	while(t2!=NULL)
	{
		addele(h3,t2->co,t2->exp);
		t2=t2->next;
	}
	return(h3);
}
int main()
{
	poly* h1=NULL;
	poly* h2=NULL;
	input(h1);
	input(h2);
	poly* h3=add(h1,h2);
	display(h1);
	display(h2);
	display(h3);
	return 0;
	
}
