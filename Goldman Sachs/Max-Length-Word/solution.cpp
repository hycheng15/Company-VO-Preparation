#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> maxLengthWord(vector<string> dictionary, string target) {
    unordered_map<char, int> frequency;
    vector<string> result;
    int result_length = 0;
    for (char t : target) {
        frequency[t]++;
    }

    for (string word : dictionary) {
        unordered_map<char, int> word_freq;
        for (char w : word) {
            word_freq[w]++;
        }
        bool canForm = true;
        for (auto it = word_freq.begin(); it != word_freq.end(); it++) {
            if (frequency.count(it->first) == 0 || frequency[it->first] < it->second) {
                canForm = false;
                break;
            }
        }
        if (canForm) {
            if (word.length() == result_length) {
                result.push_back(word);
            }
            else if (word.length() > result_length) {
                result_length = word.length();
                result.clear();
                result.push_back(word);
            }
        }
    }

    return result;
}

int main() {
    vector<string> dictionary = {"to", "banana", "toe", "dogs", "ababcd", "elephant"};
    string target = "eot";
    vector<string> ans = maxLengthWord(dictionary, target);
    for (string a : ans) {
        cout << a << ", ";
    }
    cout << endl;

    dictionary = {"to", "banana", "toes", "dogs", "ababcd", "elephant"};
    target = "ogtdes";
    ans = maxLengthWord(dictionary, target);
    for (string a : ans) {
        cout << a << ", ";
    }
    cout << endl;


    return 0;
}