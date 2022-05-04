#include <iostream>
#include <vector>

const int MAX_VERTEX_CNT = 100;

std::vector<int> graph[MAX_VERTEX_CNT];
bool visited[MAX_VERTEX_CNT];
int vertexCnt, edgesCnt;
int startVertex;

void dfs(int node)
{
    visited[node] = true;
    for(int i = 0; i < graph[node].size(); i++) 
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
    int vTo, vFrom;
    for(int i = 0; i < edgesCnt; i++ )
    {
        scanf("%d %d", &vFrom, &vTo);

        graph[vTo].push_back(vTo);
        graph[vFrom].push_back(vTo);
    }

    scanf("%d", &startVertex);
    dfs(startVertex);
    return 0;
}
