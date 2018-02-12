//
// Created by HyeRyeongSong on 2017. 11. 28..
//
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct universe
{
    long long parent;
    long long depth;
    long long smallest;
};

struct edge
{
    long long src;
    long long dst;
    long long weight;
};

class Kruskal
{
private:
    universe* U;

public:

    Kruskal()
    {
        U = new universe[1002];
    }

    void makeset(long long i)
    {
        U[i].parent = i;
        U[i].depth = 0;
        U[i].smallest = i;
    }

    long long find(long long i)
    {
        long long j;

        j = i;

        while(U[j].parent != j)
            j = U[j].parent;
        return j;
    }

    void merge (long long p, long long q)
    {
        if(U[p].depth == U[q].depth)
        {
            U[p].depth = U[p].depth + 1;
            U[q].parent = p;
            if(U[q].smallest < U[p].smallest)
                U[p].smallest = U[q].smallest;
        }
        else if(U[p].depth < U[q].depth) {
            U[p].parent = q;
            if(U[p].smallest < U[q].smallest)
                U[q].smallest = U[p].smallest;
        }
        else {
            U[q].parent = p;
            if(U[q].smallest < U[p].smallest)
                U[p].smallest = U[q].smallest;
        }
    }

    bool equal (long long p, long long q)
    {
        if(p == q)
            return true;
        else
            return false;
    }

    void initial (long long n)
    {
        for(long long i = 1; i<=n; i++)
            makeset(i);
    }

    void kruskal(long long n, long long m, vector<edge> E, vector<edge>& F, long long llExist)
    {
        long long i, j;
        long long p, q;
        edge e;

        sort(E.begin(), E.end(), compareByTime);

        F.clear();

        initial(n);

        mergeExists(llExist);

        long long iIndex = 0;

        while(F.size() < n-1)
        {
            e.src = E[iIndex].src;
            e.dst = E[iIndex].dst;
            e.weight = E[iIndex].weight;
            iIndex++;
            i = e.src;
            j = e.dst;

            p = find(i);

            q = find(j);

            if(!equal(p, q))
            {
                merge(p, q);
                F.push_back(e);
            }
        }
    }

    static bool compareByTime(const edge &a, const edge &b)
    {
        return a.weight < b.weight;
    }

    void mergeExists(long long llExist)
    {
        pair<long long, long long> pair1;
        for(long long i=0; i<llExist; ++i)
        {
            cin >> pair1.first >> pair1.second;
            long long p = find(pair1.first);
            long long q = find(pair1.second);
            if(!equal(p, q))
                merge(p, q);
        }

    }

};

int main()
{

    Kruskal k;
    vector<edge> E;
    vector<edge> F;
    E.clear();
    edge e;

    long long llSum = 0;
    long long llMax = 0;

    long long vertexNum, edgeNum;
    long long llExist;

    cin >> vertexNum >> llExist;

    pair<long long, long long> pair1[vertexNum+1];

    for(int i=1; i<=vertexNum; ++i)
        cin >> pair1[i].first >> pair1[i].second;

    edgeNum = ((vertexNum * vertexNum-3) / 2) + vertexNum;

    for(int i=1; i<=vertexNum; ++i)
    {
        for(int j=i+1; j<=vertexNum; ++j)
        {
            e.src = i;
            e.dst = j;
            e.weight = sqrt(pow(pair1[i].first-pair1[j].first, 2) + pow(pair1[i].second-pair1[j].second, 2));
            E.push_back(e);
        }
    }

    k.kruskal(vertexNum, edgeNum, E, F, llExist);

    for(int i=0; i<F.size(); ++i)
    {
        llSum+=F[i].weight;
    }

    cout << llSum;

    return 0;
}

