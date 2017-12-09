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
        head_ = tail_= n;
        n -> next_ = nullptr;
    }
    else{
        if (n -> address_ <= head_ -> address_){
            n -> next_ = head_;
            head_ = n;
        }
        else{
            node* curr = head_;
            node* temp;
            while (curr != nullptr && curr -> address_ < n -> address_){
                temp = curr;
                curr = curr -> next_;
            }
            temp -> next_ = n;
            tail_= n;
            n -> next_ = curr;
        }
    }
//    std::cout << "Key "<< n -> address_ << " and data_"<< n -> data_<<" inserted" << std::endl;
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

        while (curr != nullptr && curr->address_ != key) {
            temp = curr;
            curr = curr->next_;
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
            head_ = head_->next_;
        }

        delete n;
//        std::cout << "Key "<< n -> address_ << " and data_"<< n -> data_<<" deleted" << std::endl;
        --count_;
    }
}

auto sortedlist::print() -> void{
    node* n = head_;
    while(n != tail_){
        std::cout << "(" << n -> address_ << ", " << n -> data_<< ") --> ";
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
    std::cout << "Searched key: "<< n -> address_ << ", data_for this key: " << n -> data_<< std::endl;
    return n -> address_;
};

auto sortedlist::findmin() -> int{
    if(count_ == 0)
        throw std::logic_error("Sorted linked list is empty");
    node* n = head_;
    std::cout << "Minimum key: " << n -> address_ << ", data_for this key: " << n -> data_<< std::endl;
    return n -> address_;
}

auto sortedlist::findmax() -> int{
    if(count_ == 0)
        throw std::logic_error("Sorted linked list is empty");
    node* n = tail_;
    std::cout << "Maximum key: " << n -> address_ << ", data_for this key: " << n -> data_<< std::endl;
    return n -> address_;
}

auto sortedlist::count() -> size_t{
    return count_;
}

