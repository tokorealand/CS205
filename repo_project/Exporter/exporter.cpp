#include "exporter.h"

/**
 * @brief Exporter::Exporter
 *
 * Exporter constructor.
 */
Exporter::Exporter(){
}

/**
 * @brief Exporter::~Exporter
 *
 * Exporter deconstructor.
 */
Exporter::~Exporter(){
}

/**
 * @brief Exporter::combine_lab
 * @param currentLab
 * @param currentClass
 * @param rubricIndex
 *
 * writes the file
 */
void Exporter::combine_lab(Lab* currentLab, Class *currentClass, int rubricIndex){

    this->rubricIndex = rubricIndex;
    this->currentClass = currentClass;

    //create a name for the class
    string name = currentLab->get_id() + "-" + currentLab->get_lab_name() + ".html";

    this->currentLab = currentLab;
    ofstream oss;
    string filepathclass ="./ExportedFiles/"+currentClass->get_id();
    string filepathlab ="./ExportedFiles/"+currentClass->get_id()+"/"+currentLab->get_lab_num();

    mkdir("./ExportedFiles",S_IRWXU);
    mkdir(filepathclass.c_str(),S_IRWXU);
    mkdir(filepathlab.c_str(),S_IRWXU);

    oss.open(filepathlab+"/"+name);

    oss << "<html>" << endl;
           oss << get_textof()<<endl;

    //end writing the file
    oss << "</html>" << endl;

    //close the file writer
    oss.close();
}

/**
 * @brief Exporter::get_textof
 * @return a string containing the full lab plus comments plus the rubric
 *
 * starts combining the lab with the text of the comments and rubrics
 */
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
    }
    whole += get_rubric();

   return whole;
}

/**
 * @brief Exporter::get_rubric
 * @return a string of the final rubric with point totals and section text
 */
string Exporter::get_rubric(){

    string rubricDrawing = "<br>RUBRIC <br>";

    //get a rubric
    RubricObject *rubric = currentClass->get_rubrics().at(rubricIndex);

    //write a rubric section
    for(int i = 0; i < rubric->get_rubric_sections().size(); i++){
        RubricSection *rs  = rubric->get_rubric_sections().at(i);

        rubricDrawing+= "<pre>" + font_color(rs->get_color()) + rs->get_description() + ": " + get_points_off(rs, stoi(rs->get_points())) + " / " + rs->get_points() + "</pre>";

    }
    return rubricDrawing;
}

/**
 * @brief Exporter::get_points_off
 * @param rs
 * @param total
 * @return the string of the points off the given section
 */
string Exporter::get_points_off(RubricSection *rs, int total){

    //track points off section
    int ptsOffThisSection = 0;

    //for all the components
    for(int i = 0; i < currentLab->get_components().size(); i ++){
        currentComponent = currentLab->get_components().at(i);

        //for all the comments in the component
        for(int j = 0; j < currentComponent->get_comments().size(); j++){

            //get the current comment
            Comment* currentComment = currentComponent->get_comments().at(j);

            if(currentComment->get_deleted() == false)
            {
                //get the rubric section that the comment corresponds to
                string currentRS = currentComment->get_rubric_section();

                if(currentRS == rs->get_description()){ //if the section matches
                    ptsOffThisSection+=currentComment->get_points_deducted(); //add points to point total
                }
            }
        }
    }
    return to_string(total - ptsOffThisSection);
}


/**
 * @brief Exporter::parse_line
 * @param line
 * @param currentLab
 * @param lineNo
 * @return parsed line of code
 *
 * parses a line of code according to the comments
 */
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

         string colorTemp = "";

        //check if a rubric color is specified
        if(currentComment->get_rubric_section() != ""){
            RubricObject *rubric = currentClass->get_rubrics().at(rubricIndex);
            for(int i = 0; i < rubric->get_rubric_sections().size(); i++){
                if(rubric->get_rubric_sections().at(i)->get_description() == currentComment->get_rubric_section()){
                    colorTemp = rubric->get_rubric_sections().at(i)->get_color();
                }
            }
            fontColor = font_color(colorTemp);
        }

        //check if a highlight is specified
        if(currentComment->get_highlight() == true){
            highlight = "<mark>";
            endHighlight = "</mark>";
        }

        //check if comment text is specified
        if(currentComment->get_comment_text() != ""){
            commentText = "<b>"+ fontColor + string("     #") + currentComment->get_comment_text() + " -" + to_string(currentComment->get_points_deducted()) + "</b>" + "</pre>";
        }

        htmlLine = "<pre>" +  highlight + line  + endHighlight;

    }else{

        htmlLine = string("<pre>") + fontColor + line + "</pre>";
    }
    return htmlLine + commentText;
}

/**
 * @brief Exporter::get_finished
 * @return the finished string
 */
string Exporter::get_finished(){
    return "";
}

/**
 * @brief Exporter::space
 * @return a space string
 */
string Exporter::space(){
    return " ";
}

/**
 * @brief Exporter::enter
 * @return an enter
 */
string Exporter::enter(){
    return "\n";
}

/**
 * @brief Exporter::bold
 * @return bold symbol for html
 */
string Exporter::bold(){
    return "<b>";
}

/**
 * @brief Exporter::font_color
 * @param color
 * @return the string of the color
 */
string Exporter::font_color(string color){
    if(color == "red"){
        return "<font color = 'red'>";
    }else if (color == "cyan"){
        return "<font color = 'cyan'>";
    } else if(color == "magenta"){
        return "<font color = 'pink'>";
    } else if(color == "green"){
        return "<font color = 'green'>";
    } else if(color == "blue"){
        return "<font color = 'blue'>";
    } else if(color == "yellow"){
        return "<font color = 'yellow'>";
    }else{
        return "<font color = 'orange'>";
    }
}
