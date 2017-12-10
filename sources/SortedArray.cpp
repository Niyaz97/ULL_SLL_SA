#include "SortedArray.hpp"


sortedarray::sortedarray(): count_(0), capacity_(0){
    arr_ = new node[capacity_];
    std::function<bool(const int&, const int&)> compare = std::less<int>();
    comparator = compare;
}

sortedarray::~sortedarray() {
    delete[] arr_;
}

auto sortedarray::insert(int key, int data) -> void{
    if(count_ >= capacity_){
        resize();
    }

    if(count_ == 0){
        arr_[count_].key_ = key;
        arr_[count_].data_ = data;
        count_++;
        return;
    }

    size_t index = insert_idx(key);
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

auto sortedarray::remove(int key) -> void{
    if(count_ == 0){
        throw std::logic_error("Sorted array is empty");
    }
    size_t index = binarysearch(key);

    for (; index < count_-1; index++) {
        arr_[index].key_ = arr_[index + 1].key_;
        arr_[index].data_ = arr_[index + 1].data_;
    }
    count_--;
//    std::cout << "Key "<< arr_[index].key_ << " and data "<< arr_[index].data_ <<" deleted" << std::endl;
}

auto sortedarray::print() -> void{
    std::cout << "[ ";
    for(size_t i = 0; i < count_; i++){
        std::cout<< "(" << arr_[i].key_ << ", ";
        std::cout << arr_[i].data_ << ") " << std::endl;
    }
    std::cout << "]" << std::endl;
}

auto sortedarray::binarysearch(int key) -> size_t {
    size_t count = 2;
    size_t right = idx(key, count);
    size_t left = right/count;

    if(right == count)
        left = 0;
    if(right > count_)
        right = count_ - 1;
    while(left < right){
        size_t mid = (right + left) / 2;
        if(arr_[mid].key_ == key) {
//            std::cout << "Searched key: " << arr_[mid].key_ << ", data for this key: "<< arr_[mid].data_ <<std::endl;
            return mid;
        }
        if(comparator(key, arr_[mid].key_))
            right = mid - 1;
        else
            left = mid + 1;
    }

    if(arr_[right].key_ == key) {
//        std::cout << "Searched key: " << arr_[right].key_ << ", data for this key: "<< arr_[right].data_ <<std::endl;
        return right;
    }
    else
        throw std::logic_error("Key wasn't found");

}

auto sortedarray::findmin() -> int{
    if(count_ == 0)
        throw std::logic_error("Sorted array is empty");
    std::cout << "Minimum key: " << arr_[0].key_ << ", data for this key: " << arr_[0].data_ << std::endl;
    return arr_[0].key_;
}


auto sortedarray::findmax() -> int{
    if(count_ == 0)
        throw std::logic_error("Sorted array is empty");
    std::cout << "Maximum key: " << arr_[count_-1].key_ << ", data for this key: " << arr_[count_-1].data_ << std::endl;
    return arr_[count_-1].key_;
}

auto sortedarray::insert_idx(int key) -> size_t{
    if(comparator(arr_[count_-1].key_, key))
        return count_;
    if(!comparator(arr_[0].key_, key))
        return 0;
    size_t mult = 2;

    auto right = idx(key, mult);
    auto left = right/mult;
    if(!right == mult)
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

auto sortedarray::idx(int key, size_t index) -> size_t{
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


auto sortedarray::resize() -> void{
    if(!capacity_){
        capacity_ += 1;
        arr_ = new node[capacity_];
        return;
    }
    capacity_ = capacity_ * 2;
    node* new_arr = new node[capacity_];

    for(int i=0; i < count_; ++i){
        new_arr[i] = arr_[i];
    }
    delete[] arr_;
    arr_ = new_arr;
}

auto sortedarray::count() -> size_t {
    return count_;
}