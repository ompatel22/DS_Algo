#include<iostream>
#include<stack>
#include<string>
using namespace std;
int  prec(char x)
{
	if(x=='^')
	return 3;
	else if(x=='*' || x=='/')
	return 2;
	else if(x=='+' || x=='-')
	return 1;
	else if (x=='#')
	return -1;
}
string intopost(string s)
{
	stack <char> st;
	st.push('#');
	string post="";
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9')
		{
			post+=s[i];		
		}
		else if(s[i]=='(')
		{
			st.push(s[i]);
		}
		else if(s[i]==')')
		{
			char c;
			for(c=st.top();c!='(';c=st.top())
			{
				st.pop();
				post+=c;
			}
			if(c=='(')
			{
				st.pop();
			}
		}
		else
		{
			if(prec(s[i]) <= prec(st.top()))
			{
				for(char c=st.top();prec(s[i])<=prec(c);c=st.top())
				{
					st.pop();
					post+=c;
				}
			}
			if(prec(s[i]) > prec(st.top()))
			{
				st.push(s[i]);
			}
		}
	}
	char c=st.top();
	while(c!='#')
	{
		st.pop();
		post+=c;
		c=st.top();
	}
	return (post);
	
}
int main()
{
	string s="a-b/c*d*e+f";
	cout<<intopost(s)<<endl;
}
