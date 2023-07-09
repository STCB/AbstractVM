#include "Int8.hpp"

eOperandType Int8::getType() const {
    return _type;
}

Int8::Int8(std::string v) {
    setValue(std::move(v));
}

bool Int8::operator==(const IOperand &rhs) const {
    return std::stoi(_value) == std::stoi(rhs.toString());
}

IOperand* Int8::operator+(const IOperand &rhs) const {
    int res = std::stoi(_value) + std::stoi(rhs.toString());
    if (res > 127 || res < -126)
        throw std::overflow_error("Int8: +");
    return new Int8(std::to_string(res));
}

IOperand *Int8::operator-(const IOperand &rhs) const {
    int res = std::stoi(_value) - std::stoi(rhs.toString());
    if (res > 127 || res < -126)
        throw std::overflow_error("Int8: -");
    return new Int8(std::to_string(res));
}

IOperand *Int8::operator/(const IOperand &rhs) const {
    int res = std::stoi(_value) / std::stoi(rhs.toString());
    if (res > 127 || res < -126)
        throw std::overflow_error("Int8: /");
    return new Int8(std::to_string(res));
}

IOperand *Int8::operator*(const IOperand &rhs) const {
    int res = std::stoi(_value) * std::stoi(rhs.toString());
    if (res > 127 || res < -126)
        throw std::overflow_error("Int8: *");
    return new Int8(std::to_string(res));
}

IOperand *Int8::operator%(const IOperand &rhs) const {
    int res = std::stoi(_value) % std::stoi(rhs.toString());
    if (res > 127 || res < -126)
        throw std::overflow_error("Int8: %");
    return new Int8(std::to_string(res));
}
