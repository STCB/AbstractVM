//
// Created by steph on 7/7/23.
//

#ifndef ABSTRACTVM_STACK_HPP
    #define ABSTRACTVM_STACK_HPP

    #include <stack>
    #include <iostream>
    #include <iomanip>
    #include "IOperand.hpp"
    #include "Factory.hpp"
    #include "Register.hpp"
    #include "eOperandType.hpp"

    class Stack {
    public:
        Stack();
        ~Stack();
        void push(IOperand *op);
        void pop();
        void clear();
        void dup();
        void swap();
        void dump();
        void assert(IOperand *op);
        void add();
        void sub();
        void mul();
        void div();
        void mod();
        void load(IOperand *op);
        void store(IOperand *op);
        void print();
        std::stack<IOperand *> _stack;
        Register _register;
    private:
        void is_empty();
        void is_full();
        void least_two();
    };

#endif //ABSTRACTVM_STACK_HPP
