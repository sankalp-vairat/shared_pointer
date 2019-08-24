#include <iostream>
using namespace std;

template <typename T>
class Shared_ptr {
    private:
        T* m_ptr;
        int counter = 0;
        int *p_counter = &counter;

    public:

        Shared_ptr() {
            ++(*p_counter);
        }

        Shared_ptr(T *ptr) {
            ++(*p_counter);
            m_ptr = ptr;
        }
        Shared_ptr& operator=(Shared_ptr& ptr) {
            ++(*ptr.p_counter);
            delete p_counter;
            p_counter = ptr.p_counter;
            return *this;
        }

        ~Shared_ptr() {
            (*p_counter)--;
            if(*p_counter == 0) {
                delete p_counter;
                delete m_ptr;
            }
        }
};
