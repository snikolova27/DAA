#include <iostream>
#include <stack>
#include <limits.h>
#include <vector>
using namespace std;

const int MAX_VERTEX_CNT = 10050;
const int MAX_EDGES_CNT = 500050;

int vertexCnt, edgesCnt;
int startNode, finishNode;
int dist[MAX_VERTEX_CNT];
bool used[MAX_VERTEX_CNT];
int pathsCnt[MAX_VERTEX_CNT];


struct Edge
{
    int to;
    int time;
};

vector<Edge> graph[MAX_VERTEX_CNT];

void init()
{

    scanf("%d%d", &vertexCnt,&edgesCnt);
    for(int i  = 0; i < edgesCnt; i++)
    {
        int from,to,time;
        Edge temp;
        scanf("%d%d%d", &from,&temp.to,&temp.time);
        graph[from].push_back(temp);
    }

    scanf("%d%d", &startNode, &finishNode);
}

void topo(int vertex, bool visited[], stack<int>& st)
{
    visited[vertex] = true;
    for(int i = 0; i < graph[vertex].size(); i++)
    {
        Edge temp = graph[vertex][i];
        if(!visited[temp.to])
        {
            topo(temp.to, visited, st);
        }
    }

    st.push(vertex);
}

void longestPath(int start)
{
    stack<int> stack;
    fill(dist, dist + vertexCnt, INT_MIN);
    fill(used, used + vertexCnt, false);
    
    for(int i = 0; i < vertexCnt; i++)
    {
        if(!used[i])
        {
            topo(i, used, stack);
        }
    }


    dist[start] = 0;
    pathsCnt[start] = 1;

    while(!stack.empty())
    {
        int current = stack.top();
        stack.pop();

        for(int i = 0; i < graph[current].size(); i++)
        {
            Edge temp = graph[current][i];
            int newDist = dist[current] + temp.time;

            if(newDist > dist[temp.to])
            {
                dist[temp.to] = newDist;
                pathsCnt[temp.to] = pathsCnt[current];
            }
            else if(dist[temp.to] == newDist)
            {
                pathsCnt[temp.to] += pathsCnt[current];
            }

        }
    }
}

void output(int finish)
{
    printf("%d %d\n", dist[finish], pathsCnt[finish]);
}

int main()
{
    init();
    longestPath(startNode);
    output(finishNode);
    return 0;
}
/*
6 8
3 4 2
3 0 1
0 2 1
3 2 4
4 2 2
1 3 5
0 5 1
5 2 2
3 2
*/