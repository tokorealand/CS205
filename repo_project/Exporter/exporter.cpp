#include "exporter.h"

Exporter::Exporter(){
}

Exporter::~Exporter(){
}

//writes the file
void Exporter::combine_lab(Lab* currentLab, Class *currentClass, int rubricIndex){

    this->rubricIndex = rubricIndex;
    this->currentClass = currentClass;

    //create a name for the class
    string name = currentLab->get_id() + "-" + currentLab->get_lab_name() + ".html";

    this->currentLab = currentLab;
    ofstream oss;
    oss.open(name);

    oss << "<html>" << endl;
           oss << get_textof()<<endl;

    //end writing the file
    oss << "</html>" << endl;

    //close the file writer
    oss.close();
}

//used to get a string containing all components
std::string Exporter::get_textof(){

    std::string whole;

    //get the components from this lab
    vector<Component*> componentVector = currentLab->get_components();

    for(int i = 0; i < componentVector.size(); i++){

            currentComponent = componentVector.at(i);

            //get a current class
            vector<string> classTemp = currentComponent->get_text_lines();
            currentComponent = componentVector.at(i);



    //for each line in the class
    for(int j = 0; j < classTemp.size(); j++){
        string lineTemp = to_string(j) + string(" ") + classTemp.at(j);
        whole+= parse_line(lineTemp, currentLab, j);
    }
    whole+="----------------------------------------------------------------------------------------------------------------------------------------------";
    whole += get_rubric();
    }
   return whole;
}

string Exporter::get_rubric(){

    string rubricDrawing = "RUBRIC <br>";

    //get a comment vector
    vector<Comment*> comments = currentComponent->get_comments();

    //get a rubric
    RubricObject *rubric = currentClass->get_rubrics().at(rubricIndex);

    //write a rubric section
    for(int i = 0; i < rubric->get_rubric_sections().size(); i++){
        RubricSection *rs  = rubric->get_rubric_sections().at(i);

        rubricDrawing+= "<pre>" + font_color(rs->get_color()) + rs->get_description() + ": " + get_points_off(rs, stoi(rs->get_points())) + "/" + rs->get_points() + "</pre>";
    }
}

string Exporter::get_points_off(RubricSection *rs, int total){

    //get comment vector
    vector<Comment*> com = currentComponent->get_comments();

    //track points off section
    int ptsOffThisSection = 0;

    //get all the comments for this section
    for(int i = 0; i<com.size(); i++){
        Comment *current = com.at(i);
        string currentRS = current->get_rubric_section();
        if(currentRS == rs->get_description()){ //if the section matches
            ptsOffThisSection+=current->get_points_deducted(); //add points to point total
        }
    }
    return to_string(total - ptsOffThisSection);
}

//parses a line of code according to the comments
string Exporter::parse_line(string line, Lab *currentLab, int lineNo){

    string htmlLine; //final line saved to html file

    //initialize everything as empty
    string bold         = "";
    string highlight    = "";
    string fontColor    = "<font color = 'black'>";
    string commentText  = "";
    string endBold      = "";
    string endHighlight = "";

    //if there is a comment for that line
    if(currentComponent->is_comment_at(lineNo)){

        //save an instance of the current comment
        Comment *currentComment = currentComponent->get_comment_at(lineNo);

        //check if a rubric color is specified
        if(currentComment->get_rubric_section() != ""){
            fontColor = font_color(currentComment->get_section_color());
        }
        //check if a highlight is specified
        if(currentComment->get_highlight() == true){
            highlight = "<mark>";
            endHighlight = "</mark>";
        }
        //check if comment text is specified
        if(currentComment->get_comment_text() != ""){
            commentText = "<b>"+ fontColor + string("     #") + currentComment->get_comment_text() + "</b>" + "</pre>";
        }

        htmlLine = "<pre>" +  highlight + line  + endHighlight;

    }else{

        htmlLine = string("<pre>") + fontColor + line + "</pre>";
    }
    return htmlLine + commentText;
}

//gets the finished string
string Exporter::get_finished(){
    return "";
}

string Exporter::space(){
    return " ";
}

string Exporter::enter(){
    return "\n";
}

string Exporter::bold(){
    return "<b>";
}

string Exporter::highlight(){
    return "<b>";
}

string Exporter::font_color(string color){
    if(color == "red"){
        return "<font color = 'red'>";
    }else if (color == "blue"){
        return "<font color = 'blue'>";
    } else if(color == "pink"){
        return "<font color = 'pink'>";
    } else if(color == "green"){
        return "<font color = 'green'>";
    }else{
        return "<font color = 'orange'>";
    }
}
