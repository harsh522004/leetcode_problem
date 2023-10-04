#include<iostream>
#include <unordered_map>
using namespace std;
bool isAnagram(string s, string t) {

    bool hasNonZeroKey = false;
     unordered_map<char,int> Smap ;
     if(s.size() != t.size()){
        return false;
     }


     //cout << "Loop For String S" << endl;

     for(int i =0 ; i<s.size() ; i++){

        if(Smap.find(s[i]) == Smap.end()){
            Smap[s[i]] = 1;
        }
        else{
            int val =  Smap[s[i]];
            Smap[s[i]] = val+1;
        }
     }

     //cout << "After Cretae Map for S" << endl;

    // for (const auto& pair : Smap) {
    //     cout << pair.first << ": " << pair.second << endl;
    // }

     //cout << "Loop For String t" << endl;


     for(int i =0 ; i<t.size() ; i++){
        if(Smap.find(t[i]) == Smap.end() ){
            return false;
        }
        else{
            int val =  Smap[t[i]];
            Smap[t[i]] = val-1;

        }
     }

    //  cout << "After Cheking Map for t" << endl;

    //  for (const auto& pair : Smap) {
    //     cout << pair.first << ": " << pair.second << endl;
    // }

    for (const auto& pair : Smap) {
        if (pair.second != 0) {
            
            return false;
        }
    }
    return true;

        
}
int main(){
    string str1 = "Harsh";
    string str = "car";
    bool a = isAnagram(str1,str);
    cout << a << endl;
}
