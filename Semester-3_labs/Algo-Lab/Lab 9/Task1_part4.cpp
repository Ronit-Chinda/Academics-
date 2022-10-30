#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &list,int n){
    std::vector<std::vector<int>> matrix(n,vector<int>(n));
    vector<int> temp;

     for (int i = 0; i < list.size(); ++i)
    {
        for (int j = 0; j < list[i].size(); ++j)
        {
            matrix[i][list[i][j]-1]=1;
        }
        
    }
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n,x,no;
    cout<<"Enter number of vertices : ";
    cin >> n;
    std::vector<std::vector<int>> list;
    std::vector<int> temp;
    for (int i = 0; i < n; ++i)
    {

        cout<<"Enter how many nodes for "<<i+1<<" vertices : ";
        cin>>no;
        cout<<"Enter connected vertices : ";
        temp.clear();
        for (int j = 0; j < no; ++j)
        {
            cin>>x;
            temp.push_back(x);
        }
        list.push_back(temp);
    }

    print(list,n);
   
}
