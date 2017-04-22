#ifndef EXPORTER_H
#define EXPORTER_H

#include "string"
#include <fstream>
#include <iostream>
#include "../grader/comment.h"
#include "../grader/lab.h"


class Exporter{

public:

    //construction
    Exporter();
    ~Exporter();


    //methods


    //void new_file(Lab lab);
    void parse_file(Lab *currentLab);
    string parse_line(string line, Lab *currentLab, int lineNo);
    string space();
    string enter();
    string highlight();
    string font_color(string color);
    string bold();
    string get_finished();

    //variables
    Lab* currentLab;
    string fileString;
    vector<string> codeByLine;
    vector<vector<string>> codeLinesByClass;

};

#endif // EXPORTER_H
