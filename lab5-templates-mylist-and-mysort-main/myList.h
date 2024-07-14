#pragma once

#include <memory>
#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>


#define IMPLEMENTED_constructorOfEmptyList
#define IMPLEMENTED_pushingAndPopingElementsFront
#define IMPLEMENTED_nodesStoredAsUniquePtrs
#define IMPLEMENTED_popFromWhenEmptyList
#define IMPLEMENTED_copyingDisabled
#define IMPLEMENTED_removingElements
#define IMPLEMENTED_iteratorOperations
#define IMPLEMENTED_iteratorWithRangedForLoop
#define IMPLEMENTED_iteratorWithStlAlgorithm
#define IMPLEMENTED_ostreamOperator

template<typename T>
class MyList {
public:
    using value_type = T;
    class Node;
    class Iterator;
    class ConstIterator;
    class InsertIterator;

public:
    std::unique_ptr<Node> head_;
    MyList() : head_{ nullptr } {}
    MyList(const MyList& other) = delete;
    MyList(MyList&& other) noexcept : head_{ std::move(other.head_) }, size_{ other.list_size } {
        other.size_ = 0;
    }
    ~MyList() { clear(); }
    T& front() const;
    [[nodiscard]] size_t size() const {
        return size_;
    }
    MyList& operator=(const MyList& other) = delete;
    void push_front(const T& t);
    T pop_front();
    void remove(const T& t);
    MyList& operator=(MyList&& other) noexcept {
        if (this != &other) {
            clear();
            head_ = std::move(other.head_);
            size_ = other.size_;
            other.size_ = 0;
        }
        return *this;
    }
    void sort() {
        if (head_ == nullptr || head_->next_ == nullptr) return;

        std::unique_ptr<Node> sorted{ nullptr };

        while (head_) {
            std::unique_ptr<Node> node = std::move(head_);
            head_ = std::move(node->next_);

            if (!sorted || node->value() < sorted->value()) {
                node->next_ = std::move(sorted);
                sorted = std::move(node);
            } else {
                Node* current{ sorted.get() };
                while (current->next_ && current->next_->value() < node->value()) {
                    current = current->next_.get();
                }
                node->next_ = std::move(current->next_);
                current->next_ = std::move(node);
            }
        }

        head_ = std::move(sorted);
    }
    Iterator begin() {
        return Iterator(head_.get());
    }
    Iterator end() {
        return Iterator(nullptr);
    }
    ConstIterator begin() const {
        return ConstIterator(head_.get());
    }
    ConstIterator end() const {
        return ConstIterator(nullptr);
    }
    void clear() {
        while (head_) {
            head_ = std::move(head_->next_);
            --size_;
        }
    }
private:
    size_t size_ {0};
};


template<typename T>
void MyList<T>::push_front(const T& t) {
    auto newNode = std::make_unique<Node>(t);
    newNode->next_ = std::move(head_);
    head_ = std::move(newNode);
    ++size_;
}

template<typename T>
T MyList<T>::pop_front() {
    if (head_ == nullptr) {
        throw std::out_of_range("Cannot pop from an empty list");
    }
    T value = std::move(head_->value());
    head_ = std::move(head_->next_);
    --size_;
    return value;
}
template<typename T>
T& MyList<T>::front() const {
    if (head_ == nullptr) {
        throw std::out_of_range("List is empty");
    }
    return head_->value();
}


template<typename T>
void MyList<T>::remove(const T& t) {
    while (head_ && head_->value() == t) {
        head_ = std::move(head_->next_);
        --size_;
    }
    Node* current = head_.get();
    while (current && current->next_) {
        if (current->next_->value() == t) {
            current->next_ = std::move(current->next_->next_);
            --size_;
        } else {
            current = current->next_.get();
        }
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const MyList<T>& list) {
    for (const auto& item : list) {
        os << '\t' << item << std::endl;
    }
    return os;
}

template<typename T>
class MyList<T>::Node {
private:
    T value_;
public:
    explicit Node(const T& value) : value_(value) {}
    std::unique_ptr<Node> next_ = nullptr;
    T& value() {
        return value_;
    }
    const T& value() const {
        return value_;
    }
};

template<class T>
class MyList<T>::Iterator {
private:
    Node* current;
public:
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;

    explicit Iterator()  : current(nullptr) {}

    explicit Iterator(Node* node)  : current(node) {}

    Iterator& operator++()  {
        current = current->next_.get();
        return *this;
    }
    Iterator operator++(int) {
        Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    bool operator!=(const Iterator& other) const noexcept {
        return current != other.current;
    }

    reference operator*() const {
        if (!current) throw std::out_of_range("Dereferencing a null iterator");
        return current->value();
    }

    pointer operator->() const;


};

template<class T>
class MyList<T>::ConstIterator {
private:
    const Node* current;

public:
    using value_type = T;
    using reference = const T&;
    using pointer = const T*;
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;

    explicit ConstIterator()  : current(nullptr) {}
    explicit ConstIterator(const Node* node)  : current(node) {}
    ConstIterator& operator++()  {
        if (current) {
            current = current->next_.get();
        }
        return *this;
    }
    ConstIterator operator++(int) {
        ConstIterator tmp = *this;
        ++(*this);
        return tmp;
    }
    bool operator!=(const ConstIterator& other) const  {
        return current != other.current;
    }
    bool operator==(const ConstIterator& other) const {
        return current == other.current;
    }
    reference operator*() const  {
        if (!current) throw std::out_of_range("Dereferencing a null iterator");
        return current->value();
    }
    pointer operator->() const  {
        if (!current) throw std::out_of_range("Dereferencing a null iterator");
        return &current->value();
    }

};
template<class T>
class MyList<T>::InsertIterator {
public:
    using iterator_category = std::output_iterator_tag;
    using value_type = T;
    using difference_type = void;
    using pointer = void;
    using reference = void;

    explicit InsertIterator(MyList<T>& myList) : myList_(myList) {}

    InsertIterator& operator=(const T& value) {
        myList_.push_front(value);
        return *this;
    }

    InsertIterator& operator*() { return *this; }
    InsertIterator& operator++() { return *this; }
    InsertIterator& operator++(int) { return *this; }

private:
    MyList<T>& myList_;
};