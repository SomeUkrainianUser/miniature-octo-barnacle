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
    semicolon,
    colon,
    add,
    sub,
    mult,
    divide,
    assign,
    equ,
    more,
    lss,
    more_equ,
    less_equ,
    n_equ,
    c_and,
    c_or,
    nt,
    l_parent,
    r_parent,
    comma
};

// find id and keywords
string findStrToken(string code, int i) {
    string buffer;
    
    buffer.push_back(code[i]);
    while (isalnum(code[i+1])) {
        buffer.push_back(code[i+1]);
        i++;
    }

    return buffer;
}

// find numbers
string findNumToken(string code, int i) {
    string buffer;

    buffer.push_back(code[i]);
    while (isdigit(code[i+1])) {
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
    vector<Token> tokens;
    int len = code.length();
    for (int i = 0; i < len; i++) {
        char c = code.at(i);
        char c1 = code.at(i+1);
        if (isalpha(c)) {
            // finding token
            string token = findStrToken(code, i);

            //matching token with any keyword
            if      (token == "exit")       tokens.push_back({ext, "exit"});
            else if (token == "int")        tokens.push_back({int_t, "int_t"});
            else if (token == "char")       tokens.push_back({char_t, "char_t"});
            else if (token == "string")     tokens.push_back({string_t, "string_t"});
            else if (token == "boolean")    tokens.push_back({bool_t, "bool_t"});
            else if (token == "true")       tokens.push_back({True, "True"});
            else if (token == "false")      tokens.push_back({False, "False"});
            else if (token == "function")   tokens.push_back({function, "function"});
            else if (token == "assign")     tokens.push_back({assign, "assign"});
            else tokens.push_back({id, "id"});
            i += token.length() - 1;
        } else if (isdigit(c)) {
            string token = findNumToken(code, i);
            i += token.length() - 1;
            tokens.push_back({int_literal, "int_l"});
        } 
        else if (c == ' ') continue;
        else if (c == ';') tokens.push_back({semicolon, ";"});
        else if (c == ',') tokens.push_back({comma, ","});
        else if (c == '+') tokens.push_back({add, "+"});
        else if (c == '-') tokens.push_back({sub, "-"});
        else if (c == '*') tokens.push_back({mult, "*"});
        else if (c == '/') tokens.push_back({divide, "/"});
        else if (c == '=') tokens.push_back({equ, "="});
        else if (c == '>') tokens.push_back({more, ">"});
        else if (c == '<') tokens.push_back({lss, "<"});
        else if (c == '(') tokens.push_back({l_parent, "("});
        else if (c == ')') tokens.push_back({r_parent, ")"});
        else if (c == ':') tokens.push_back({colon, ":"});
        else if (c == '>' && c1 == '=') { i++; tokens.push_back({more_equ, ">="}); }
        else if (c == '<' && c1 == '=') { i++; tokens.push_back({less_equ, "<="}); }
        else if (c == '!' && c1 == '=') { i++; tokens.push_back({n_equ, "!="}); }
    }
    return tokens;
}