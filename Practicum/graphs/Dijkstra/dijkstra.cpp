//версия за ориентирани графи
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int infinity = 100000;

struct Edge
{
    int to;
    int weight;
};

vector<Edge> graph[100];
int n,m;
int startNode, finishNode;
priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;

int path[100];

void input()
{
    scanf("%d%d",&n, &m);
    int from;
    Edge temp;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &from, &temp.to, &temp.weight);
        graph[from].push_back(temp);
    }
    scanf("%d%d", &startNode, &finishNode);
}

void nullify()
{
    fill(path, path + n, infinity);
    while(!que.empty())
    {
        que.pop();
    }
}

void shortestPath(int start, int finish)
{
    // инициализираме всички стойности с безкрайност(зануляване)
    nullify();

    path[start] = 0;
    que.push({0, start});
    while(!que.empty())
    {
        int node = que.top().second; //node
        que.pop();

        for(int i = 0; i < graph[node].size(); i++)
        {
            Edge temp = graph[node][i];
            if(path[node] + temp.weight < path[temp.to])
            {
                path[temp.to] = temp.weight + path[node];
                que.push({path[temp.to], temp.to});
            }
        }
    }
}

int main()
{
    input();
    shortestPath(startNode, finishNode);
    printf("%d", path[finishNode]);
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
*/
