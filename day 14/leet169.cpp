// find majority element ( repeat more than n/2 time)
// use moon's voting algorithm with 




#include<iostream>
#include<vector>
using namespace std;




class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element = nums[0];

        for(int i = 0 ; i < nums.size() ; i++){
            if(count == 0){
                element = nums[i];
            }
            if(nums[i] == element){
                count++;
            }
            else{
                count--;
            }
        }

        return element;
        
    }
};