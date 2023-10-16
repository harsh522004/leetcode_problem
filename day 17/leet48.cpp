// Rotate Image
#include<iostream>
#include<vector>


 
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>>  matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    int n = matrix.size();
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            int tamp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tamp;
        }
    }

    for(auto x : matrix){
        for(auto y : x){
            cout << y << "  ";
        }
        cout << endl;
    }


    for(int row = 0 ; row < n ; row++ ){
        reverse(matrix[row].begin(),matrix[row].end());

    }
    for(auto x : matrix){
        for(auto y : x){
            cout << y << "  ";
        }
        cout << endl;
    }
    
    return 0;
}
