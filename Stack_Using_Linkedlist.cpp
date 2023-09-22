#include<iostream>
using namespace std;
class node
{
public:
node * link;
int data;

public:
node(int d,node * l)
{
data=d;
link=l;

}

};

class impl
{
node * top;
public:
impl()
{

top=NULL;
}

int push(int data)
{
top=new node(data,top);


}

int pop()
{

int val=top->data;
node * temp=top;
top=top->link;

delete(temp);
return val;



}

int gettop()
{
	return(top->data);
}

};
int main()
{
	impl s1;
	s1.push(1);
	s1.push(1);
	s1.push(1);
	s1.push(1);
	s1.push(1);
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	
}
