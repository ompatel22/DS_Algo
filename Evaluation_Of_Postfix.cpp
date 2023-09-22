#include<stack>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int prec(char c)
{
	if(c=='^')
	return 4;
	else if(c=='*' || c=='/')
	return 3;
	else if(c=='+' || c=='-')
	return 2;
	else
	return 1;
}
string itop(string str)
{
	string po;
	stack <char> st;
	st.push('#');
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='(')
		st.push(str[i]);
		else if(str[i]>='A' && str[i]<='Z')
		po+=str[i];
		else if(str[i]==')')
		{
			while(st.top()!='(')
			{
				po+=st.top();
				st.pop();
			}
			st.pop();
		}
		else 
		{
			if(st.top()=='#')
			st.push(str[i]);
			else
			{
				if(prec(str[i])>prec(st.top()))
				{
					st.push(str[i]);
				}
				else
				{
					while(prec(str[i])<=prec(st.top()))
					{
						po+=st.top();
						st.pop();
					}
					st.push(str[i]);
				}
			}
		}
	}
	while(st.top()!='#')
	{
		po+=st.top();
		st.pop();
	}
	return(po);
}
int eval(string str)
{
	stack <int> st;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			st.push((str[i]-'0'));
		}
		else
		{
		int op2=st.top();
		st.pop();
		int op1=st.top();
		st.pop();
		switch(str[i])
		{
			case '+':
				st.push(op1+op2);break;
			case '-':
				st.push(op1-op2);break;
			case '*':
				st.push(op1*op2);break;
			case '/':
				st.push(op1/op2);break;		
		}
	}
	}
	return(st.top());
}
int main()
{
	string s="46+2/5*7+";
	cout<<eval(s);
}
