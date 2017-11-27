#ifndef ULL_SLL_SA_SORTEDLINKEDLIST_HPP
#define ULL_SLL_SA_SORTEDLINKEDLIST_HPP


#include <iostream>


class list{
public:
    list();
    ~list();
    auto push(int key, int data) -> void;
    auto pop(int key) -> void;
    auto print() -> void;
    auto search(int key) -> int;
    auto findmin() -> int;
    auto findmax() -> int;

private:
    struct node{
        int address;
        int data;
        node* next;
    };

    node* head;
    node* curr;
    node* temp;
    node* tail;
};

list::list(){
    head = NULL;
    curr = NULL;
    temp = NULL;
    tail = NULL;
}

list::~list(){

    if(head != NULL){
        node* curr = head;
        while(curr -> next != NULL){
            curr = curr -> next;
            delete head;
            head = curr;
        }
    }
}

auto list::push(int key, int data) -> void{

    node* n = new node;
    n -> address = key;
    n -> data = data;

    if (head == NULL){
        head = tail = n;
        n -> next = NULL;
    }
    else{
        if (n -> address <= head -> address){
            n -> next = head;
            head = n;
        }
        else{
            curr = head;
            while (curr != NULL && curr -> address < n -> address){
                temp = curr;
                curr = curr -> next;
            }
            temp -> next = n;
            tail = n;
            n -> next = curr;
        }
    }
}

auto list::pop(int key) -> void{

    node* n = NULL;
    temp = head;
    curr = head;

    while (curr != NULL && curr -> address != key){
        temp = curr;
        curr = curr -> next;
    }
    if (curr != NULL){
        n = curr;
        curr = curr -> next;
        temp -> next = curr;
    }
    if (n == head){
        head = head -> next;
    }
    delete n;
}

auto list::print() -> void{
    node* n = head;
    while(n != NULL){
        std::cout << n -> address << "-->";
        n = n -> next;
    }
    std::cout << std::endl;

    n = head;
    while(n != NULL){
        std::cout << n -> data << "\t";
        n = n -> next;
    }
    std::cout << std::endl;
}
auto list::search(int key) -> int{
    node* n = head;
    while(n -> address != key){
        n = n -> next;
    }
    std::cout << n -> address << std::endl << n -> data;
    return n -> address;
};

auto list::findmin() -> int{
    node* n = head;
    return n -> address;
}

auto list::findmax() -> int{
    node* n = tail;
    return n -> address;
}



#endif //ULL_SLL_SA_SORTEDLINKEDLIST_HPP
