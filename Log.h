#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

#include <vector>
#include <string>


//class to log all program acitivity

class Log
{
    //data
    private:
        std::vector<std::string> logstr;

    //methods declaration
    public:
        //constructors
        Log();

        //methods
        bool load_log(const char path[]); //loads a saved log from file 'filename' -- return value: true=ok | errors: false=file not found or could not be opened
        bool save_log(const char path[]); //saves 'logstr' to file 'path' or overwrites it (!) -- return value: true=ok | errors: false=file could not be opened
        void add(std::string s); //add normal entry
        void err(std::string s); //add error entry

        //print methods
        void print(unsigned int entry); //displays 'logstr[entry]'
        void print(unsigned int start, unsigned int end); //displays 'logstr[start]' to 'logstr[end]' -- if end=0 logstr[start] to logstr[entries] will be displayes
        void print(); //displays whole content of 'logstr'

    private:
        void send_console(); //sends last entry to standard output -- used to print new log entry
};


#endif // LOG_H_INCLUDED
