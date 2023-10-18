#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums = {1,1,0,1,1,1};
    int maxOnes = 0;
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            cout << "index  :" << i << endl;
            cout << "elemnt : " << nums[i] << endl;
            cout << "count : " << count << endl;
            cout << "Mx : " << maxOnes << endl; 
            if(nums[i] == 1){
                count++;
            }else{
                
                count = 0;
            }
            maxOnes = max(maxOnes,count);
        }
        cout << maxOnes << endl;

}
