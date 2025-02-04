#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int uniqueSubstrings(string str, int k) {
    int str_size = str.size();
    unordered_set<string> result;
    for (int i = 0; i <= str_size - k; i++) {
        string substr = str.substr(i, k);
        result.insert(substr);
    }

    return result.size();
}

int main() {
    cout << uniqueSubstrings("abcd", 2) << endl;
    cout << uniqueSubstrings("aaaaaaaab", 3) << endl;
    return 0;
}