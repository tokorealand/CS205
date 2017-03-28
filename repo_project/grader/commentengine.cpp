#include "commentengine.h"

CommentEngine::CommentEngine(DBTool *tool, std::string table):DBTable(tool,table)
{

}

CommentEngine::~CommentEngine()
{

}

void CommentEngine::add_comment(std::string comment)
{

    comment_list.push_back(comment);
}

void CommentEngine::remove_comment(int id)
{
    comment_list.erase(comment_list.begin()+id);
}

std::string CommentEngine::get_comment(int id)
{

}
