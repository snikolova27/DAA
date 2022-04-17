#include <cstdio>
#include <iostream>
#include <vector>
const int MAX_VERTEX_CNT = 100;

std::vector<int> graph[MAX_VERTEX_CNT];
std::vector<int> path;
bool visited[MAX_VERTEX_CNT];
int vertexCnt, edgesCnt;

void print()
{
    int pathSize = path.size();
    printf("%d", path[0]);
    for(int i  = 1; i < pathSize; i++)
    {
        printf(" %d", path[i]);
    }

    printf("\n");
}

void dfs(int node)
{
    visited[node] = true;
    path.push_back(node);
    for(int i = 0; i < graph[node].size(); i++)
    {
        if(!visited[graph[node][i]])
        {
            dfs(graph[node][i]);
        }
    }
    visited[node] = false;
    print();
    path.pop_back();
}

int main()
{
    scanf("%d %d", &vertexCnt, &edgesCnt);
    int vFrom, vTo;
    for(int i = 0; i < edgesCnt; i++)
    {
        scanf("%d%d", &vFrom, &vTo);
        graph[vTo].push_back(vFrom);
        graph[vFrom].push_back(vTo);
    }

    for(int i  = 1; i <= vertexCnt; i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }

    return 0;
}

/*
5 6 
1 2
2 3
4 5
3 4
1 3
2 4
*/