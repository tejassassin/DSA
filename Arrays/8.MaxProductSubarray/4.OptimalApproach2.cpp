#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int maxProductSubarray(vector<int>& nums) {
    if (nums.empty()) return 0;

    int max_product = nums[0];  // Stores the maximum product so far
    int min_product = nums[0];  // Stores the minimum product (negative numbers can become max)
    int result = nums[0];       // Stores the final max product

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) {
            swap(max_product, min_product);  // Swap when encountering a negative number
        }

        max_product = max(nums[i], nums[i] * max_product);
        min_product = min(nums[i], nums[i] * min_product);

        result = max(result, max_product);
    }

    return result;
}

int main() {
    vector<int> arr = {2, 3, -2, 4, -1};  // Example array
    cout << "Maximum Product Subarray: " << maxProductSubarray(arr) << endl;
    return 0;
}
