#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums = {0,1,2,3,4,5,7,8,9} ;
    int xorS = 0;
    for(int i = 0 ; i <= 9 ; i ++){
        xorS = xorS ^ i;

    }
    for(int i = 0; i < nums.size() ; i++){
        xorS = xorS ^ nums[i];
    }
    cout << xorS << endl;
    return 0;
}
