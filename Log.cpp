/* Copyright (C) 2011 by Felix Wiemuth
   This code is licensed under the GNU GENERAL PUBLIC LICENSE http://www.gnu.org/licenses/gpl.txt */

#include "Log.h"

#include <string>
#include <fstream>
#include <iostream>


using namespace std;

Log::Log()
{
    add("Logging done by Log 1.0");
    add("--- Begin logging now ---");
}

bool Log::load(const char path[])
{
    logstr.clear();
    ifstream infile(path); //create filestream to read, open file
    if (infile.is_open() == false)
        return false; //file not found or couldn´t be opened -> abort and return false

    string line; //buffer for single lines of the file

    //TODO eof() correct?
    while ( !(infile.eof()) )
    {
        getline(infile, line);
        logstr.push_back(line);
    }

    infile.close(); //close filestream

    return true; //return true = O.K.
}

//TODO last line is written twice into text-file!
bool Log::save(const char path[])
{
    ofstream file(path, ios::trunc); //create filestream to write, open file
    if (file.is_open() == false)
        return false; //file not opended -> abort and return false

    for(int i=0; i < logstr.size(); i++) //write line by line into textfile
    {
        file << logstr[i] + "\n";
    }
    file << logstr.back(); //write last line without creating new line

    file.close(); //close file filestream

    return true; //return true = O.K.
}

void Log::add(string s)
{
    logstr.push_back(s);
    send_console();
}

void Log::err(std::string s)
{
    logstr.push_back("ERR: " + s);
    send_console();
}

void Log::print(unsigned int entry)
{
    if (entry >= logstr.size())
        return; //catching out of range
    cout << logstr[entry] << endl;
}

void Log::print(unsigned int start, unsigned int end)
{
    if (end == 0)
        end = logstr.size()-1;
    if ( (end > logstr.size()-1) || (start > end) )
        return; //catching out of range

    for (int i=start; i <= end; i++)
    {
        cout << logstr[i] << endl;
    }
}

void Log::print()
{
    for (int i=0; i < logstr.size(); i++)
    {
        cout << logstr[i] << endl;
    }
}

void Log::send_console()
{
    cout << ">>> " << logstr.back() << endl; //send every log entry to standard output
}
