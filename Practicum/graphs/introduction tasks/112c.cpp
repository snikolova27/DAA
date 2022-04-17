#include <exception>
#include<iostream>
#include<vector>
#include<queue>
 
const int MAX_VERTEX_COUNT = 2005;
 
std::vector<int> graph[MAX_VERTEX_COUNT];
std::queue<int> q;
std::vector<int> answer;
 
int vertexCount, edgeCount;
bool visited[MAX_VERTEX_COUNT];
int component[MAX_VERTEX_COUNT];

void bfs(int start, int componentInd)
{
    component[start] = componentInd;
    q.push(start);
    int currentNode;

    while(!q.empty())
    {
        currentNode = q.front();
        component[currentNode] = componentInd;
        q.pop();

        for(int i = 0; i < graph[currentNode].size(); i++)
        {
            if(!visited[graph[currentNode][i]])
            {
                visited[graph[currentNode][i]] = true;
                q.push(graph[currentNode][i]);
            }
        }
    }

}

void findComponents()
{
    int componentInd = 1;
    for(int node = 1; node <= vertexCount; node++)
    {
        if(!visited[node])
        {
            bfs(node, componentInd);
            componentInd++;
        }
    }
}

void input()
{
    scanf("%d%d",&vertexCount, &edgeCount);
    int vertexFrom, vertexTo;
    for(int i = 0; i < edgeCount; i++)
    {
        scanf("%d%d", &vertexFrom,&vertexTo);
        graph[vertexFrom].push_back(vertexTo);
        graph[vertexTo].push_back(vertexFrom);
    }
}

void print()
{
    int size = answer.size();
    for(int i = 0; i < size; i++)
    {
        printf("%d",answer[i]);
    }
    printf("\n");
}

void query()
{
    int from, to, q;
    scanf("%d",&q);
    for(int i = 0; i < q; i++)
    {
        scanf("%d%d",&from, &to);
        if(component[from] == component[to]) 
        {
            answer.push_back(1);
        }
        else
        {
            answer.push_back(0);
        }
    }
    print();
}
 

int main()
{
    input();
    findComponents();
    query();
    return 0;
}

/*
9 9 
1 2
3 4
5 6
7 8
9 5
7 2
8 2
6 9
1 7
3
1 8
6 2
4 7
*/