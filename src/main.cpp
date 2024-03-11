// libs
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

// heads
#include "headers/tokenization.hpp"
#include "headers/tree.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    // check if compiler has right args
    if (argc != 2) {
        cerr << "Error: wrong usage. Use:" << endl;
        cerr << "br <input.br>" << endl;
        return EXIT_FAILURE;
    }

    // read src code
    
    string contents;
    stringstream contents_stream;
    fstream input(argv[1], ios::in);
    contents_stream << input.rdbuf();
    contents = contents_stream.str();

    vector<Token> tokens = tokenize(contents);

    for (int i = 0; i < tokens.size(); i++) {
        cout << tokens[i].value << " ";
    }

    cout << endl;

    return 0;
}
