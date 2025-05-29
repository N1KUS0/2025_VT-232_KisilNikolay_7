#ifndef SMART_PTR_H
#define SMART_PTR_H

template <typename T>
class smart_ptr {
    T* ptr;

public:
    // Конструктор
    explicit smart_ptr(T* p = nullptr) : ptr(p) {}

    // Перемещающий конструктор
    smart_ptr(smart_ptr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // Перемещающее присваивание
    smart_ptr& operator=(smart_ptr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // Удаляем копирование
    smart_ptr(const smart_ptr&) = delete;
    smart_ptr& operator=(const smart_ptr&) = delete;

    // Доступ к объекту
    T* operator->() const { return ptr; }
    T& operator*() const { return *ptr; }

    // Деструктор
    ~smart_ptr() { delete ptr; }

    // Получение указателя (по необходимости)
    T* get() const { return ptr; }
};

#endif // SMART_PTR_H
