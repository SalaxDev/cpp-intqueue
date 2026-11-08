<div align="center">
  
# cpp-intqueue

</div>

> [!NOTE]
> In Development ⚒️

---

**C++ Integer Queue** - a small, dependency-free fixed-capacity FIFO queue of `int`, implemented as a ring buffer.

Tested In: [![C++17 / C++20](https://img.shields.io/badge/C%2B%2B-17%20%2F%2020-blue.svg)](#)
<br>
License: [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE.txt)


<div align="center">

  
  [<kbd>Features</kbd>](#features) · [<kbd>Prerequisites</kbd>](#prerequisites) · [<kbd>Quick start</kbd>](#quick-start) · [<kbd>API</kbd>](#api) ·
  [<kbd>Build</kbd>](#build) · [<kbd>How to use</kbd>](#how-to-use) · [<kbd>Limitations</kbd>](#limitations) · [<kbd>Download</kbd>](#download)
</div>

<a id="features"></a>
## ⚙️ Features
- Clean, minimal codebase
- Documented
- RAII
- Cross platform
- Dependecy free

<a id="prerequisites"></a>
## 🛠️ Prerequisites
- Cmake 3.19+
- A compiler that supports C++17/C++20 (g++ | clang++ | msvc)

<a id="quick-start"></a>
## 🚀 Quick Start
<details>
  <summary>Click to expand</summary>

  ```cpp
#include "IntQueue.hpp"
#include <iostream>

void log(IntQueue &q) {
    bool empty ; // Logging
    std::cout << "Capacity: " << q.getQueueStoredSize() << std::endl ;
    std::cout << "First Item: " << q.getFirstQueueItem(empty) << std::endl ;
    if (empty) {
        std::cout << "Container is empty" << std::endl ;
    }
    std::cout << "Last Item: " << q.getLastQueueItem(empty) << std::endl ;
    if (empty) {
        std::cout << "Container is empty" << std::endl ;
    }
}

int main(int argc, const char** argv) {
    IntQueue q(5) ;
    std::cout << q.getQueueSize() << std::endl ;
    // Initializing Container and checking for errors
    if (!q.init()) {
        std::cout << "Error: " << q.getError() << std::endl ;
        return 1 ;
    }
    
    std::cout << "Queue Minimum Size Limit: " << q.getMinQueueSize() << std::endl ;
    std::cout << "Queue Maximum Size Limit: " << q.getMaxQueueSize() << std::endl ;
    
    for (int i = 10; !q.isFull(); i *= 2) {
        // Adding Item to Container
        if (!q.addQ(i)) {
            std::cout << "Error: " << q.getError() << std::endl ;
        }
        
        log(q) ;
    }
    
    // Trying to add another item
    if (!q.addQ(200)) {
        std::cout << "Error: " << q.getError() << std::endl ;
    }
    
    // Removing Stored Integers
    while (!q.isEmpty()) {
        int item ;
        if (!q.removeQ(item)) {
            std::cout << "Error: " << q.getError() << std::endl ;
        }
        std::cout << "Removed Item: " << item << std::endl ;
    }
    
    // Trying to Remove another item
    if (!q.removeQ()) {
        std::cout << "Error: " << q.getError() << std::endl ;
    }
    
    // Resizing the Container
    if (!q.setQueueSize(100)) {
        std::cout << "Error: 1" << q.getError() << std::endl ;
    }
    std::cout << q.getQueueSize() << std::endl ;
    
    return 0 ;
}
  ```
</details>

<a id="api"></a>
## 🧩 API
<table>
  <thead>
    <tr>
      <th>Function Name</th>
      <th>Description</th>
    </tr>
  </thead>

  <tbody>
    <tr>
      <td><code>bool init()</code></td>
      <td>Initializes necessary variable including Queue container and heap allocation, returns true on success or failure on false</td>
    </tr>
    <tr>
      <td><code>bool addQ(int item)</code></td>
      <td>Adds Integer variable to the container, returns true in success or false if it the container is full</td>
    </tr>
    <tr>
      <td><code>bool removeQ(int &item)</code></td>
      <td>Remove the first item in the container and returns the removed item, returns true in success or false if the container is empty</td>
    </tr>
    <tr>
      <td><code>bool removeQ()</code></td>
      <td>same as <code>bool removeQ(int &item)</code> but it won't return the removed item</td>
    </tr>
    <tr>
      <td><code>bool setQueueSize(int size)</code></td>
      <td>Set how much the container can hold before it gets full, <code>IntQueue::init()</code> should be called after for initializing container capacity, returns true on success or false on failure</td>
    </tr>
    <tr>
      <td><code>bool isFull() const</code></td>
      <td>A function to check whether the container is full or not, returns true if it's full or false if there's still room </td>
    </tr>
    <tr>
      <td><code>bool isEmpty() const</code></td>
      <td>A function to check whether the container is Empty or not, returns true if it's empty or false if there's still room</td>
    </tr>
    <tr>
      <td><code>void getError(const char *&info) const</code></td>
      <td>Points to a fixed buffer size in the container for debugging why previous call failed</td>
    </tr>
    <tr>
      <td><code>const char *getError() const</code></td>
      <td>Same as <code>void getError(const char *&info) const</code> but instead it returns a pointer to the error buffer</td>
    </tr>
    <tr>
      <td><code>int getMaxQueueSize() const</code></td>
      <td>Returns the Maximum allowed size in the container</td>
    </tr>
    <tr>
      <td><code>int getMinQueueSize() const</code></td>
      <td>Returns the Minimum allowed size in the container</td>
    </tr>
  </tbody>
</table>


<a id="build"></a>
## ⚒️ How to Build
  1. first make sure you have [Prerequisites](#prerequisites)
  2. Clone or download the source project
  3. Open terminal and type this (root project directory) :
  4. `cmake -S . -B build -DCMAKE_BUILD_TYPE=Release`
  5. `cmake --build build`
  6. if you wish to have static library, add `-DBUILD_SHARED_LIBS=OFF`
  7. install it using `cmake --install build` or also add `--prefix="C:/Your/path"`
<a id="how-to-use"></a>
## ✨How to use
[Download]() or [Build]() the library <br>
in your `cmakelists.txt`:
```
find_package(iqueue 1.0.0 CONFIG REQUIRED)

# Linking to your program
target_link_libraries(your_program PRIVATE iqueue::iqueue)
```
<a id="limitations"></a>
## ⭕ Limitations
IntQueue container have **fixed size** capacity, which makes you call initialization after you change the capacity
<a id="download"></a>
## 🌐 Download
alternatively you can download the compiled library and use it : <br>
<sup>Windows 7+ SP1 64 Bit:</sup> [![Latest Release](https://img.shields.io/github/v/release/salaxdev/cpp-intqueue?style=for-the-badge&color=blue)](https://github.com/salaxdev/cpp-intqueue/releases/latest) <br>
> [!NOTE]
> Pre-Compiled versions of library in the release are not **Code-Signed**, which the library might be Flagged by Anti Virus, if that happen, exclude the folder or file in the settings
