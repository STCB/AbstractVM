#include "Int8.hpp"

eOperandType Int8::getType() const {
    return _type;
}

Int8::Int8(std::string v) {
    if (std::stoi(v) > 127 || std::stoi(v) < -126)
        throw std::overflow_error("Int8 oveflow on generation: " + v + " is out of range");
    setValue(std::move(v));
}

bool Int8::operator==(const IOperand &rhs) const {
    return std::stoi(_value) == std::stoi(rhs.toString());
}

IOperand* Int8::operator+(const IOperand &rhs) const {
    int res = std::stoi(rhs.toString()) + std::stoi(_value);
    if (res > 127 || res < -126)
        throw std::overflow_error("Int8 oveflow: +");
    return new Int8(std::to_string(res));
}

IOperand *Int8::operator-(const IOperand &rhs) const {
    int res = std::stoi(rhs.toString()) - std::stoi(_value);
    if (res > 127 || res < -126)
        throw std::overflow_error("Int8 oveflow: -");
    return new Int8(std::to_string(res));
}

IOperand *Int8::operator/(const IOperand &rhs) const {
    if (std::stoi(_value) == 0)
        throw std::overflow_error("Int8: Division by zero is not implemented yet");
    int res = std::stoi(rhs.toString()) / std::stoi(_value);
    if (res > 127 || res < -126)
        throw std::overflow_error("Int8 oveflow: /");
    return new Int8(std::to_string(res));
}

IOperand *Int8::operator*(const IOperand &rhs) const {
    int res =  std::stoi(rhs.toString()) * std::stoi(_value);
    if (res > 127 || res < -126)
        throw std::overflow_error("Int8 oveflow: *");
    return new Int8(std::to_string(res));
}

IOperand *Int8::operator%(const IOperand &rhs) const {
    if (std::stol(_value) == 0)
        throw std::overflow_error("Int8: Modulo by zero is not implemented yet");
    int res = std::stoi(rhs.toString()) % std::stoi(_value);
    if (res > 127 || res < -126)
        throw std::overflow_error("Int8 oveflow: %");
    return new Int8(std::to_string(res));
}
