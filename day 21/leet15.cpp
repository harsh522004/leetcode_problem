// 3Sum probleam
#include<iostream>
#include<vector>
#include <algorithm>
#include <utility> 
#include<map>
using namespace std;
int main(){
   vector<int> nums = {-1,0,1,2,-1,-4};
int n = nums.size();
sort(nums.begin(), nums.end());

vector<vector<int>> triplets;

int i = 0;

while (i < n - 2) {
    int j = i + 1;
    int k = n - 1;

    if (i > 0 && nums[i] == nums[i - 1]) {
        i++;
        continue; // Skip duplicate i values
    }

    while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];

        if (sum == 0) {
            triplets.push_back({nums[i], nums[j], nums[k]});

            // Skip duplicate j and k values
            while (j < k && nums[j] == nums[j + 1]) j++;
            while (j < k && nums[k] == nums[k - 1]) k--;

            j++;
            k--; // also this is needed, because you must be change atleast two element for new triplets
        } else if (sum < 0) {
            j++;
        } else {
            k--;
        }
    }

    i++;
}



  for(auto x: triplets){
    for(auto y: x){
        cout << y << "  ";
    }
    cout << endl;
  }


    // aproch 1 : using 3 pointers ( Got TLE )
    // sort(nums.begin(), nums.end());
    // int PosIndex = 0;
    // for (int i = 0; i < n; i++) {
    //   if (nums[i] >= 0) {
    //     PosIndex = i;
    //     break;
    //   }
    // }
    // vector<vector<int>> ans;
    // int i = 0;
    // int j = PosIndex;
    // int k = j + 1;
    // while (i < PosIndex) {
    //   if (i != 0) {
    //     if (nums[i] == nums[i - 1]) {
    //       i++;
    //       if (i >= PosIndex)
    //         break;
    //     }
    //   }
    //   j = PosIndex;
    //   k = j + 1;
    //   while (j < n - 1) {
    //     if (k <= n - 1) {
    //       int sum = nums[i] + nums[j] + nums[k];
    //       if (sum == 0) {
    //         vector<int> tamp;
    //         tamp.push_back(nums[i]);
    //         tamp.push_back(nums[j]);
    //         tamp.push_back(nums[k]);
    //         ans.push_back(tamp);
    //       }
    //       k++;
    //     }
    //   }
    //   i++;
    // }
    // i = PosIndex;
    // j = 0;
    // k = j + 1;

    // while (i < n) {
    //   if (i != PosIndex) {
    //     if (nums[i] == nums[i - 1]) {
    //       i++;
    //       if (i >= n)
    //         break;
    //     }
    //   }
    //   j = 0;
    //   k = j + 1;
    //   while (j < PosIndex - 1) {
    //     if (k <= PosIndex) {
    //       int sum = nums[i] + nums[j] + nums[k];
    //       if (sum == 0) {
    //         vector<int> tamp;
    //         tamp.push_back(nums[i]);
    //         tamp.push_back(nums[j]);
    //         tamp.push_back(nums[k]);
    //         ans.push_back(tamp);
    //       }
    //       k++;
    //     }
    //   }
    //   i++;
    // }
    // return ans;
    return 0;

}