#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <iostream>
#include <fstream>
#include <qdiriterator.h>
#include "grader.h"
#include <vector>

using namespace std;

class Grader;
class FileParser{

public:
    FileParser(string, Grader* );
    ~FileParser();
    void parse_lab_file(string);
    void parse_java_file(string);

private:
    string fileName;
    ifstream file;
    Grader*grader;
    vector<vector<string>> classAndClassContentsVector;
};

#endif // FILEPARSER_H
