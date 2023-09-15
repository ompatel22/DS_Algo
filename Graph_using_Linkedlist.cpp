#include<iostream>
#include<queue>
using namespace std;

class node
{
	public:
	int ele;
	int w;
	node* next;
	
	node(int ele,int w)
	{
		this->ele=ele;
		this->w=w;
		next=NULL;	
	}	
};
class ll
{
	public:
	node* head;
	ll()
	{
		head=NULL;
	}
	void ins(int ele,int w=0)
	{
		node* nn=new node(ele,w);
		node* curr=head;
		if(head==NULL)
		{
			head=nn;
			return;
		}
		while(curr->next!=NULL)
		curr=curr->next;
		
		curr->next=nn;
	}
};

class Graph2
{
	int tv;
	ll* arrofll;
	bool* visited;
	public:
		Graph2(int tv)
		{
			this->tv=tv;
			arrofll=new ll[tv];
			visited=new bool[tv];
			//assigning all as false;	
			for(int i=0;i<tv;i++)
			{
			visited[i]=false;
			}
		}
		void add_edge(int s,int d,int w=0)
		{
			arrofll[s].ins(d,w);	
		}
		void dis_list()
		{
			for(int i=0;i<tv;i++)
			{
				ll l1=arrofll[i];
				node* curr=l1.head;
				cout<<i<<"--->";
				while(curr!=NULL)
				{
					cout<<curr->ele<<"->";
					curr=curr->next;
				}
				cout<<"NULL\n";
			}
		}	
		void DFS(int v)
		{
			visited[v]=true;
			cout<<v<<" ";
			
			ll l1=arrofll[v];
			node* curr=l1.head;
			while(curr!=NULL)
			{
				int ele=curr->ele;
				
				if(visited[ele]!=true)
				{
					DFS(ele);
				}
					
				curr=curr->next;
			}	
		}	
		void BFS(int v)
		{
			for(int i=0;i<tv;i++)
			visited[i]=false;
			
			queue <int> q;
			visited[v]=true;
			cout<<v<<" ";
			q.push(v);
			
			while(!q.empty())
			{
				int ele=q.front();
				q.pop();
				ll l1=arrofll[ele];
				node* curr=l1.head;
				while(curr!=NULL)
				{
					if(visited[curr->ele]!=true)
					{
						visited[curr->ele]=true;
						cout<<curr->ele<<" ";
						q.push(curr->ele);
					
					}
					curr=curr->next;
				}
			}
			
		}
};
int main()
{
	Graph2 g(11);
	g.add_edge(1,4);
	g.add_edge(1,2);
	g.add_edge(2,3);
	g.add_edge(2,1);
	g.add_edge(2,5);
	g.add_edge(2,7);
	g.add_edge(2,8);
	g.add_edge(3,4);
	g.add_edge(3,2);
	g.add_edge(3,10);
	g.add_edge(3,9);
	g.add_edge(4,1);
	g.add_edge(4,3);
	g.add_edge(5,6);
	g.add_edge(5,2);
	g.add_edge(5,7);
	g.add_edge(6,5);
	g.add_edge(7,5);
	g.add_edge(7,8);
	g.add_edge(7,2);
	g.add_edge(8,7);
	g.add_edge(8,5);
	g.add_edge(8,2);
	g.add_edge(9,3);
	g.add_edge(10,3);
	cout<<"dis_list\n";
	g.dis_list();
	cout<<"\nDFS\n";
	g.DFS(1);
	cout<<"\nBFS\n";
	g.BFS(1);
	return 0;
		
}
