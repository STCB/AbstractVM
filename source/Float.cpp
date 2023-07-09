#include <cmath>
#include "Float.hpp"

eOperandType Float::getType() const {
    return _type;
}

Float::Float(std::string v) {
    setValue(std::move(v));
}

IOperand* Float::operator+(const IOperand &rhs) const {
    double res = std::stof(_value) + std::stof(rhs.toString());
    if (res > FLT_MAX || res < FLT_MIN)
        throw std::overflow_error("Float: +");
    return new Float(std::to_string(res));
}

IOperand *Float::operator-(const IOperand &rhs) const {
    double res = std::stof(_value) - std::stof(rhs.toString());
    if (res > FLT_MAX || res < FLT_MIN)
        throw std::overflow_error("Float: -");
    return new Float(std::to_string(res));
}

IOperand *Float::operator/(const IOperand &rhs) const {
    double res = std::stof(_value) / std::stof(rhs.toString());
    if (res > FLT_MAX || res < FLT_MIN)
        throw std::overflow_error("Float: /");
    return new Float(std::to_string(res));
}

IOperand *Float::operator*(const IOperand &rhs) const {
    double res = std::stof(_value) * std::stof(rhs.toString());
    if (res > FLT_MAX || res < FLT_MIN)
        throw std::overflow_error("Float: *");
    return new Float(std::to_string(res));
}

IOperand *Float::operator%(const IOperand &rhs) const {
    double res = fmodf(std::stof(_value), std::stof(rhs.toString()));
    if (res > FLT_MAX || res < FLT_MIN)
        throw std::overflow_error("Float: %");
    return new Float(std::to_string(res));
}

bool Float::operator==(const IOperand &rhs) const {
    return std::stof(_value) == std::stof(rhs.toString());
}
