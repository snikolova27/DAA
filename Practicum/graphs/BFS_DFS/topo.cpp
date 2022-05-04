#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n, m, edgesCount[int(1e5)];
vector<int> gr[int(1e5)];

void init(){
    int from, to;

    scanf("%d %d", &n, &m);

    for(int i=0;i<m;i++){
        scanf("%d %d", &from, &to);

        gr[from].push_back(to);

        edgesCount[to]++;
    }
}

void topoSort(){
    queue<int> ready;
    vector<int> sorted;

    for(int i=0;i<n;i++){
        if(edgesCount[i] == 0){
            ready.push(i);
        }
    }

    while(!ready.empty()){
        int node = ready.front();
        ready.pop();
        sorted.push_back(node);

        for(int neighbor : gr[node]){
            edgesCount[neighbor]--;

            if(edgesCount[neighbor] == 0){
                ready.push(neighbor);
            }
        }
    }

    if(sorted.size() != n){
        printf("There is a cycle!\n");
    } else {
        for(int i=0;i<sorted.size(); i++){
            printf("%d ", sorted[i]);
        }
        printf("\n");
    }
}

int main(){
    init();
    topoSort();
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