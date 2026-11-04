#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#ifdef IQUEUE_STATIC
    #define IQUEUE_API
#elif defined(_WIN32) || defined(__CYGWIN__) // Windows

    #ifndef IQUEUE_EXPORTS
        #define IQUEUE_API __declspec(dllimport)
    #else
        #define IQUEUE_API __declspec(dllexport)
    #endif // IntQ_EXPORTS
    
#else // Non-windows
    #define IQUEUE_API
#endif // IQUEUE_STATIC

class IntQueue {
private :
    // Variables
    int *nItems = nullptr ;
    int rear = 0 ;
    int front = 0 ;
    int nQueueSize ;
    
    // Queue Size Structure
    struct Limits {
        int minQ = 2 ;
        int maxQ = 100 ;
        int defaultQ = 5 ;
    }; Limits limits ;
    
    constexpr static int nErrorSize = 256 ;
    char sError[nErrorSize] {} ;
    bool bInited = false ;
public :
    // Constructor
    IntQueue(int IntQueueSize = 5) ;
    // Destructor
    ~IntQueue() ;
    
    // Copy & Assign
    
    // Copy Semantic
    // Copy Constructor
    IntQueue(const IntQueue &other) = delete ;
    // Copy Operator
    IntQueue &operator=(const IntQueue &other) = delete ;
    
    // Move Semantic
    // Move Construtor
    IntQueue(IntQueue &&other) = delete ;
    // Move Operator
    IntQueue &operator=(IntQueue &&other) = delete ;
    
    
    // Functions
    
    /**
     *  \brief Initializes Necessary Items and reserving space
     *  \returns true on success or false on failure; call getError() for more information.
     */
    bool init() ;
    
    // Setters
    
    /**
     *  Adds an Integer to the first available Items
     *  \returns true on success or false on failure; call getError() for more information.
     */
    bool addQ(int item) ;
    
    /**
     *  removes the first Integer from the Items
     *  \param item returns the removed Integer from the Items
     *  \returns true on success or false on failure; call getError() for more information.
     */
    bool removeQ(int &item) ;
    
    /**
     * \brief removes the first Integeer from the Items
     * \returns true on success or false on failure; call getError() for more information.
     */
    bool removeQ() ;
    
    /**
     *  \brief Sets the maximum amount of Item size buffer, init() should be called for re-allocationg and resetting,
     *         Initialization resets until init called again
     *  \returns true on success or false on failure; call getError() for more information.
     */
    bool setQueueSize(int size) ;
    
    // Getters
    // still not complete
    /**
     * \brief A function to check wether the Container is Full or not.
     * 
     * \returns true when Container is full or false when it has space
     */
    bool isFull() const ;
    
    /**
     * \brief A function to check wether the Container is empty or not
     * 
     * \returns true when Container is empty or false when it has Items
     */
    bool isEmpty() const ;
    
    /**
     * \brief  Retrieves the description of the last error, for debugging why
     *         previous calls failed.
     * \param  info Set to point to the last error description.
     */
    void getError(const char *&info) const ;
    
    /**
     * \brief  Retrieves the description of the last error, for debugging why
     *         previous calls failed.
     * \param  info Set to point to the last error description.
     */
    const char *getError() const ;
    
    /**
     * \brief Get the Max IntQueue Size object
     */
    int getMaxQueueSize() const ;
    /**
     * \brief Get the Min IntQueue Size object
     */
    int getMinQueueSize() const ;
};

#endif // CONTAINER_HPP
