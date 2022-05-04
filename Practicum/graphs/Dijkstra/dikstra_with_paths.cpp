#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int edgeCount, vertexCount;
int dist[int(1e5)];
bool used[int(1e5)];
int parent[int(1e5)], pathsCount[int(1e5)];
vector <pair<int,int>> graph[int(1e5)];

void init()
{
    int from, to, weight;
    scanf("%d%d", &vertexCount, &edgeCount);
    
    for(int i = 0; i < edgeCount; i++)
    {
        scanf("%d%d%d", &from, &to, &weight);

        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }
}

void dijkstra()
{
    fill(dist, dist + vertexCount, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> nodes;
    dist[0] = 0;
    pathsCount[0] = 1;
    parent[0] = -1;
    nodes.push({0,0});

    while(!nodes.empty())
    {
        int currentNode = nodes.top().second;
        nodes.pop();

        if(used[currentNode])
        {
            continue;
        }
        used[currentNode] = true;

        for(auto edge : graph[currentNode])
        {
            int newDist = dist[currentNode] + edge.second;

            if(dist[edge.first] > newDist)
            {
                dist[edge.first] = newDist;
                parent[edge.first] = currentNode;
                pathsCount[edge.first] = pathsCount[currentNode];

                nodes.push({dist[edge.first], edge.first});
            }
            else if(dist[edge.first] == newDist)
            {
                pathsCount[edge.first] += pathsCount[currentNode];
            }
        }
    }
}

void restorePath(int node)
{
    while(node != -1)
    {
        printf("%d ", node);
        node = parent[node];
    }
    printf("\n");
}

void print()
{
    for(int i  = 0; i < vertexCount; i++)
    {
        printf("%d -> %d count =  %d\n", i, dist[i], pathsCount[i]);
    }
    restorePath(vertexCount - 1);
}

int main()
{
    init();
    dijkstra();
    print();
    return 0;
}
/**
5 6
0 1 4
0 2 3
1 3 2
2 3 7
1 4 4
3 4 5

7 8
0 1 1
0 2 2
1 3 2
2 3 1
3 4 1
3 5 1
4 6 1
5 6 1
*/