#ifndef EXPORTER_H
#define EXPORTER_H

#include "string"
#include <fstream>
#include <iostream>
#include "../grader/comment.h"
#include "../grader/lab.h"
#include "../grader/component.h"
#include "../grader/rubricobject.h"
#include "../grader/class.h"

/**
 * @brief The Exporter class
 *
 * Takes a lab and puts it together with the rubric and comments and exports
 * the html file.
 */
class Exporter{

public:

    //construction
    Exporter();
    ~Exporter();

    //methods

    //void new_file(Lab lab);
    void parse_file(Lab *currentLab);
    void combine_lab(Lab *currentLab, Class *selectedClass, int rubricIndex);
    string parse_line(string line, Lab *currentLab, int lineNo);
    string space();
    string enter();
    string font_color(string color);
    string bold();
    string get_finished();
    string get_textof();
    string get_rubric();
    string get_points_off(RubricSection *rs, int total);

    //variables
    Lab* currentLab;
    Component *currentComponent;
    Class *currentClass;
    string fileString;
    vector<string> codeByLine;
    vector<vector<string>> codeLinesByClass;
    int rubricIndex;

};

#endif // EXPORTER_H
