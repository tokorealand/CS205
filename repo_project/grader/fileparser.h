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
    FileParser(Grader* );
    ~FileParser();
    vector<string> parse_java_file(string);

private:
    Grader*grader;
    vector<vector<string>> classAndClassContentsVector;
    vector<string> labIDList;
};

#endif // FILEPARSER_H
