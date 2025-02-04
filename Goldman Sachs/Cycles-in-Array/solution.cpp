#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int lengthOfCycle(vector<int> arr, int startIndex) {
    vector<int> visited;
    int current_index = startIndex;
    while (find(visited.begin(), visited.end(), current_index) == visited.end()) {
        if (current_index > arr.size() - 1) {
            return -1;
        }
        visited.push_back(current_index);
        current_index = arr[current_index];
    }

    return visited.size() - (find(visited.begin(), visited.end(), current_index) - visited.begin());
}

int main() {
    cout << lengthOfCycle({1, 2, 0}, 0) << endl;
    cout << lengthOfCycle({1, 0}, 0) << endl;
    cout << lengthOfCycle({1, 2, 3, 1}, 0) << endl;
    cout << lengthOfCycle({1, 2, 3, 4}, 0) << endl;
    cout << lengthOfCycle({1, 2, 3, 4}, -1) << endl;
    cout << lengthOfCycle({1, 2, 3, 4}, 4) << endl;
    cout << lengthOfCycle({2, 3, 4, 0}, 0) << endl;
    cout << lengthOfCycle({2, 3, 0}, 0) << endl;
    return 0;
}