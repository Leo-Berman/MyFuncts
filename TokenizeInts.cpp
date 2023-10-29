#include<cmath>
#include<vector>
#ifndef TokenizeInt
#define TokenizeInt
// Function to tokenize integers ended up being unused
std::vector <int> TokenizeInts(int num){
    
    // return vector
    std::vector <int> ret;

    // find number of digits
    int digits = int(log10(num) + 1);

    // declaration of numbers to divide by and get remainder of 
    int divisor = 1;
    int remainder = 10;
    for(int i = 0; i < digits; i++){

        // adding the digit
        ret.push_back(num/divisor % remainder);
        
        // incrementing to the next digit
        divisor = divisor*remainder;
    }
    return ret;
}

#endif