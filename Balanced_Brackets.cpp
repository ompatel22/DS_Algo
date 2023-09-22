#include<iostream>
#include<string>
//#include<stack>
using namespace std;
template <class T>
class stack
{
	int capacity;
	int top;
	T* arr;
	public:
		stack(int c)
		{
			capacity=c;
			top=-1;
			arr=new T[c];
		}
		void push(T x)
		{
			if(top>=capacity-1)
			{
				cout<<"overflow\n";
				return;
			}
			arr[++top]=x;
		}
		void pop()
		{
			if(top==-1)
			{
				cout<<"underflow\n";
				return;
			}
			top--;
		}
		T topp()
		{
			if(top==-1)
			{
				cout<<"underflow\n";
				return(0);
			}
			return(arr[top]);
		}
		int isfull()
		{
			if(top>=capacity-1)
			return(1);
			else
			return 0;
		}
		int size()
		{
			return(top+1);
		}
		int isempty()
		{
			if(top==-1)
			return 1;
			else 
			return 0;
		}
};
/*int main()
{
	stack <char> s1(5);
	for(int i=0;i<5;i++)
	{
		int ele;
		cin>>ele;
		s1.push(ele);
	}
	s1.push(100);
	s1.push(999);
	for(int i=0;i<5;i++)
	{
		cout<<s1.pop()<<" ";
	}
	cout<<endl;
	int t=s1.pop();
	
	cout<<s1.isempty()<<endl;
	cout<<s1.isfull()<<endl;

}
*/
/*class stack;
class node
{
	friend class stack;
	int data;
	node* next;
	public:
	node(int x)
	{
		data=x;
		next=NULL;
	}	
};
class stack
{
	node* head;
	int capacity;
	int size;
	public:
		stack(int c)
		{
			head=NULL;
			capacity=c;
			size=0;
		}
		void push(int ele)
		{
			if(size==capacity)
			{
				cout<<"overflow\n";
				return;
			}
			node* nn=new node(ele);
			size++;
			nn->next=head;
			head=nn;
		}
		int pop()
		{
			if(head==NULL)
			{
				cout<<"underflow\n";
				return(0);
			}
			int res=head->data;
			node* temp=head;
			head=head->next;
			delete temp;
			size--;
			return(res);
		}
		int isempty()
		{
			if(head==NULL)
			return 1;
			else
			return 0;
		}
		int isfull()
		{
			if(size==capacity)
			return 1;
			else
			return 0;
		}
		int getsize()
		{
			return(size);
		}
};
stack copy(stack& ip)
{
	stack temp(5),res(5);
	while(ip.isempty()==0)
	{
		int ele=ip.pop();
		temp.push(ele);
	}
	while(temp.isempty()==0)
	{
		int ele=temp.pop();
		res.push(ele);
	}
	return(res);
}
void copy(stack &ip,stack &res)
{
	if(ip.isempty()==1)
	return;
	int ele=ip.pop();
	copy(ip,res);
	res.push(ele);
}*/
int isbalanced(string s)
{
	stack <char> s1(25);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(' || s[i]=='{' || s[i]=='[')
		{
			s1.push(s[i]);
		}
		else
		{
			if(s1.isempty()==1)
			{
				return 0;
			}
			else if( s[i]==')' && s1.topp()=='(' || s[i]=='}' && s1.topp()=='{' || s[i]==']' && s1.topp()=='['  )
			{
				s1.pop();
			}
			else
			{
				return(0);
			}
		}
	}
	if(s1.isempty()==1)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
/*int isbalanced(std::string s) {
    std::stack<char> s1;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            s1.push(s[i]);
        } else {
            if (s1.empty()) {
                return 0; // No corresponding opening bracket on the stack.
            }
            if ((s[i] == ')' && s1.top() == '(') ||
                (s[i] == '}' && s1.top() == '{') ||
                (s[i] == ']' && s1.top() == '[')) {
                s1.pop();
            } else {
                return 0; // Mismatched closing bracket.
            }
        }
    }

    return s1.empty() ? 1 : 0; // Check if there are any unclosed opening brackets.
}*/
int main()
{
	string s1="([([])]){({{{[[()]]}}})}";
	int x=isbalanced(s1);
	cout<<x<<endl;
	
}
