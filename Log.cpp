/* Copyright (C) 2011 by Felix Wiemuth
   This code is licensed under the GNU GENERAL PUBLIC LICENSE http://www.gnu.org/licenses/gpl.txt */

#include "Log.h"

#include <string>
#include <fstream>
#include <iostream>


using namespace std;

Log::Log()
{
    init();
    log_info();
}

Log::Log(const char path[])
{
    load(path);
    init();
    log_info();
}

void Log::init()
{
    echo_on();
    reset_messages();
}

void Log::reset_messages()
{
    file_ending = ".log";
    file_name = "log";
    seperator = "\n";
    output_symbol = ">>> ";
    error_symbol = "ERR: ";
    msg_log_info = "Logging done by SimpleLog ALPHA";
    msg_begin_log = "--- Begin logging now ---";
}

void Log::log_info()
{
    add(msg_log_info);
    add(msg_begin_log);
}

bool Log::load(const char path[])
{
    logstr.clear();
    ifstream infile(path); //create filestream to read, open file
    if (infile.is_open() == false)
        return false; //file not found or couldn´t be opened -> abort and return false

    string line; //buffer for single lines of the file

    while ( !(infile.eof()) )
    {
        getline(infile, line);
        logstr.push_back(line);
    }

    infile.close(); //close filestream

    return true; //return true = O.K.
}

bool Log::load()
{
    return load((file_name + file_ending).c_str());
}

bool Log::save(const char path[])
{
    ofstream file(path, ios::trunc); //create filestream to write, open file
    if (file.is_open() == false)
        return false; //file not opended -> abort and return false

    for(vector<string>::iterator entry = logstr.begin(); entry != logstr.end(); ++entry) //write line by line into textfile
    {
        file << *entry << seperator;
    }
    file << logstr.back(); //write last line without creating new line

    file.close(); //close file filestream

    return true; //return true = O.K.
}

bool Log::save()
{
    return save((file_name + file_ending).c_str());
}

void Log::add(string s)
{
    logstr.push_back(s);
    if (echo_msg)
        send_console();
}

void Log::err(std::string s)
{
    logstr.push_back(error_symbol + s);
    if (echo_err)
        send_console();
}

void Log::echo_on()
{
    echo_msg = true;
    echo_err = true;
}

void Log::echo_off()
{
    echo_msg = false;
    echo_err = false;
}

void Log::echo_msg_on()
{
    echo_msg = true;
}

void Log::echo_msg_off()
{
    echo_msg = false;
}

void Log::echo_err_on()
{
    echo_err = true;
}

void Log::echo_err_off()
{
    echo_err = false;
}

void Log::set_file_ending(std::string file_ending)
{
    this->file_ending = file_ending;
}
void Log::set_file_name(std::string file_name)
{
    this->file_name = file_name;
}
void Log::set_seperator(std::string seperator)
{
    this->seperator = seperator;
}
void Log::set_output_symbol(std::string output_symbol)
{
    this->output_symbol = output_symbol;
}
void Log::set_error_symbol(std::string error_symbol)
{
    this->error_symbol = error_symbol;
}
void Log::set_msg_begin_log(std::string msg_begin_log)
{
    this->msg_begin_log = msg_begin_log;
}

void Log::print(unsigned int entry)
{
    if (entry >= logstr.size())
        return; //catching out of range
    cout << logstr[entry] << endl;
}

void Log::print(unsigned int start, unsigned int end)
{
    vector<string>::iterator last;
    if ( (end > logstr.size()-1) || (start > end) )
        last = logstr.end();
    else
        last = logstr.begin() + end + 1;

    for (vector<string>::iterator entry = logstr.begin() + start; entry != last; ++entry)
    {
        cout << *entry << endl;
    }
}

void Log::print()
{
    for (vector<string>::iterator entry = logstr.begin(); entry != logstr.end(); ++entry)
    {
        cout << *entry << endl;
    }
}

void Log::send_console()
{
    cout << output_symbol << logstr.back() << endl; //send every log entry to standard output
}

