#include <iostream>
#include <string>
#include <functional>
#include <map>

#include "cmd.h"

using namespace std;

// map<string, void(*)(const string&)> function_map;
// TODO: check std::functional
map<string, function<void(const string &)>> function_map;

int main(int argc, char *args[])
{
    cout << "Hello git user" << endl;
    switch (argc)
    {
    case 1:
        print_help();
        break;
    default:
        parse_arguments(argc, args);
    }
    return 0;
}