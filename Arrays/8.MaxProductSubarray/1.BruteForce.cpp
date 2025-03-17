#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N^3)

// Reason: 3 nested loops to generate all subarrays and calculate their product.

// Space Complexity: O(1)

int maxProductSubArray(vector<int>& nums) {
    int result = INT_MIN;
    
    for (int i = 0; i < nums.size(); i++) {  // Should iterate up to nums.size()
        for (int j = i; j < nums.size(); j++) {  // j should start from i, not i+1
            int prod = 1;
            for (int k = i; k <= j; k++) 
                prod *= nums[k];
            result = max(result, prod);    
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray: " << maxProductSubArray(nums) << endl;
    return 0;
}
