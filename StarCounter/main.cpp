//
//  main.cpp
//  StarCounter
//
//  Created by Rodrigo Pigatti Marroquim on 11/11/15.
//  Copyright (c) 2015 Rodrigo Pigatti Marroquim. All rights reserved.
//

#include <iostream>

struct DIGIT {
    short value;
    DIGIT *nextDigit;
    
    void increment() {
        if (value < 9) {
            this->value++;
        } else {
            this->value = 0;
            
            if (this->nextDigit == NULL) {
                DIGIT nextDigit = {};
                this->nextDigit = &nextDigit;
            }
            
            this->nextDigit->increment();
        }
    }
    
    std::string toString () {
        std::string nextDigitRepresentation = "";
        
        if (this->nextDigit != NULL) {
            nextDigitRepresentation = this->nextDigit->toString();
        }
        
        return nextDigitRepresentation + std::to_string(this->value);
    }
    
} decimal_digit_representation;


int main(int argc, const char * argv[]) {
    DIGIT digitChain;
    
    int i = 0;
    while (i < 123456789) {
        digitChain.increment();
        i++;
    }
    
    std::cout << digitChain.toString();
    
    return 0;
}
