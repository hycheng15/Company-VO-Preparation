#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int nums_length = nums.size();
        int result = INT_MAX;

        // Using sliding window
        // https://www.geeksforgeeks.org/window-sliding-technique/
        int left = 0;
        int right = 0;
        int sum = 0;
        while (right < nums_length) {
            // Increase the window
            while (sum < target && right < nums_length) {
                sum += nums[right];
                right += 1;
            }
            
            // Decrease the window
            while (sum >= target && left < right) {
                result = min(result, right - left);
                sum -= nums[left];
                left++;
            }

        }
        
        return result == INT_MAX ? 0 : result;
    }
};