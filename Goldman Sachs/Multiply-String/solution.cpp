#include <iostream>
#include <string>

using namespace std;

string encode(string word, int number) {
    int i = 0;
    string number_str = to_string(number);
    string result = "";
    while (i < number_str.length()) {
        for (int j = 0; j < number_str[i] - '0'; j++) {
            result += word[i];
        }
        i++;
    }
    while (i < word.length()) {
        result += word[i];
        i++;
    }

    return result;
}

vector<string> decode(string word) {
    int word_length = word.length();
    string result = "";
    string result_count = "";
    char current = word[0];
    int count = 0;
    for (int i = 0; i < word_length; i++) {
        if (word[i] == current) {
            count += 1;
        }
        else {
            result += current;
            result_count += to_string(count);
            count = 1;
            current = word[i];
        }
    }
    // Deal with the last char
    result += current;
    result_count += to_string(count);

    return {result, result_count};
}

int main() {
    cout << "===== Encoding Tests =====" << endl;
    cout << encode("abcd", 123) << endl;
    cout << encode("abcde", 4) << endl;
    
    cout << "\n===== Decoding Tests =====" << endl;
    cout << decode("aabbbccccd")[0] << " " << decode("aabbbccccd")[1] << endl;
    cout << decode("aaaaa")[0] << " " << decode("aaaaa")[1] << endl;
    cout << decode("bbhhh111errrqq")[0] << " " << decode("bbhhh111errrqq")[1] << endl;

    return 0;
}