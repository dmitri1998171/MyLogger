#include <iostream>
#include <fstream>

using namespace std;

enum LogError{INFO, WARNING, ERROR};

class MyLogger {
    private:
        int error_lvl;

        char* LogError() {
            switch (error_lvl) {
                case INFO:
                    return "INFO";

                case WARNING:
                    return "WARNING";
                
                case ERROR:
                    return "ERROR";
            }

            return "INFO";
        }
        
    public:
        char* logname;

        MyLogger(const char* filename, const char* funcName, int lineNumber, int error_lvl, char* message) {
            this->error_lvl = error_lvl;
            
            cout << LogError() << ' ' << filename << ":" << funcName << ":" << lineNumber << "  " << __DATE__ << ' ' << __TIME__ << ' ' <<  message << endl;
        }

        void fileLog(int error_lvl, char* message) {
            ofstream file(logname, ios_base::app);

            this->error_lvl = error_lvl;

            file << LogError() << ' ' << __DATE__ << ' ' << __TIME__ << ' ' <<  message << endl;

            file.close();
        }
};

// #if DEBUG 

    #define LOG(error_lvl, msg) MyLogger logger(__FILE__, __FUNCTION__, __LINE__, error_lvl, msg);

    #define LOG_CONFIG_FILENAME(_filename) logger.logname = _filename; 


// #endif
