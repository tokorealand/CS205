#ifndef COMMENT_H
#define COMMENT_H

#include <vector>
#include <string>

using namespace std;
class Comment
{
public:
    Comment(string commentText, string rubricSection, double pointsDeducted, string highlightColor);
    string get_get_comment_text();
    string get_rubric_section();
    double get_points_deducted();
    string get_highlight_color();
private:
    string commentText;
    string rubricSection;
    double pointsDeducted;
    string highlightColor;
};

#endif // COMMENT_H
