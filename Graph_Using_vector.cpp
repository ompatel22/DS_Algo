#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph3
{
	int tv;
	bool* visited;
	vector< vector<int> > adjlist;
	public:
	Graph3(int tv)
	{
		this->tv=tv;
		adjlist.resize(tv);
		visited=new bool[tv];
		
		for(int i=0;i<tv;i++)//------------------------------------------>>>>>>>>>>>>>most
		visited[i]=false;
	}
	void add_edge(int s,int d)
	{
		adjlist[s].push_back(d);
	}
	void dis_list()
	{
		for(int i=0;i<tv;i++)
		{
			cout<<i<<"--->";
			for(int j=0;j<adjlist[i].size();j++)
			{
				cout<<adjlist[i].at(j)<<" ";//OR adjlist[i][j];
			}
			cout<<"\n";
		}
	}
	void DFS(int v)
	{
		visited[v]=true;
		cout<<v<<" ";
		
		for(int i=0;i<adjlist[v].size();i++)
		{
			int ele=adjlist[v][i];
			if(visited [ele]!=true)
			{
				DFS(ele);
			}
		}
	}
	void BFS(int v)
	{
		for(int i=0;i<tv;i++)
		{
			visited[i]=false;
		}
		
		queue <int> q;
		q.push(v);
		visited[v]=true;
		cout<<v<<" ";
		
		while(!q.empty())
		{
			int ele=q.front();
			q.pop();
			for(int i=0;i<adjlist[ele].size();i++)
			{
				int temp=adjlist[ele][i];
				if(visited[temp]!=true)
				{
					visited[temp]=true;
					cout<<temp<<" ";
					q.push(temp);	
				}	
			}		
		}
	}
		
};
int main()
{
	Graph3 g(11);
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
