#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_EDGES = 100000;

struct Edge
{
    int from;
    int to;
    int weight;
    
    bool operator < (const Edge& other)
    {
        return this->weight < other.weight;
    }
};
Edge edges[MAX_EDGES];

int n,m;
int dsuParent[MAX_EDGES];
vector<pair<int,int>> mst[MAX_EDGES];

void init()
{
    scanf("%d%d", &n,&m);
    for(int  i = 0; i < m; i++)
    {
       scanf("%d%d%d", &edges[i].from, &edges[i].to, &edges[i].weight);
    }

    for(int i = 0; i < n; i++)
    {
        dsuParent[i]=i;
    }
}

int findRoot(int node)
{
    if(node == dsuParent[node])
    {
        return node;
    }
    int root = findRoot(dsuParent[node]);
    dsuParent[node] = root;

    return root;
}

void unite(int root1, int root2)
{
    dsuParent[root1] = root2;
}

void Kruskal()
{
    sort(edges, edges + m);

    for(int i = 0; i < m; i++)
    {
        int root1 = findRoot(edges[i].from);
        int root2 = findRoot(edges[i].to);

        if(root1 == root2)
        {
            continue;
        }

        mst[edges[i].from].push_back({edges[i].to, edges[i].weight});
        mst[edges[i].to].push_back({edges[i].from, edges[i].weight});

        unite(root1, root2);
    }
}

void print()
{
    for(int i = 0; i < n; i++)
    {
        printf("neighbours of %d \n", i);
        for(int j = 0; j < mst[i].size(); j++ )
        {
            printf("%d with weight %d \n", mst[i][j].first, mst[i][j].second);
        }
        printf("\n");
    }
}

int main()
{
    init();
    Kruskal();
    print();
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
*/