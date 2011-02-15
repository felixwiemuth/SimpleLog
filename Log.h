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
        //mode vars
        bool echo; //if set 'true', every new entry will be printed in console by 'send_console()'
        //text-vars
        std::string std_file_ending; //standard file ending
        std::string std_file_name; //standard file name
        std::string seperation_symbol; //string to seperate log entries in log-file
        std::string output_symbol; //string to be put before every log entry printed in the console
        std::string error_symbol; //string to be put before every error entry
        //messages
        std::string msg_log_info; //information about "SimpleLog" at construction of object
        std::string msg_begin_log; //information about starting to log

    //methods declaration
    public:
        //constructors
        Log(); //create empty log
        Log(const char path[]); //create log with 'logstr' from file 'path'

        void init(); //set standard values for messages / echo
        void log_info(); //logs information about Log at beginning

        //methods
        bool load(const char path[]); //loads a saved log from file 'filename' -- return value: true=ok | errors: false=file not found or could not be opened
        bool load(); //calls 'load(const char path[])' with 'std_file_name' and 'std_file_ending'
        bool save(const char path[]); //saves 'logstr' to file 'path' or overwrites it (!) -- return value: true=ok | errors: false=file could not be opened
        bool save(); //calls 'save(const char path[])' with 'std_file_name' and 'std_file_ending'
        void add(std::string s); //add normal entry
        void err(std::string s); //add error entry

        //mode switches
        void echo_on();
        void echo_off();

        //print methods
        void print(unsigned int entry); //displays 'logstr[entry]'
        void print(unsigned int start, unsigned int end); //displays 'logstr[start]' to 'logstr[end]' -- if end<start logstr[start] to logstr[entries] will be displayes
        void print(); //displays whole content of 'logstr'

    private:
        void send_console(); //sends last entry to standard output -- used to print new log entry
};


#endif // LOG_H_INCLUDED
