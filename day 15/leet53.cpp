// subarray with max sum
// kadanes' algo
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int n = nums.size();








    // approach 1

//     vector<int> cum_arr;
// int sum = 0;
// for (int i = 0; i < n; i++) {
//     sum = sum + nums[i];
//     cum_arr.push_back(sum); // Use push_back to add elements to cum_arr
// }

// int i = 0;
// int j = i;
// int total_sum = cum_arr[n - 1];
// int max_sum = cum_arr[i];

// while (i < n) {
//     int left = i > 0 ? cum_arr[i - 1] : 0;
//     int right = j < n ? cum_arr[j] : 0;
//     int sum = right - left;
//     max_sum = max(sum, max_sum);

//     if (sum < 0) {
//         // If the current sum becomes negative, it's better to start with a new subarray.
//         i = j;
//         j = i;
//     } else {
//         j++;
//     }
// }


    // approach 2

//     int current_sum = nums[0];
//    // int max_sum = 0;
//    int max_sum = nums[0];

//     for(int i = 0 ; i < n ; i++){
//         int New = current_sum+nums[i];
//         current_sum = max(nums[i],New);
//         max_sum = max(current_sum,max_sum);

//     }

//     cout << max_sum << endl;

    return 0;
}
