#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    int n;
    cout << "Enter number of jobs" << endl;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<pair<int, int>> v2;
    vector<int> v1(n);

    for (int i = 0; i < n; i++)
    {
        int start, end;
        // cout << "Enter start and end time" << endl;
        cin >> start >> end;
        v[i] = {start, end};
    }
    sort(v.begin(), v.end(), sortbysec);

    for (int i = 0; i < n; i++)
    {
        int conflicts = 0;
        int second = v[i].second;
        int first = v[i].first;
        bool flag = false;
        for (int j = 0; j < n; j++)
        {
            if (second == v[j].second && first == v[j].first)
            {
                flag = true;
                continue;
            }

            if (flag == false && first < v[j].second)
            {
                conflicts++;
            }

            if (second <= v[j].first && flag == true)
            {
                continue;
            }
            else if (flag == true)
            {
                conflicts++;
            }
        }
        v1[i] = conflicts;
    }

    auto max = *max_element(v1.begin(), v1.end());
    auto min = *min_element(v1.begin(), v1.end());

    cout << "Conflicts" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "(" << v[i].first << "," << v[i].second << ")"
             << " : " << v1[i] << endl;
    }
    for (int i = 0; i < n - 1; i++)
    {
        v2.push_back(v[i]);
        int j = i + 1;
        while (j < n && v[i].second > v[j].first)
        {
            j++;
        }
        i = j - 1;
    }

    cout << "Maximum Job's that can be scheduled : " << endl;
    for (auto i : v2)
    {
        cout << "(" << i.first << "," << i.second << ")";
    }
    cout << endl;
    cout << "Job with maximum conflict" << endl;
    for (int i = 0; i < n; i++)
    {
        if (v1[i] == max)
        {
            cout << "(" << v[i].first << "," << v[i].second << ")" << endl;
        }
    }
    cout << "Job with minimum conflict" << endl;
    for (int i = 0; i < n; i++)
    {
        if (v1[i] == min)
        {
            cout << "(" << v[i].first << "," << v[i].second << ")" << endl;
        }
    }
}
/*
10
2 4
1 5
3 6
4 6
7 9
4 10
8 10
8 11
9 12
11 12
*/