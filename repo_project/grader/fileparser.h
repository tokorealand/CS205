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
    string parse_student_file(string);
    void parse_lab_file(string);
    vector<string> parse_java_file(string);

private:
    string fileName;
    ifstream file;
    Grader*grader;
    vector<vector<string>> classAndClassContentsVector;
    vector<string> labIDList;
};

#endif // FILEPARSER_H
