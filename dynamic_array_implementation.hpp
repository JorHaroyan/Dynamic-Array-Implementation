#ifndef DYNAMIC_ARRAY_IMPLEMENTATION
#define DYNAMIC_ARRAY_IMNPLEMENTATION


template <typename T>
void Vector<T>::push_back(const T* arr, int length) {
    for (int i = 0; i < length; ++i) {
        push_back(arr[i]);
    }
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
    return m_arr[index];
}

template <typename T>
Vector<T>::Vector() {
    m_size = 0;
    m_capacity = 1;
    m_arr = new T[m_capacity];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] m_arr;
}

template <typename T>
void Vector<T>::push_back(const T& val) {
    ++m_size;
    if (m_size > m_capacity) {
        m_capacity *= 2;
        T* new_arr = new T[m_capacity];

        for (int i = 0; i < m_size - 1; ++i) {
            new_arr[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = new_arr;
        new_arr = nullptr;
    }
    m_arr[m_size - 1] = val;
}

template <typename T>
void Vector<T>::print_vector() const {
    for (size_t i{}; i < m_size; ++i) {
        std::cout << m_arr[i] << " ";
    }
    std::cout << "\n";
}

template <typename T>
void Vector<T>::reserve(int size) {
    if (size <= m_capacity) return ;

    T* new_arr = new T[size];

    for (int i = 0; i < m_size; ++i) {
        new_arr[i] = m_arr[i];
    }
    delete[] m_arr;
    m_capacity = size;
    m_arr = new_arr;
}

template <typename T>
void Vector<T>::push_back(const T& val, int count) {
    if (m_size + count > m_capacity) {
        this->reserve(m_size + count);
    }
    for (int i = 0; i < count; ++i) {
        m_arr[m_size++] = val;
    }
}

template <typename T>
void Vector<T>::pop_back() {
    --m_size;
}

template <typename T>
void Vector<T>::pop_back(size_t count) {
    if (count > m_size) {
        return ;
    }
    m_size -= count;
}

template <typename T>
void Vector<T>::push_front(const T& val) {
    ++m_size;
    if (m_size > m_capacity) {
        m_capacity *= 2;
        T* new_arr = new T[m_capacity];
        for (int i = 1; i < m_size; ++i) {
            new_arr[i] = m_arr[i - 1];
        }
        delete[] m_arr;
        m_arr = new_arr;
    } else {
        for (int i = m_size - 1; i >= 0; --i) {
            m_arr[i] = m_arr[i - 1];
        }
    }
    m_arr[0] = val;
}

template <typename T>
void Vector<T>::push_front(const T& val, int count) {
    for (int i = 0; i < count; ++i) {
        this->push_front(val);
    }
}

template <typename T>
void Vector<T>::pop_front() {
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = m_arr[i + 1];
    }
    pop_back();
}

template <typename T>
void Vector<T>::pop_front(int count) {
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = m_arr[i + count];
    }
    for (int i = 0; i < count; ++i) {
        this->pop_back();
    }
}

template <typename T>
void Vector<T>::insert(const T& val, int pos) {
    if (pos == 0) push_front(val);
    else if (pos == m_size + 1) push_back(val);

    else {
        ++m_size;
        for (int i = m_size - 1; i > pos; --i) {
            m_arr[i] = m_arr[i - 1]; 
        }
        m_arr[pos] = val;
    }
    
}

template <typename T>
void Vector<T>::insert(const T& val, int count, int pos) {
    if (pos == 0) push_back(val, count);
    if (pos == m_size + 1) push_back(val, count);
    
    else {
        m_size += count;
        reserve(count);
        for (int i = m_size - 1; i > pos; --i) {
            m_arr[i] = m_arr[i - count];
        }

        for (int i = pos; i < pos + count; ++i) {
            m_arr[i] = val;
        }
    }
}

template <typename T>
void Vector<T>::remove(int pos) {
    for (int i = pos; i < m_size - 1; ++i) {
        m_arr[i] = m_arr[i + 1];
    }
    pop_back();
}

template <typename T>
void Vector<T>::remove(int pos, int count) {
    for (int i = pos; i < m_size - count; ++i) {
        m_arr[i] = m_arr[i + count];
    }
    pop_back(count);
}

template <typename T>
void Vector<T>::shrink() {
    m_capacity = m_size;
}

template <typename T>
size_t Vector<T>::get_capacity() const {
    return m_capacity;
}

template <typename T>
size_t Vector<T>::get_size() const {
    return m_size;
}

#endif //DYNAMIC_ARRAY_IMNPLEMENTATION