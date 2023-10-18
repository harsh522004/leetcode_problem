#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    vector<int> nums = //{2, 2, 2, 3, 3, 4, 4, 4, 5, 5};
    {3,2,3};
    int n = nums.size();
        int count1 = 0;
        int candidate1 = INT_MIN;
        int count2 = 0;
        int candidate2 = INT_MIN;
        int i = 0;
        while(i < n){
            if(count1 == 0 && candidate2 != nums[i]){
                candidate1 = nums[i];
                count1 = 1;

            }
            else if(count2 == 0 && candidate1 != nums[i]){
                candidate2 = nums[i];
                count2 = 1;

            }
            else if(nums[i] == candidate1){
                count1++;
            }
            else if(nums[i] == candidate2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
            i++;
        }
        vector<int> ans;
        int mini = ((int) n/3 + 1);
        count1 = 0, count2 = 0;
        for(int i = 0 ; i < n ; i ++){
            if(nums[i] == candidate1){
                count1++;
            }else if(nums[i] != candidate2){
                count2++;
            }

        }
        if(count1 >= mini){
            ans.push_back(candidate1);
        }if(count2 >= mini){
            ans.push_back(candidate2);
        }
        for(auto x: ans){
            cout << x << " " ;
        }
        cout << endl;
        return 0;
}

