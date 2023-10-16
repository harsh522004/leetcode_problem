#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int har = 0;
        for(int x : nums){
             har  = har ^ x;
        }
        return har;
        
    }
};