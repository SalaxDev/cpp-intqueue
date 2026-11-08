#include "IntQueue.hpp"
#include <iostream>

int main(int argc, const char** argv) {
    // Creating the object and specify the total size
    IntQueue queue(10) ;
    // Initializing IntQueue Container and checking for errors in case of failure
    if (!queue.init()) {
        std::cout << "Error: " << queue.getError() << std::endl ;
    }
    
    // Adding and Removing
    queue.addQ(20) ;
    queue.addQ(30) ;
    queue.removeQ() ;
    
    // checking 
    
    return 0 ;
}