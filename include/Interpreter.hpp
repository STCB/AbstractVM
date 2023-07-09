//
// Created by steph on 7/7/23.
//

#ifndef ABSTRACTVM_INTERPRETER_HPP
#define ABSTRACTVM_INTERPRETER_HPP

#include "stack.hpp"
#include "Factory.hpp"
#include <string>

class Interpreter {
public:
    Interpreter();
    ~Interpreter() = default;
    static void file_read(const std::string& path);
    static void stdin_read();
private:
    static Stack _stack;
    static void line_read(std::string const &line);
    static IOperand *get_value(const std::string& line);
};


#endif //ABSTRACTVM_INTERPRETER_HPP
