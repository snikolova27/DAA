#include <iostream>
#include <vector>
#include <queue>
int n,m;
int edgesCount[int(1e5)];
std::vector<int> graph[int(1e5)];
std::vector<int> sorted;


void init()
{
    int from, to;

    scanf("%d %d", &n, &m);

    for(int i = 0;i < m; i++)
    {
        scanf("%d %d", &from, &to);

        graph[from].push_back(to);

        edgesCount[to]++;
    }
}

void print()
{
    for(int i = 0; i < sorted.size();i++)
    {
        printf("%d", sorted[i]);
    }
    printf("\n");
}

void topoSort()
{
    std::queue<int> ready;
  
    for(int i = 0; i < n; i++)
    {
        if(edgesCount[i] == 0)
        {
            ready.push(i);
        }
    }

    while(!ready.empty())
    {
        int node = ready.front();
        ready.pop();
        sorted.push_back(node);

        for(int neighbour : graph[node])
        {
            edgesCount[neighbour]--;

            if(edgesCount[neighbour] == 0)
            {
                ready.push(neighbour);
            }
        }
    }

    if(sorted.size() != n)
    {
        printf("There is a cycle in the graph! \n");
        printf("%d", sorted.size());
    }
    else 
    {
        print();
    }
}
int main()
{
    init();
    topoSort();

    return 0;
}
/**
6 8
0 2
4 0
0 5
1 4
1 5
2 3
2 4
4 5

6 8
0 2
0 4
0 5
1 4
1 5
2 3
2 4
4 5

*/