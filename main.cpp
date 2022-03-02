#include "MyLogger.hpp"

#define DEBUG 1

void foo() {
    LOG(WARNING, "foo")

}

int main(int argc, char* argv[]) {

    // LOG_PRINT(INFO, "Hello")

    foo();

    return 0;
}