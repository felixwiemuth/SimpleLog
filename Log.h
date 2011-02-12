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
        bool load_log(const char path[]);
        bool save_log(const char path[]);
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
