#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int gcd(long long a, long long b);
long long lcm(int a, int b);


int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    int iNum;
    char temp;

    vector<int> vector1;

    for(int i=0; i<N; ++i) {

        do {
            scanf("%d%c", &iNum, &temp);
            vector1.push_back(iNum);
        } while (temp != '\n');

        

    }
    long long a, b;
    cin >> a >> b;
    cout << gcd(a, b) << '\n' << lcm(a, b);
}


int gcd(long long a, long long b) {
    if(b==0)
        return a;
    else
        return(b%a);
}

long long lcm(int a, int b)
{
    return (long long)a * b / gcd(a, b);
}
//1<<1, (1<<1) + 1
// >> 부모노드 접근, << 자식노드 접근

//priority queue 쓸 때는 pair 구조체 많이 사용함
//연산자가 미리 만들어져 있기 때