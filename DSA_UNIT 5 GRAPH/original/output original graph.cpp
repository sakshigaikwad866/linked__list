#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of substations: ";
    cin >> n;

    cout << "Enter number of power lines: ";
    cin >> m;

    vector<vector<int >> graph(n, vector<int>(n, 0));

    cout << "Enter power lines (u v cost):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1][v - 1] = w;
        graph[v - 1][u - 1] = w;
    }

    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    key[0] = 0;
    int totalCost = 0;

    cout << "\nSelected power lines (MST):\n";

    for (int count = 0; count < n; count++) {
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] &&
                (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        if (u == -1 || key[u] == INT_MAX) {
            cout << "Network is disconnected.\n";
            return 0;
        }

        visited[u] = true;

        if (parent[u] != -1) {
            cout << parent[u] + 1 << " - "
                 << u + 1 << "  Cost: "
                 << key[u] << "\n";
            totalCost += key[u];
        }

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nTotal cost/length = "
         << totalCost << endl;

    return 0;
}
