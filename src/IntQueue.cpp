#include "Container.hpp"
#include <cstring>
#include <cstdio>
#include <new>


// Constructor
Queue::Queue(int queueSize) {
    if (queueSize < limits.minQ) {
        printf("Queue Constructor Ignored queue size because of a number lower than %d, default value size applies(%d).\n", limits.minQ, limits.defaultQ) ;
        nQueueSize = limits.defaultQ ;
        return ;
    } else if (queueSize > limits.maxQ) {
        printf("Queue Constructor Ignored queue size because of a number higher than %d, default value size applies(%d).\n", limits.maxQ, limits.defaultQ) ;
        nQueueSize = limits.defaultQ ;
        return ;
    }
    
    nQueueSize = queueSize ;
}


// Destructor
Queue::~Queue() {
    if (nItems) {
        delete[] nItems ;
        nItems = nullptr ;
    }
}

// Functions
bool Queue::init() {
    if (nItems) {
        delete[] nItems ;
        nItems = nullptr ;
    }
    nItems = new (std::nothrow) int[nQueueSize] ;
    if (!nItems) {
        strncpy(sError, "Failed to Allocate enough space for Items size, probable insufficient memory space", nErrorSize - 1) ;
        sError[nErrorSize - 1] = '\0' ;
        bInited = false ;
        return false ;
    }
    
    
    rear = front = 0 ;
    bInited = true ;
    return true ;
}


// Setters
bool Queue::addQ(int item) {
    if (!bInited) {
        strncpy(sError, "Initialization either has been failed or not started, make sure you've called Queue::init() before using", nErrorSize - 1) ;
        sError[nErrorSize - 1] = '\0' ;
        return false ;
    } else if (isFull()) {
        snprintf(sError, nErrorSize, "No enough space in Container to add [%d]", item) ;
        return false ;
    }
    
    nItems[front] = item ;
    front = (front + 1) % nQueueSize ;
    
    return true ;
}

bool Queue::delQ(int &item) {
    if (!bInited) {
        strncpy(sError, "Initialization either has been failed or not started, make sure you've called Queue::init() before using", nErrorSize - 1) ;
        sError[nErrorSize - 1] = '\0' ;
        return false ;
    } else if (isEmpty()) {
        strncpy(sError, "No Items left in Container", nErrorSize - 1) ;
        sError[nErrorSize - 1] = '\0' ;
        return false ;
    }
    
    item = nItems[rear] ;
    rear = (rear + 1) % nQueueSize ;
    
    return true ;
}

bool Queue::delQ() {
    if (!bInited) {
        strncpy(sError, "Initialization either has been failed or not started, make sure you've called Queue::init() before using", nErrorSize - 1) ;
        sError[nErrorSize - 1] = '\0' ;
        return false ;
    } else if (isEmpty()) {
        strncpy(sError, "No Items left in Container", nErrorSize - 1) ;
        sError[nErrorSize - 1] = '\0' ;
        return false ;
    }
    
    rear = (rear + 1) % nQueueSize ;
    
    return true ;
}

bool Queue::setQueueSize(int size) {
    if (size < limits.minQ) {
        snprintf(sError, nErrorSize, "Queue size cannot be lower than %d", limits.minQ) ;
        return false ;
    } else if (size > limits.maxQ) {
        snprintf(sError, nErrorSize, "Queue size cannot be higher than %d", limits.maxQ) ;
        return false ;
    }
    
    nQueueSize = size ;
    bInited = false ;
    return true ;
}


// Getters
bool Queue::isFull() const {
    int newFront = (front + 1) % nQueueSize ;
    if (newFront == rear) {
        return true ;
    } return false ;
}

bool Queue::isEmpty() const {
    if (rear == front) {
        return true ;
    } return false ;
}

void Queue::getError(const char *&info) const {
    info = sError ;
}

const char *Queue::getError() const {
    return sError ;
}

int Queue::getMaxQueueSize() const {
    return limits.maxQ ;
}

int Queue::getMinQueueSize() const {
    return limits.minQ ;
}
