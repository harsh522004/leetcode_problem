#include<iostream>
#include<vector>
using namespace std;


class Solution {
private:
    bool isSorted(const vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }
public:
    bool check(vector<int>& nums) {
        int rotation = nums.size();
        bool ans = false;
        
        while (rotation > 0) {
            vector<int> tamp(nums.size()); // Initialize tamp with the same size as nums

            for (int i = 0; i < nums.size(); i++) {
                int futureIndex = (i + rotation) % nums.size();
                tamp[futureIndex] = nums[i];
            }

            if (isSorted(tamp)) {
                ans = true;
                break;
            }

            rotation = rotation - 1;
        }

        return ans;
    }
};
