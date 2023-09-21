#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;
	bool leftthread;
	bool rightthread;
	node(int val)
	{
		data=val;
	}
};

node* build(node* nn)
{
	node* dummyroot=new node(999);
	node* root=nn;
	dummyroot->right=dummyroot;
	dummyroot->rightthread=false;
	dummyroot->left=root;
	dummyroot->leftthread=false;
	
	root->left=dummyroot;
	root->leftthread=true;
	root->right=dummyroot;
	root->rightthread=true;
	
	return(root);
}

void insert(node*& root,node* nn)
{
	if(root==NULL)
	{
		root=build(nn);	
		return;
	}
	if(nn->data < root->data)
	{
		if(root->leftthread==true)
		{
			nn->left=root->left;
			nn->leftthread=true;
			nn->right=root;
			nn->rightthread=true;
			
			root->left=nn;
			root->leftthread=false;
		}
		else
		{
			insert(root->left,nn);
		}
	}
	else if(nn->data > root->data)
	{
		if(root->rightthread==true)
		{
			nn->left=root;
			nn->leftthread=true;
			nn->right=root->right;
			nn->rightthread=true;
			
			root->right=nn;
			root->rightthread=false;
		}
		else
		{
			insert(root->right,nn);
		}
	}
}

node* insucc(node* curr)
{
	if (curr->rightthread)
	{
		return curr->right;
	} 
    else
    {
    	node* temp= curr->right;
        while (temp->leftthread==false)
            temp = temp->left;
        return temp;
	} 
}

void inorder(node* root)
{
	if(root==NULL)
	{	
		return;
	}
	node* temp=root;
	while(temp->leftthread==false)
	temp=temp->left;
	
	while (temp->data!=999)
	{
		cout<<temp->data<<" ";
		temp=insucc(temp);
	}
}

int main()
{
	node* root=NULL;
	int val;char ans;
	do
	{
		cout<<"enter Element\n";
		cin>>val;
		node* nn=new node(val);
		insert(root,nn);
		cout<<"continue?\n";
		cin>>ans;	
	}while(ans!='n');

	inorder(root);
	return 0;
}

