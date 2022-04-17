#include <iostream>
#include <vector>
#include <queue>

const int MAX_VERTEX_CNT = 100;

std::vector<int> graph [MAX_VERTEX_CNT];
std::queue<int> q;
bool visited[MAX_VERTEX_CNT];

int vCnt, eCnt;

void bfs(int start)
{
    visited[start] = true;
    q.push(start);
    int currentNode;

    int level = 1;
    int nodesOfLevel = 1;
    int nodesOfNextLevel = 0;

    while(!q.empty())
    {
        currentNode = q.front();
        printf("node = %d at level = %d \n", currentNode, level);
        nodesOfLevel--;
        q.pop();


        for(int i = 0; i < graph[currentNode].size(); i++)
        {
            if(!visited[graph[currentNode][i]])
            {
                visited[graph[currentNode][i]] = true;
                nodesOfNextLevel++;
                q.push(graph[currentNode][i]);
            }
        }

        if(nodesOfLevel == 0)
        {
            level++;
            nodesOfLevel = nodesOfNextLevel;
            nodesOfNextLevel = 0;
        }
    }

}
int main()
{
    scanf("%d%d",&vCnt, &eCnt);
    int vertexFrom, vertexTo;
    for(int i = 0; i < eCnt; i++)
    {
        scanf("%d%d", &vertexFrom,&vertexTo);
        graph[vertexFrom].push_back(vertexTo);
        graph[vertexTo].push_back(vertexFrom);
    }
    bfs(1);
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