#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T>
class Vector
{
public:
    
    Vector();   
    ~Vector();  

    void push_back(const T& val);              
    void push_back(const T& val, int count);    
    void push_back(const T* arr, int length);   

    void pop_back();                
    void pop_back(size_t count);    

    void push_front(const T& val);              
    void push_front(const T& val, int count);  

    void pop_front();           
    void pop_front(int count);  

    void insert(const T& val, int pos);             
    void insert(const T& val, int count, int pos);  
    void remove(int pos);                           
    void remove(int pos, int count);                

    void shrink();                          
    size_t get_size() const;                
    size_t get_capacity() const;           
    const T& operator[](int index) const;   
    void reserve(int size);                 
    void print_vector() const;              

private:
    T* m_arr;           
    size_t m_size;     
    size_t m_capacity;  

};

#include "dynamic_array_implementation.hpp"

#endif //VECTOR_H
