#include <iostream>
#include <vector>
const int MAX_VERTEX_COUNT = 100;

struct Node
{
    int to;
    int weight;
};

std::vector<int> directedGraph[MAX_VERTEX_COUNT];
std::vector<int> undirecredGraph[MAX_VERTEX_COUNT];


bool matrixGraph[MAX_VERTEX_COUNT][MAX_VERTEX_COUNT];
int matrixWeightedGraph[MAX_VERTEX_COUNT][MAX_VERTEX_COUNT];

std::vector<Node> weightedGraph[MAX_VERTEX_COUNT];
Node temp;

int vertexCnt, edgesCnt;

int main()
{
    scanf("%d %d", &vertexCnt, &edgesCnt);
    int vertexTo, vertexFrom, weight;
    
    for(int i = 0; i < edgesCnt; i++)
    {
        scanf("%d %d", &vertexFrom, &vertexTo);
        // undirected

        undirecredGraph[vertexTo].push_back(vertexFrom);
        undirecredGraph[vertexFrom].push_back(vertexTo);

        matrixGraph[vertexTo][vertexFrom] = true;
        matrixGraph[vertexFrom][vertexTo] = true;

        // directed

        directedGraph[vertexFrom].push_back(vertexTo);
        matrixGraph[vertexFrom][vertexTo] = true;

        // weighted
        scanf("%d", &weight);

            // directed
        temp.to = vertexTo;
        temp.weight = weight;
        weightedGraph[vertexFrom].push_back(temp);

            // undirected
        temp.to = vertexFrom;
        weightedGraph[vertexTo].push_back(temp);

        matrixWeightedGraph[vertexFrom][vertexTo] = weight;
        matrixWeightedGraph[vertexTo][vertexFrom] = weight;
    }
    return 0;
}