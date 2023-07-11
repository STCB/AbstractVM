//
// Created by steph on 7/7/23.
//

#include "Interpreter.hpp"
#include <iostream>
#include <fstream>
#include <string>

Stack Interpreter::_stack;

Interpreter::Interpreter() = default;

void Interpreter::file_read(const std::string& path) {
    int exit = 0;
    int end = 0;
    std::string line;
    std::fstream file;

    file.open(path, std::ios::in);
    try {
        while (std::getline(file, line)) {
            if (line.find("exit") == 0)
                exit = 1;
            if (line.find('#') != std::string::npos)
                end = 1;
            if (end == 1 || (!std::cin && std::cin.eof()))
                break;
            line_read(line);
        }
        if (exit == 0)
            throw std::runtime_error("No exit instruction !");
        _stack.clear();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        _stack.clear();
        file.close();
        std::exit(84);
    }
    file.close();
}

void Interpreter::stdin_read() {
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.find(";;") != std::string::npos)
            break;
        line_read(line);
    }
}

static std::string get_nbr(std::string str)
{
    std::string temp;
    for (int i = str.find('(') + 1; str[i] != ')'; i++) {
        if (!isdigit(str[i]) && str[i] != '-' && str[i] != '.')
            throw std::runtime_error("Invalid value");
        temp += str[i];
    }
    if (temp.empty())
        throw std::runtime_error("Invalid value");
    return temp;
}

IOperand *Interpreter::get_value(const std::string& line)
{
    std::string value = get_nbr(line);

    if (line.find("int8(") < line.length())
        return Factory::createOperand(eOperandType::t_Int8, value);
    if (line.find("int16(") < line.length())
        return Factory::createOperand(eOperandType::t_Int16, value);
    if (line.find("int32(") < line.length())
        return Factory::createOperand(eOperandType::t_Int32, value);
    if (line.find("float(") < line.length())
        return Factory::createOperand(eOperandType::t_Float, value);
    if (line.find("double(") < line.length())
        return Factory::createOperand(eOperandType::t_Double, value);
    throw std::runtime_error("Invalid type [" + line + "]");
}

std::string clean_line(std::string str)
{
    std::string temp;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t')
            temp += str[i];
    }
    return temp;
}

bool is_comment_line(std::string str)
{
    str = clean_line(str);
    if (str[0] == ';' || str.empty())
        return 1;
    return 0;
}

void Interpreter::line_read(const std::string &line) {
    if (is_comment_line(line))
        return;
    std::string temp = clean_line(line);

    try {
        if (temp.find("push") == 0)
            return _stack.push(get_value(temp));
        if (temp == "pop")
            return _stack.pop();
        if (temp == "clear")
            return _stack.clear();
        if (temp == "dup")
            return _stack.dup();
        if (temp == "swap")
            return _stack.swap();
        if (temp == "dump")
            return _stack.dump();
        if (temp.find("assert") == 0)
            return _stack.assert(get_value(temp));
        if (temp == "add")
            return _stack.add();
        if (temp == "sub")
            return _stack.sub();
        if (temp == "mul")
            return _stack.mul();
        if (temp == "div")
            return _stack.div();
        if (temp == "mod")
            return _stack.mod();
        if (temp.find("load") == 0)
            return _stack.load(get_value(temp));
        if (temp.find("store") == 0)
            return _stack.store(get_value(temp));
        if (temp == "clear")
            return _stack.clear();
        if (temp == "print")
            return _stack.print();
        if (temp == "exit") {
            exit(0);
        }
        throw std::runtime_error("Invalid instruction: " + temp );
    } catch (std::exception &e) {
        std::cout << "Command error: " << e.what() << std::endl;
        exit(84);
    }
}
