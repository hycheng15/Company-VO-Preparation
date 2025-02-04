#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

int largestTreeRoot(vector<vector<int>> edges) {
    unordered_map<int, vector<int>> adjList;
    unordered_map<int, int> inDegree;
    
    for (vector<int> edge : edges) {
        adjList[edge[1]].push_back(edge[0]);
        inDegree[edge[0]]++;
        if (inDegree.find(edge[1]) == inDegree.end()) {
            inDegree[edge[1]] = 0;
        }
    }

    int count = INT_MIN;
    int result_root;

    // Traverse from all roots and do bfs
    // Get all the root nodes using inDegree == 0
    for (auto [key, value]: inDegree) {
        if (value == 0) {
            int current_count = 0;
            queue<int> bfs;
            bfs.push(key);
            while (bfs.size() != 0) {
                for (int child : adjList[bfs.front()]) {
                    bfs.push(child);
                }
                bfs.pop();
                current_count += 1;
            }
            if (current_count > count) {
                count = current_count;
                result_root = key;
            }
            else if (current_count == count) {
                result_root = min(key, result_root);
            }
        }
    }

    return result_root;
}
int main() {
    vector<vector<int>> childToParent = {{8, 4}, {9, 4}, {1, 4}, {10, 4}, {5, 20}, {7, 3}, {2, 3}, {6, 7}};
    cout << largestTreeRoot(childToParent) << endl;

    childToParent = {{1, 2}, {3, 4}};
    cout << largestTreeRoot(childToParent) << endl;

    childToParent = {{1, 4}, {2, 4}, {3, 1}, {0, 1}, {5, 3}, {7, 6}, {12, 6}, {8, 7}, {10, 8}, {9, 8}, {13, 12}};
    cout << largestTreeRoot(childToParent) << endl;

    return 0;
}