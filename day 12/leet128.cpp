#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_set>
using namespace std;

// aproach 1

void longestConsecutive(vector<int>& nums) {
    int n = nums.size();

    set<int> mySet;

    
    for (int i = 0; i < n; i++) {
        mySet.insert(nums[i]);
    }

    int count = 1;
    int max_seq = 0;
    int prev = *(mySet.begin()); 

    
    for (auto it = next(mySet.begin()); it != mySet.end(); ++it) {
        int current = *it;

        if (current == prev + 1) {
            count = count + 1;
        } else {
            max_seq = max(count, max_seq);
            count = 1;
        }
        prev = current;
    }

    max_seq = max(count, max_seq);

    cout << max_seq << endl;
}


// aproch 2 

class Solution {

   

public:
    int longestConsecutive2(vector<int>& nums) {
   



    unordered_set<int> mySet(nums.begin(), nums.end());
    int max_Seq = 0;

    for(int ele : mySet){
        bool isFirst = (mySet.find(ele-1) == mySet.end());
        if(isFirst){
            int currentNum = ele;
            int seq = 1;
            while(mySet.find(currentNum+1) != mySet.end()){
                currentNum++;
                seq++;
            }
            max_Seq = max(seq,max_Seq);
        }

    }
    return max_Seq;
    }
};











    




    

   


















        


































        


int main(){
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    longestConsecutive(nums);
    return 0;
    
}