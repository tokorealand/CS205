#include "fileparser.h"
#include <qdiriterator.h>

FileParser::FileParser(string aFileName, Grader* aGrader){
    fileName = aFileName;
    grader   = aGrader;
    //parse_student_file();
    //parse_java_file("./Lab_1");
}


FileParser::~FileParser(){

}


//parses the student file
string FileParser::parse_student_file(string aFilePath){

    string studentInfo = "";

    try{
        file.open(aFilePath);
    }
    catch(const std::exception& e)
    {
        cout<<"ERROR File does not exist";
        cout<<'\n';
    }

    string s;

    while(getline(file , s))
    {

        string delim = ":";
        int start = 0;
        int end = s.find_first_of(delim);
        int len = end-start;

        string first_name = s.substr(start , len);
        start = end+1;
        end = s.find_first_of(delim, start);
        len = end-start;

        string last_name = s.substr(start,len);
        start = end+1;
        end = s.find_first_of(delim, start);
        len = end-start;

        string class_name = s.substr(start,len);
        start = end+1;
        end = s.find_first_of(delim, start)+1;
        len = end-start;

        string class_section = s.substr(start,len);
        start = end+1;
        end = s.find_first_of(delim, start)+1;
        len = end-start;


        string classID = class_name;
        string sectionID = class_name + "_" +class_section;
        string studentID = first_name + "_" + last_name;

        grader->add_class(classID, 0);
        grader->add_section(sectionID, classID);
        grader->add_student(studentID, sectionID, first_name, last_name);

        studentInfo = studentInfo + first_name + " " + last_name + " " + class_name +" " + class_section+" " +'\n';
        //        cout<<first_name + " " + last_name + " " + class_name +" " + class_section;
        //        cout<<'\n';
    }

    file.close();
    return studentInfo;
}

//parses a java class
void FileParser::parse_java_file(string aFilepath)
{

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
         parseEnd = lab.length();
         parseLen = parseEnd - parseStart;
         string lab_number= lab.substr(parseStart, parseLen);

          if(parseEnd != lab.npos)
          {

                string classID = class_name;
                string sectionID = class_name + "_" + section_number;
                string studentID = first_name + "_" + last_name;
                string labID = first_name + "_" + last_name + "_" +lab_number;
                string labName = first_name + "_" + last_name + "_" + class_name + "_" +  section_number + "_"+ lab_number;


                grader->add_class(classID, 0);
                grader->add_section(sectionID, classID);
                grader->add_student(studentID, sectionID, first_name, last_name);

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
                       string componentID = labID + "_" + componentName;
//                        cout<<componentName;
//                        cout<<'\n';

                            ifstream java;
                            java.open(component.toStdString());

                            string s;
                            string javaText = "";

                            while(getline(java,s))
                            {
                                javaText = javaText + s + '\n';
                            }

                           grader->add_component(componentID, labID, javaText);
                      }

                   }

                grader->add_lab(labID, studentID, labName, lab_number);
                cout<<"Lab Sucessfully added";
                cout<<'\n';
           }
    }

}


