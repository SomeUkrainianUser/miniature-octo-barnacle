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
    else_s,
    for_s,
    while_s,
    ret,
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
    l_brace,
    r_brace,
    l_bracket,
    r_bracket,
    comma,
    ptr,
    endline,
    ampersand
};

struct Token {
    TokenType type;
    string value;
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


// lexin func
vector<Token> tokenize(string code) {
    vector<Token> tokens;
    int len = code.length();
    for (int i = 0; i < len; i++) {
        char c, c1; 
        c = code.at(i);
        try { c1 = code.at(i+1); }
        catch(out_of_range) { }
        if (isalpha(c)) {
            // finding token
            string token = findStrToken(code, i);

            //matching token with any keyword
            if      (token == "return")     tokens.push_back({ret, "return"});
            else if (token == "int")        tokens.push_back({int_t, "int_t"});
            else if (token == "char")       tokens.push_back({char_t, "char_t"});
            else if (token == "string")     tokens.push_back({string_t, "string_t"});
            else if (token == "boolean")    tokens.push_back({bool_t, "bool_t"});
            else if (token == "true")       tokens.push_back({True, "True"});
            else if (token == "false")      tokens.push_back({False, "False"});
            else if (token == "function")   tokens.push_back({function, "function"});
            else if (token == "assign")     tokens.push_back({assign, "assign"});
            else if (token == "if")         tokens.push_back({if_s, "if"});
            else if (token == "else")       tokens.push_back({else_s, "else"});
            else if (token == "for")        tokens.push_back({for_s, "for"});
            else if (token == "while")      tokens.push_back({while_s, "while"});
	        else if (token == "and")        tokens.push_back({c_and, "and"});
	        else if (token == "or")         tokens.push_back({c_or, "and"});
            else 			    tokens.push_back({id, "id"});
            i += token.length() - 1;
        } 
        
        // matching digits
        else if (isdigit(c)) {
            string token = findNumToken(code, i);
            i += token.length() - 1;
            tokens.push_back({int_literal, "int_l"});
        } 

        // matching with special symbols
        else if (c == '>' && c1 == '=') { i++; tokens.push_back({more_equ, ">="}); continue; }
        else if (c == '<' && c1 == '=') { i++; tokens.push_back({less_equ, "<="}); continue; }
        else if (c == '!' && c1 == '=') { i++; tokens.push_back({n_equ, "!="});    continue; }
        switch (c)
        {
            case ' ':                                       break;
            case '\n': tokens.push_back({endline, "\n"});   break;
            case ';': tokens.push_back({semicolon, ";"});   break;
            case ',': tokens.push_back({comma, ","});       break;
            case '+': tokens.push_back({add, "+"});         break;
            case '-': tokens.push_back({sub, "-"});         break;
            case '*': tokens.push_back({mult, "*"});        break;
            case '/': tokens.push_back({divide, "/"});      break;
            case '=': tokens.push_back({equ, "="});         break;
            case '>': tokens.push_back({more, ">"});        break;
            case '<': tokens.push_back({lss, "<"});         break;
            case '(': tokens.push_back({l_parent, "("});    break;
            case ')': tokens.push_back({r_parent, ")"});    break;
            case '[': tokens.push_back({l_brace, "["});     break;
            case ']': tokens.push_back({r_brace, "]"});     break;
            case '{': tokens.push_back({l_bracket, "{"});   break;
            case '}': tokens.push_back({r_bracket, "}"});   break;
            case ':': tokens.push_back({colon, ":"});       break;
            case '@': tokens.push_back({ptr, "ptr"});       break;
	    case '&': tokens.push_back({ampersand, "&"});   break;      
        }
    }
    return tokens;
}
