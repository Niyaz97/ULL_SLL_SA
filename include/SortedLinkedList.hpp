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

    auto count() -> size_t;

private:
    struct node{
        int   address;
        int   data;
        node* next;
    };

    node* head;
    node* tail;

    size_t count_; //счетчик количества элементов в списке
};

sortedlist::sortedlist(): head(NULL), tail(NULL), count_(0){
}

sortedlist::~sortedlist(){
    node* curr = head;
    while(head != NULL){
        curr = head -> next;
        delete head->next;
        head = curr;
    }
}

auto sortedlist::insert(int key, int data) -> void{
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
            node* curr = head;
            node* temp;
            while (curr != NULL && curr -> address < n -> address){
                temp = curr;
                curr = curr -> next;
            }
            temp -> next = n;
            tail = n;
            n -> next = curr;
        }
    }
    std::cout << "Key and data were inserted successfully" << std::endl;
    ++count_;
}

auto sortedlist::remove(int key) -> void{
    if(count_ == 0){
        throw std::logic_error("Sorted linked list is empty");
    }

    else{
        node* n = NULL;
        node* temp = head;
        node* curr = head;

        while (curr != NULL && curr->address != key) {
            temp = curr;
            curr = curr->next;
            if(!curr){
                delete n;
                throw std::logic_error("Key wasn't found");
            }
        }
        if (curr != NULL) {
            n = curr;
            curr = curr->next;
            temp->next = curr;
        }
        if (n == head) {
            head = head->next;
        }

        delete n;
        std::cout << "Key and data were deleted successfully" << std::endl;
        --count_;
    }
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
    if(count_ == 0)
        throw std::logic_error("sorted linked list is empty");
    node* n = head;
    while(n -> address != key){
        n = n -> next;
        if(!n)
            throw std::logic_error("Key wasn't found");
    }
    std::cout << "Searched key: "<< n -> address << ", data for this key: " << n -> data << std::endl;
    return n -> address;
};

auto sortedlist::findmin() -> int{
    node* n = head;
    std::cout << "Minimum key: " << n -> address << ", data for this key: " << n -> data << std::endl;
    return n -> address;
}

auto sortedlist::findmax() -> int{
    node* n = tail;
    std::cout << "Maximum key: " << n -> address << ", data for this key: " << n -> data << std::endl;
    return n -> address;
}


auto sortedlist::count() -> size_t{
    return count_;
}


#endif //ULL_SLL_SA_SORTEDLINKEDLIST_HPP