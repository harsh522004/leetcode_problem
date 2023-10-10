#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    vector<int> nums = {1,-1,0};
    int target = 0;
    int n = nums.size();
    int current_sum = 0;
    int count = 0;
    unordered_map<int,int> PastSum ;
    PastSum[0] = 1;

    for(int i=0;i<n;i++){
        current_sum = current_sum + nums[i];
        int ele = current_sum - target;
        if(PastSum.find(ele) != PastSum.end()){
            count =  PastSum[current_sum] + 1;
        }
        PastSum[current_sum]++;
    }

    cout << count << endl;


    
    // int n = nums.size();
    // int current_Sum = 0;
    // int count = 0;
    // int i = 0;
    // int j = i;

    // while(i < n){
    //     current_Sum = current_Sum + nums[j];
    //     if(current_Sum == target){
    //         count++;
    //     }
    //     j++;
    //     if(j == n){
    //         i++;
    //         j = i;
    //         current_Sum = 0;
    //     }
    // }

    // cout << count << endl;
    return 0;
}
