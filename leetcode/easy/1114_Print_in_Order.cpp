#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>

class Foo {
public:
    Foo() {
        m1.lock();
        m2.lock();
    }

    void first(std::function<void()> printFirst) {
        printFirst();
        m1.unlock();
    }

    void second(std::function<void()> printSecond)
    {
        // Lock first mutex because we need print 2 after 1
        // Will be wait until first() executes m1.unlock()
        m1.lock();
        printSecond();
        m1.unlock();
        // Unlock thirt() execution
        m2.unlock();
    }

    void third(std::function<void()> printThird)
    {
        // Waiting second() exectution
        m2.lock();
        printThird();
        m2.unlock();
    }
private:
    std::mutex m1;
    std::mutex m2;
};

int main(int argc, char const *argv[])
{
    Foo s;
    return 0;
}
