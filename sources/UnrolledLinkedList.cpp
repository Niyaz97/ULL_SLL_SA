#include "UnrolledLinkedList.hpp"


unrolledlist::unrolledlist(): head_(nullptr), tail_(nullptr), count_(0){
    std::function<bool(const int&, const int&)> compare = std::less<int>();
    comparator = compare;
    size_ = 8;
}

unrolledlist::~unrolledlist() = default;

auto unrolledlist::insert(int key, int data) -> void{
    auto ptr = head_;
    if(head_ == nullptr){
        head_ = std::make_shared<array>(size_);
        head_ -> insert(key, data, comparator);
        tail_ = head_;
        ++count_;
        return;
    }


    while(ptr){
        if(comparator(key, ptr -> arr_[ptr -> count_ - 1].key_)){
            if(!(ptr -> full())){
                ptr -> insert(key, data, comparator);
                ++count_;
                return;
            }

            auto new_ptr = std::make_shared<array>(size_);
            if(comparator(key, ptr -> arr_[0].key_)){
                if(ptr -> prev_){
                    if(!(ptr -> prev_ -> full())){
                        ptr -> prev_ -> insert(key, data, comparator);
                        ++count_;
                        return;
                    }
                }
                new_ptr -> next_ = ptr;
                new_ptr -> prev_ = ptr -> prev_;
                if(!ptr -> prev_)
                    head_ = new_ptr;
                else
                    ptr -> prev_ -> next_ = new_ptr;
                ptr -> prev_ = new_ptr;
                new_ptr -> insert(key, data, comparator);
                ++count_;
                return;
            }
            if(ptr -> next_){
                if(!(ptr -> next_ -> full())){
                    ptr -> next_ -> insert(ptr -> arr_[--ptr -> count_].key_, ptr -> arr_[--ptr -> count_].data_, comparator);
                    ptr -> insert(key, data, comparator);
                    ++count_;
                    return;
                }
                ptr -> next_ -> prev_ = new_ptr;
            }
            else
                tail_ = new_ptr;

            new_ptr -> prev_ = ptr;
            new_ptr -> next_ = ptr -> next_;
            ptr -> next_ = new_ptr;

            new_ptr -> insert(ptr -> arr_[--ptr -> count_].key_, ptr -> arr_[--ptr -> count_].data_, comparator);
            ptr -> insert(key, data, comparator);
            ++count_;
            return;
        }
        ptr = ptr -> next_;
    }
    ptr = tail_;

    if(!ptr -> full()){
        ptr -> insert(key, data, comparator);
        ++count_;
        return;
    }

    auto new_ptr = std::make_shared<array>(size_);
    tail_ = new_ptr;

    new_ptr -> prev_ = ptr;
    ptr -> next_ = new_ptr;

    new_ptr -> insert(key, data, comparator);
    ++count_;
}

auto unrolledlist::remove(int key) -> void{
    if(head_ == nullptr)
        throw std::logic_error("Unrolled linked list is empty");

    auto ptr = head_;
    while(ptr){
        if(!comparator(ptr -> arr_[ptr -> count_ - 1].key_, key)){
            if(ptr -> remove(key)){
                --count_;
                return;
            }
        }
        ptr = ptr -> next_;
    }
}

auto unrolledlist::search(int key) -> std::pair<int, int>{
    if(head_ == nullptr)
        throw std::logic_error("Unrolled linked list is empty");
    auto ptr = head_;

    while(ptr){
        if(!comparator(ptr -> arr_[ptr -> count_ - 1].key_, key))
            return ptr -> search(key);
        ptr = ptr -> next_;
    }
}

auto unrolledlist::print(std::ofstream& fout) -> void{
    auto ptr = head_;
    while(ptr -> next_ != nullptr){
        ptr -> print(fout);
        fout << " --> " << std::endl;
        ptr = ptr -> next_;
    }
    ptr -> print(fout);
    fout << std::endl;
}

auto unrolledlist::findmin() -> std::pair<int, int>{
    if(!count_)
        throw std::logic_error("Unrolled linked list is empty");

    return std::make_pair(head_ -> arr_[0].key_, head_ -> arr_[0].data_);
}

auto unrolledlist::findmax() -> std::pair<int, int>{
    if(!count_)
        throw std::logic_error("Unrolled linked list is empty");

    return std::make_pair(tail_ -> arr_[tail_ -> count_ - 1].key_, tail_ -> arr_[tail_ -> count_ - 1].data_);
}

auto unrolledlist::count() -> size_t{
    return count_;
}
