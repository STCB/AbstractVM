
#include "Interpreter.hpp"
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac > 1) {
        std::string path = av[1];
        std::fstream file;
        file.open(path, std::ios::in);
        if (!file.is_open())
            throw std::runtime_error("File not found");
        file.close();
        Interpreter::file_read(path);
    } else {
        Interpreter::stdin_read();
    }
}
