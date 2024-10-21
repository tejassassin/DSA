#include <bits/stdc++.h>
using namespace std;

int main()
{


    vector<int> numbers = {0,1,1,2,0,2,2}; //n = 7  //numbers.size()
                         //0,1,2,3,4,5,6   // 0 - (n-1)   ->  0 - 6
    
    int n = numbers.size();

    int low=0, mid =0, high=n-1;

    while(mid <= high){

        if(numbers[mid] == 0){
            int tmp = numbers[low];
            numbers[low] = numbers[mid];
            numbers[mid] = tmp;

            low++;
            mid++;
        }

        else if (numbers[mid] == 1) {
                mid++;
        }
        
        else if (numbers[mid]==2){
            int tmp = numbers[high];
            numbers[high] = numbers[mid];
            numbers[mid] = tmp;

            high--;

        }


    }

 
    for(auto ele: numbers){
        cout<<ele<<" ";
    }
    cout<<endl;

  
}



