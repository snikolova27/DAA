#include <iostream>
#include <vector>

const int MAX_STUDENTS = 550;
bool used[MAX_STUDENTS];
std::vector<int> connections [MAX_STUDENTS];

int n,m;

void init()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        connections[from].push_back(to);
        connections[to].push_back(from);
    }
}

void dfs(int node)
{
    used[node] = true;
    for(int i = 0; i < connections[node].size(); i++)
    {
        if(!used[connections[node][i]])
        {
            dfs(connections[node][i]);
        }
    }
}
int componentsCnt()
{
    int answer = 0;
    for(int i =1; i <= n; i++)
    {
        if(!used[i])
        {
            dfs(i);
            answer++;
        }
    }
    return answer;
}

int main()
{
    init();
    printf("%d \n", componentsCnt());
    
    return 0;
}
/*
6 4
1 3
1 4
2 5
4 6
*/