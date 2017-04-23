#ifndef RUBRICOBJECT_H
#define RUBRICOBJECT_H

#include "string"
#include "vector"

using namespace std;

class Lab;
class MainWindow;
class AddLabsGUI;
class RubricCreatorGUI;

class RubricObject{

public:
    //constructors
    RubricObject();

    void operator=(RubricObject &obj); //copy assignment

    //getters
    vector<string> get_rubric_sections();
    vector<string> get_point_totals();
    vector<string> get_section_colors();
    string get_total_points();
    string get_section_at(int i);
    string get_section_text_at(int i);
    string get_color_at(int i);
    int get_size();

    //setters
    void set_rubric_sections(string rubricSection);
    void set_point_totals(string pointTotal);
    void set_section_colors(string color);
    void set_total_points(string totalPoints);

    int size = 0;

private:
    vector<string> rubricSections;
    vector<string> pointTotals;
    vector<string> sectionColors;
    string totalPoints;
};

#endif // RUBRICOBJECT_H
