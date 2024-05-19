# Dynamic Array Implementation in C++

This repository contains a template-based dynamic array implementation in C++. The dynamic array, implemented as a `Vector` class, supports various operations like adding, removing, and accessing elements both at the end and at specific positions.

## Files

- `dynamic_arr.h`: Header file containing the `Vector` class template declarations.
- `dynamic_array_implementation.hpp`: Header file containing the `Vector` class template definitions.
- `main.cpp`: Main file containing a demonstration of how to use the `Vector` class.

## Features

- `push_back`: Add elements at the end of the vector.
- `push_front`: Add elements at the front of the vector.
- `pop_back`: Remove elements from the end of the vector.
- `pop_front`: Remove elements from the front of the vector.
- `insert`: Insert elements at specific positions.
- `remove`: Remove elements from specific positions.
- `shrink`: Shrink the capacity to fit the current size.
- `reserve`: Reserve memory to optimize memory usage.
- `print_vector`: Print all elements in the vector.
- Overloaded `[]` operator for element access.

## Usage

1. Clone the repository:

    ```sh
    git clone https://github.com/JorHaroyan/Dynamic-Array-Implementation.git
    cd dynamic-array
    ```

2. Compile the code:

    ```sh
    g++ main.cpp -o dynamic_array
    ```

3. Run the executable:

    ```sh
    ./dynamic_array
    ```

## Example

Here is an example of how to use the `Vector` class:

```cpp
#include "dynamic_arr.h"

int main() {
    Vector<int> v1;

    v1.push_back(12);       
    v1.push_back(54);       
    v1.push_back(3, 4);     
    v1.pop_back();          
    v1.pop_back(2);         
    v1.push_front(333);     
    // v1.pop_front(3);     // Uncomment to remove the first three elements
    v1.insert(88, 2);       
    v1.insert(5, 2, 0);     
    v1.remove(2);           
    v1.remove(0);           
    v1.remove(6);           
    v1.remove(0, 2);        
    v1.shrink();            
    std::cout << "capacity: " << v1.get_capacity() << std::endl;

    const int size = 3;
    const int arr[size] = {888, 555, 323};
    v1.push_back(arr, size); 

    v1.print_vector();       
    std::cout << v1[2] << std::endl; 

    return 0;
}
