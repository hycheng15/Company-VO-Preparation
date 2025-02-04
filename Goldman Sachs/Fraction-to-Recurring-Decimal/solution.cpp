#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result = "";
        if (numerator == 0) {
            return "0";
        }
        // Be careful: cannot use a * b < 0, otherwise will overflow
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }
        long long num = abs((long long)numerator);
        long long denom = abs((long long)denominator);
        long long remainder = num % denom;
        result += to_string(num / denom);

        // map {remainder: position}
        unordered_map<long long, int> prev_remainders;
        if (remainder != 0) result += ".";
        while (remainder != 0) {
            // This remainder has occur before, thus we have repeating decimal
            if(prev_remainders.find(remainder) != prev_remainders.end()) {
                // https://cplusplus.com/reference/string/string/insert/
                result.insert(prev_remainders[remainder], "(");
                result += ")";
                break;
            }

            prev_remainders[remainder] = result.size();
            remainder *= 10;
            while (remainder < denom) {
                result += "0";
                remainder *= 10;
            }
            result += to_string(remainder/denom);
            remainder %= denom;
        }

        return result;
    }
};