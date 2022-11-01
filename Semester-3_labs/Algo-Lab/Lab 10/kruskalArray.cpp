#include<bits/stdc++.h>
using namespace std;

int parent[10000];
int rnk[10000];

int findpar(int node){
	if (node==parent[node])
	{
		return node;
	}
	return parent[node]=findpar(parent[node]);
}

void Union(int u,int v){
	u=findpar(u);
	v=findpar(v);

	if (rnk[u]<rnk[v])
	{
		parent[u]=v;
	}
	else if (rnk[v]<rnk[v])
	{
		parent[v]=u;
	}
	else{
		parent[v]=u;
		rnk[u]++;
	}
}

int kruskal(vector<pair<int,pair<int,int>>> adj,vector<pair<int,int>> &mst){
	int cost=0;
	for(auto it : adj){
		if (findpar((it.second).first) != findpar((it.second).second))
		{
			cost +=it.first;
			Union((it.second).first,(it.second).second);
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

	for (int i = 0; i < n; ++i)
	{
		parent[i]=i;
		rnk[i]=0;
	}

	sort(adj.begin(), adj.end());

	vector<pair<int,int>> mst;

	cout<<"The cost of minimum spanning tree is : ";
	cout<<kruskal(adj,mst)<<endl;
	cout<<"The spanning tree is : "<<endl;
	for(auto it : mst){
		cout<<it.first<<" "<<it.second<<endl;
	}
	cout<<endl;

	return 0;
}