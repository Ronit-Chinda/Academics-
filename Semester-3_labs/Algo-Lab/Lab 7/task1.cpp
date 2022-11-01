#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, capacity;
    cout << "Enter the number of petrol pumps in the journey  : ";
    cin >> n;
    vector<int> v;
    cout << "Enter distance of every petrol pumps : ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    cout << "Enter the capacity of vehicle : ";
    cin >> capacity;
    sort(v.begin(), v.end());
    vector<int> ans;
    int temp = capacity;
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        if (v[0] > capacity)
        {
            cout << "Travelling not possible!" << endl;
            ans.clear();
            flag = false;
            break;
        }
        else if (v[i] - v[i - 1] > temp)
        {
            cout << "Travelling not possible!" << endl;
            ans.clear();
            flag = false;
            break;
        }
        else if (v[i] > capacity)
        {
            ans.push_back(v[i - 1]);
            capacity = v[i - 1] + temp;
        }
    }

    if (flag)
    {
        cout << "------------------------------------------------" << endl;
        cout << "\tRefilling positions are : " << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << "\tPetrol Pump at distance : " << ans[i] << endl;
        }
    }
}