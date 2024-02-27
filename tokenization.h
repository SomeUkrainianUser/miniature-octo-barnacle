#pragma once
#include <iostream>
#include <optional>
#include <string>
#include <vector>

using namespace std;

enum TokenType {
    int_t,
    string_t,
    char_t,
    float_t,
    bool_t,
    True,
    False,
    function,
    if_s,
    while_s,
    ext,
    int_literal,
    float_literal,
    name,
    semicolon
};

struct Token {
    TokenType type;
    optional<string> value;
};

vector<Token> tokenize(string code) {
    string buffer;
    vector<Token> tokens;
    int len = code.length();
    for (int i = 0; i < len; i++) {
        char c = code.at(i);
        if (isalpha(c)) {
            while (isalpha(code.at(i+1))) {
                buffer.push_back(code.at(i+1));
                i++;
            }
            
            if (code.substr(i, 4) == "exit") {
                i += 4;
                tokens.push_back({ext});
            } else if (code.substr(i, 3) == "int") {
                i += 3;
                tokens.push_back({int_t});
            } else if (code.substr(i, 5) == "float") {
                i += 5;
                tokens.push_back({float_t});
            } else if (code.substr(i, 4) == "char") {
                i += 4;
                tokens.push_back({char_t});
            } else if (code.substr(i, 6) == "string") {
                i += 6;
                tokens.push_back({string_t});
            } else if (code.substr(i, 7) == "boolean") {
                i += 7;
                tokens.push_back({bool_t});
            } else if (code.substr(i, 4) == "true") {
                i += 4;
                tokens.push_back({True});
            } else if (code.substr(i, 5) == "false") {
                i += 5;
                tokens.push_back({False});
            } else if (code.substr(i, 8) == "function") {
                i += 8;
                tokens.push_back({function});
            }
        } else if (isdigit(c)) {

        } else if (c == ' ') continue;
        else if (c == ';') tokens.push_back({semicolon});
    }
    return tokens;
}