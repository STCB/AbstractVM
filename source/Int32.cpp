#include "Int32.hpp"

eOperandType Int32::getType() const {
    return _type;
}

Int32::Int32(std::string v) {
    if (std::stol(v) > INT32_MAX || std::stol(v) < INT32_MIN)
        throw std::overflow_error("Int32 oveflow on generation: " + v + " is out of range");
    setValue(std::move(v));
}

IOperand* Int32::operator+(const IOperand &rhs) const {
    long res = std::stol(rhs.toString()) + std::stol(_value);
    if (res > INT32_MAX || res < INT32_MIN)
        throw std::overflow_error("Int32 oveflow: +");
    return new Int32(std::to_string(res));
}

IOperand *Int32::operator-(const IOperand &rhs) const {
    long res = std::stol(rhs.toString()) - std::stol(_value);
    if (res > INT32_MAX || res < INT32_MIN)
        throw std::overflow_error("Int32 oveflow: -");
    return new Int32(std::to_string(res));
}

IOperand *Int32::operator/(const IOperand &rhs) const {
    if (std::stol(_value) == 0)
        throw std::overflow_error("Int32: Division by zero is not implemented yet");
    long res = std::stol(rhs.toString()) / std::stol(_value);
    if (res > INT32_MAX || res < INT32_MIN)
        throw std::overflow_error("Int32 oveflow: /");
    return new Int32(std::to_string(res));
}

IOperand *Int32::operator*(const IOperand &rhs) const {
    long res = std::stol(rhs.toString()) * std::stol(_value);
    if (res > INT32_MAX || res < INT32_MIN)
        throw std::overflow_error("Int32 oveflow: *");
    return new Int32(std::to_string(res));
}

IOperand *Int32::operator%(const IOperand &rhs) const {
    if (std::stol(_value) == 0)
        throw std::overflow_error("Int32: Modulo by zero is not implemented yet");
    long res = std::stol(rhs.toString()) % std::stol(_value);
    if (res > INT32_MAX || res < INT32_MIN)
        throw std::overflow_error("Int32 oveflow: %");
    return new Int32(std::to_string(res));
}

bool Int32::operator==(const IOperand &rhs) const {
    return std::stol(_value) == std::stol(rhs.toString());
}
