#include <cstdio>
#include <cstring>
#include <SDL3/SDL.h>
#include "Container.hpp"

int main(int argc, const char** argv) {
    Queue q ;
    q.init() ;
    printf("Error: %s\n", q.getError()) ;
    q.init() ;
    printf("Error: %s\n", q.getError()) ;
    q.setQueueSize(-99999999) ;
    printf("Error: %s\n", q.getError()) ;
    q.setQueueSize(9999) ;
    printf("Error: %s\n", q.getError()) ;
    q.init() ;
    printf("Error: %s\n", q.getError()) ;
    
    return 0 ;
}