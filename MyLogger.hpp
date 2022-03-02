#ifndef MY_LOGGER_HPP
#define MY_LOGGER_HPP

// ===============

#define DEBUG 1     // 1 - switch on logger; 0 - switch off

// ===============


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum LogError{INFO, WARNING, ERROR};

class MyLogger {
    private:
        int error_lvl;
        static string tab;    // Indent line

        string LogError() {
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
        static string logname; // logname: file name where logger write 
        string output; // output: stdout - to console; file - to logfile; mix - both ways.

        MyLogger(string filename, string funcName, int lineNumber, int error_lvl, string message) {
            this->error_lvl = error_lvl;
            output = "file";

            if(output == "stdout") {
                cout << tab << LogError() << ' ' << filename << ":" << funcName << "():" << lineNumber << "  " << __DATE__ << ' ' << __TIME__ << ' ' <<  message << endl;
            }

            if(output == "file") {
                fileLog(filename, funcName, lineNumber, error_lvl, message);
            }

            tab.append("    ");
        }

        ~MyLogger() {
            tab.resize(tab.length() - 4);
        }

        void fileLog(string filename, string funcName, int lineNumber, int error_lvl, string message) {
            ofstream file(logname, ios_base::app);

            file << tab << LogError() << ' ' << filename << ":" << funcName << "():" << lineNumber << "  " << __DATE__ << ' ' << __TIME__ << ' ' <<  message << endl;

            file.close();
        }
};

string MyLogger::logname = "log.log";
string MyLogger::tab;


#if DEBUG == 1
    #define LOG(error_lvl, msg) \
        MyLogger logger(__FILE__, __FUNCTION__, __LINE__, error_lvl, msg); 

    #define LOG_CONFIG_FILENAME(_filename) \
        MyLogger::logname = _filename; 

#else
    #define LOG(x, y)
    #define LOG_CONFIG_FILENAME(x)

#endif

#endif
