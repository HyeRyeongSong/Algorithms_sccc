#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, l, p, cnt, tmp;
    pair<int, int> s[10001];


    scanf("%d%d", &n, &l);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &s[i].first, &s[i].second);
    sort(s, s + n);
    for (int i = 0; i < n; ++i)
    {
        p = max(p, s[i].first);
        tmp = s[i].second - p + l - 1;
        tmp /= l;
        cnt += tmp;
        p += tmp * l;
    }
    printf("%d\n", cnt);
    return 0;
}