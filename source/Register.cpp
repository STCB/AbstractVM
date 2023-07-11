//
// Created by steph on 7/10/23.
//

#include "Register.hpp"

Register::~Register() {
    for (int i = 0; i < 16; i++) {
        if (_register[i] != nullptr)
            delete _register[i];
    }
}

void Register::set_register(IOperand *op, int v) {
    _register[v] = op;
}

IOperand *Register::get_register(int v) {
    if (_register[v] == nullptr)
        throw std::runtime_error("Register is empty");
    return Factory::createOperand(_register[v]->getType(), _register[v]->toString());
}
