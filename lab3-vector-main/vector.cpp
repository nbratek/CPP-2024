#include <algorithm>
#include <stdexcept>
#include <utility> // std::swap()
#include "vector.h"

//#warning "Metody sa do zaimplementowania. Instrukcja w pliku naglowkowym" // po zaimplementowaniu sugeruje usuniecie tej linijki - nie chcemy warningow

Vector::Vector(const Vector &vector)  {
    size_t capacity = vector.capacity_;
    size_ = vector.size();
    data_ = new Fraction[capacity];
    capacity_ = capacity;
    for (std::size_t i = 0; i < size_; ++i) {
        data_[i] = vector.data_[i];
    }

}

Vector::~Vector() {
    delete[] data_;
    data_ = nullptr;
}

Vector::Vector(std::size_t capacity) {
    data_ = new Fraction[capacity];
    size_ = 0;
    capacity_ = capacity;

}

Vector::Vector( Vector &&vector)  noexcept {
    capacity_ = vector.capacity();
    data_ = vector.data();
    size_ = vector.size();
    vector.data_ = nullptr;
    vector.size_ = 0;
    vector.capacity_ = 0;

}

Vector &Vector::operator=(const Vector &vector) noexcept{
    if (this != &vector){
        delete[] data_;
        size_ = vector.size();
        capacity_ = vector.capacity();
        data_ = new Fraction[capacity_];
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = vector.data_[i];
        }

    }
    return (*this);
}

Vector &Vector::operator=( Vector &&vector) noexcept{
    if (this != &vector){
        delete[] data_;
        size_ = vector.size();
        capacity_ = vector.capacity();
        data_ = vector.data_;
        vector.data_ = nullptr;
        vector.size_ = 0;
        vector.capacity_ = 0;

    }
    return (*this);
}

void Vector::push_back(const Fraction &value) noexcept{
    if(size_ == capacity_){
        std:: size_t new_capacity;
        if (capacity_ > 0) {
            new_capacity = capacity_ + 1;
        }
        else {
            new_capacity = 1;
        }
        auto* newdata = new Fraction[new_capacity];
        for (std::size_t i = 0; i < size_; ++i) {
            newdata[i] = data_[i];
        }
        delete[] data_;
        data_ = newdata;
        capacity_ = new_capacity;
    }
    data_[size_] = value;
    size_ ++;

}

Fraction &Vector::operator[](std::size_t index) {
    if(index + 1 > (size_)){
        throw std::out_of_range("out of range");
    }
    return data_[index];
}

Fraction &Vector::operator[](std::size_t index) const {
    if(index + 1 > (size_ )){
        throw std::out_of_range("out of range");
    }
    return data_[index];
}
