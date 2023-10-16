#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums = {3,1,-2,-5,2,-4};
    int n = nums.size();
    int arr[n];
    int posEnd = (n/2)-1;
    //int negStart = (n/2);

    int pos = 0;
    int neg = (n/2);

    for(int i = 0 ; i < n ; i++){

        if(nums[i] > 0 && pos <= posEnd){
            arr[pos] = nums[i];
            pos++;
        }
        else if(nums[i] < 0 && neg < n){
            arr[neg] = nums[i];
            neg++;
        }

    }

    // Print Array
    // for(int i = 0; i < n ; i++){
    //     cout << arr[i] << "  " ;
    // }
    // cout << endl;


    vector<int> ans;
    pos = 0;
    neg = (n/2);

    for(int i = 0 ; i < n ; i++){
        if(i % 2 == 0 && pos <= posEnd){
            ans.push_back(arr[pos]);
            pos++;
        }
        else if(i % 2 != 0 && neg < n){
            ans.push_back(arr[neg]);
            neg++;

        }
    }

    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;


}
   