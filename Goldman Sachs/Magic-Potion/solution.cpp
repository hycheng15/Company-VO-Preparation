#include <vector>
#include <iostream>
#include <string>

using namespace std;

string stringCompression(string input_str) {
    string current_previous{input_str[0]};
    string result = current_previous;

    int str_length = input_str.length();
    for (int i = 1; i < str_length; i++) {
        if (current_previous == input_str.substr(i, current_previous.length())) {
            result.append("*");
            i += (current_previous.size() - 1);
            current_previous.append(current_previous);
        }
        else {
            result += input_str[i];
            current_previous += input_str[i];
        }
    }
    return result;
}

int main() {
    cout << stringCompression("abcabcd") << endl;
    cout << stringCompression("aabbaabb") << endl;
    cout << stringCompression("ABCDABCD") << endl;
    cout << stringCompression("AAAABBBB") << endl;
    cout << stringCompression("ABCABCE") << endl;
    cout << stringCompression("ABABCABABCD") << endl;
    cout << stringCompression("AAAAAA") << endl;
    cout << stringCompression("AAAAAAA") << endl;
    return 0;
}