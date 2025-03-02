#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


// Time Complexity: O(N), where N = size of the given array.
// If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).
// Space Complexity : O(1)

vector<int> majorityElements(vector<int>& nums, int k) {
    if (k < 2) throw invalid_argument("k must be at least 2");

    unordered_map<int, int> candidates;
    
    // Step 1: Find potential candidates
    for (int num : nums) {
        if (candidates.count(num)) {
            candidates[num]++;
        } else if (candidates.size() < k - 1) {
            candidates[num] = 1;
        } else {
            // Reduce counts of all candidates
            vector<int> to_remove;
            for (auto& pair : candidates) {
                pair.second--;
                if (pair.second == 0) {
                    to_remove.push_back(pair.first);
                }
            }
            for (int key : to_remove) {
                candidates.erase(key);
            }
        }
    }

    // Step 2: Verify candidates
    unordered_map<int, int> counts;
    for (int num : nums) {
        if (candidates.count(num)) {
            counts[num]++;
        }
    }

    vector<int> result;
    int n = nums.size();
    for (auto& pair : counts) {
        if (pair.second > n / k) {
            result.push_back(pair.first);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 2, 2, 3, 3, 3, 4, 4, 4};
    int k = 4;
    vector<int> result = majorityElements(nums, k);

    cout << "Elements appearing more than ⌊n/" << k << "⌋ times: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
