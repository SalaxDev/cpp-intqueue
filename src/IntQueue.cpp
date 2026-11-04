#include "IntQueue.hpp"
#include <cstring>
#include <cstdio>
#include <new>


// Constructor
IntQueue::IntQueue(int queueSize) {
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
IntQueue::~IntQueue() {
    if (nItems) {
        delete[] nItems ;
        nItems = nullptr ;
    }
}

// Functions
bool IntQueue::init() {
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
bool IntQueue::addQ(int item) {
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

bool IntQueue::delQ(int &item) {
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

bool IntQueue::delQ() {
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

bool IntQueue::setQueueSize(int size) {
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
bool IntQueue::isFull() const {
    int newFront = (front + 1) % nQueueSize ;
    if (newFront == rear) {
        return true ;
    } return false ;
}

bool IntQueue::isEmpty() const {
    if (rear == front) {
        return true ;
    } return false ;
}

void IntQueue::getError(const char *&info) const {
    info = sError ;
}

const char *IntQueue::getError() const {
    return sError ;
}

int IntQueue::getMaxQueueSize() const {
    return limits.maxQ ;
}

int IntQueue::getMinQueueSize() const {
    return limits.minQ ;
}
