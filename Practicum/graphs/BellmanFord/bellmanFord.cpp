#include <cstdio>
#include <vector>
#include <limits.h>

using namespace std;

struct Edge
{
    int from;
    int to;
    int cost;

    bool operator < (const Edge& other)
    {
        return this->cost < other.cost;
    }
};

int path[int(2e5) + 50];
vector<Edge> edges;

int n,m;
int startV;

void init()
{
    int f,t,c;
    scanf("%d%d%d", &n,&m, &startV);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &f, &t,&c);
        edges.push_back({f,t,c});
        edges.push_back({t,f,c});
    }
}

void bellmanFord()
{
    fill(path, path + n, INT_MAX);
    bool somethingChanged;

    path[startV] = 0;
    for(int i = 0; i < n ; i++)
    {
        somethingChanged = false;

        for(auto neighbour : edges)
        {
            int newDist = path[neighbour.from] + neighbour.cost;
            if(path[neighbour.from] != INT_MAX && newDist < path[neighbour.to] )
            {
                path[neighbour.to]  = newDist;
                somethingChanged = true;
            }

            if(!somethingChanged)
            {
                break;
            }
        }
    }
    for(int i = 0 ; i < n; i++)
        {
            if(path[i] == INT_MAX)
            {
                printf("+inf \n");
            }
            else if(somethingChanged)
            {
               printf("-inf\n");
            }
            else 
            {
                printf("%d\n", path[i]);
            }
        }
}


int main()
{
    init();
    bellmanFord();
    return 0;
}
/*
5 6 0
0 1 4
0 2 3
1 3 2
2 3 7
1 4 4
3 4 5
*/