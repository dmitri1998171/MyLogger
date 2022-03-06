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
        string str;
        int error_lvl;
        static string tab;     // Indent line

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
        static string logname; // File name where logger write 
        static string output;  // stdout - to console; file - to logfile; mix - both ways.
        static bool timestamp;  

        MyLogger(string filename, string funcName, int lineNumber, int error_lvl, string message) {
            this->error_lvl = error_lvl;
            
            str = tab + LogError() + ' ' + filename + ":" + funcName + "():" + to_string(lineNumber) + "  ";
            
            if(timestamp) {
                str += __DATE__;
                str += ' ';
                str += __TIME__;
            }
            
            str += ' ' + message;
            
            if(output == "stdout") {
                cout << str;
            }

            if(output == "file") {
                fileLog();
            }

            if (output == "mix") {
                cout << str;
                fileLog();
            }

            tab.append("    ");
        }

        ~MyLogger() {
            tab.resize(tab.length() - 4);
        }

        void fileLog() {
            ofstream file(logname, ios_base::app);
            file << str << endl;
            file.close();
        }
};

string MyLogger::logname = "log.log";
string MyLogger::output = "file";
bool MyLogger::timestamp = true;
string MyLogger::tab;

// ========================================================

#if DEBUG == 1
    #define LOG(error_lvl, msg) \
        MyLogger logger(__FILE__, __FUNCTION__, __LINE__, error_lvl, msg); 

// Print variable with value
    #define PRINT(var) \
        cout << #var << ": " << var << endl;

// stdout - to console; file - to logfile; mix - both ways.
    #define LOG_CONFIG_FILENAME(_filename) \
        MyLogger::logname = _filename; 

    #define LOG_CONFIG_TIMESTAMP(check) \
        if(check) \
            MyLogger::timestamp = true; \
        else \
            MyLogger::timestamp = false;
#else
    #define LOG(x, y)
    #define LOG_CONFIG_FILENAME(x)

#endif

#endif
