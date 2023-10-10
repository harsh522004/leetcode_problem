#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}} ; 
    int m = 3;
    int n = 3;

    vector<int> row(m,1);
    vector<int> col(n,1);

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(matrix[i][j] == 0){
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(row[i] == 0 || col[j] == 0){
                matrix[i][j] = 0;
            }
        }
    }


    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cout <<  matrix[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;



        
    
}
