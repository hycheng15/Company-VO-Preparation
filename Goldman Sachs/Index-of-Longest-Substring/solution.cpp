#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

pair<int, int> longestSubstring(string str) {
    int str_length = str.length();
    int result_index = 0;
    int result_length = 0;

    int head = 0;
    int tail = 0;
    while (tail < str_length) {
        if (str[head] != str[tail]) {
            int current_length = tail - head;
            if (current_length > result_length) {
                result_length = current_length;
                result_index = head;
            }
            head = tail;
        }
        else if (tail == str_length - 1 && str[head] == str[tail]) {
            int current_length = tail - head + 1;
            if (current_length > result_length) {
                result_length = current_length;
                result_index = head;
            }
            head = tail;
        }
        tail++;
    }
    
    return make_pair(result_index, result_length);
}

int main() {
    vector<string> tests = {"aabbbbbccddb", "aabbb22rrrrr345571111111", "aaaabbeedddd", "a"};
    for (string test : tests) {
        pair<int, int> ans = longestSubstring(test);
        cout << ans.first << ", " << ans.second << endl;
    }
    return 0;
}