#include "Node.hpp"

array::array(size_t capacity = 4) : prev_(nullptr), next_(nullptr), count_(0), capacity_(capacity){
    arr_ = new node[capacity];
    std::function<bool(const int&, const int&)> compare = std::less<int>();
    comparator = compare;
}

array::~array() {
    delete[] arr_;
}

auto array::insert(int key, int data, std::function<bool(const int &, const int &)> comparator) -> void{
    if(count_ == 0){
        arr_[count_].key_ = key;
        arr_[count_].data_ = data;
        ++count_;
        return;
    }

    size_t index = insert_idx(key, comparator);

    for(size_t i = count_; i > index;){
        arr_[i].key_ = arr_[--i].key_;
    }

    for(size_t i = count_; i > index;){
        arr_[i].data_ = arr_[--i].data_;
    }

    arr_[index].key_ = key;
    arr_[index].data_ = data;
    ++count_;

}

auto array::remove(int key) -> bool{
    for(int i = 0; i < count_; i++){
        if(arr_[i].key_ == key){
            for(int j = i; j < count_ - 1; j++) {
                arr_[j].key_ = arr_[j + 1].key_;
                arr_[j].data_ = arr_[j + 1].data_;
            }
            --count_;
            if(!count_){
                if(this->prev_)
                    this->prev_->next_ = this->next_;
                if(this->next_)
                    this->next_->prev_ = this->prev_;
            }
            return true;
        }
    }
    return false;
}

auto array::search(int key) -> int{
    for(size_t i = 0; i < count_; i++){
        if(arr_[i].key_ == key) {
//            std::cout << "Searched key: " << arr_[i].key_ << ", data for this key: "<< arr_[i].data_ <<std::endl;
            return arr_[i].key_;
        }
    }
    throw std::logic_error("Key wasn't found");
}

auto array::print() -> void{
    std::cout << "[ ";
    for(size_t i = 0; i < count_ - 1; i++){
        std::cout << "(" << arr_[i].key_ << ", ";
        std::cout << arr_[i].data_ << "); ";
    }
    std::cout << "(" << arr_[count_ - 1].key_ << ", ";
    std::cout << arr_[count_ - 1].data_ << ") ";
    std::cout << "]";
}

auto array::insert_idx(int key, std::function<bool(const int &, const int &)> comparator) -> size_t{
    if(comparator(arr_[count_ - 1].key_, key))
        return count_;
    if(!comparator(arr_[0].key_, key))
        return 0;
    size_t index = 2;

    auto right = idx(key, index, comparator);
    auto left = right/index;

    if(!right == index)
        left = 0;
    while(right - left > 1){
        auto mid = (right+left)/2;
        if(arr_[mid].key_ == key)
            return mid;
        if(!comparator(arr_[mid].key_, key))
            right = mid;
        else
            left = mid;
    }
    return right;
}

auto array::idx(int key, size_t index, std::function<bool(const int &, const int &)> comparator) -> size_t{
    size_t right = index;

    while(right < count_){
        if(!comparator(arr_[right].key_, key))
            break;
        right *= index;
    }

    if(right >= count_)
        right = count_ - 1;
    return right;
}

auto array::full() -> bool{
    return (count_ == capacity_);
}


