#include "fileparser.h"

FileParser::FileParser(string aFileName)
{
    fileName = aFileName;
    parse();
}


FileParser::~FileParser()
{

}

void FileParser::parse()
{

    file.open(fileName);

    string s;

    while(getline(file , s))
    {
        cout<<s;
        cout<<'/n';
    }
    file.close();
}
