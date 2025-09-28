#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
template <typename T>
class Array
{
    private:
    T *arr;
    size_t n;
    public:
        Array()
        {
            this->n = 0;
            this->arr = new T[0];
        }
        Array(size_t n)
        {
            this->n = n;
            this->arr = new T[n];
        }
        Array(const Array &obj)
        {
            this->n = obj.n;
            this->arr = new T[obj.n];
            for (size_t i = 0; i < obj.n; i++)
            {
                this->arr[i] = obj.arr[i];
            }
        }
        Array &operator=(const Array &obj)
        {
            if (this != &obj)
            {
                delete[] this->arr;
                this->n = obj.n;
                this->arr = new T[obj.n];
                for (size_t i = 0; i < obj.n; i++)
                {
                    this->arr[i] = obj.arr[i];
                }
            }
            return (*this);
        }
        ~Array()
        {
            delete[] arr;
        }
        size_t size() const
        {
            return (n);
        }
        T &operator[] (const size_t i) const
        {
            if(i >= n)
                throw std::exception();
            return arr[i];
        }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
};

#endif