#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;

unordered_map<char, int> order_map;
bool comparator(string &a, string &b) {
    int a_length = a.length();
    int b_length = b.length();
    for (int i = 0; i < min(a_length, b_length); i++) {
        if (a[i] != b[i]) {
            return order_map[a[i]] < order_map[b[i]];
        }
    }
    return a_length < b_length;
}

void sortInCustomOrder(vector<string> strings, string order) {
    for (int i = 0; i < order.size(); i++) {
        order_map[order[i]] = i;
    }

    sort(strings.begin(), strings.end(), comparator);
    for (string str : strings) {
        cout << str << ", ";
    }
    cout << endl;
}

int main() {
    sortInCustomOrder({"abcd", "yyyy", "zk"}, "yzxabcdefghijklmnopqrstuvw");
    return 0;
}