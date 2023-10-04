#include<vector>
#include<map>
#include<iostream>
using namespace std;

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;  

    for (int j = low; j <= high - 1; j++) {
        
        if (arr[j] <= pivot) {
            i++;  
            std::swap(arr[i], arr[j]);
        }
    }

    
    std::swap(arr[i + 1], arr[high]);

    return i + 1;
}


void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        
        
        
        int pivotIndex = partition(arr, low, high);

        
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}


vector<int> topKFrequent(vector<int>& nums, int k) {

    if(nums.size() == 1){
        return nums;
    }

    quicksort(nums,0,nums.size()-1);

    // count -> element
    map<int,int> hmap;

    int cheak = nums[0];
    int count = 0;


    cout << nums[2] << endl;
   

    for(int i = 0; i<nums.size() ; i++){

        cout << "Loop Call For : " << nums[i] << endl;

        if(i == nums.size()-1){

            cout << "1 COndition Run " << endl;

            if(nums[i] == cheak){
                 cout << "1.1 COndition Run " << endl;
            count++;  
            hmap[count] = nums[i]; 
        }else{
            cout << "1.2 COndition Run " << endl;
            hmap[1] = nums[i];
            
        }

        }
      
else{
    cout << "2 COndition Run " << endl;
             if(nums[i] == cheak){
             cout << " 2.1 COndition Run " << endl;
            count++;   
        }
        
        
        
        else{
             cout << "2.2 COndition Run " << endl;
            hmap[count] = nums[i-1];
            cheak = nums[i];
            count = 1;
        }


}
        

       

    }

    for(auto x : hmap){
        cout << x.first << " -> " << x.second << endl;
    }

    // int tamp = 0;
    // vector<int> ans;
    // for (const auto& pair : hmap) {
    //     if (tamp < k) {
    //         ans.push_back(pair.second);
    //         tamp++;
    //     } else {
    //         break; // Exit the loop after the first three elements
    //     }
    // }


    // vector<int> hans;

    // int tamp1 = 0;
    // for (auto rit = hmap.rbegin(); rit != hmap.rend() && tamp1 < k; ++rit, ++tamp1) {
    //     hans.push_back(rit->second);
    // }

    // for(auto z:hans){
    //     cout << z << " " ; 
    // }


    
        
}
int main(){

    vector<int> nums = {1,2,2,3,3};
    topKFrequent(nums,2);


    return 0;



     
}