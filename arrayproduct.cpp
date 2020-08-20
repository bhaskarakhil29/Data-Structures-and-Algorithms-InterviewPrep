#include <iostream>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin >> n;
    ll arr[n];
    ll output[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll left = 1;
    output[0] = 1;
    for (int i = 1; i < n; i++)
    {
        output[i] = left * arr[i - 1];
        left *= arr[i - 1];
    }
    ll right = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        right *= arr[i + 1];
        output[i] = right * output[i];
    }
    for (auto x : output)
    {
        cout << x << " ";
    }
    return 0;
}