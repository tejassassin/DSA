#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N2)

// Reason: We are using two nested loops

// Space Complexity: O(1)


int maxProductSubArray(vector<int>& nums) {
    int result = INT_MIN;
    for(int i=0;i<nums.size();i++) {
        int p = 1;
        for(int j=i;j<nums.size();j++) {
            p *= nums[j];
            result = max(result,p);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}

