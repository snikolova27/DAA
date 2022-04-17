#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

int n,m,k;
const int MAX_FIELDS = 2005;
bool used[MAX_FIELDS][MAX_FIELDS];
int dist[MAX_FIELDS][MAX_FIELDS];
std::pair<int, int> knights[MAX_FIELDS];

int startI, startJ;

int iMovement[] = {-1,-2,-2,-1,+1,+2,+2,+1};
int jMovement[] = {-2,-1,+1,+2,+2,+1,-1,-2};


void input()
{   int a,b;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++ )
    {
        scanf("%d %d", &a, &b);
        used[a][b] = true;
    }

    for(int i = 0; i < k ;i++)
    {
        scanf("%d %d", &knights[i].first, &knights[i].second);
    }

    scanf("%d %d", &startI, &startJ);
}

bool isNodeValid(std::pair<int, int> node)
{
    return node.first >= 0 && node.first < n && node.second >= 0 && node.second < n;  
}

void bfs()
{
    std::queue<std::pair<int, int>> toVisit;
    toVisit.push({startI, startJ});
    used[startI][startJ] = true;

    while(!toVisit.empty())
    {   
        auto node = toVisit.front();
        toVisit.pop();

        for(int i = 0; i < 8; i++)
        {
            std::pair<int,int> neighbour = std::make_pair(node.first + iMovement[i], node.second + jMovement[i]);

            if(!used[neighbour.first][neighbour.second] && isNodeValid(neighbour))
            {
                toVisit.push(neighbour);

                dist[neighbour.first][neighbour.second] = dist[node.first][node.second] + 1;
                used[neighbour.first][neighbour.second] = true;

            } 
        }   
    }
}


void calculateAnswer()
{
    int maxSteps = 0;
    int br = 0;
    for(int i = 0; i < k; i++)
    {
        if(used[knights[i].first][knights[i].second])
        {
            br++;
            maxSteps = std::max(maxSteps, dist[knights[i].first] [knights[i].second]);
        }
    }

    printf("%d %d \n", br, maxSteps);
}
int main()
{
    input();
    bfs();
    calculateAnswer();
    return 0;
}
/*
5 0 8
0 1
0 3
1 0
1 4
3 0
3 4
4 1
4 3
2 2

8 1
*/ 
