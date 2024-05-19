#include "dynamic_arr.h"

int main() {
    Vector<int> v1;
    v1.push_back(12);       
    v1.push_back(54);       
    v1.push_back(3, 4);     
    v1.pop_back();
    v1.pop_back(2);
    v1.push_front(333);
    //v1.pop_front(3);
    v1.insert(88, 2);  
    v1.insert(5, 2, 0);
    v1.remove(2);
    v1.remove(0);
    v1.remove(6);
    v1.remove(0, 2);
    v1.shrink();
    std::cout << "capacity: " << v1.get_capacity() << std::endl;
    int const size = 3;
    int const arr[size] = {888, 555, 323};
    v1.push_back(arr, size);
    v1.print_vector();
    std::cout << v1[2] << std::endl;

    return 0;
}