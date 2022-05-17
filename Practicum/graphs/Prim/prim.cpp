#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_VERTEX_CNT = 1000;

struct Edge
{
    int from;
    int to;
    int price;
    Edge(int f, int t, int p) : from(f), to(t), price(p) {}

    bool operator < (const Edge& other) const
    {
        return this->price > other.price;
    }
};

struct State
{
    int to, price;
    State(int t, int p) : to(t), price(p) {}
};

int n,m;
vector<State> v[MAX_VERTEX_CNT];

void init()
{
    scanf("%d%d", &n,&m);
    int f,t,p;
    for(int i = 0; i < m ;i++)
    {
        scanf("%d%d%d", &f, &t, &p);
        // when the vertices start from 1
        v[f-1].push_back(State((t-1),p));
        v[t-1].push_back(State((f-1), p));
    }
}

bool visited[MAX_VERTEX_CNT];

void Prim()
{
    // start node is the first vertex
    priority_queue<Edge> spis;
    for(int i  = 0; i < v[0].size(); i++)
    {
        spis.push(Edge(0,v[0][i].to, v[0][i].price));
    }

    visited[0] = true;
    int totalSum = 0;

    while(!spis.empty())
    {
        int from = spis.top().from;
        int to = spis.top().to;
        int edgePrice = spis.top().price;

        spis.pop();

        if(visited[from] && visited[to])
        {
            continue;
        }

        // if(!visited[to])
        visited[to] = true;
     //   cout << "from " << from << " to " << to << " price " << edgePrice << endl;
        totalSum += edgePrice;

        for(int i  = 0; i < v[to].size(); i++)
        {
            int next = v[to][i].to;
            int nextPrice = v[to][i].price;

            if(!visited[next])
            {
                spis.push(Edge(to, next, nextPrice));
            }
        }
    }

    printf("%d\n", totalSum);
}

int main()
{
    init();
    Prim();
    return 0;
}

/*
6 10
6 4 2
2 4 3
5 4 1
3 4 5
1 6 2
2 3 4
5 1 2
3 5 1
6 2 3
5 2 4

9
*/