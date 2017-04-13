#include "rubricobject.h"

using namespace std;

RubricObject::RubricObject(Lab aLab){
}

//getters
vector<string> RubricObject::get_rubric_sections(){
    return rubricSections;
}

vector<string> RubricObject::get_point_totals(){
    return pointTotals;
}

vector<string> RubricObject::get_section_colors(){
    return sectionColors;
}

string RubricObject::get_total_points(){
    return totalPoints;
}

//setters
void RubricObject::set_rubric_sections(string rubricSection){
    rubricSections.push_back(rubricSection);
}

void RubricObject::set_point_totals(string pointTotal){
    pointTotals.push_back(pointTotal);
}

void RubricObject::set_section_colors(string color){
    sectionColors.push_back(color);
}

void RubricObject::set_total_points(string totalPoints){
    this->totalPoints = totalPoints;
}
