#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int m = n + 2;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    int totalxor = arr[0];
    for (int i = 1; i < m; i++)
    {
        totalxor ^= arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        totalxor ^= i;
    }
    int setbitno = (totalxor) & ~(totalxor - 1);
    int x = 0, y = 0;
    for (int i = 0; i < m; i++)
    {
        if (arr[i] & setbitno)
            x ^= arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i & setbitno)
            x ^= i;
    }
    y = x ^ totalxor;
    int index0;
    for (int i = m - 1; i >= 0; i--)
    {
        if (arr[i] == x)
        {
            index0 = i;
            break;
        }
    }
    int index1;
    for (int i = m - 1; i >= 0; i--)
    {
        if (arr[i] == y)
        {
            index1 = i;
            break;
        }
    }
    cout << arr[min(index0, index1)] << " " << arr[max(index0, index1)] << endl;
}
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}