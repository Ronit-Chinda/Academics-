#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &matrix,int n){
    std::vector<std::vector<int>> list;
    vector<int> temp;
     for (int i = 0; i < n; ++i)
    {
        temp.clear();
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j]==1)
            {
                temp.push_back(j+1);
            }
        }
        list.push_back(temp);
    }
    for (int i = 0; i < list.size(); ++i)
    {
        cout<<i+1<<" : ";
        for (int j = 0; j < list[i].size(); ++j)
        {
            cout<<list[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n,x;
    cout<<"Enter number of vertices : ";
    cin >> n;
    std::vector<std::vector<int>> matrix;
    std::vector<int> temp;
    cout<<"Enter Data : "<<endl;
    for (int i = 0; i < n; ++i)
    {
        temp.clear();
        for (int j = 0; j < n; ++j)
        {
            cin>>x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }

    print(matrix,n);
   
}
