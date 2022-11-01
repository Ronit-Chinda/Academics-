#include<bits/stdc++.h>
using namespace std;


int findpar(int node,vector<int> &parent){
	if (node==parent[node])
	{
		return node;
	}
	return parent[node]=findpar(parent[node],parent);
}

void Union(int u,int v,vector<int> &parent,vector<int> &rank){
	u=findpar(u,parent);
	v=findpar(v,parent);

	if (rank[u]<rank[v])
	{
		parent[u]=v;
	}
	else if (rank[v]<rank[v])
	{
		parent[v]=u;
	}
	else{
		parent[v]=u;
		rank[u]++;
	}
}

int kruskal(vector<int> &parent,vector<int> &rank,vector<pair<int,pair<int,int>>> adj,vector<pair<int,int>> &mst){
	int cost=0;
	for(auto it : adj){
		if (findpar((it.second).first,parent) != findpar((it.second).second,parent))
		{
			cost +=it.first;
			Union((it.second).first,(it.second).second,parent,rank);
			mst.push_back({(it.second).first,(it.second).second});
		}
	}

	return cost;
}


int main(){
	cout<<"Enter number of Vertices  and Edges"<<endl;
	int n, m;   
	cin>>n>>m;
	
	vector<pair<int,pair<int,int>>> adj;
	cout<<"Enter all edges : "<<endl;

	for(int i=0;i<m;i++){
		int v1, v2,v3;
		cin>>v1>>v2>>v3;
		adj.push_back({v3,{v1,v2}});
	}

	std::vector<int> parent(n);
	std::vector<int> rank(n,0);

	for (int i = 0; i < n; ++i)
	{
		parent[i]=i;
		rank[i]=0;
	}

	sort(adj.begin(), adj.end());

	vector<pair<int,int>> mst;

	cout<<"The cost of minimum spanning tree is : ";
	cout<<kruskal(parent,rank,adj,mst)<<endl;
	cout<<"The spanning tree is : "<<endl;
	for(auto it : mst){
		cout<<it.first<<" "<<it.second<<endl;
	}
		for(auto it : parent){
		cout<<it<<" ";
	}
	cout<<endl;

	return 0;
}