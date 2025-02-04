#include <iostream>
#include <vector>

using namespace std;    

int secondSmallest(vector<int> nums) {
    int nums_size = nums.size();
    if (nums_size < 2) {
        return 0;
    }

    int smallest = nums[0];
    int second_smallest = INT_MAX;
    for (int i = 1; i < nums_size; i++) {
        if (nums[i] > smallest && nums[i] < second_smallest) {
            second_smallest = nums[i];
        }
        else if (nums[i] < smallest) {
            second_smallest = smallest;
            smallest = nums[i];
        }
        else if (nums[i] == smallest) {
            second_smallest = nums[i];
        }
    }
    return second_smallest;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << secondSmallest(nums) << endl;

    nums = {4, 8, 9, 2, 1, 1};
    cout << secondSmallest(nums) << endl;
    return 0;
}