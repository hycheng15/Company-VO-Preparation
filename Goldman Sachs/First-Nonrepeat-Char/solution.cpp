#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

char firstNonRepeat(string s) {
    int s_size = s.size();
    unordered_map<char, int> freq;
    for (int i = 0; i < s_size; i++) {
        freq[s[i]] += 1;
    }
    for (int i = 0; i < s_size; i++) {
        if (freq[s[i]] == 1) {
            return s[i];
        }
    }
    return '0';
}

int main() {
    cout << firstNonRepeat("asubsebusapd") << endl;
    cout << firstNonRepeat("aabbcc") << endl;
    return 0;
}