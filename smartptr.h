#ifndef SMARTPTR_H
#define SMARTPTR_H

template <typename T>
class SmartPtr {
    T* obj;
public:
    explicit SmartPtr(T* obj = nullptr) : obj(obj) {}
    ~SmartPtr() { delete obj; }

    // Запрет копирования
    SmartPtr(const SmartPtr&) = delete;
    SmartPtr& operator=(const SmartPtr&) = delete;

    // Поддержка перемещения
    SmartPtr(SmartPtr&& other) noexcept : obj(other.obj) {
        other.obj = nullptr;
    }

    SmartPtr& operator=(SmartPtr&& other) noexcept {
        if (this != &other) {
            delete obj;
            obj = other.obj;
            other.obj = nullptr;
        }
        return *this;
    }

    T* operator->() const { return obj; }
    T& operator*() const { return *obj; }
    T* get() const { return obj; }

    explicit operator bool() const { return obj != nullptr; }
};

#endif
