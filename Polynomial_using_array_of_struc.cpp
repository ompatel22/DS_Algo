#include<iostream>
using namespace std;
struct poly
{
	int coeff;
	int exp;	
};
int add(poly* p1,poly* p2,poly* &p3,int t1,int t2)
{
	p3=new poly[t1+t2];
	int i,j,k;
	i=j=k=0;
	while(i<t1 && j<t2)
	{
		if(p1[i].exp==p2[j].exp)
		{
			p3[k].coeff=p1[i].coeff+p2[j].coeff;
			p3[k].exp=p1[i].exp;
			i++;j++;k++;
		}
		else if(p1[i].exp>p2[j].exp)
		{
			p3[k].coeff=p1[i].coeff;
			p3[k].exp=p1[i].exp;
			i++;k++;
		}
		else
		{
			p3[k].coeff=p2[j].coeff;
			p3[k].exp=p2[j].exp;
			j++;k++;
		}
	}
	while(i!=t1)
	{
		p3[k].coeff=p1[i].coeff;
		p3[k].exp=p1[i].exp;
		i++;k++;
	}
	while(j!=t2)
	{
		p3[k].coeff=p2[j].coeff;
		p3[k].exp=p2[j].exp;
		j++;k++;
	}
	return(k);
}
int mul(poly* p1,poly* p2,poly* &p3,int n1,int n2)
{
	p3=new poly[n1+n2];
	int i,j,k,co,ex,n3=0,flag;
	i=0;
	while(i!=n1)
	{
		j=0;
		while(j!=n2)
		{
			k=0;
			flag=0;
			co=p1[i].coeff*p2[j].coeff;
			ex=p1[i].exp+p2[j].exp;
			while(k!=n3 && flag==0)
			{
				if(p3[k].exp==ex)
				{
					flag=1;
					break;
				}
				else
				{
					k++;
				}
			}
			if(flag==1)
			{
				p3[k].coeff+=co;
				p3[k].exp=ex;
			}
			else
			{
				p3[n3].coeff=co;
				p3[n3].exp=ex;
				n3++;
			}
			j++; 
		}
		i++;
	}
	return(n3);
}
void dis(poly* p,int n)
{
	for(int i=0;i<n-1;i++)
	{
		cout<<"("<<p[i].coeff<<"x^"<<p[i].exp<<")"<<"+";
	}
	cout<<"("<<p[n-1].coeff<<"x^"<<p[n-1].exp<<")"<<endl;
}
void input(poly* &p,int n)
{
	p=new poly[n];
	for(int i=0;i<n;i++)
	{
		cout<<"enter coefficient of "<<i+1<<"th ele\n";
		cin>>p[i].coeff;
		cout<<"enter exp of "<<i+1<<"th ele\n";
		cin>>p[i].exp;
	}
}
int main()
{
	int n1,n2;
	poly *p1,*p2,*p3,*p4;
	cout<"enter total no. of ele of 1st poly.\n";
	cin>>n1;

	input(p1,n1);
	cout<<"enter total no. of ele of 2nd poly.\n";
	cin>>n2;
	
	input(p2,n2);

	int n3=add(p1,p2,p3,n1,n2);
	int n4=mul(p1,p2,p4,n1,n2);
	dis(p3,n3);
	cout<<"mul\n";
	dis(p4,n4);
	return 0;
}
