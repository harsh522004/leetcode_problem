#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numIndices;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        // Check if the complement exists in the map
        if (numIndices.find(complement) != numIndices.end()) {
            result.push_back(numIndices[complement]); // Index of complement
            result.push_back(i); // Current index
            return result;
        }

        // Handle zero elements by checking if the current element is zero
        if (nums[i] == 0 && numIndices.find(0) != numIndices.end()) {
            result.push_back(numIndices[0]); // Index of the previous zero
            result.push_back(i); // Current index
            return result;
        }

        // Store the current element and its index in the map
        numIndices[nums[i]] = i;
    }

    return result; // No valid solution found
}

int main() {
    vector<int> nums = {0,4,0,1};
    int target = 0;
    vector<int> ans = twoSum(nums, target);

    if (ans.empty()) {
        cout << "No valid solution found." << endl;
    } else {
        cout << "Indices of elements that add up to the target: ";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
