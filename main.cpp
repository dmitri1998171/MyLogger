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

    LOG(WARNING, "Error message will be here.")

    foo();

    return 0;
}