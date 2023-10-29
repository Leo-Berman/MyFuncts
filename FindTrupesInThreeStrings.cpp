#include<Vector>
#include<string>
#include<iostream>
using namespace std;
#ifndef FindTruplicatesInThreeStrings
#define FindTruplicatesInThreeStrings
vector<char> FindTrupesInThreeStrings(string in1, string in2,string in3){
    vector<char> working;
    for(int i = 0; i<in1.size(); i++){
        for(int j = 0; j<in2.size();j++){
            for(int k = 0; k<in3.size();k++){
                if((in1[i]==in2[j]) && (in1[i]==in3[k])) working.push_back(in1[i]); 
            }
        }
    }
    if(working.size() == 0){
        cout << "No Trupes Found" << endl;
    }
    return working;
}
#endif