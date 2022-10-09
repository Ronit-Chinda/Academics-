#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &v)
{
    int minimum = v[0], maxprofit = 0, cost = 0, buy = 0, sell = 0;

    for (int i = 1; i < v.size(); i++)
    {
        cost = v[i] - minimum;
        if (maxprofit < cost)
        {
            maxprofit = cost;
            sell = i;
        }
        if (minimum > v[i])
        {
            minimum = v[i];
            buy = i;
        }
    }
    if (buy < sell)
    {
        cout << "Buy at price : " << v[buy] << " Sell at price : " << v[sell] << endl;
    }

    else
    {
        cout << "Cannot get any positive profit" << endl;
    }
}

int main()
{
    int n, x;
    cout << "Enter the number of days : ";
    cin >> n;
    vector<int> v;
    cout << "Enter data : ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    solve(v);
}