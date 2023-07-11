
#include "stack.hpp"

Stack::Stack() = default;

Stack::~Stack()
{
    clear();
}

void Stack::is_empty() {
    if (_stack.empty())
        throw std::runtime_error("Stack is empty");
}

void Stack::least_two() {
    is_empty();
    if (_stack.size() < 2)
        throw std::runtime_error("Stack has less than two elements");
}

void Stack::push(IOperand *op) {
    _stack.push(op);
}

void Stack::pop() {
    is_empty();
    _stack.pop();
}

void Stack::clear() {
    int tot = _stack.size();

    for (int i = 0; i != tot; i++) {
        delete _stack.top();
        _stack.pop();
    }
}

void Stack::dup() {
    _stack.push(Factory::createOperand(_stack.top()->getType(), _stack.top()->toString()));
}

void Stack::swap() {
    least_two();
    IOperand *tmp1 = _stack.top();
    _stack.pop();
    IOperand *tmp2 = _stack.top();
    _stack.pop();
    _stack.push(tmp1);
    _stack.push(tmp2);
}

void Stack::dump() {
    std::stack<IOperand *> tmp = _stack;
    std::ostringstream oss;

    while (!tmp.empty()) {
        if (tmp.top()->getType() == eOperandType::t_Double)
            oss.precision(15);
        else if (tmp.top()->getType() == eOperandType::t_Float)
            oss.precision(7);
        oss << tmp.top()->toString();
        std::cout << std::fixed << oss.str() << std::endl;
        tmp.pop();
    }
}

void Stack::assert(IOperand *op) {
    is_empty();
    if (_stack.top()->getType() != op->getType())
        throw std::runtime_error("Assert failed, wrong type.");
    if (_stack.top()->toString() != op->toString())
        throw std::runtime_error("Assert failed, wrong value.");
}

void Stack::add() {
    least_two();
    IOperand *tmp = _stack.top();
    pop();
    IOperand *tmp2 = _stack.top();
    pop();
    if (tmp->getType() < tmp2->getType())
        tmp = Factory::createOperand(tmp2->getType(), tmp->toString());
    else if (tmp->getType() > tmp2->getType())
        tmp2 = Factory::createOperand(tmp->getType(), tmp2->toString());
    push(*tmp + *tmp2);
    delete tmp;
    delete tmp2;
}

void Stack::sub() {
    least_two();
    IOperand *tmp = _stack.top();
    pop();
    IOperand *tmp2 = _stack.top();
    pop();
    if (tmp->getType() < tmp2->getType())
        tmp = Factory::createOperand(tmp2->getType(), tmp->toString());
    else if (tmp->getType() > tmp2->getType())
        tmp2 = Factory::createOperand(tmp->getType(), tmp2->toString());
    push(*tmp - *tmp2);
    delete tmp;
    delete tmp2;
}

void Stack::mul() {
    least_two();
    IOperand *tmp = _stack.top();
    pop();
    IOperand *tmp2 = _stack.top();
    pop();
    if (tmp->getType() < tmp2->getType())
        tmp = Factory::createOperand(tmp2->getType(), tmp->toString());
    else if (tmp->getType() > tmp2->getType())
        tmp2 = Factory::createOperand(tmp->getType(), tmp2->toString());
    push(*tmp * *tmp2);
    delete tmp;
    delete tmp2;
}

void Stack::div() {
    least_two();
    IOperand *tmp = _stack.top();
    pop();
    IOperand *tmp2 = _stack.top();
    pop();
    if (tmp->getType() < tmp2->getType())
        tmp = Factory::createOperand(tmp2->getType(), tmp->toString());
    else if (tmp->getType() > tmp2->getType())
        tmp2 = Factory::createOperand(tmp->getType(), tmp2->toString());
    push(*tmp / *tmp2);
    delete tmp;
    delete tmp2;
}

void Stack::mod() {
    least_two();
    IOperand *tmp = _stack.top();
    pop();
    IOperand *tmp2 = _stack.top();
    pop();
    if (tmp->getType() < tmp2->getType())
        tmp = Factory::createOperand(tmp2->getType(), tmp->toString());
    else if (tmp->getType() > tmp2->getType())
        tmp2 = Factory::createOperand(tmp->getType(), tmp2->toString());
    push(*tmp % *tmp2);
    delete tmp;
    delete tmp2;
}

void Stack::load(IOperand *op) {
    double v = std::stod(op->toString());
    if (v < 0 || v > 15)
        throw std::runtime_error("Index out of range (0 : 15)");

    _stack.push(_register.get_register(v));
}

void Stack::store(IOperand *op) {
    double v = std::stod(op->toString());
    is_empty();
    if (v < 0 || v > 15)
        throw std::runtime_error("Index out of range (0 : 15)");
    IOperand * tmp = _stack.top();

    _stack.pop();
    _register.set_register(tmp, v);
}

void Stack::print() {
    is_empty();
    if (_stack.top()->getType() != eOperandType::t_Int8)
        throw std::runtime_error("Print failed");
    std::cout << static_cast<char>(std::stoi(_stack.top()->toString())) << std::endl;
}
