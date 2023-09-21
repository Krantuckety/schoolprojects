#ifndef LINE_INFO_H
#define LINE_INFO_H

#include <string>
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <sstream>

using namespace std;

string LineInfo(string const& errorstr, char const* file, long line)
{
    stringstream s;
    s << endl 
      << "Exception : " << errorstr << endl 
      << "File :      " << file     << endl 
      << "Line :      " << line     << endl << endl;
    return s.str();
}

#endif
