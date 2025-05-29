#ifndef SMARTPTR_H
#define SMARTPTR_H

#include <memory>

template <typename T>
class smart_ptr {
    T* obj;
public:
    explicit smart_ptr(T* obj) : obj(obj) {}
    ~smart_ptr() { delete obj; }

    T* operator->() { return obj; }
    T& operator*() { return *obj; }

    // Запрет копирования
    smart_ptr(const smart_ptr&) = delete;
    smart_ptr& operator=(const smart_ptr&) = delete;
};


#endif // SMARTPTR_H
