#include <iostream>
using namespace std;
int findequal(int *arr, int n, int sum)
{
    int left_sum = 0, right = sum;
    for (int i = 0; i < n; i++)
    {
        left_sum += arr[i];
        right = sum - left_sum;
        if (left_sum == right)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int arr[n], sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << findequal(arr, n, sum);
    return 0;
}