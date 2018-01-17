#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    int iArray[N];
    for(int i=0; i<N; ++i)
    {
        cin >> iArray[i];
    }

    sort(iArray, iArray+N);

    for(int i=0; i<N; ++i)
        cout << iArray[i] << '\n';
}

//1<<1, (1<<1) + 1
// >> 부모노드 접근, << 자식노드 접근

//priority queue 쓸 때는 pair 구조체 많이 사용함
//연산자가 미리 만들어져 있기 때