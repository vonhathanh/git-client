#include <string>
#include <iostream>
#include <iomanip>
#include "cmd.h"

using namespace std;

void print_command(const string &command, const string &guide)
{
    cout << "    " << setw(10) << left << command << guide << endl;
}

void print_help()
{
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

void print_args(char *args[], string arg_name)
{
    if (arg_name != "")
        cout << arg_name << ": ";
    // just plain args won't work because it's always point to something in the memory, we need *args
    // *args = args[0]
    while (*args)
    {
        // args[i] = *(args + i)
        cout << args[0];
        if (*(++args))
            cout << ", ";
    }
    cout << endl;
}

void run_command(char *commands[], char *options[], char *flags[])
{
    print_args(commands, "Commands");
    print_args(options, "Options");
    print_args(flags, "Flags");
}

// char *args[]: array of char pointer
// args[0] has type of: char*
void parse_arguments(int argc, char *args[])
{
    char *commands[4], *options[4], *flags[4];
    // initialize these variables by 0 because they are inside a function
    // their values are indeterminate (essentially random garbage)
    // HINT: remove the initialization and watch it by urself
    // Why this happen? init these variables cost CPU, the compiler choose to leave them with what were left from previous
    // function call instead of zeroing them.
    unsigned int cmd_idx = 0, opt_idx = 0, flag_idx = 0;

    for (int i = 1; i < argc; i++)
    {
        string argument = args[i];
        if (argument.find("--") == 0)
            options[opt_idx++] = args[i];
        else if (argument.find("-") == 0)
            flags[flag_idx++] = args[i];
        else
            commands[cmd_idx++] = args[i];
    }

    // same reason as above, they are not initialized to nullptr
    commands[cmd_idx] = nullptr;
    options[opt_idx] = nullptr;
    flags[flag_idx] = nullptr;

    run_command(commands, options, flags);
}