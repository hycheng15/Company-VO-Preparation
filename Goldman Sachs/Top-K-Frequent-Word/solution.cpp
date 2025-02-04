#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Comparator {
    public:
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first; 
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> frequency;
        int words_length = words.size();
        for (int i = 0; i < words_length; i++) {
            frequency[words[i]]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, Comparator> pq;
        for (auto it = frequency.begin(); it != frequency.end(); it++) {
            pq.push(make_pair(it->second, it->first));
        }

        vector<string> result;
        int remaining = k;
        while (k > 0) {
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return result;
    }
};