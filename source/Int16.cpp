#include "Int16.hpp"

eOperandType Int16::getType() const {
    return _type;
}

Int16::Int16(std::string v) {
    setValue(std::move(v));
}

IOperand* Int16::operator+(const IOperand &rhs) const {
    int res = std::stoi(_value) + std::stoi(rhs.toString());
    if (res > INT16_MAX || res < INT16_MIN)
        throw std::overflow_error("Int16: +");
    return new Int16(std::to_string(res));
}

IOperand *Int16::operator-(const IOperand &rhs) const {
    int res = std::stoi(_value) - std::stoi(rhs.toString());
    if (res > INT16_MAX || res < INT16_MIN)
        throw std::overflow_error("Int16: -");
    return new Int16(std::to_string(res));
}

IOperand *Int16::operator/(const IOperand &rhs) const {
    int res = std::stoi(_value) / std::stoi(rhs.toString());
    if (res > INT16_MAX || res < INT16_MIN)
        throw std::overflow_error("Int16: /");
    return new Int16(std::to_string(res));
}

IOperand *Int16::operator*(const IOperand &rhs) const {
    int res = std::stoi(_value) * std::stoi(rhs.toString());
    if (res > INT16_MAX || res < INT16_MIN)
        throw std::overflow_error("Int16: *");
    return new Int16(std::to_string(res));
}

IOperand *Int16::operator%(const IOperand &rhs) const {
    int res = std::stoi(_value) % std::stoi(rhs.toString());
    if (res > INT16_MAX || res < INT16_MIN)
        throw std::overflow_error("Int16: %");
    return new Int16(std::to_string(res));
}

bool Int16::operator==(const IOperand &rhs) const {
    return std::stoi(_value) == std::stoi(rhs.toString());
}
