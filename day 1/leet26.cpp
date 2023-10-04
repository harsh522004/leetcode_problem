#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

void removeDuplicates(vector<int>& nums) {
        vector<int> extnum = {};
        unordered_map<int,bool> chek;
        //int count = 0;
        for(int  i = 0 ; i < nums.size() ; i++){
            int current = nums[i];
            if(!(chek.find(current) != chek.end())){
                
                chek[current] = true;
                extnum.push_back(current);
            }

        }

        // for(int i =0 ;i <extnum.size() ; i++){
        //     cout << extnum[i] << " " << endl;
        // }

        cout << extnum.size();
        
        
    }

    int main(){
         vector<int> nums= {0,0,1,1,1,2,2,3,3,4};
         removeDuplicates(nums);
        return 0;
    }