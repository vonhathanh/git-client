#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <errno.h>
#include "handlers.h"
#include "cmd.h"
#include "constants.h"

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

void create_branch(const char* name) {
    struct stat info;
    string path = BRANCH_DIR + '/' + string(name);
    if (stat(path.c_str(), &info) != 0) {
        if (errno == EACCES)
        {
            cout << "EACCES: Permission denied\n";
        }
        else if (errno == EIO)
        {
            cout << "EIO: I/O error\n";
        }
        else if (errno == ELOOP)
        {
            cout << "ELOOP: Too many symbolic links\n";
        }
        else if (errno == ENAMETOOLONG)
        {
            cout << "ENAMETOOLONG: Path too long\n";
        }
        else if (errno == ENOENT)
        {
            cout << "OK" << endl;
            ofstream file;
            file.open(path, ios::out);
            if (!file) {
                cout << "Can't create file at: " << path << endl;
                return;
            }
            file.write(name, strlen(name));
            file.close();
        }
        else if (errno == ENOTDIR)
        {
            cout << "ENOTDIR: Not a directory\n";
        }
        else if (errno == EOVERFLOW)
        {
            cout << "EOVERFLOW: Value cannot fit in struct stat\n";
        }
        else
        {
            cout << "Unknown errno = " << errno << endl;
        }
    } else {
        cout << "Branch " << name << " already existed" << endl;
    }
}

void checkout(const char *branch, char *options[] = nullptr, char *flags[] = nullptr)
{
    if (options == nullptr) return;
    if (strcmp(options[0],"-b")) {
        create_branch(branch);
    }
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
        if (errno == EACCES)
        {
            cout << "EACCES: Permission denied\n";
        }
        else if (errno == EIO)
        {
            cout << "EIO: I/O error\n";
        }
        else if (errno == ELOOP)
        {
            cout << "ELOOP: Too many symbolic links\n";
        }
        else if (errno == ENAMETOOLONG)
        {
            cout << "ENAMETOOLONG: Path too long\n";
        }
        else if (errno == ENOENT)
        {
            cout << "Initializing new git repository...\n";
            // three main flags: read, write, execute
            // three distinct entities: owner(u), group(g), others(o)
            // read = 4, write = 2, execute = 1, 7 = read + write + execute
            // 700 -> only owner has the right to read/write/.execute
            mkdir(GIT_DIR.c_str(), 0700);
            mkdir(BRANCH_DIR.c_str(), 0700);
            mkdir(COMMIT_DIR.c_str(), 0700);
            create_branch("master");
            checkout("master");
        }
        else if (errno == ENOTDIR)
        {
            cout << "ENOTDIR: Not a directory\n";
        }
        else if (errno == EOVERFLOW)
        {
            cout << "EOVERFLOW: Value cannot fit in struct stat\n";
        }
        else
        {
            cout << "Unknown errno = " << errno << endl;
        }
        return;
    }

    if (info.st_mode & S_IFDIR)
    {
        cout << ".git is already existed" << endl;
    }
    else if (info.st_mode & S_IFREG)
    {
        cout << ".git is a file, you should delete it and run git init again\n";
    }
    else
    {
        cout << "Something went wrong during `git init`" << endl;
    }
}