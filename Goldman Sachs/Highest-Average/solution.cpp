#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int highestAverage(vector<pair<string, string>> &input) {
    unordered_map<string, int> sum;
    unordered_map<string, int> count;
    int input_size = input.size();
    for (pair<string, string> in : input) {
        sum[in.first] += stoi(in.second);
        count[in.first] += 1;
    }
    
    int result = INT_MIN;
    for (auto it = sum.begin(); it != sum.end(); it++) {
        int average = floor(it->second / count[it->first]);
        result = max(result, average);
    }
    return result;
}

int main() {
    vector<pair<string, string>> input = {
        {"Bob", "87"}, {"Mike", "35"}, {"Bob", "52"},
        {"Jason", "35"}, {"Mike", "55"}, {"Jessica", "99"}
    };
    cout << highestAverage(input);
    return 0;
}