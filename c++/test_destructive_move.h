#ifndef TEST_DESTRUCTIVE_MOVE
#define TEST_DESTRUCTIVE_MOVE
#include<iostream>
#include<algorithm>
#include<memory>


class mnode {
private:
    std::unique_ptr<int> uptr;
public:
    mnode() {};
    explicit mnode(int arg) {
        uptr = std::make_unique<int>(arg);
    }
    // move constructor
    mnode(mnode&& other) noexcept {
        std::cout << "move constructor called...\n";
        uptr = std::move(other.uptr);
    }
    void show_value() const {
        if (uptr != nullptr) std::cout << "value = " << *uptr << std::endl;
        else std::cout << "uptr is nullptr\n";
    }
    ~mnode() {
        std::cout << "destructor called...\n";
    }
};


void test_destructive_move() {
  
    mnode m1(11);
    auto m2 = std::move(m1); // destructive move
    m1.show_value(); // valid but unspecified state. only functions without preconditions are safe
    m2.show_value();
}

#endif TEST_DESTRUCTIVE_MOVE
