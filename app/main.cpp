#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void print_command(string command, string guide) {
    cout << "    " << setw(10) << left << command << guide << endl;
}


int main(int argc, char* args[]) {
    cout << "Hello git user" << endl;
    switch (argc) {
        case 1: 
            cout << "usage: git --options <command> [args]" << endl;
            cout << "commond Git commands in various situations" << endl;
            cout << endl;

            cout << "start a working area (see also: git help tutorial)" << endl;
            print_command("clone", "Clone a repositor into a new directory");
            print_command("init", "Create an empty Git repository or reinitialize an existing one");
            cout << endl;

            cout << "work on the current change (see also: git help everyday)" << endl;
            print_command("add", "Add file contents to the index");
            print_command("rm", "Remove files from the working tree and from the index");
            cout << endl;

            cout << "examine the history and state" << endl;
            print_command("diff", "Show changes between commits");
            print_command("log", "Show commit logs");
            cout << endl;

            cout << "grow, mark and tweak your common history" << endl;
            print_command("branch", "List, create, or delete branches");
            print_command("commit", "Record changes to the repository");
            print_command("merge", "Join two or more development histories together");
            print_command("rebase", "Reapply commits on top of another base tip");
            print_command("reset", "Reset current HEAD to the specified state");
            print_command("checkout", "Switch to specific git commit/branch or create & move to new branch");
            cout << endl;

            cout << "collaborate" << endl;
            print_command("fetch", "Download objects and refs from another history");
            print_command("pull", "Fetch from and integrate with another repository or a local branch");
            print_command("push", "Update remote refs along with assoicated objects");
            cout << endl;
    }
    return 0;
}