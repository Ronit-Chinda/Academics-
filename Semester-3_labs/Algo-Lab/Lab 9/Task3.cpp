#include <bits/stdc++.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
using namespace std;


void dfs(vector<vector<int>> adj,int vertex,vector<bool> &visited,stack<int> &st){
	visited[vertex]=true;
	for(auto i : adj[vertex]){
		if (!visited[i])
		{
			dfs(adj,i,visited,st);
		}
	}
	st.push(vertex);
}

void revdfs(vector<vector<int>> adj, vector<bool> &visited,int source,vector<int> &temp){
	visited[source]=true;
	temp.push_back(source);
	for(int v : adj[source]){
		if(!visited[v]){
			revdfs(adj,visited,v,temp);
		}
	}
}

vector<vector<int>> kosaraju(vector<vector<int>> adj){

	vector<bool> visited(adj.size());
	for (int i = 0; i < adj.size(); ++i)
	{
		visited[i]=false;
	}

	stack<int> st;
	for (int i = 0; i < adj.size(); ++i)
	{
		if (!visited[i])  	
			dfs(adj,i,visited,st);
	}
	vector<vector<int>> tgraph;
	for (int i = 0; i < adj.size(); ++i)
	{
		vector<int> temp;
		tgraph.push_back(temp);
	}
	for(int i=0;i<adj.size();i++){
		visited[i]=false;
		for(auto element : adj[i]){
			tgraph[element].push_back(i);
		}
	}

	vector<vector<int>> ans;
	vector<int> temp;

	while(st.size()>0){
		int node=st.top();
		st.pop();
		if (!visited[node])
		{
			revdfs(tgraph,visited,node,temp);
			ans.push_back(temp);
		}
		temp.clear();
	}

	return ans;
}

void print(vector<vector<int>> v){
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}

void bruteforce(vector<vector<int>> adj){

	vector<bool> visited;
	vector<int> temp;
	bool flag=true;
	for (int i = 0; i < adj.size(); ++i)
	{
		visited.push_back(false);
	}

	for (int i = 0; i < adj.size(); ++i)
	{
		revdfs(adj,visited,i,temp);

		if (temp.size()!=adj.size())
		{
			cout<<"Weakly Connected using bruteforce"<<endl;
			flag=false;
			break;
		}

		temp.clear();	
		visited.clear();
		for (int i = 0; i < adj.size(); ++i)
		{
			visited.push_back(false);
		}
	}

	if (flag)
	{
		cout<<"Strongly Connected using bruteforce"<<endl;
	}	

}
int main(){

	cout<<"Enter number of Vertices  and Edges"<<endl;
	int n, m;   
	cin>>n>>m;

	vector<vector<int>> adj;
	cout<<"Enter all edges : "<<endl;
	for(int i=0;i<n;i++){
		vector<int> temp;
		adj.push_back(temp);
	}

	for(int i=0;i<m;i++){
		int v1, v2;
		cin>>v1>>v2;
		adj[v1].push_back(v2);
	}
	vector<vector<int>> ans;
	ans=kosaraju(adj);

	if (ans.size()>1)
	{
		cout<<"Weakly connected using G(T) approach"<<endl;
	}
	else{
		cout<<"Strongly connected using G(T) approach"<<endl;
	}
	cout<<"Connected components using G(T) approach are : "<<endl;
	print(ans);
	cout<<"Number of strongly connected components are : "<<ans.size()<<endl;
	bruteforce(adj);
	return 0;
}