// Link - https://www.geeksforgeeks.org/merging-intervals/

#include <bits/stdc++.h>
using namespace std;
void printStack(stack<pair<int, int>> s)
{
    if (s.empty())
        return;
    pair<int, int> p = s.top();
    s.pop();
    printStack(s);
    cout << p.first << " " << p.second << " ";
}
void solve()
{
    int n, i = 0, fst, sec;
    cin >> n;
    vector<pair<int, int>> v;
    stack<pair<int, int>> s;
    while (i < n)
    {
        cin >> fst;
        cin >> sec;
        v.push_back(make_pair(fst, sec));
        i++;
    }
    pair<int, int> p;
    sort(v.begin(), v.end());
    for (i = 0; i < n; i++)
    {
        if (s.empty())
        {
            s.push(v[i]);
        }
        else
        {
            p = s.top();
            s.pop();
            if (p.second >= v[i].first)
            {
                s.push(make_pair(p.first, max(p.second, v[i].second)));
            }
            else
            {
                s.push(p);
                s.push(v[i]);
            }
        }
    }
    printStack(s);
    cout << "\n";
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