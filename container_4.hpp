#include "container_common.hpp"

#include <vector>
#include <deque>
#include <list>

//////////////////////////// TASK 4 ////////////////////////////

class my_unique_ptr {
    int* data_ = nullptr;

public:
    my_unique_ptr() = default;

    my_unique_ptr(int v)
        : data_(new int{v})
    {}

    my_unique_ptr(const my_unique_ptr& p)
        : data_(p.data_ ? new int{*p.data_} : nullptr)
    {}

    my_unique_ptr(my_unique_ptr&& p)
        : data_(p.data_)
    {
        p.data_ = nullptr;
    }

    my_unique_ptr& operator=(const my_unique_ptr& p) {
        delete data_;
        data_ = (p.data_ ? new int{*p.data_} : nullptr);
        return *this;
    }

    my_unique_ptr& operator=(my_unique_ptr&& p) {
        std::swap(data_, p.data_);
        return *this;
    }

    ~my_unique_ptr() {
        delete data_;
    }
};



class my_unique_ptr_opt {
    int* data_ = nullptr;

public:
    my_unique_ptr_opt() = default;
    my_unique_ptr_opt(int v)
        : data_(new int{v})
    {}

    my_unique_ptr_opt(const my_unique_ptr_opt& p)
        : data_(p.data_ ? new int{*p.data_} : nullptr)
    {}

    my_unique_ptr_opt(my_unique_ptr_opt&& p)
        : data_(p.data_)
    {
        p.data_ = nullptr;
    }

    my_unique_ptr_opt& operator=(const my_unique_ptr_opt& p) {
        delete data_;
        data_ = (p.data_ ? new int{*p.data_} : nullptr);
        return *this;
    }

    my_unique_ptr_opt& operator=(my_unique_ptr_opt&& p) {
        std::swap(data_, p.data_);
        return *this;
    }

    ~my_unique_ptr_opt() {
        delete data_;
    }
};



std::vector<my_unique_ptr> naive_uptr();
std::vector<my_unique_ptr_opt> optimized_uptr();


//////////////////////////// DETAIL ////////////////////////////
BENCHMARK_CAPTURE(containers_insertion, naive_uptr, naive_uptr)->Range(8, 8<<10);
BENCHMARK_CAPTURE(containers_insertion, optim_uptr, optimized_uptr)->Range(8, 8<<10);
