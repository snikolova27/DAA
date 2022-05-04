#include <iostream>
#include <vector>

const int MAX_VERTEX_CNT  = 100;
std::vector<int> graph[MAX_VERTEX_CNT];
bool visited[MAX_VERTEX_CNT];
int vertexCnt, edgesCnt;

void dfs(int node)
{
    visited[node] = true;
    for(int i  = 0 ; i < graph[node].size(); i++)
    {
        if(!visited[graph[node][i]])
        {
            dfs(graph[node][i]);
        }
    }
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

    int components = 0;
    for(int i = 1; i <= vertexCnt; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);
    return 0;
}