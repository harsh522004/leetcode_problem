// sort color question

#include<iostream>
#include<vector>
using namespace std;

int  main(){
    vector<int> nums = {2,0};

    //constant extra space
    vector<int> tamp (3,0);

    // 0(n)

    for(int i = 0 ;i < nums.size() ; i++){
        tamp[nums[i]] =  tamp[nums[i]] + 1;
    }

    // jus tracing

    // for(auto x: tamp){
    //     cout << x << " ";
    // }
    // cout << endl;

    int j = 0;


    //0(n)

    for(int i = 0;i<nums.size() ; i++){
        if(tamp[j] == 0){
            j++;
        }
        if(tamp[j] != 0){
            nums[i] = j;
            tamp[j] = tamp[j] - 1;
        }
        if(tamp[j] == 0){
            j++;
        }
    }

    // after sorting nums

    // for(auto x: nums){
    //     cout << x << " ";
    // }
    return 0;



}