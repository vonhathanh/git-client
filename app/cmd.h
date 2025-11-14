#include <string>
#include "types.h"

using namespace std;

void print_help();
void help(Command cmd);
void print_command(const string &command, const string &guide);
void print_args(char *args[], string arg_name = "");
void run_command(char *commands[], char *options[], char *flags[]);
void parse_arguments(int argc, char *args[]);