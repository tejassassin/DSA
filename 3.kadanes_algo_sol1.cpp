
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &arr, int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {

        // i = starting point

        // i=0
        for (int j = i; j < n; j++) {

            //j = ending point
            // j=2
            int sum = 0;

            for (int k = i; k <= j; k++) {
                sum = sum + arr[k];
            }

            maxi = max(maxi, sum);
            cout<<sum<<" "<<maxi<<endl;
        }
    }

    return maxi;
}

int main()
{

    vector<int> arr= { -2, 1, -3, 4, -1, 2, 1, -5, 4};

    int n = arr.size();
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

