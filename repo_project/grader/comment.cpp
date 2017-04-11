#include "comment.h"

using namespace std;

Comment::Comment(string commentText, string rubricSection, double pointsDeducted, string highlightColor){

    this->commentText       = commentText;
    this->rubricSection     = rubricSection;
    this->pointsDeducted    = pointsDeducted;
    this->highlightColor    = highlightColor;

}

string Comment::get_comment_text(){
    return commentText;
}

string Comment::get_rubric_section(){
    return rubricSection;
}

double Comment::get_points_deducted(){
    return pointsDeducted;
}

string Comment::get_highlight_color(){
    return highlightColor;
}
