#include<iostream>
#include "handlers.h"
#include "cmd.h"

using namespace std;

void clone(char *commands[], char *options[], char *flags[]) {
    if (commands[0] == nullptr) {
        help(Clone);
    } else {
        clone_repository(commands[0], options, flags);
    }
}

void init(char *commands[], char *options[], char *flags[]) {
    if (commands[0] == nullptr) {
        help(Init);
    } else {
        init_repository(commands[0], options, flags);
    }
}

void add(char *commands[], char *options[], char *flags[]) {
    // add files/directory to the index
    // usage: git add file1.txt file2.txt
    // git add ./
    // git add ./*.txt
}

void rm(char *commands[], char *options[], char *flags[]) {
    // remove files/directory from the index
    // usage: same with git add
}

void diff(char *commands[], char *options[], char *flags[]) {
    // output the changes of a single or multiple files compared to the lastest commit
    // usage: git diff (output all diff)
    // git diff file1.txt file2.txt
}

void log(char *commands[], char *options[], char *flags[]) {
    // logs all commit history in the current branch
}

void clone_repository(char* repo_url, char *options[], char *flags[]) {
    // validate url format, perform HEAD request to the repo_url, check response status
    // call GET repo_url to download the repo to cwd
    // if its private repo then sign the request with ssh key
}

void init_repository(char* repo_path, char *options[], char *flags[]) {
    // create & init index file
    // init default local branch
    // init report: staged area, temp area
    cout << "Repository is initialized" << endl;
}