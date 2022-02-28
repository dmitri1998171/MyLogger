#include <iostream>
#include <fstream>

using namespace std;

enum LogError{INFO, WARNING, ERROR, DEBUG};

char errors[4][8] = {
    "INFO", "WARNING", "ERROR", "DEBUG"
};

int error = ERROR;

char* LogError() {
    switch (error) {
        case INFO:
            return errors[0];

        case WARNING:
            return errors[1];
        
        case ERROR:
            return errors[2];

        case DEBUG:
            return errors[3];
    }

    return errors[0];
}

void consoleLog(char* message) {
    cout << LogError() << ' ' << __DATE__ << ' ' << __TIME__ << ' ' <<  message << endl;
}

void fileLog(char* message) {
    ofstream file("log.log", ios_base::app);

    file << LogError() << ' ' << __DATE__ << ' ' << __TIME__ << ' ' <<  message << endl;

    file.close();
}

void mixedLog(char* message) {
    consoleLog(message);
    fileLog(message);
}
