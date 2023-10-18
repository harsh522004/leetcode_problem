// pascals triangle

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int row = 6;
    int count = 0;
    vector<vector<int>> pascals;


    // approach 1
    
    // while(count < row){
    //     if(count == 0){
    //         vector<int> tamp = {1};
    //         pascals.push_back(tamp);
    //     }
    //     else if (count == 1){
    //         vector<int> tamp = {1,1};
    //         pascals.push_back(tamp);
    //     }
    //     else{
    //         vector<int> old = pascals[count-1];
    //         vector<int> tamp;
    //         tamp.push_back(1);
    //         for(int i = 1 ; i < old.size() ; i++){
    //             int sum = old[i-1]+old[i];
    //             tamp.push_back(sum);
    //         }
    //         tamp.push_back(1);
    //         pascals.push_back(tamp);
    //     }
    //     count++;
    // }    

    for(auto x: pascals){
        for(auto y: x){
            cout << y << " " ;
        }
        cout << endl;
    }
    return 0;

}