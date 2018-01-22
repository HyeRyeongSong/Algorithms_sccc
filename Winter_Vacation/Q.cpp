#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int iCount = 0;
int r, c;

void Compress(int iSx, int iSy, int iLength);

int main() {

    int N;
    int iSum = 1;

    int X[4] = {0,0,1,1};
    int Y[4] = {0,1,0,1};

    cin >> N;

    for(int i=0; i<N; ++i)
        iSum*=2;

    cin >> r >> c;


    Compress(0, 0, iSum);

    return 0;
}

void Compress(int iSx, int iSy, int iLength)
{
    if(iLength != 2)
    {
        iLength /=2;

        Compress(iSx, iSy, iLength);
        Compress(iSx, iSy+iLength, iLength);

        Compress(iSx+iLength, iSy, iLength);
        Compress(iSx+iLength, iSy+iLength, iLength);
    }
    for(int i=iSx; i<iSx+2; ++i)
        for(int j=iSy; j<iSy+2; ++j)
        {
            if(i==r && j == c)
                cout << iCount;
            else
                ++iCount;
        }
}


//1<<1, (1<<1) + 1
// >> 부모노드 접근, << 자식노드 접근

//priority queue 쓸 때는 pair 구조체 많이 사용함
//연산자가 미리 만들어져 있기 때