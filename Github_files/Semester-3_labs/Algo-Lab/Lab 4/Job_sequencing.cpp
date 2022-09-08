#include <bits/stdc++.h>
using namespace std;
bool sort_endtime(pair<int,int> &p1, pair<int, int> &p2)
{
    return p1.second > p2.second;
}

int main()
{
    int n;
    cout << "Enter number of jobs" << endl;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cout << "Enter start and end time" << endl;
        cin >> start >> end;
        v[i] = {start, end};
    }
    
    for(auto i:v){
        cout << i.first << " " << i.second << endl;
    }
}