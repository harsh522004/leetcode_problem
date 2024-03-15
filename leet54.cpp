#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){

    vector<vector<int>>  matrix = { {1,2,3},{4,5,6},{7,8,9}};

    map< pair<int,int> , bool> hmap;
    int row_count = 3;
    int col_count = 4;

    int row = 0;
    int col = 0;

    while(true){

        cout << matrix[row][col] << "  " ;
        

        if(col < col_count && hmap[make_pair(row,col)] != 1 ){



        }
        else if( row < row_count && hmap[make_pair(row,col)] != 1 ){
            
        }
        else if(col > 0 && hmap[make_pair(row,col)] != 1 ){
            
        }
        else if(row > 0 && hmap[make_pair(row,col)] != 1 ){
            
        }

    }

}