#include<iostream>
#include<vector>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;a=b;b=temp;
}
void display(vector<int>& v)
{
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
}
void MaxHeapify(vector<int>& a,int i)
{
	int j,n=a.size();
	int key=a[i];
	for(j=(i*2)+1;j<n;j=(j*2)+1)
	{
		if(j<n-1)
		{
			if(a[j]<a[j+1])
			j++;	
		}
		if(key > a[j])
		{
			break;
		}
		a[(j-1)/2]=a[j];
	}
	a[(j-1)/2]=key;
}
void insert(vector<int>& a,int key)
{
	a.push_back(key);
	int i=a.size()-1;
	while(i>0)
	{
		int parent=((i-1)/2);
		if(a[parent]<a[i])
		{
			swap(a[parent],a[i]);
			i=parent;
		}
		else
		{
			return;
		}
	}
}
void deleteInHeap(vector<int>& a,int key)
{
	int n=a.size(),i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		break;
	}
	swap(a[i],a[n-1]);
	a.pop_back();
	MaxHeapify(a,i);
	//OR, if we want to always delete the Max. ele.
	/*
		int n=a.size();
		swap(a[0],a[n-1]);
		a.pop_back();
		MaxHeapify(a,0);
	*/ 
}
int main()
{
	vector<int> a;
	char c;
	int key;
	do
	{
		cout<<"enter a value\n";
		cin>>key;
		insert(a,key);
		cout<<"continue?\n";
		cin>>c;
	}while(c!='n');
	display(a);
	cout<<"enter value to delete\n";
	cin>>key;
	deleteInHeap(a,key);
	display(a);
	return 0;
}
