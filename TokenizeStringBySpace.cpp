#include <vector>
#include <string>
#ifndef TokenizeStringsBySpace
#define TokenizeStringsBySpace

std::vector <std::string> TokenizeStringBySpace(std::string in){ //Tokenizing Strings By Spaces
    std::string s = in;
    std::string workin;
    char delimiter = ' ';
   std:: vector<std::string> ret;
   int i = 0;
    while(in[i]!='\0'){
        if(in[i]==delimiter) {
            ret.push_back(workin);
            workin.clear();
        }
        else workin.push_back(in[i]);
        i++;
    }
    return ret;
}
#endif