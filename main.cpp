#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "tokenization.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Error: wrong usage. Use:" << endl;
        cerr << "br <input.br>" << endl;
        return EXIT_FAILURE;
    }

    string contents;
    {
        stringstream contents_stream;
        fstream input(argv[1], ios::in);
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
    }

    vector<Token> tokens = tokenize(contents);

    return 0;
}