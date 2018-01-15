#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int iTestCaseNum;
    cin >> iTestCaseNum;
    for(int i=0; i<iTestCaseNum; ++i)
    {
        queue<int> queue1;
        int N, M;
        cin >> N >> M;
        int iArray[N];
        int iComp[N];
        int iPrintNum;
        for(int i=0; i<N; ++i)
        {
            cin >> iArray[i];
            queue1.push(iArray[i]);
        }
        iPrintNum = iArray[M];
        copy(iArray, iArray+N, iComp);
        sort(iComp, iComp+N, greater<int>());
        for(int i=0; i<N; ++i)
        {
            if(iArray[i] < iComp[i])
            {
                queue1.pop();
                queue1.push(iArray[i]);
            }
            else
            {
                queue1.front();
            }
            if(iArray[i] == iPrintNum) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}