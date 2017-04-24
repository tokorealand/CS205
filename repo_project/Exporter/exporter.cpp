#include "exporter.h"

Exporter::Exporter(){
}

Exporter::~Exporter(){
}

void Exporter::parse_file(Lab* currentLab){

    this->currentLab = currentLab;

    //get the components from this lab
    vector<Component*> componentVector = currentLab->get_components();


    //for each class in the submission
    for(int i = 0; i < componentVector.size(); i++){

        currentComponent = componentVector.at(i);

        //get a current class
        vector<string> classTemp = currentComponent->get_text_lines();

        //create a name for the class
        string name = currentLab->get_id() + "-" + currentLab->get_lab_name() + "-"
                             + string("class") + to_string(i) + ".html";
        //open a file writer
        ofstream ofs;
        cout << "name" << name << endl;
        ofs.open(name);

        //begin writing the file
        ofs << "<html>" << endl;

        //for each line in the class
        for(int j = 0; j < classTemp.size(); j++){
            string lineTemp = to_string(j) + string(" ") + classTemp.at(j);
            ofs << parse_line(lineTemp, currentLab, j) << endl;
        }

        //end writing the file
        ofs << "</html>" << endl;

        //close the file writer
        ofs.close();
    }
}


//parses a line of code according to the comments
string Exporter::parse_line(string line, Lab *currentLab, int lineNo){

    string htmlLine; //final line saved to html file

    //initialize everything as empty
    string bold = "";
    string highlight = "";
    string fontColor = "<font color = 'black'>";
    string commentText = "";
    string endBold = "";
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
            commentText = "<b>"+ fontColor + string("     #") + currentComment->get_comment_text() + "</b>" + "</p>";





        }

        htmlLine = "<p>" +  highlight + line  + endHighlight;

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
