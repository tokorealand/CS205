#ifndef EXPORTER_H
#define EXPORTER_H

#include "string"
#include <fstream>
#include <iostream>
#include "../grader/comment.h"
#include "../grader/lab.h"
#include "../grader/component.h"


class Exporter{

public:

    //construction
    Exporter();
    ~Exporter();


    //methods


    //void new_file(Lab lab);
    void parse_file(Lab *currentLab);
    void combine_lab(Lab *currentLab);
    string parse_line(string line, Lab *currentLab, int lineNo);
    string space();
    string enter();
    string highlight();
    string font_color(string color);
    string bold();
    string get_finished();
    string get_textof();

    //variables
    Lab* currentLab;
    Component *currentComponent;
    string fileString;
    vector<string> codeByLine;
    vector<vector<string>> codeLinesByClass;

};

#endif // EXPORTER_H
