#include "MyLogger.hpp"

#define DEBUG 1

void foo() {
    // LOG(WARNING, "Error message will be here.")
    
    LOG_CONFIG_FILENAME("test.log")

    LOG(WARNING, "Error message will be here.")
}

int main(int argc, char* argv[]) {

    // LOG_PRINT(INFO, "Hello")

    foo();

    return 0;
}