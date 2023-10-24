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

    // Delete an edge from 'from' to 'to'.
    void deleteEdge(int from, int to) {
        adj[from].remove(to);
    }

    // Perform a depth-first search with cycle detection.
    bool isCyclicDFS(int v, vector<bool>& visited, vector<bool>& recStack) {
        if (!visited[v]) {
            visited[v] = true;
            recStack[v] = true;

            for (int neighbor : adj[v]) {
                if (!visited[neighbor] && isCyclicDFS(neighbor, visited, recStack)) {
                    return true;
                } else if (recStack[neighbor]) {
                    return true;
                }
            }
        }
        recStack[v] = false;
        return false;
    }

    // Check if the graph is acyclic using depth-first search.
    bool isAcyclic() {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++) {
            if (isCyclicDFS(i, visited, recStack)) {
                return false;
            }
        }
        return true;
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

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Check Acyclic\n";
        cout << "4. Topological Sort\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int from, to;
                cout << "Enter edge to add (e.g., 2 3): ";
                cin >> from >> to;
                digraph.addEdge(from - 1, to - 1);
                break;
            }
            case 2: {
                int from, to;
                cout << "Enter edge to delete (e.g., 2 3): ";
                cin >> from >> to;
                digraph.deleteEdge(from - 1, to - 1);
                break;
            }
            case 3: {
                if (digraph.isAcyclic()) {
                    cout << "The graph is acyclic.\n";
                } else {
                    cout << "The graph has a cyclic dependency.\n";
                }
                break;
            }
            case 4: {
                if (digraph.isAcyclic()) {
                    cout << "Topological Sort Order:\n";
                    list<int> result = digraph.topologicalSort();
                    for (int task : result) {
                        cout << tasks[task] << endl;
                    }
                } else {
                    cout << "Cannot perform topological sort. The graph has a cyclic dependency.\n";
                }
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please select a valid option.\n";
        }

    } while (choice != 5);

    return 0;
}