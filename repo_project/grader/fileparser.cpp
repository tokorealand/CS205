#include "fileparser.h"
#include <QTCore/qdiriterator.h>

FileParser::FileParser(string aFileName, Grader* aGrader)
{
    fileName = aFileName;
    grader = aGrader;
    //parse_student_file();
   parse_java_file("./Lab_1");

}


FileParser::~FileParser()
{

}

void FileParser::parse_student_file()
{

    file.open(fileName);

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

        grader->add_class(class_name, 2);
        grader->add_section(class_section, class_name);
        grader->add_student(first_name+last_name, class_section, first_name, last_name);

        cout<<first_name + " " + last_name + " " + class_name +" " + class_section;
        cout<<'\n';
    }
    file.close();
}

void FileParser::parse_java_file(string aFilepath)
{
    vector<string> javafiles;
    QString filepath= QString::fromStdString(aFilepath);
    QDirIterator it(filepath, QDirIterator::NoIteratorFlags);

    while(it.hasNext())
    {

        QString labEntry = it.next();


        // lab submissions should be titled "firstname_lastname_classname_sectionnumber_labnumber"

        int parseStart = labEntry.toStdString().find(aFilepath);
        int parseEnd = labEntry.toStdString().length();
        int parseLen = parseEnd - parseStart;
        string lab = labEntry.toStdString().substr(parseStart, parseLen);

        parseStart = 0;
        parseEnd = lab.find("_");
        parseLen = parseEnd - parseStart;
        string firstname = lab.substr(parseStart, parseLen);


        parseStart = parseEnd+1 ;
        parseEnd = lab.find("_");
        parseLen = parseEnd - parseStart;
        string lastname = lab.substr(parseStart, parseLen);

        parseStart = parseEnd+1 ;
        parseEnd = lab.find("_");
        parseLen = parseEnd - parseStart;
        string classname = lab.substr(parseStart, parseLen);

        parseStart = parseEnd+1 ;
        parseEnd = lab.find("_");
        parseLen = parseEnd - parseStart;
        string sectionnumber = lab.substr(parseStart, parseLen);

        parseStart = parseEnd+1 ;
        parseEnd = lab.find("_");
        parseLen = parseEnd - parseStart;
        string labnumber= lab.substr(parseStart, parseLen);



        QDirIterator it2(labEntry, QDirIterator::NoIteratorFlags);

        while(it2.hasNext())
        {

            QString component=it2.next();


            parseStart = component.toStdString().find(".java");
            parseEnd = component.toStdString().length();
            parseLen = parseEnd - parseStart;



            if(parseStart !=component.toStdString().npos)
            {

                cout<<component.toStdString();
                cout<<'\n';

                ifstream java;

                java.open(component.toStdString());

                string s;
                string javaText = "";
                while(getline(java,s))
                {
                    javaText = javaText + s;
                }

                javafiles.push_back(javaText);

            }




         }


       }

}
