#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited,int source,vector<int> &ans){
	visited[source]=true;
	ans.push_back(source);
	for(int v : adj[source]){
		if(!visited[v])
		dfs(adj,visited,v,ans);
	}
}

vector<vector<int>> dfscount(vector<vector<int>> &adj){
	vector<bool> visited;
	vector<vector<int>> components;
	vector<int> ans;
 	int count=0;
	for(int i=0;i<=adj.size();i++){
		visited.push_back(false);
	}

	for(int i=0;i<adj.size(); i++){
		if(!visited[i]){	
			dfs(adj,visited,i,ans);
			components.push_back(ans);
			ans.clear();
		} 
	}
	return components;
}

int main(){
	int n,x,temp,data;
	cout<<"Enter number of vertices : ";
	cin>>n;
	vector<vector<int>> adj;
	vector<vector<int>> components;
	vector<int> tempvec;

	for(int i=0;i<n;i++){
		cout<<"Enter how many elements in adjacency list of vertices "<<i<<" : "; 
		cin>>x;
		cout<<"Enter Elements : ";
		tempvec.clear();
		for(int j=0;j<x;j++){
			
			cin>>temp;
			tempvec.push_back(temp);
		}
		adj.push_back(tempvec);
	}
	
	components=dfscount(adj);
	int vertice1,vertice2,index1=-1,index2=-1;
	cout<<"Enter both vertice to check : ";
	cin>>vertice1>>vertice2;

	for (int i = 0; i < components.size(); ++i)
	{
		for (int j = 0; j < components[i].size(); ++j)
		{
			cout<<components[i][j]<<" ";	
		}
		cout<<endl;
	}

	for (int i = 0; i < components.size(); ++i)
	{
		for (int j = 0; j < components[i].size(); ++j)
		{
			if (vertice1==components[i][j])
			{
				index1=i;
			}
			if (vertice2==components[i][j])
			{
				index2=i;
			}
		}
	}

	if (index2==index1 && index1>=0)
	{
		cout<<"In the same connected graph"<<endl;
	}
	else{
		cout<<"In different connected graph"<<endl;
	}
	return 0;
}