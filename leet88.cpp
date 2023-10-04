#include <iostream>
#include <queue>
#include<vector>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> nums1 = {0};
    int m = 0;
    vector<int> nums2 ={1} ; 
    int n = 1;

    int i = 0;
    int j = 0;
    cout << "Loop start " << endl;
    while(j < n){
        if(nums1[i] > nums2[j]){
             cout << "cond 1 " << endl;
            int tamp = nums1[i];
            nums1[i] = nums2[j];
            minHeap.push(tamp);
            j++;
        }
        else if( ((nums1[i] < nums2[j]) && (i < m))  || (nums1[i] == nums2[j])){
            cout << "cond 2 " << endl;
            i++;
        } 
        else if(((nums1[i] < nums2[j]) && (i >= m))){
            cout << "cond 3 " << endl;
            nums1[i] = nums2[j];
            i++;
            j++;
        }     
    }

    

    int indicate = i;
    cout << "after first Loop" << endl;
     for(auto x:nums1){
        cout << x << "  " ;
    }

    cout << endl;
 

    //after this minHeap Ready and we Covered portion N from nums2



    int ij =0;
    cout << indicate << endl;
    while(ij < indicate){

        cout << "index : " << ij << endl;
        if(minHeap.empty()){
            break;
        }
        int top = minHeap.top();
        cout << "Top :" << top << endl;
        if(nums1[ij] <= top){
            ij++;
        }
        else if(nums1[ij] > top){

            cout << "When nums is greater then top " << endl;
            cout << "nums : " << nums1[ij] << endl;
            cout << "top : " << minHeap.top() << endl;
            int tamp = nums1[ij];
            nums1[ij] = top;
            minHeap.pop();
            minHeap.push(tamp);
            cout << "nums : " << nums1[ij] << endl;
            cout << "top : " << minHeap.top() << endl;
            ij++;
        }

    }

     cout << "after second  Loop" << endl;
     for(auto x:nums1){
        cout << x << "  " ;
    }
    cout << endl;


    // Now turn for all zeroes
    for(int i = indicate ; i < m+n ; i++ ){
        int top = minHeap.top();
        nums1[i] = top;
        minHeap.pop();
    }



    for(auto x:nums1){
        cout << x << "  " ;
    }
        
    
   

    return 0;
}
