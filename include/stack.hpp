//
// Created by steph on 7/7/23.
//

#ifndef ABSTRACTVM_STACK_HPP
    #define ABSTRACTVM_STACK_HPP

    #include "IOperand.hpp"

    class Stack {
    public:
        Stack();
        ~Stack() = default;
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
        void load(int v);
        void store(int v);
        void print();
    private:
        int top();
        void is_empty();
        void is_full();
        void least_two();
        IOperand *_stack[16]{};
    };

#endif //ABSTRACTVM_STACK_HPP
