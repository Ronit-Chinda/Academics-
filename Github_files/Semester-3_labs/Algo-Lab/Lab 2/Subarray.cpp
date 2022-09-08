#include <bits/stdc++.h>
#define int long long
#define f(n) for (int i = 0; i < n; i++)
using namespace std;
struct ans
{
    int val;
    int idx1;
    int idx2;
};

struct ans in_o_n3(int arr[], int n, struct ans get)
{
    int maxsum = INT_MIN, sum = 0;
    int idx1 = 0;
    int idx2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum = sum + arr[k];
            }
            if (sum > maxsum)
            {
                maxsum = sum;
                idx1 = i;
                idx2 = j;
            }
        }
    }
    get.val = maxsum;
    get.idx1 = idx1;
    get.idx2 = idx2;
    return get;
}

struct ans maxcrosssumsumarray3(int arr[], int p, int q, int r, struct ans get)
{
    int leftsum = INT_MIN;
    int sum = 0;
    for (int i = q; i >= p; i--)
    {
        sum += arr[i];
        if (sum > leftsum)
        {
            leftsum = sum;
            get.idx1 = i;
        }
    }

    int rightsum = INT_MIN;
    int sum1 = 0;
    for (int i = q + 1; i <= r; i++)
    {
        sum1 += arr[i];
        if (sum1 > rightsum)
        {
            rightsum = sum1;
            get.idx2 = i;
        }
    }
    get.val = leftsum + rightsum;
    return get;
}

struct ans in_o_n2(int arr[], int n, struct ans get)
{
    int maxsum = INT_MIN, sum = 0;
    int idx1 = 0;
    int idx2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            if (sum > maxsum)
            {
                maxsum = sum;
                idx1 = i;
                idx2 = j;
            }
        }
    }
    get.val = maxsum;
    get.idx1 = idx1;
    get.idx2 = idx2;
    return get;
}

struct ans maxsumsumarray3(int arr[], int p, int r, struct ans get)
{
    if (p == r)
    {
        get.val = arr[p];
        get.idx1 = p;
        get.idx2 = r;
        return get;
    }
    int q = (p + r) / 2;
    struct ans L = maxsumsumarray3(arr, p, q, get);
    struct ans R = maxsumsumarray3(arr, q + 1, r, get);
    struct ans C = maxcrosssumsumarray3(arr, p, q, r, get);
    if (R.val < C.val)
        get = C;
    else
        get = R;
    if (L.val > get.val)
        get = L;
    return get;
}

void print(int arr[], struct ans get)
{
    for (int i = get.idx1; i <= get.idx2; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "the max sum is " << get.val << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        struct ans q1, q2, q3;
        int n;
        cin >> n;
        int arr[n];
        f(n)
        {
            cin >> arr[i];
        }
        q1 = in_o_n3(arr, n, q1);
        q2 = in_o_n2(arr, n, q2);
        
        q3 = maxsumsumarray3(arr, 0, n - 1, q3);
        print(arr, q1);
        print(arr, q2);
        print(arr, q3);
    }
    return 0;
}