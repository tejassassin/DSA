#include <bits/stdc++.h>
using namespace std;

/** Time Complexity : O(n^3)
 * Explanation: there are 3 loops nested so O(n^3)
 * We also insert element into set. Set is a Balanced BST so take O(log(m)) time to insert where m is the numner of elements in the set. 
 * In the worst case there can be n^3 elements so insertion takes O(log(n^3)) = 3 O(log(n))
 * We are also sorting the temp array but just 3 elements so O(1)
 * We are copying the entire set to answer array which will again take O(n^3) in the worst case
 * 
 * Space Complexity : O(n^3)
 * Explanation : we are storing answers in set and list. In worst case we store 2 x O(n^3) elements
 * **/


vector<vector<int>> FindTriplets(int n, vector<int> &arr) {
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = FindTriplets(n, arr);
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

