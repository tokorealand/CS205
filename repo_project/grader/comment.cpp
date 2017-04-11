#include "comment.h"

using namespace std;

Comment::Comment(string commentText, string rubricSection, double pointsDeducted, string highlightColor){

    this->commentText = commentText;
    this->rubricSection = rubricSection;
    this->pointsDeducted = pointsDeducted;
    this->highlightColor = highlightColor;

}

string get_get_comment_text(){
    return commentText;
}

string get_rubric_section(){
    return rubricSection;
}

double get_points_deducted(){
    return pointsDeducted;
}

string get_highlight_color(){
    return highlightColor;
}
