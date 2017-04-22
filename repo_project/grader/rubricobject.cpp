#include "rubricobject.h"
#include <iostream>

using namespace std;

RubricObject::RubricObject(){
}

void RubricObject::operator = (RubricObject &obj) {
    this->rubricSections = obj.rubricSections;
    this->pointTotals = obj.pointTotals;
    this->sectionColors = obj.sectionColors;
    this->totalPoints = obj.totalPoints;
    this->size = obj.size;
    //SHOW_WHERE
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
    size++;
}

void RubricObject::set_point_totals(string pointTotal){
    pointTotals.push_back(pointTotal);
    cout << "points: " << pointTotals.at(pointTotals.size()-1) << endl;
}

void RubricObject::set_section_colors(string color){
    sectionColors.push_back(color);
    cout << "colors: " << sectionColors.at(sectionColors.size()-1) << endl;
}

void RubricObject::set_total_points(string totalPoints){
    this->totalPoints = totalPoints;
    cout << "point total: " << totalPoints << endl;
}

int RubricObject::get_size(){
    cout << "size " + size << endl;
    return size;
}

string RubricObject::get_section_at(int i){
    return rubricSections.at(i);
}

string RubricObject::get_section_text_at(int i){
    return rubricSections.at(i);
}

string RubricObject::get_color_at(int i){
    cout << "colorsA: " << sectionColors.at(sectionColors.size()-1) << endl;
    return sectionColors.at(i);
}
