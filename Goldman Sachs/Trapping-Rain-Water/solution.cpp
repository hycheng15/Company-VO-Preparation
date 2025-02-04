#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int height_size = height.size();
        int result = 0;
        vector<int> left_max(height_size);
        vector<int> right_max(height_size);

        left_max[0] = height[0];
        for (int i = 1; i < height_size; i++) {
            left_max[i] = max(left_max[i-1], height[i]);
        }

        right_max[height_size-1] = height[height_size-1];
        for (int i = height_size - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i+1], height[i]);
            result += ( min(right_max[i], left_max[i]) - height[i]);
        }

        return result;
    }
};