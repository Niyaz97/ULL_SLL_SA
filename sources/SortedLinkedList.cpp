#include "SortedLinkedList.hpp"

sortedlist::sortedlist(): head_(nullptr), tail_(nullptr), count_(0){
}

sortedlist::~sortedlist(){
    node* curr;
    while(head_ != nullptr){
        curr = head_ -> next_;
        delete head_-> next_;
        head_ = curr;
    }
}

auto sortedlist::insert(int key, int data) -> void{
    node* n = new node;
    n -> address_ = key;
    n -> data_= data;

    if (head_ == nullptr){
        n -> address_ = key;
        n -> data_= data;
        head_ = n;
        tail_ = head_;
        n -> next_ = nullptr;
        n -> prev_ = nullptr;
    }
    else{
        if(tail_ != nullptr){
            if(key > tail_ -> address_){
                n -> next_ = nullptr;
                n -> prev_ = tail_;
                tail_ -> next_ = n;
                tail_ = n;
                ++count_;
                return;
            }
            if(key < head_ -> address_){
                n -> next_ = head_;
                n -> prev_ = nullptr;
                head_ -> prev_ = n;
                head_ = n;
                ++count_;
                return;
            }
        }

        node* curr = head_ -> next_;
        while(curr != nullptr && curr -> address_ < key){
            curr = curr -> next_;
        }
        n -> next_ = curr;
        n -> prev_ = curr -> prev_;
        if(curr -> prev_ != nullptr)
            curr -> prev_ -> next_ = n;
        curr -> prev_ = n;
    }
    ++count_;
}

auto sortedlist::remove(int key) -> void{
    if(count_ == 0){
        throw std::logic_error("Sorted linked list is empty");
    }

    else{
        node* n = nullptr;
        node* temp = head_;
        node* curr = head_;

        while (curr != nullptr && curr -> address_ != key) {
            temp = curr;
            curr = curr -> next_;
            if(!curr){
                delete n;
                throw std::logic_error("Key wasn't found");
            }
        }
        if (curr != nullptr) {
            n = curr;
            curr = curr -> next_;
            temp -> next_ = curr;
        }
        if (n == head_) {
            head_ = head_ -> next_;
        }

        delete n;
        --count_;
    }
}

auto sortedlist::print() -> void{
    node* n = head_;
    while(n != tail_){
        std::cout << "(" << n -> address_ << ", " << n -> data_<< ") --> " << std:: endl;
        n = n -> next_;
    }
    std::cout << "(" << n -> address_ << ", " << n -> data_<< ")" << std::endl;
}

auto sortedlist::search(int key) -> int{
    if(count_ == 0)
        throw std::logic_error("Sorted linked list is empty");
    node* n = head_;
    while(n -> address_ != key){
        n = n -> next_;
        if(!n)
            throw std::logic_error("Key wasn't found");
    }
//    std::cout << "Searched key: "<< n -> address_ << ", data for this key: " << n -> data_<< std::endl;
    return n -> address_;
};

auto sortedlist::findmin() -> int{
    if(count_ == 0)
        throw std::logic_error("Sorted linked list is empty");
    node* n = head_;
    std::cout << "Minimum key: " << n -> address_ << ", data for this key: " << n -> data_<< std::endl;
    return n -> address_;
}

auto sortedlist::findmax() -> int{
    if(count_ == 0)
        throw std::logic_error("Sorted linked list is empty");
    node* n = tail_;
    std::cout << "Maximum key: " << n -> address_ << ", data for this key: " << n -> data_<< std::endl;
    return n -> address_;
}

auto sortedlist::count() -> size_t{
    return count_;
}

