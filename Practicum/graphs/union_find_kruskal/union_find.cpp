#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int to;
    int from;
    int weight;
};

bool cmp(const Edge& that, const Edge& other)
{
    return that.weight < other.weight;
}

vector<Edge> edges;
vector<Edge>  mst[100];
int n,m;
int uf[100], depth[100];

void init()
{
    scanf("%d%d", &n,&m);
    Edge temp;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &temp.from, &temp.to, &temp.weight);
        edges.push_back(temp);
    }

    sort(edges.begin(), edges.end(), cmp);
}

int findRoot(int node)
{
    while(node!= uf[node])
    {
        node = uf[node];
    } 
    return node;
}

void link(int node1, int node2)
{
    if(depth[node1] == depth[node2]) depth[node1]++;
    if(depth[node1] < depth[node2]) swap(node1, node2);
    uf[node2] = node1;
}

Edge temp;
void solve()
{
    for(int i = 0; i < n; ++i)
    {
        uf[i] = i;
    }

    for(int i = 0; i < n; i++)
    {
        //има ли път между двата върха
        int root1 = findRoot(edges[i].from);
        int root2 = findRoot(edges[i].to);
        if(root1 != root2) 
        {
            link(root1, root2);
            // reader za from
            temp.to = edges[i].to;
            temp.weight = edges[i].weight; 
            mst[edges[i].from].push_back(temp);
        }
    }
} 
void output()
{
    cout << "---------------\n";
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < mst[i].size();j++)
        {
         
            cout << mst[i][j].from << " "  << mst[i][j].to << " " << mst[i][j].weight << endl;
        }
    }
}
int main()
{
    init();
    solve();
    output();
    return 0;
}

/*
6 10
6 4 2
2 4 3
5 4 1
3 4 5
1 6 2
2 3 4
5 1 2
3 5 1
6 2 3
5 2 4
*/