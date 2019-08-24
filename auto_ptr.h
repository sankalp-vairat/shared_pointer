#ifndef AUTO_PTR_H
#define AUTO_PTR_H

#include <iostream>
using namespace std;

template <typename T>
class Auto_ptr {
    private:
        T* m_ptr;
    public:
        Auto_ptr(T* ptr = nullptr):m_ptr(ptr) {}

        ~Auto_ptr() {
            delete m_ptr;
        }

        T* operator*() {
            return *m_ptr;
        }

        T& operator->() {
            return m_ptr;
        }

        Auto_ptr(Auto_ptr<T>& a_ptr) {
                delete m_ptr;
                m_ptr = a_ptr.m_ptr;
                a_ptr = nullptr;
        }

        Auto_ptr<T>& operator=(Auto_ptr<T>& a_ptr) {
            if(*this == *a_ptr) {
                return *this;
            }
            delete m_ptr;
            m_ptr = a_ptr.m_ptr;
            a_ptr = nullptr
            return *this;
        }
};

#endif //AUTO_PTR_H
