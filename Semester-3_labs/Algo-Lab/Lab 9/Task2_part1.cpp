#include<bits/stdc++.h>
using namespace std;


void bfs(vector<vector<int>> &adj, vector<bool> &visited,int source){
	queue<int> q;
	visited[source]=true;
	q.push(source);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v : adj[u]){
			if(!visited[v]){
				visited[v]=true;
				q.push(v);
			}
		}
	}	
}

void bfscount(vector<vector<int>> &adj){
	vector<bool> visited;
	int count=0;
	for(int i=0;i<=adj.size();i++){
		visited.push_back(false);
	}

	for(int i=0;i<adj.size(); i++){
		if(!visited[i]){
			bfs(adj,visited,i);
			count++;
		} 
	}
	cout<<"Number of connected components are : "<<count<<endl;
}

int main(){
	int n,x,temp,data;
	cout<<"Enter number of vertices : ";
	cin>>n;
	vector<vector<int>> adj;
	vector<int> tempvec;

	for(int i=0;i<n;i++){
		cout<<"Enter how many elements in adjacency list of vertices "<<i+1<<" : "<<endl; 
		cin>>x;
		cout<<"Enter Elements : ";
		tempvec.clear();
		for(int j=0;j<x;j++){
			
			cin>>temp;
			tempvec.push_back(temp);
		}
		adj.push_back(tempvec);
	}

	bfscount(adj);

	return 0;
}