#include <iostream>
#include <vector>
#include <queue>

const int MAX_VERTEX_CNT = 100;

std::vector<int> graph[MAX_VERTEX_CNT];
std::queue<int> queue;
bool visited[MAX_VERTEX_CNT];

int vertexCnt, edgesCnt;
int startNode, finishNode;

bool bfs(int start, int finish)
{
    queue.push(start);
    int currentNode;
    while(!queue.empty())
    {
        currentNode = queue.front();
        queue.pop();
        
        for(int i = 0; i <graph[currentNode].size(); i++)
        {
            if(!visited[graph[currentNode][i]])
            {
                visited[graph[currentNode][i]] = true;
                if(graph[currentNode][i] == finish)
                {
                    return true;
                }
                queue.push(graph[currentNode][i]);
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &vertexCnt, &edgesCnt);
    int vTo, vFrom;
    for(int i = 0; i < edgesCnt; i++)
    {
        scanf("%d %d", &vFrom, &vTo);
        graph[vTo].push_back(vFrom);
        graph[vFrom].push_back(vTo);
    }

    scanf("%d%d", &startNode, &finishNode);
    std::cout << bfs(startNode, finishNode) << " \n";

    return 0;
}