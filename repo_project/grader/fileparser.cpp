#include "fileparser.h"
#include <qdiriterator.h>

/**
 * @brief FileParser::FileParser
 * Given a file path to a directory, will parse through all lab submission subdirectories
 * @param aGrader
 */
FileParser::FileParser(Grader* aGrader){
    grader   = aGrader;
}

/**
 * @brief FileParser::~FileParser
 */
FileParser::~FileParser(){
}

/**
 * @brief FileParser::parse_java_file
 * Parses lab sumbissions within the specified directory. Lab submissions must be formatted
 * in the following way "firstName_lastnName_class_section_labNum_semester_year".
 * Will only use .java files with each submission to generate components, ignoring all other file types
 * @param aFilepath
 * Path to directory containing file submissions
 * @return
 * a vector of lab IDs
 */
vector<string> FileParser::parse_java_file(string aFilepath){

    QString filepath= QString::fromStdString(aFilepath);

    QDirIterator it(filepath, QDirIterator::NoIteratorFlags);

    //for parsing the file name
    while(it.hasNext())
    {

        QString labEntry = it.next();

        // lab submissions should be titled "firstname_lastname_classname_sectionnumber_labnumber"

        int parseStart = filepath.length()+1;
        int parseEnd = labEntry.toStdString().length();
        int parseLen = parseEnd - parseStart;
        string lab = labEntry.toStdString().substr(parseStart, parseLen);

        cout<<lab;
        cout<<'\n';


        if(lab.compare(".") != 0 && lab.compare("..") != 0)
        {
            parseStart = 0;
            parseEnd = lab.find("_", parseStart);
            parseLen = parseEnd - parseStart;
            string first_name = lab.substr(parseStart, parseLen);

            parseStart = parseEnd+1 ;
            parseEnd = lab.find("_", parseStart);
            parseLen = parseEnd - parseStart;
            string last_name = lab.substr(parseStart, parseLen);

            parseStart = parseEnd+1 ;
            parseEnd = lab.find("_", parseStart);
            parseLen = parseEnd - parseStart;
            string class_name = lab.substr(parseStart, parseLen);

            parseStart = parseEnd+1 ;
            parseEnd = lab.find("_", parseStart);
            parseLen = parseEnd - parseStart;
            string section_number = lab.substr(parseStart, parseLen);

             parseStart = parseEnd+1 ;
             parseEnd = lab.find("_", parseStart);
             parseLen = parseEnd - parseStart;
             string lab_number= lab.substr(parseStart, parseLen);

             parseStart = parseEnd+1 ;
             parseEnd = lab.find("_", parseStart);
             parseLen = parseEnd - parseStart;
             string semester = lab.substr(parseStart, parseLen);

             parseStart = parseEnd+1 ;
             parseEnd = lab.length();
             parseLen = parseEnd - parseStart;
             string year = lab.substr(parseStart, parseLen);

                string yearID = year;
                string semesterID = semester+"_"+yearID;
                string classID = class_name+"_"+semesterID;
                string sectionID = section_number+"_"+classID;
                string studentID = first_name + "_" + last_name+"_"+sectionID;
                string labID = lab_number+"_"+studentID;
                string labName = first_name + "_" + last_name + "_" + class_name + "_" +  section_number + "_"+ lab_number;


                grader->add_year(yearID);
                grader->add_semester(semesterID, yearID);
                grader->add_class(classID, semesterID);
                grader->add_section(sectionID, classID);
                grader->add_student(studentID, sectionID, first_name, last_name);
                grader->add_lab(labID, studentID, labName, lab_number,"0");
                labIDList.push_back(labID);


                QDirIterator it2(labEntry, QDirIterator::NoIteratorFlags);
                while(it2.hasNext())
                {

                    QString component = it2.next();

                    parseStart  = labEntry.toStdString().length()+1;
                    parseEnd    = component.toStdString().find(".java");
                    parseLen    = parseEnd - parseStart;

                    if(parseEnd != component.toStdString().npos)
                    {

                       string componentName = component.toStdString().substr(parseStart, parseLen);
                       string componentID = componentName+"_"+labID;
                        cout<<componentID;
                        cout<<'\n';

                            ifstream java;
                            java.open(component.toStdString());

                            string s;
                            string javaText = "";


                            while(getline(java,s))
                            {
                                javaText = javaText + s + "\n";
                            }

                           grader->add_component(componentID, labID, javaText);
                      }
                   }
           }
    }
    return labIDList;
}


