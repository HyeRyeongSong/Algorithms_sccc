#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Person
{
    int iSum = 0;
    int iSeq = 0;

    bool operator> (const Person& ref) const {
        if(iSum == ref.iSum)
            return iSeq < ref.iSeq;
        return iSum < ref.iSum;
    }
};

int main()
{
    cin.sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin >> N;

    Person person;

    int iSeq = 0;

    priority_queue<Person, vector<Person>, greater<Person>> priorityQueue;

    int iNum[5];
    int iSum[10];

    for(int i=0; i<N; ++i)
    {
        for(int i=0; i<5; ++i) {
            cin >> iNum[i];
        }

        int max_val = 0;

        for (int fir = 0; fir < 5; fir ++)
            for (int sec = fir+1; sec < 5; sec ++)
                for (int thr = sec+1; thr < 5; thr ++)
                    max_val = max(max_val, (iNum[fir] + iNum[sec] + iNum[thr])%10);

        int iSumValue = *max_element(iSum, iSum+9);

        ++iSeq;

        person.iSeq = iSeq;
        person.iSum = iSumValue;

        priorityQueue.push(person);

    }

    cout << priorityQueue.top().iSeq;

    return 0;
}

//1<<1, (1<<1) + 1
// >> 부모노드 접근, << 자식노드 접근

//priority queue 쓸 때는 pair 구조체 많이 사용함
//연산자가 미리 만들어져 있기 때