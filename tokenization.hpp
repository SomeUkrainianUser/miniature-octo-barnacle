#pragma once
#include <iostream>
#include <optional>
#include <string>
#include <vector>

using namespace std;

// token types
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
    id,
    semicolon
};

string foo(string code, int i) {
    string buffer;
    
    buffer.push_back(code[i]);
    while (isalnum(code[i+1])) {
        buffer.push_back(code[i+1]);
        i++;
    }

    return buffer;
}

// token itself
struct Token {
    TokenType type;
    string value;
};

// lexin func
vector<Token> tokenize(string code) {
    string buffer;
    vector<Token> tokens;
    int len = code.length();
    for (int i = 0; i < len; i++) {
        char c = code.at(i);
        if (isalpha(c)) {
            string token = foo(code, i);
            if (token == "exit") {
                i += 4;
                tokens.push_back({ext, "exit"});
            } else if (token == "int") {
                i += 3;
                tokens.push_back({int_t, "int_t"});
            } else if (token == "char") {
                i += 4;
                tokens.push_back({char_t, "char_t"});
            } else if (token == "string") {
                i += 6;
                tokens.push_back({string_t, "string_t"});
            } else if (token == "boolean") {
                i += 7;
                tokens.push_back({bool_t, "bool_t"});
            } else if (token == "true") {
                i += 4;
                tokens.push_back({True, "True"});
            } else if (token == "false") {
                i += 5;
                tokens.push_back({False, "False"});
            } else if (token == "function") {
                i += 8;
                tokens.push_back({function, "function"});
            } else {
                i += token.length();
                tokens.push_back({id, token});
            }
        } else if (isdigit(c)) {

        } else if (c == ' ') continue;
        else if (c == ';') tokens.push_back({semicolon, ";"});
    }
    return tokens;
}