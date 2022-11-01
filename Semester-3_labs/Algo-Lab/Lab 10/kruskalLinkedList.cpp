#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int index;
	int parent;
	struct Node* next;
	struct Node* prev;

};

void insert(struct Node **head,int data,int index){

	if (*head==NULL)
	{
		struct Node* node=(struct Node*)malloc(sizeof(struct Node));
		node->index=index;
		node->parent=data;
		node->next=NULL;
		node->prev=NULL;
		*head=node;
	}

	else{
		struct Node* trav=*head;
		while(trav->next!=NULL){
			trav=trav->next;
		}
		struct Node* node=(struct Node*)malloc(sizeof(struct Node));
		node->index=index;
		node->parent=data;
		node->next=NULL; 
		node->prev=trav;
		trav->next=node;
	}
}

void display(struct Node *head){
	struct Node* trav=head;
	struct Node* second =head;
	while(trav!=NULL){
		cout<<trav->index<<" "<<trav->parent<<endl;
		trav=trav->next;
	}

}
int findpar(int node,struct Node* head){
	struct Node* trav=head;
	int parent;
	while(trav){
		bool flag=false;
		
		if (node==trav->parent && node==trav->index)
		{
			return node;
			break;
		}
		
		else if(node!=trav->parent && node==trav->index){
			parent=trav->parent;
			if (trav->parent>trav->index)
			{
				while(trav){
					if (parent==trav->index)
					{
						break;
					}
					trav=trav->next;
				}
				flag=true;
				node=trav->index;
			}
			else{
				while(trav){

					if (parent==trav->index)
					{
						break;
					}
					trav=trav->prev;
				}
				node=trav->index;
				flag=true;
			}
		}
		if (flag && parent==trav->index && trav->parent==parent){
					return trav->parent;
					break;
				}
		if (!flag)
		{
			trav=trav->next;
		}
	}
	return node; // nothing (-1)
	
}
int findrank(int node,struct Node* rank){
	struct Node* trav=rank;
	while(trav){
		if (node==trav->index)
		{
			return trav->parent;
		}
		trav=trav->next;
	}
	return -1;
}
void makeparent(int node,int ind,struct Node *parent){
	struct Node* trav=parent;
	while(trav){
		if (ind==trav->index)
		{
			trav->parent=node;
			break;
		}
		trav=trav->next;
	}
}
void updateRank(int ind,struct Node *rank){
	struct Node* trav=rank;
	while(trav){
		if (ind==trav->index)
		{
			trav->parent +=1;
			break;
		}
		trav=trav->next;
	}
}
void Union(int u,int v,struct Node *parent,struct Node* rank){
	u=findpar(u,parent);
	v=findpar(v,parent);

	if (findrank(u,rank)<findrank(v,rank))
	{
		makeparent(v,u,parent);
	}
	else if (findrank(u,rank)>findrank(v,rank))
	{
		makeparent(u,v,parent);
	}
	else{
		makeparent(u,v,parent);
		updateRank(u,rank);
	}
}


int kruskal(struct Node *parent,struct Node *rank,vector<pair<int,pair<int,int>>> adj,vector<pair<int,int>> &mst){
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
	cout<<"Enter number of Vertices and Edges"<<endl;
	int n,m;   
	cin>>n>>m;
	
	vector<pair<int,pair<int,int>>> adj;
	cout<<"Enter all edges : "<<endl;

	for(int i=0;i<m;i++){
		int v1, v2,v3;
		cin>>v1>>v2>>v3;
		adj.push_back({v3,{v1,v2}});
	}
	
	sort(adj.begin(), adj.end());

	struct Node *parent=NULL;
	struct Node *rank=NULL;

	for (int i = 0; i < n; ++i)
	{
		insert(&parent,i,i);
		insert(&rank,0,i);
	}

	cout<<findpar(4,parent)<<endl;

	vector<pair<int,int>> mst;

	cout<<"The cost of minimum spanning tree is : ";
	cout<<kruskal(parent,rank,adj,mst)<<endl;
	cout<<"The spanning tree is : "<<endl;
	for(auto it : mst){
		cout<<it.first<<" "<<it.second<<endl;
	}

}