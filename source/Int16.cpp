#include "Int16.hpp"

eOperandType Int16::getType() const {
    return _type;
}

Int16::Int16(std::string v) {
    if (std::stoi(v) > INT16_MAX || std::stoi(v) < INT16_MIN)
        throw std::overflow_error("Int16 oveflow on generation: " + v + " is out of range");
    setValue(std::move(v));
}

IOperand* Int16::operator+(const IOperand &rhs) const {
    int res = std::stoi(rhs.toString()) + std::stoi(_value);
    if (res > INT16_MAX || res < INT16_MIN)
        throw std::overflow_error("Int16 oveflow: +");
    return new Int16(std::to_string(res));
}

IOperand *Int16::operator-(const IOperand &rhs) const {
    int res = std::stoi(rhs.toString()) - std::stoi(_value);
    if (res > INT16_MAX || res < INT16_MIN)
        throw std::overflow_error("Int16 oveflow: -");
    return new Int16(std::to_string(res));
}

IOperand *Int16::operator/(const IOperand &rhs) const {
    if (std::stoi(_value) == 0)
        throw std::overflow_error("Int16 : Division by zero is not implemented yet");
    int res = std::stoi(rhs.toString()) / std::stoi(_value);
    if (res > INT16_MAX || res < INT16_MIN)
        throw std::overflow_error("Int16 oveflow: /");
    return new Int16(std::to_string(res));
}

IOperand *Int16::operator*(const IOperand &rhs) const {
    int res = std::stoi(rhs.toString()) * std::stoi(_value);
    if (res > INT16_MAX || res < INT16_MIN)
        throw std::overflow_error("Int16 oveflow: *");
    return new Int16(std::to_string(res));
}

IOperand *Int16::operator%(const IOperand &rhs) const {
    if (std::stol(_value) == 0)
        throw std::overflow_error("Int16: Modulo by zero is not implemented yet");
    int res = std::stoi(rhs.toString()) % std::stoi(_value);
    if (res > INT16_MAX || res < INT16_MIN)
        throw std::overflow_error("Int16 oveflow: %");
    return new Int16(std::to_string(res));
}

bool Int16::operator==(const IOperand &rhs) const {
    return std::stoi(_value) == std::stoi(rhs.toString());
}
