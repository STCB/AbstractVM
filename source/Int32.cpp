#include "Int32.hpp"

eOperandType Int32::getType() const {
    return _type;
}

Int32::Int32(std::string v) {
    setValue(std::move(v));
}

IOperand* Int32::operator+(const IOperand &rhs) const {
    long res = std::stol(_value) + std::stol(rhs.toString());
    if (res > INT32_MAX || res < INT32_MIN)
        throw std::overflow_error("Int32: +");
    return new Int32(std::to_string(res));
}

IOperand *Int32::operator-(const IOperand &rhs) const {
    long res = std::stol(_value) - std::stol(rhs.toString());
    if (res > INT32_MAX || res < INT32_MIN)
        throw std::overflow_error("Int32: -");
    return new Int32(std::to_string(res));
}

IOperand *Int32::operator/(const IOperand &rhs) const {
    long res = std::stol(_value) / std::stol(rhs.toString());
    if (res > INT32_MAX || res < INT32_MIN)
        throw std::overflow_error("Int32: /");
    return new Int32(std::to_string(res));
}

IOperand *Int32::operator*(const IOperand &rhs) const {
    long res = std::stol(_value) * std::stol(rhs.toString());
    if (res > INT32_MAX || res < INT32_MIN)
        throw std::overflow_error("Int32: *");
    return new Int32(std::to_string(res));
}

IOperand *Int32::operator%(const IOperand &rhs) const {
    long res = std::stol(_value) % std::stol(rhs.toString());
    if (res > INT32_MAX || res < INT32_MIN)
        throw std::overflow_error("Int32: %");
    return new Int32(std::to_string(res));
}

bool Int32::operator==(const IOperand &rhs) const {
    return std::stol(_value) == std::stol(rhs.toString());
}
