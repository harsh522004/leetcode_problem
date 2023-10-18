#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    int start = 0;
    int end = nums.size()-1;
    int index = -1;
    while(start <= end){
        cout << "start : " << start << endl;
        cout << "end : " << end << endl;
        int mid = (start + end)/2;
        cout << "mid : " << mid << endl;
        if(nums[mid] == target){
            index = mid;
            break;
        }
        else if (nums[mid] > target){
            end = mid;
        }
        else if(nums[mid] < target){
            start = mid;
        }
    }
    cout << index << endl;
    return 0;
}