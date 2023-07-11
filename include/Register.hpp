//
// Created by steph on 7/10/23.
//

#ifndef ABSTRACTVM_REGISTER_HPP
#define ABSTRACTVM_REGISTER_HPP

#include "Factory.hpp"
#include "IOperand.hpp"

class Register {
public:
    Register() = default;
    ~Register();

    void set_register(IOperand *op, int v);
    IOperand *get_register(int v);
    IOperand * _register[16] = {nullptr};
};


#endif //ABSTRACTVM_REGISTER_HPP
