#ifndef MULTITHREADING_H

    // defines
    #define MULTITHREADING_H

    // includes
    #include <string>
    #include <thread>
    #include <iostream>
    #include <unistd.h>

    // namespace
    using namespace std;

    // Functions
    void print_function(std::string thread_name);
    void thread_function(void);

#endif