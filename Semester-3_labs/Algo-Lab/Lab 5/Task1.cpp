#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,capacity;
    cout<<"Please enter total number of Denomination"<<endl;
    cin >> n;
    vector<int> v(n);
    vector<int> v1(n);
    cout<<"Please enter denominations : "; 
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v[i]=x;
    }

    sort(v.begin(), v.end(), greater<int>());
    cout<<"Please enter the amount you want to change : "<<endl;
    cin>>capacity;

    for (int i = 0; i < n; ++i)
    {
        if(capacity>=v[i]){

             v1[i]=capacity/v[i];
             capacity -= (capacity*v1[i]);
        }     
    }
    cout<<"Your Denomination :"<<endl;
    cout<<"-------------------------------"<<endl;
    for (int i = 0; i < n; ++i)
    {
        if (v1[i]>0)
        {
            cout<<v1[i]<<" * "<<v[i]<<" Rs coin"<<endl;
        }
    }
    cout<<"-------------------------------"<<endl;
    
}
