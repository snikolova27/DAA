#include <iostream>
#include <queue>

const int mod = 1000007;
int from, to;
bool used[mod+10];
int dist[mod+10];

void init()
{
    scanf("%d%d", &from, &to);
}

int rev(int num)
{
    long long res = 0;
    while(num)
    {
        res = res *10 + num % 10;
        num /= 10;
    }
    return res % mod;
}

int solve()
{
    std::queue<int> toVisit;

    toVisit.push(from);
    used[from] = 1;
    dist[from] = 1;

    while(!toVisit.empty())
    {
        int node = toVisit.front();
        toVisit.pop();

        int num1 =(node+1) % mod;
        int num2 = rev(node);

        if(num1 == to || num2 == to)
        {
            return dist[node] + 1;
        } 
        if(!used[num1])
        {
            used[num1] = 1;
            toVisit.push(num1);
            dist[num1] = dist[node] + 1;
        }
        if(!used[num2])
        {
            used[num2] = 1;
            toVisit.push(num2);
            dist[num2] = dist[node] + 1;
        }
    }
}


int main()
{
    init();
    printf("%d \n",solve());
    return 0;
}
/*
7 21
1000006 0
1000002 8
*/