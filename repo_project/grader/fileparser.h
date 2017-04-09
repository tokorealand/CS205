#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <iostream>
#include <fstream>
#include <QTCore/qdiriterator.h>



using namespace std;


class FileParser{

public:
    FileParser(string );
    ~FileParser();
    void parse_student_file();
    void parse_lab_file();
    void parse_java_file(string);

private:
    string fileName;
    ifstream file;
};

#endif // FILEPARSER_H
