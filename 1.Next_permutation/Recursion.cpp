#include <iostream>
#include <vector>  
#include <algorithm>


using namespace std;



void RecurPermute(int index, vector<int> &nums, vector<vector<int>> &ans){
    if(index == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int i=index;i<nums.size();i++){
        swap(nums[i], nums[index]);
        RecurPermute(index + 1, nums, ans);
        swap(nums[i], nums[index]);
    }

}

void findNextPermutation(vector<vector<int>> &ans, vector<int> &target) {

    auto it = find(ans.begin(), ans.end(), target);

    if (it != ans.end()) {
        if (it + 1 != ans.end()) {
            cout << "Next permutation: ";
            for (int num : *(it + 1)) {
                cout << num << " ";
            }
            cout << endl;
        } else {
            cout << "Next permutation (looping to first): ";
            for (int num : ans[0]) {
                cout << num << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Given permutation not found in the generated permutations!" << endl;
    }
}

int main() {  
    vector<int> arr = {1, 2, 3};  
    vector<vector<int>> ans;
    RecurPermute(0, arr, ans);
    for(auto arr : ans){
        for(int x : arr){
            cout<< x << " ";
        }
        cout << endl;
    }

    //search for next permutation
    findNextPermutation(ans, arr);

    return 0; 
}
