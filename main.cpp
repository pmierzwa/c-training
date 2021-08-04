#include "src/file_operations.h"
#include "src/multithreading.h"

using namespace std;

int main() {
    csvread("heating.csv");
    thread_function();
    return 0;
}

