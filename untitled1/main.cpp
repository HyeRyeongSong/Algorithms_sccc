#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    int iCount = 0;

    long long coin[6] = {1, 5, 10, 50, 100, 500};

    cin >> k;

    int i=5;

    k = 1000 - k;

    while(i>=0 && k>0)
    {
        if(k-coin[i] >= 0)
        {
            k-=coin[i];
            ++iCount;
        }
        else
        {
            --i;
        }
    }

    cout << iCount;




    return 0;
}



//1<<1, (1<<1) + 1
// >> 부모노드 접근, << 자식노드 접근

//priority queue 쓸 때는 pair 구조체 많이 사용함
//연산자가 미리 만들어져 있기 때