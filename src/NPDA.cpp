#include "NPDA.h"
#include <iostream>

npda::npda() {}

void npda::reset() {
    while (!stack.empty()) {
         stack.pop();
    }
}

 bool npda::read(std::string& input) { 
    int len = input.length();
    if (len == 0) {
        return true; // empty string palindrome
    }

    int mid = len / 2;
    
    // Push first half onto the stack
    for (int i = 0; i < mid; ++i) {
        stack.push(input[i]);
        std::cout << "-Read: " << input[i] << " | Action: Push " << input[i] << " | Stack Top: " << stack.top() << std::endl;
    }

    // If length is odd, skip the middle character
    int start_second_half = (len % 2 == 0) ? mid : mid + 1;
    if (len % 2 != 0) {
            std::cout << "-Read: " << input[mid] << " | Action: Skip middle char" << std::endl;
    }


    // Match second half with stack
    for (int i = start_second_half; i < len; ++i) {
        if (stack.empty()) {
            return false; // More characters in second half than first
         }
        char top = stack.top();
        std::cout << "-Read: " << input[i] << " | Action: Pop and Compare | Stack Top: " << top << std::endl; 
        stack.pop();
        if (input[i] != top) {
            return false; // Mismatch
            }
}

    return stack.empty();
} 