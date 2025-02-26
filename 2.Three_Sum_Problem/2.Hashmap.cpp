#include <bits/stdc++.h>
using namespace std;

/** Time Complexity : O(n^2 x log(n))
 * Explanation: There are two loops and each time we are inserting into hashmap which will take log(m) 
 * where m is the no of elements in the hashset. In worst case m could be n so log(n)
 * 
 * we are also storing elemets in the set which takes O(log(k)) where k is the number of triplets. Which can be n^2 in worst case
 * so O(Log(n^2)) = 2O(log(n))
 * 
 * Total = O(n^2 x log(n))
 * 
 * Space Complexity : O(n^2) 
 * There are total O(n^3) no of triplets but we are not storing all of them as we are not storing duplicates, 
 * In simple terms for each i loop and each j loop we make one insertion to the set so space is at max O(n^2)
 * for each element a there is a pair (b, c) at max n pairs. 
 * and for each inner loop we are storing at max n elements int he hashmap. 
 * 
 * **/


vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            //Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

