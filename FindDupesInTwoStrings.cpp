#include<Vector>
#include<String>
#include<iostream>
#ifndef FindDuplicatesInTwoStrings
#define FindDuplicatesInTwoStrings
vector<char> FindDupesInTwoStrings(string in1, string in2){
    vector<char> working;
    for(int i = 0; i<in1.size(); i++){
        for(int j = 0; j<in2.size();j++){
            if(in1[i] == in2[j]) working.push_back(in1[i]);
        }
    }
    if(working.size() == 0){
        cout << "No Dupes Found" << endl;
    }
    return working;
}
#endif