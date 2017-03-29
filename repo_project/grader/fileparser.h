#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <iostream>
#include <fstream>

using namespace std;


class FileParser{

public:
    FileParser(string );
    ~FileParser();
    void parse();

private:
    string fileName;
    ifstream file;
};

#endif // FILEPARSER_H
