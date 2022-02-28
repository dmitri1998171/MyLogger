#include <iostream>
#include <fstream>

using namespace std;

enum LogError{INFO, WARNING, ERROR, DEBUG};

class MyLogger {
    private:
        char* LogError() {
            switch (error_lvl) {
                case INFO:
                    return "INFO";

                case WARNING:
                    return "WARNING";
                
                case ERROR:
                    return "ERROR";

                case DEBUG:
                    return "DEBUG";
            }

            return "INFO";
        }
        
    public:
        int error_lvl;
        char* filename;

        MyLogger() {
            error_lvl = INFO;
            filename = "log.log";
        }

        void consoleLog(char* message) {
            cout << LogError() << ' ' << __DATE__ << ' ' << __TIME__ << ' ' <<  message << endl;
        }

        void fileLog(char* message) {
            ofstream file(filename, ios_base::app);

            file << LogError() << ' ' << __DATE__ << ' ' << __TIME__ << ' ' <<  message << endl;

            file.close();
        }

        void mixedLog(char* message) {
            consoleLog(message);
            fileLog(message);
        }
};