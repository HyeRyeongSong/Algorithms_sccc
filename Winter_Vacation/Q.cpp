#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {

    int n;
    int iMax = 0;
    pair<int, int> p[100002];
    vector<pair<int, int>> vt;
    int dp[100002];

    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;

    for(int i=0; i<n; ++i)
        cin >> p[i].first >> p[i].second;

    sort(p, p+n);

    vt.push_back(p[0]);

    for(int i=1; i<n; ++i)
    {
        int index = lower_bound(dp, dp+i, p[i].second)-dp+1;
        cout << index << endl;
    }

    for(int i=1; i<n; ++i)
    {

    }

    dp[1] = 1;

    for(int i=1; i<n; ++i)
    {
        dp[i] = 1;
        iMax = 0;
        for(int j=0; j<i; ++j)
        {
            if((p[j].second < p[i].second))
            {
                if(iMax < dp[j]) {
                    iMax = dp[j];
                }
                //dp[i] = dp[j] + 1;
            }
        }
        dp[i] = iMax +1;
    }

    iMax = 0;
    int largestNum;

    for(int i=0; i<n; ++i)
    {
        if(iMax < dp[i]) {
            iMax = dp[i];
            largestNum = i;
        }
    }

    cout << n-iMax << '\n';

    for(int i=largestNum-1; i>=0; --i)
    {
        if(dp[largestNum]-1 == dp[i])
        {
            largestNum = i;
        }
        else
        {
            pq.push(p[i].first);
        }
    }

    while(!pq.empty())
    {
        cout << pq.top() << '\n';
        pq.pop();
    }

    return 0;
}
