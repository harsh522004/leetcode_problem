<<<<<<< HEAD
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> grouped;

//         for (const string& str : strs) {
//             string sortedStr = str;
//             sort(sortedStr.begin(), sortedStr.end());
//             grouped[sortedStr].push_back(str);
//         }

//         vector<vector<string>> result;

//         for (const auto& entry : grouped) {
//             result.push_back(entry.second);
//         }

//         return result;
//     }
// };


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


int main() {

    vector<string> input1 = {"eat","tea","tan","ate","nat","bat","c","c"};
    vector<string> input ;

     for (const string& str : input1) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        input.push_back(sortedStr);
    }

    for(auto it: input){
        cout << it << " " ;
    }
    cout << endl;


    
    
    unordered_map<string, vector<int>> grouped;
    
    for(int i = 0 ; i < input.size() ; i++){
        string word = input[i];
        grouped[word].push_back(i);

    }

    

    for (auto& x : grouped) {
    cout << x.first << ": ";
    for (const int& word : x.second) {
        cout << word << ", ";
    }
    cout << endl;
}
    vector<vector<string>> result;
    
    for (const auto& entry : grouped) {
        vector<string> tamp;
        for(auto &it:entry.second){
            tamp.push_back(input1[it]);
        }
        result.push_back(tamp);
    }


    
    
    for (const std::vector<std::string>& innerVector : result) {
        std::cout << "(";
        for (size_t i = 0; i < innerVector.size(); ++i) {
            std::cout << innerVector[i];
            if (i < innerVector.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ")" << std::endl;
    }
    
    return 0;
}
=======
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> grouped;

//         for (const string& str : strs) {
//             string sortedStr = str;
//             sort(sortedStr.begin(), sortedStr.end());
//             grouped[sortedStr].push_back(str);
//         }

//         vector<vector<string>> result;

//         for (const auto& entry : grouped) {
//             result.push_back(entry.second);
//         }

//         return result;
//     }
// };


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


int main() {

    vector<string> input1 = {"eat","tea","tan","ate","nat","bat","c","c"};
    vector<string> input ;

     for (const string& str : input1) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        input.push_back(sortedStr);
    }

    for(auto it: input){
        cout << it << " " ;
    }
    cout << endl;


    
    
    unordered_map<string, vector<int>> grouped;
    
    for(int i = 0 ; i < input.size() ; i++){
        string word = input[i];
        grouped[word].push_back(i);

    }

    

    for (auto& x : grouped) {
    cout << x.first << ": ";
    for (const int& word : x.second) {
        cout << word << ", ";
    }
    cout << endl;
}
    vector<vector<string>> result;
    
    for (const auto& entry : grouped) {
        vector<string> tamp;
        for(auto &it:entry.second){
            tamp.push_back(input1[it]);
        }
        result.push_back(tamp);
    }


    
    
    for (const std::vector<std::string>& innerVector : result) {
        std::cout << "(";
        for (size_t i = 0; i < innerVector.size(); ++i) {
            std::cout << innerVector[i];
            if (i < innerVector.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << ")" << std::endl;
    }
    
    return 0;
}
>>>>>>> c9eea5002a11dd5daafd919f004578bbd2730afd
