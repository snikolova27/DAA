#include <iostream>
#include <queue>
#include<limits.h>

using namespace std;

int n,m;
int startI, startJ, endI, endJ;
int mat[2000][2000];
bool used[2000][2000];
int dist[2000][2000];
int moveI[] = {-1,+1,0,0};
int moveJ[] = {0,0,-1,+1};

struct Edge
{
    int i;
    int j;
    int dist;

    bool operator > (const Edge& other) const
    {
        return this->dist > other.dist;
    }
};


void init()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    scanf("%d %d %d %d", &startI, &startJ, &endI, &endJ);

    startI--; startJ--; endI--; endJ--;
}

bool isValid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && !used[i][j];
}

void dijkstra()
{
    priority_queue<Edge, vector<Edge>, greater<Edge>> nodes;

    for(int  i = 0; i < n; i++)  // nullifying
    {
        fill(dist[i], dist[i] + m + 1, INT_MAX);
    }

    dist[startI][startJ] = mat[startI][startJ];
    nodes.push( {startI, startJ, mat[startI][startJ]});

    while(!nodes.empty())
    {
        Edge node = nodes.top();
        nodes.pop();

        if(used[node.i][node.j])
        {
            continue;
        }
        used[node.i][node.j] = true;

        for(int i  = 0; i < 4; i++)
        {
            int newI = node.i + moveI[i];
            int newJ = node.j + moveJ[i];

            if(!isValid(newI, newJ))
            {
                continue;
            }

            if(dist[node.i][node.j] + mat[newI][newJ] < dist[newI][newJ])
            {
                dist[newI][newJ] = dist[node.i][node.j] + mat[newI][newJ];
                nodes.push({newI, newJ, dist[newI][newJ]});
            }
        }
    }
    printf("%d\n", dist[endI][endJ]);
}


int main()
{
    init();
    dijkstra();
    return 0;
}
/*
3 4
5 6 9 8
1 5 4 8
3 5 8 9
1 1
3 3

22
*/

