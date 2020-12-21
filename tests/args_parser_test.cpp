//
// Created by L. Jiang on 2020/12/21.
//

#include <iostream>
#include <ismdeep-cpp-utils/ArgsParser.h>

using namespace std;


int main(int argc, const char *argv[]) {
    // -n 1 -in hello.dat --save
    ArgsParser argsParser(argc, argv);
    cout << argsParser.get_int("-n") << endl;
    cout << argsParser.get_string("-in") << endl;
    cout << argsParser.has("--save") << endl;

    return 0;
}