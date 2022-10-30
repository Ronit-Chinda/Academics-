#include <bits/stdc++.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
using namespace std;

// Find minimum spanning tree

// without minheap
int primsMst(vector<vector<int>> graph,int v){
	int key[v],res=0;
	fill(key,key+v,INT_MAX);

	key[0]=0;
	bool mset[v]={false};
	for (int count = 0; count < v; ++count)
	{
		int u=-1;
		// this loop is for finding minimum weighted edge out of all the adjacent of it and traversing to it 
		for (int i = 0; i < v; ++i)
		{
			if (!mset[i] && (u==-1 || key[i]<key[u]))
			{
				u=i;
			}
		}
		mset[u]=true;
		res=res+key[u];
		for (int j = 0; j < v; ++j)
		{
			if (graph[u][j]!=0 && !mset[j])
			{
				key[j]=min(key[j],graph[u][j]);
			}
		}
	}
	return res;
}

int main(){

	cout<<"Enter number of Vertices"<<endl;
	int n, m;   
	cin>>n;

	vector<vector<int>> graph;
	vector<int> temp;
	for (int i = 0; i < n; ++i)
	{
		temp.clear();
		for (int j = 0; j < n; ++j)
		{
			cin>>m;
			temp.push_back(m);
		}
		graph.push_back(temp);
	}
	cout<<primsMst(graph,n)<<endl;
	return 0;
}

// using adjacency list 
/*void primsMst(vector<vector<pair<int,int>>> adj){
	bool visited[adj.size()];
	int res=0;
	vector<int> dist(adj.size(),INT_MAX);
	dist[0]=0;

	for (int i = 0; i < adj.size(); ++i)
	{
		visited[i]=false;
	}

	for (int count = 0; count < adj.size(); ++count)
	{
		int u=-1;

		for(int i=0; i< adj.size(); ++i){
			if (!visited[i] && (u==-1 || dist[u]>dist[i]))
			{
				u=i;
			}	
		}
		res +=dist[u];
		visited[u]=true;

		for (auto it : adj[u])
		{
			if (!visited[it.first])
			{
				dist[it.first]=min(it.second,dist[it.first]);
			}
		}
	}

	cout<<"result : "<<res<<endl;
}

int main(){
	cout<<"Enter number of Vertices and Edges"<<endl;

	int n, m;   
	cin>>n>>m;

	vector<vector<pair<int,int>>> adj;
	cout<<"Enter all edges : "<<endl;
	for(int i=0;i<n;i++){
		vector<pair<int,int>> temp;
		adj.push_back(temp);
	}

	for(int i=0;i<m;i++){
		int v1, v2,wt;
		cin>>v1>>v2>>wt;
		adj[v1].push_back({v2,wt});
		adj[v2].push_back({v1,wt});
	}

	primsMst(adj);

	return 0;
}
*/