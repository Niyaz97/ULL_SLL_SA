#ifndef ULL_SLL_SA_SORTEDLINKEDLIST_HPP
#define ULL_SLL_SA_SORTEDLINKEDLIST_HPP
#include <iostream>



class sortedlist{
public:
    sortedlist();
    ~sortedlist();
    auto insert(int key, int data) -> void;
    auto remove(int key) -> void;
    auto print() -> void;
    auto search(int key) -> int;
    auto findmin() -> int;
    auto findmax() -> int;

private:
    struct node{
        int   address;
        int   data;
        node* next;
    };

    node* head;
    node* curr;
    node* temp;
    node* tail;
};

sortedlist::sortedlist(): head(nullptr), curr(nullptr), temp(nullptr), tail(nullptr){
}

sortedlist::~sortedlist(){
    if(head != nullptr){
        node* curr = head;
        while(curr -> next != nullptr){
            curr = curr -> next;
            delete head;
            head = curr;
        }
    }
}

auto sortedlist::insert(int key, int data) -> void{
    node* n = new node;
    n -> address = key;
    n -> data = data;

    if (head == nullptr){
        head = tail = n;
        n -> next = nullptr;
    }
    else{
        if (n -> address <= head -> address){
            n -> next = head;
            head = n;
        }
        else{
            curr = head;
            while (curr != nullptr && curr -> address < n -> address){
                temp = curr;
                curr = curr -> next;
            }
            temp -> next = n;
            tail = n;
            n -> next = curr;
        }
    }
    std::cout << "Key and data were inserted successfully" << std::endl;
}

auto sortedlist::remove(int key) -> void{
    node* n = nullptr;
    temp = head;
    curr = head;

    while (curr != nullptr && curr -> address != key){
        temp = curr;
        curr = curr -> next;
    }
    if (curr != nullptr){
        n = curr;
        curr = curr -> next;
        temp -> next = curr;
    }
    if (n == head){
        head = head -> next;
    }
    delete n;
    std::cout << "Key and data were deleted successfully" << std::endl;
}

auto sortedlist::print() -> void{
    node* n = head;
    while(n != tail){
        std::cout << "(" << n -> address << ", " << n -> data << ") --> ";
        n = n -> next;
    }
    std::cout << "(" << n -> address << ", " << n -> data << ")" << std::endl;
}

auto sortedlist::search(int key) -> int{
    node* n = head;
    while(n -> address != key){
        n = n -> next;
    }
    std::cout << "Searched key: "<< n -> address << ", data for this key: " << n -> data << std::endl;
    return n -> address;
};

auto sortedlist::findmin() -> int{
    node* n = head;
    n -> address;
    std::cout << "Minimum key: " << n -> address << ", data for this key: " << n -> data << std::endl;
    return n -> address;
}

auto sortedlist::findmax() -> int{
    node* n = tail;
    std::cout << "Maximum key: " << n -> address << ", data for this key: " << n -> data << std::endl;
    return n -> address;
}



#endif //ULL_SLL_SA_SORTEDLINKEDLIST_HPP