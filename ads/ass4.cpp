//minimum spanning tree

#include <iostream>
#include <climits>
#include <string>
using namespace std;

struct Dept {
    string name;
    string place;
};

int getMin(int key[], bool visited[], int n) {
    int minVal = INT_MAX, index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && key[i] < minVal) {
            minVal = key[i];
            index = i;
        }
    }
    return index;
}

void showMST(int parent[], int graph[100][100], Dept d[], int n) {
    int total = 0;
    cout << "\nConnections in MST:\n";
    for (int i = 1; i < n; i++) {
        cout << d[parent[i]].name << " - " << d[i].name << " : " << graph[i][parent[i]] << " meters\n";
        total += graph[i][parent[i]];
    }
    cout << "Total length: " << total << " meters\n";
}

void mst(int graph[100][100], int n, Dept d[], int start) {
    int key[100], parent[100];
    bool visited[100];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[start] = 0;
    parent[start] = -1;

    for (int i = 0; i < n - 1; i++) {
        int u = getMin(key, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    showMST(parent, graph, d, n);
}

int main() {
    int n;
    Dept d[100];
    int graph[100][100] = {0};

    cout << "Enter number of departments: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "Department " << i << " name: ";
        getline(cin, d[i].name);
        cout << "Location: ";
        getline(cin, d[i].place);
    }

    cout << "\nEnter distances between departments (-1 if no connection):\n";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << d[i].name << " to " << d[j].name << ": ";
            int dist;
            cin >> dist;
            if (dist > 0) {
                graph[i][j] = dist;
                graph[j][i] = dist;
            }
        }
    }

    while (true) {
        cout << "\nDepartments:\n";
        for (int i = 0; i < n; i++)
            cout << i << ": " << d[i].name << endl;

        int start;
        cout << "Enter starting index (0 to " << n - 1 << "): ";
        cin >> start;

        mst(graph, n, d, start);

        char again;
        cout << "Try another starting point? (y/n): ";
        cin >> again;
        if (again != 'y' && again != 'Y') break;
    }

    return 0;
}
