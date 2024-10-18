#include <bits/stdc++.h>
using namespace std;

int main()
{


    vector<int> numbers = {}; //n = 7  //numbers.size()
                         //0,1,2,3,4,5,6   // 0 - (n-1)   ->  0 - 6
    
    //ans = {0,0,0,1,1,2,2}

    int n = numbers.size(); //7

    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;


    for(auto ele : numbers){ // for each element in array
        if (ele == 0){
            count_0 = count_0 +1;
        }
        
        else if (ele == 1){
            count_1 = count_1 +1;
        }
        
        else {
            count_2 = count_2 +1;
        }
    }

    vector<int> ans = {};

    for (int i=0;i<count_0;i++){
        ans.push_back(0);
    }

    for (int i=0;i<count_1;i++){
        ans.push_back(1);
    }

   for (int i=0;i<count_2;i++){
        ans.push_back(2);
    }

    for(auto ele : ans){
        cout<<ele<<" ";
    }
}



