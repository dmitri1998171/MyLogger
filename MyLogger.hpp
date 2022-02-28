#include <iostream>
#include <fstream>

using namespace std;

enum LogError{INFO, WARNING, ERROR, DEBUG};

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

                case DEBUG:
                    return "DEBUG";
            }

            return "INFO";
        }
        
    public:
        char* filename;

        MyLogger() {
            error_lvl = INFO;
            filename = "log.log";
        }

        void consoleLog(int error_lvl, char* message) {
            this->error_lvl = error_lvl;

            cout << LogError() << ' ' << __DATE__ << ' ' << __TIME__ << ' ' <<  message << endl;
        }

        void fileLog(int error_lvl, char* message) {
            ofstream file(filename, ios_base::app);

            this->error_lvl = error_lvl;

            file << LogError() << ' ' << __DATE__ << ' ' << __TIME__ << ' ' <<  message << endl;

            file.close();
        }

        void mixedLog(int error_lvl, char* message) {
            consoleLog(error_lvl, message);
            fileLog(error_lvl, message);
        }
};

#define LOG_INIT MyLogger logger;
#define LOG_CONFIG_FILENAME(_filename) logger.filename = _filename; 
// #define LOG_INIT(_filename) \
//     MyLogger logger; \
//     LOG_CONFIG_FILENAME(_filename)


#define LOG_PRINT(error_lvl, message) logger.consoleLog(error_lvl, message);
#define LOG_FILE(error_lvl, message) logger.fileLog(error_lvl, message);
#define LOG_MIXED(error_lvl, message) logger.mixedLog(error_lvl, message);