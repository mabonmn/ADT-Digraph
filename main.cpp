#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class Digraph {
private:
    int V; // Number of vertices
    vector<list<int>> adj; // Adjacency list

public:
    Digraph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    // Add an edge from 'from' to 'to'.
    void addEdge(int from, int to) {
        adj[from].push_back(to);
    }

    // Recursive function for topological sort.
    void topologicalSortUtil(int v, vector<bool>& visited, list<int>& result) {
        visited[v] = true;
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                topologicalSortUtil(neighbor, visited, result);
            }
        }
        // Add the current vertex to the front of the result list.
        result.push_front(v);
    }

    // Perform topological sort.
    list<int> topologicalSort() {
        vector<bool> visited(V, false);
        list<int> result;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, result);
            }
        }

        return result;
    }

    // Check if the graph is acyclic.
    bool isAcyclic() {
        list<int> result = topologicalSort();
        return result.size() == V; // If the result size is equal to the number of vertices, it's acyclic.
    }
};

int main() {
    int numTasks;
    cout << "Enter the number of tasks: ";
    cin >> numTasks;

    Digraph digraph(numTasks);

    // Input tasks
    vector<string> tasks(numTasks);
    cin.ignore(); // Consume the newline character
    for (int i = 0; i < numTasks; i++) {
        cout << "Enter task " << i + 1 << ": ";
        getline(cin, tasks[i]);
    }

    // Input order relations
    int numRelations;
    cout << "Enter the number of order relations: ";
    cin >> numRelations;

    for (int i = 0; i < numRelations; i++) {
        int from, to;
        cout << "Enter order relation (e.g., 3 1): ";
        cin >> from >> to;
        digraph.addEdge(from - 1, to - 1); // Adjust indices to be 0-based.
    }

    if (digraph.isAcyclic()) {
        cout << "Topological Sort Order:\n";
        list<int> result = digraph.topologicalSort();
        for (int task : result) {
            cout << tasks[task] << endl;
        }
    } else {
        cout << "The given tasks have a cyclic dependency. Cannot perform topological sort.\n";
    }

    return 0;
}
