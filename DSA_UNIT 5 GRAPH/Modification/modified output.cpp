#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void prim(vector<vector<int> >& g, int n) {
    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> visited(n, false);

    key[0] = 0;
    int total = 0, edges = 0;

    cout << "\nSelected power lines (MST):\n";

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] &&
                (u == -1 || key[j] < key[u]))
                u = j;
        }

        if (u == -1 || key[u] == INT_MAX) {
            cout << "\nGraph is disconnected.\n";
            cout << "Spanning tree cannot be formed.\n";
            return;
        }

        visited[u] = true;

        if (parent[u] != -1) {
            total += key[u];
            edges++;

            cout << parent[u] + 1 << " - " << u + 1
                 << "  Weight: " << key[u]
                 << "  Running total: " << total << "\n";
        }

        for (int v = 0; v < n; v++) {
            if (g[u][v] > 0 && !visited[v] &&
                g[u][v] < key[v]) {
                key[v] = g[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Total cost = " << total << "\n";
    cout << "Minimum Spanning Tree formed successfully.\n";
}

int main() {
    int n, m;

    cout << "Enter number of substations: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of substations.\n";
        return 0;
    }

    cout << "Enter number of power lines: ";
    cin >> m;

    if (m < 0) {
        cout << "Invalid number of power lines.\n";
        return 0;
    }

    vector<vector<int> > g(n, vector<int>(n, 0));

    cout << "Enter power lines (u v weight):\n";

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        if (u < 1 || u > n || v < 1 || v > n ||
            u == v || w <= 0) {
            cout << "Invalid edge input.\n";
            return 0;
        }

        g[u - 1][v - 1] = w;
        g[v - 1][u - 1] = w;
    }

    cout << "\nInitial MST:";
    prim(g, n);

    char choice;
    cout << "\nDo you want to update an edge weight? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int u, v, w;

        cout << "Enter edge (u v) and new weight: ";
        cin >> u >> v >> w;

        if (u < 1 || u > n || v < 1 || v > n ||
            u == v || w <= 0 || g[u - 1][v - 1] == 0) {
            cout << "Invalid edge or weight update.\n";
            return 0;
        }

        g[u - 1][v - 1] = w;
        g[v - 1][u - 1] = w;

        cout << "\nMST after updating edge weight:";
        prim(g, n);
    }

    return 0;
}
