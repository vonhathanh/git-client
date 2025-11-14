#include <iostream>
#include <sys/stat.h>
#include "handlers.h"
#include "cmd.h"

using namespace std;

void clone(char *commands[], char *options[], char *flags[])
{
    if (commands[0] == nullptr)
    {
        help(Clone);
    }
    else
    {
        clone_repository(commands[0], options, flags);
    }
}

void init(char *commands[], char *options[], char *flags[])
{
    if (commands[0] == nullptr)
    {
        help(Init);
    }
    else
    {
        init_repository(commands[0], options, flags);
    }
}

void add(char *commands[], char *options[], char *flags[])
{
    // add files/directory to the index
    // usage: git add file1.txt file2.txt
    // git add ./
    // git add ./*.txt
}

void rm(char *commands[], char *options[], char *flags[])
{
    // remove files/directory from the index
    // usage: same with git add
}

void diff(char *commands[], char *options[], char *flags[])
{
    // output the changes of a single or multiple files compared to the lastest
    // commit usage: git diff (output all diff) git diff file1.txt file2.txt
}

void log(char *commands[], char *options[], char *flags[])
{
    // logs all commit history in the current branch
}

void clone_repository(char *repo_url, char *options[], char *flags[])
{
    // validate url format, perform HEAD request to the repo_url, check response
    // status call GET repo_url to download the repo to cwd if its private repo
    // then sign the request with ssh key
}

void checkout(char *commands[], char *options[], char *flags[])
{
    // read section 3.1 in readme.md
}

void init_repository(char *repo_path, char *options[], char *flags[])
{
    // check .git folder existence
    // if already exist -> display message for user
    // else:
    //  create .git folder
    //  create refs folder
    //  create commits folder
    //  create master branch in refs folder
    //  checkout to master branch
    //  create staged area
    //  create local repository
    struct stat info;
    if (stat("./.git", &info) != 0)
    {
        cout << "path is invalid" << endl;
        return;
    }
    if (info.st_mode & S_IFDIR)
    {
        cout << ".git is already existed" << endl;
    }
    else
    {
        cout << "Repository is initialized" << endl;
    }
}