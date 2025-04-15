#include <iostream>
#include <climits>
#include <string>
using namespace std;

struct Place {
    string name;
    string type;
};

int findMin(int dist[], bool visited[], int n) {
    int minDist = INT_MAX, index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int graph[100][100], int n, int src, Place places[]) {
    int dist[100];
    bool visited[100] = {false};

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = findMin(dist, visited, n);
        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "\nDistances from " << places[src].name << ":\n";
    for (int i = 0; i < n; i++) {
        cout << places[i].name << " (" << places[i].type << ") : ";
        if (dist[i] == INT_MAX) cout << "Unreachable";
        else cout << dist[i] << " km";
        cout << endl;
    }
}

int main() {
    int n;
    int graph[100][100];
    Place places[100];

    cout << "Enter number of places: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "Enter name of place " << i << ": ";
        getline(cin, places[i].name);
        cout << "Enter type of place " << i << ": ";
        getline(cin, places[i].type);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = (i == j) ? 0 : INT_MAX;

    cout << "Enter distances between places (-1 if no direct route):\n";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d;
            cout << "Distance between " << places[i].name << " and " << places[j].name << ": ";
            cin >> d;
            if (d >= 0) {
                graph[i][j] = d;
                graph[j][i] = d;
            }
        }
    }

    int src;
    cout << "Enter source index (0 to " << n - 1 << "): ";
    cin >> src;

    dijkstra(graph, n, src, places);

    return 0;
}
