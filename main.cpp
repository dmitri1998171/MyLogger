#include "MyLogger.hpp"


int main(int argc, char* argv[]) {

    LOG_INIT
    LOG_MIXED(INFO, "hello")

    return 0;
}