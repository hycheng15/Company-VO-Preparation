#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int chars_size = chars.size();
        int write_pos = 0;
        int check_pos = 0;

        while (check_pos < chars_size) {
            int count = 0;
            char current_char = chars[check_pos];

            // Find the same char, increment the count and move
            while (check_pos < chars_size && chars[check_pos] == current_char) {
                count += 1;
                check_pos += 1;
            }

            // Find different, dump the previous count
            chars[write_pos++] = current_char;
            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[write_pos++] = c;
                }
            }
        }

        chars.resize(write_pos);
        return chars.size();
    }
};