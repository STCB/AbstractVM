

#include <iostream>
#include "stack.hpp"
#include "eOperandType.hpp"


Stack::Stack() {
    clear();
}

void Stack::is_empty() {
    if (_stack[0] == nullptr)
        throw std::runtime_error("Stack is empty");
}

void Stack::is_full() {
    if (top() == 15)
        throw std::runtime_error("Stack is full");
}


void Stack::least_two() {
    is_empty();
    if (top() == 0)
        throw std::runtime_error("Stack has only one element");
}


int Stack::top() {
    int i = 0;
    for (; _stack[i] != nullptr && i < 16; i++) {
        if (_stack[i + 1] == nullptr)
            return i;
    }
    return i;
}

void Stack::push(IOperand *op) {
    is_full();
    _stack[top()] = op;
}

void Stack::pop() {
    is_empty();
    _stack[top()] = nullptr;
}

void Stack::clear() {
    for (auto & i : _stack) {
        i = nullptr;
    }
}

void Stack::dup() {
    is_full();
    _stack[top() + 1] = _stack[top()];
}

void Stack::swap() {
    least_two();
    IOperand *tmp = _stack[top()];
    _stack[top()] = _stack[top() - 1];
    _stack[top() - 1] = tmp;
}

void Stack::dump() {
    is_empty();
    for (int i = top(); i >= 0; i--) {
        std::cout << _stack[i]->toString() << std::endl;
    }
}

void Stack::assert(IOperand *op) {
    is_empty();
    if (_stack[top()]->getType() != op->getType() || _stack[top()] != op)
        throw std::runtime_error("Assert failed");
}

void Stack::add() {
    least_two();
    IOperand *tmp = *_stack[top()] + *_stack[top() - 1];
    pop();
    pop();
    push(tmp);
}

void Stack::sub() {
    least_two();
    IOperand *tmp = *_stack[top()] - *_stack[top() - 1];
    pop();
    pop();
    push(tmp);
}

void Stack::mul() {
    least_two();
    IOperand *tmp = *_stack[top()] * *_stack[top() - 1];
    pop();
    pop();
    push(tmp);
}

void Stack::div() {
    least_two();
    IOperand *tmp = *_stack[top()] / *_stack[top() - 1];
    pop();
    pop();
    push(tmp);
}

void Stack::mod() {
    least_two();
    IOperand *tmp = *_stack[top()] % *_stack[top() - 1];
    pop();
    pop();
    push(tmp);
}

void Stack::load(int v) {
    if (v < 0 || v > 15)
        throw std::runtime_error("Index out of range");
    if (_stack[v] == nullptr)
        throw std::runtime_error("Stack is empty");
    push(_stack[v]);
}

void Stack::store(int v) {
    if (v < 0 || v > 15)
        throw std::runtime_error("Index out of range");
    IOperand *tmp = _stack[top()];
    pop();
    _stack[v] = tmp;
}

void Stack::print() {
    is_empty();
    if (_stack[top()]->getType() != eOperandType::t_Int8)
        throw std::runtime_error("Print failed");
    std::cout << static_cast<char>(std::stoi(_stack[top()]->toString())) << std::endl;
}
