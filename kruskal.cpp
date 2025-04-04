#include <iostream>
#include <limits.h>

#define MAX 20

using namespace std;

class Graph {
    int V;
    int graph[MAX][MAX];

public:
    Graph(int vertices) {
        V = vertices;
        graph[MAX][MAX] = {0};
    }

    void addEdge(int u, int v, int w) {
        graph[u][v] = w;
        graph[v][u] = w;
    }

    void printMST(int parent[]) {
        cout << "Edge \tWeight\n";
        for (int i = 1; i < V; i++)
            cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }

    int minKey(int key[], bool mstSet[]) {
        int min = INT_MAX, min_index;

        for (int i = 0; i < V; i++)
            if (key[i] < min && mstSet[i] == false)
                min = key[i], min_index = i;

        return min_index;
    }

    void primMST() {
        int key[MAX];
        int parent[MAX];
        bool mstSet[MAX];

        for (int i = 0; i < V; i++)
            key[i] = INT_MAX, mstSet[i] = false;

        key[0] = 0;
        parent[0] = -1;

        for (int i = 0; i < V; i++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;

            for (int v = 0; v < V; v++)
                if (graph[u][v] > 0 && mstSet[v] == false && key[v] > graph[u][v])
                    key[v] = graph[u][v], parent[v] = u;
        }

        printMST(parent);
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, 1);

    cout << "Prim's Minimum Spanning Tree:\n";
    g.primMST();

    return 0;
}