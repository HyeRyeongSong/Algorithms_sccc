#include <iostream>
#include <queue>

using namespace std;

  //  I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000


int main()
{
    string str;
    int iNum_Prev = 1001, iSum = 0, iNum_Current;
    cin >> str;
    for(int i=0; i<str.length(); ++i)
    {
        switch(str[i])
        {
            case 'I':
                iNum_Current = 1;
                break;
            case 'V':
                iNum_Current = 5;
                break;
            case 'X':
                iNum_Current = 10;
                break;
            case 'L':
                iNum_Current = 50;
                break;
            case 'C':
                iNum_Current = 100;
                break;
            case 'D':
                iNum_Current = 500;
                break;
            case 'M':
                iNum_Current = 1000;
                break;
        }
        if(iSum == 0)
            iSum+=iNum_Current;
        else if(iNum_Prev >= iNum_Current)
            iSum+=iNum_Current;
        else {
            iSum-=iNum_Prev;
            iSum+=(iNum_Current - iNum_Prev);
        }

        iNum_Prev = iNum_Current;
    }

    cout << iSum << endl;
    return 0;
}

//1<<1, (1<<1) + 1
// >> 부모노드 접근, << 자식노드 접근

//priority queue 쓸 때는 pair 구조체 많이 사용함
//연산자가 미리 만들어져 있기 때