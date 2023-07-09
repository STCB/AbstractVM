//
// Created by steph on 7/7/23.
//

#include "Interpreter.hpp"
#include <iostream>
#include <fstream>
#include <string>

Interpreter::Interpreter()
{
    _stack = Stack();
}


void Interpreter::file_read(const std::string& path) {
    int exit = 0;
    int end = 0;
    std::string line;
    std::fstream file;

    file.open(path, std::ios::in);
    while (std::getline(file, line)) {
        if (line.find("exit") != std::string::npos)
            exit = 1;
        if (line.find('#') != std::string::npos)
            end = 1;
        if(end == 1 || (!std::cin && std::cin.eof())) {
            if (exit == 0)
                throw std::runtime_error("No exit instruction.");
            file.close();
            break;
        }
        line_read(line);
	}
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
    return temp;
}

IOperand *Interpreter::get_value(const std::string& line)
{
    std::string value = get_nbr(line);

    if (line.find("int8("))
        return Factory::createOperand(eOperandType::t_Int8, value);
    if (line.find("int16("))
        return Factory::createOperand(eOperandType::t_Int16, value);
    if (line.find("int32("))
        return Factory::createOperand(eOperandType::t_Int32, value);
    if (line.find("float("))
        return Factory::createOperand(eOperandType::t_Float, value);
    if (line.find("double("))
        return Factory::createOperand(eOperandType::t_Double, value);
    throw std::runtime_error("Invalid type");
}

void Interpreter::line_read(const std::string &line) {
    if (line[0] == ';' || line.empty())
        return;
    int comment = line.find(';');
    std::string temp = line.substr(0, line.length() - comment);
    
    if (line.find("push") == 0)
        return _stack.push(get_value(line));
    if (line == "pop")
        return _stack.pop();
    if (line == "clear")
        return _stack.clear();
    if (line == "dup")
        return _stack.dup();
    if (line == "swap")
        return _stack.swap();
    if (line == "dump")
        return _stack.dump();
    if (line.find("assert") == 0)
        return _stack.assert(get_value(line));
    if (line == "add")
        return _stack.add();
    if (line == "sub")
        return _stack.sub();
    if (line == "mul")
        return _stack.mul();
    if (line == "div")
        return _stack.div();
    if (line == "mod")
        return _stack.mod();
    if (line.find("load") == 0)
        return _stack.load(stoi(line.substr(4, line.length() - 4)));
    if (line.find("store") == 0)
        return _stack.store(stoi(line.substr(4, line.length() - 4)));
    if (line == "clear")
        return _stack.clear();
    if (line == "print")
        return _stack.print();
}
