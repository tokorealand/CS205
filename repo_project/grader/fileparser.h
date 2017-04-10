#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <iostream>
#include <fstream>
#include <QTCore/qdiriterator.h>
#include "grader.h"



using namespace std;

class Grader;
class FileParser{

public:
    FileParser(string, Grader* );
    ~FileParser();
    void parse_student_file();
    void parse_lab_file();
    void parse_java_file(string);

private:
    string fileName;
    ifstream file;
    Grader*grader;
};

#endif // FILEPARSER_H
