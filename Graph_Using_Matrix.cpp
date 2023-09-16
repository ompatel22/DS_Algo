#include<iostream>
#include<queue>
using namespace std;
class Graph
{
	int tv;
	int ** G;
	bool * visited;
	public:
	Graph(int tv)
	{
		this->tv=tv;
		G=new int* [tv];	
		for(int i=0;i<tv;i++)
		{
			G[i]=new int[tv];
		}
		visited=new bool[tv];
		
		//assigning all as 0 initially
		for(int i=0;i<tv;i++)
		{
			for(int j=0;j<tv;j++)
			{
				G[i][j]=0;
			}
		}
		//assigning all as false initially
		for(int i=0;i<tv;i++)
		{
			visited[i]=false;
		}
	}
	void add_edge(int s,int d,int w=1)
	{
		G[s][d]=w;	
	}
	void display_adjMat()
	{
		for(int i=0;i<tv;i++)
		{
			for(int j=0;j<tv;j++)
			{
				cout<<G[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	void DFS(int v)
	{	
		visited[v]=true;
		cout<<v<<" ";
		for(int i=0;i<tv;i++)
		{
			if(G[v][i]!=0 && visited[i]!=true)
			{
				DFS(i);
			}	
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
			for(int i=0;i<tv;i++)
			{
				if(G[ele][i]!=0 && visited[i]!=true)	
				{
					visited[i]=true;
					cout<<i<<" ";
					q.push(i);
				}
			}
		}
	}
	void DijkstrasAllPairShortestPath()
	{	
		for(int k=0;k<tv;k++)
		{
			for(int i=0;i<tv;i++)
			{
				for(int j=0;j<tv;j++)
				{
					if(G[i][k]+G[k][j]<G[i][j])
					{
						G[i][j]=G[i][k]+G[k][j];
					}
				}
			}
		}
	}
};
int main()
{
	Graph g(3);
	g.add_edge(0,1,6);
	g.add_edge(0,2,22);
	g.add_edge(1,0,8);
	g.add_edge(1,2,2);
	g.add_edge(2,0,12);0
	g.add_edge(2,1,3);
	
	cout<<"before\n";
	g.display_adjMat();
	g.DijkstrasAllPairShortestPath();
	cout<<"after\n";
	g.display_adjMat();
	/*g.add_edge(1,4);
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
	cout<<"display_adjMat\n";
	g.display_adjMat();
	cout<<"\nDFS\n";
	g.DFS(1);
	cout<<"\nBFS\n";
	g.BFS(1);*/
	return 0;
}

