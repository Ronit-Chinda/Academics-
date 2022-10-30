#include <bits/stdc++.h>
using namespace std;


void primsMst(vector<vector<pair<int,int>>> adj){
	bool visited[adj.size()];
	int res=0;
	vector<int> dist(adj.size(),INT_MAX);
	dist[0]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
	pq.push({0,0});
	for (int i = 0; i < adj.size(); ++i)
	{
		visited[i]=false;
	}

	for (int count = 0; count < adj.size(); ++count)
	{
		int u=pq.top().second;
		pq.pop();

		visited[u]=true;

		for(auto it: adj[u]){
			if (!visited[it.first] && dist[it.first]>it.second)
			{
				pq.push({it.second,it.first});
				dist[it.first]=it.second;   bool mstSet[adj.size()]; 
  
//     for (int i = 0; i < adj.size(); i++) 
//         mstSet[i] = false; 
    
//     priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

//     key[0] = 0; 
//     parent[0] = -1; 
//     pq.push({0, 0});

//     while(!pq.empty())
//     { 
//         int u = pq.top().second; 
//         pq.pop(); 
//         mstSet[u] = true; 
        
//         for (auto it : adj[u]) {
//             int v = it.first;
//             int weight = it.second;
//             if (mstSet[v] == false && weight < key[v]) {
//                 parent[v] = u;
// 	    key[v] = weight; 
//                 pq.push({key[v], v});    
//             }
//         }
            
//     } 
//     res=accumulate(key.begin(), key.end(),0);
//     cout<<res<<endl;
// }
			}
		}
	}	
	   res=accumulate(dist.begin(), dist.end(),0);
    cout<<res<<endl;
}

// void primsMst(vector<vector<pair<int,int>>> adj){
//  	int parent[adj.size()]; 
      
//     vector<int> key(adj.size(),INT_MAX); 
//     int res=0;
//     bool mstSet[adj.size()]; 
  
//     for (int i = 0; i < adj.size(); i++) 
//         mstSet[i] = false; 
    
//     priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

//     key[0] = 0; 
//     parent[0] = -1; 
//     pq.push({0, 0});

//     while(!pq.empty())
//     { 
//         int u = pq.top().second; 
//         pq.pop(); 
//         mstSet[u] = true; 
        
//         for (auto it : adj[u]) {
//             int v = it.first;
//             int weight = it.second;
//             if (mstSet[v] == false && weight < key[v]) {
//                 parent[v] = u;
// 	    key[v] = weight; 
//                 pq.push({key[v], v});    
//             }
//         }
            
//     } 
//     res=accumulate(key.begin(), key.end(),0);
//     cout<<res<<endl;
// }
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
// graph =
/*
0 5 8 0 
5 0 19 15 
8 10 0 20 
0 15 20 0 
*/