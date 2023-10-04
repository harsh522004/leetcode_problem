// spiral metrix problem
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        if (matrix.empty() || matrix[0].empty()) {
            return ans;
        }

        int row_size = matrix.size();
        int col_size = matrix[0].size();

        int row_str = 0;
        int col_str = 0;
        int row_end = row_size - 1;
        int col_end = col_size - 1;

        while (row_str <= row_end && col_str <= col_end) {

            for (int i = col_str; i <= col_end; i++) {
                ans.push_back(matrix[row_str][i]);
            }

            row_str = row_str + 1;

            for (int i = row_str; i <= row_end; i++) {
                ans.push_back(matrix[i][col_end]);
            }

            col_end = col_end - 1;

            if (row_str <= row_end) {
                for (int i = col_end; i >= col_str; i--) {
                    ans.push_back(matrix[row_end][i]);
                }
            }

            row_end = row_end - 1;

            if (col_str <= col_end) {
                for (int i = row_end; i >= row_str; i--) {
                    ans.push_back(matrix[i][col_str]);
                }
            }

            col_str = col_str + 1;
        }

        return ans;
    }
};
