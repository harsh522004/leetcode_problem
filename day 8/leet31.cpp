// next lexicographically greater permutation

#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    
    // Find the rightmost pair (i, i+1) where nums[i] < nums[i+1]
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i+1]) {
        i--;
    }
    
    // If such a pair exists, swap nums[i] with the smallest element to the right of nums[i] that is greater than nums[i]
    if (i >= 0) {
        int j = n - 1;
        while (j > i && nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }
    
    // Reverse the elements to the right of nums[i]
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    vector<int> nums = {2,3,4,1};
    nextPermutation(nums);
    
    // Output the result
    for(auto x:nums){
        cout << x << "  ";
    }
    
    return 0;
}
