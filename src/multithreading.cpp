#include "multithreading.h"

std::mutex mtx; // mutex 

void print_function(std::string thread_name)
{
    usleep(500);
    for (std::uint8_t i = 0; i < 10; i++)
    {
        mtx.lock();
        cout << thread_name + ": " + std::to_string(i) << endl;
        mtx.unlock();
        usleep(1);
    }
}

void thread_function()
{
    cout << "The following msg will showcase threads:" << endl;

    // start t1 printing
    std::thread t1(print_function, "t1");
    std::thread t2(print_function, "t2");
    std::thread t3(print_function, "t3");

    // start main thread printing
    print_function("main");

    // wait for t1 to finish
    t1.join();
    t2.join();
    t3.join();
}
