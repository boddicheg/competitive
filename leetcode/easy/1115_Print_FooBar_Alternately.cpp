#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>

class FooBar {
private:
    int n;
    std::mutex m;
    std::mutex m2;

public:
    FooBar(int n) {
        this->n = n;
        m.lock();
    }

    void foo(std::function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            m2.lock();
        	printFoo();
            m.unlock();
        }
    }

    void bar(std::function<void()> printBar) {

        for (int i = 0; i < n; i++) {

            m.lock();
        	printBar();
            m.unlock();
            m2.unlock();
        }
    }
};

int main(int argc, char const *argv[])
{
    FooBar s;
    return 0;
}
