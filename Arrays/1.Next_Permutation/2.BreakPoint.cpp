
#include <bits/stdc++.h>
using namespace std;

/** Time Complexity : O(3n)
 * Explanation: We find the break point, 
 * then we find the next greater elemenet in the right array and 
 * then we swap with the break point element and reverse the entire array
 * each of these takes O(n) so total time complexity is O(3n) 
 * 
 * Space Complexity : O(1)
 * Explanation : we are not storing any data anywhere and the changes are made in-place to O(1)
 * **/

vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size(); 

    int ind = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            ind = i;
            break;
        }
    }

    if (ind == -1) {
        reverse(A.begin(), A.end());
        return A;
    }

    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    reverse(A.begin() + ind + 1, A.end());

    return A;
}

int main()
{
    vector<int> A = {1,2,3,4,5,6,7};
    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (auto n : ans) {
        cout << n << " ";
    }
    cout << "]";
    return 0;
}

