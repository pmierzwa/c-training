#include "multithreading.h"

void print_function(std::string thread_name)
{
    for (std::uint8_t i = 0; i < 10; i++)
    {
        cout << thread_name + ": " + std::to_string(i) << endl;
        usleep(200);
    }
}

void thread_function()
{

    cout << "The following msg will showcase the two threads:" << endl;

    // start t1 printing
    std::thread t1(print_function, "t1");

    // start main thread printing
    print_function("main");

    // wait for t1 to finish
    t1.join();
}
