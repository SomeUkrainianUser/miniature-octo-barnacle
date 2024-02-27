#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "tokenization.h"

using namespace std;

int main(int argc, char* argv[]) {
    // check if compiler has right args
    if (argc != 2) {
        cerr << "Error: wrong usage. Use:" << endl;
        cerr << "br <input.br>" << endl;
        return EXIT_FAILURE;
    }

    // readin src code
    string contents;
    {
        stringstream contents_stream;
        fstream input(argv[1], ios::in);
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
    }

    // lexer lexin src code
    vector<Token> tokens = tokenize(contents);

    return 0;
}