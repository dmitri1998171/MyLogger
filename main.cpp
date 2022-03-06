#include "MyLogger.hpp"

#define DEBUG 1

void bar() {
    LOG(WARNING, "Error message will be here.")
}

void foo() {
    LOG(WARNING, "Error message will be here.")
    bar();
}

int main(int argc, char* argv[]) {

    int x = 5;
    // LOG(WARNING, "Error message will be here.")
    PRINT(x)

    // foo();

    return 0;
}