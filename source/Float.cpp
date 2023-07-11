#include "Float.hpp"

eOperandType Float::getType() const {
    return _type;
}

Float::Float(std::string v) {
    if (std::stod(v) > FLT_MAX || std::stod(v) < std::numeric_limits<float>::lowest())
        throw std::overflow_error("Float oveflow on generation: " + v + " is out of range");
    setValue(std::move(v));
}

std::string Float::toString() const
{
    std::ostringstream oss;

    oss.precision(7);
    oss << _value;
    return oss.str();
}

IOperand* Float::operator+(const IOperand &rhs) const {
    double res = std::stof(rhs.toString()) + std::stof(_value);
    if (res > FLT_MAX || res < std::numeric_limits<float>::lowest())
        throw std::overflow_error("Float oveflow: +");
    return new Float(std::to_string(res));
}

IOperand *Float::operator-(const IOperand &rhs) const {
    double res = std::stof(rhs.toString()) - std::stof(_value);
    if (res > FLT_MAX || res < std::numeric_limits<float>::lowest())
        throw std::overflow_error("Float oveflow: -");
    return new Float(std::to_string(res));
}

IOperand *Float::operator/(const IOperand &rhs) const {
    if (std::stof(_value) == 0)
        throw std::runtime_error("Float: Division by zero is not implemented yet");
    double res = std::stof(rhs.toString()) / std::stof(_value);
    if (res > FLT_MAX || res < std::numeric_limits<float>::lowest())
        throw std::overflow_error("Float oveflow: /");
    return new Float(std::to_string(res));
}

IOperand *Float::operator*(const IOperand &rhs) const {
    double res = std::stof(rhs.toString()) * std::stof(_value);
    if (res > FLT_MAX || res < std::numeric_limits<float>::lowest())
        throw std::overflow_error("Float oveflow: *");
    return new Float(std::to_string(res));
}

IOperand *Float::operator%(const IOperand &rhs) const {
    if (std::stol(_value) == 0)
        throw std::overflow_error("Float: Modulo by zero is not implemented yet");
    double res = fmodf(std::stof(rhs.toString()), std::stof(_value));
    if (res > FLT_MAX || res < std::numeric_limits<float>::lowest())
        throw std::overflow_error("Float oveflow: %");
    return new Float(std::to_string(res));
}

bool Float::operator==(const IOperand &rhs) const {
    return std::stof(_value) == std::stof(rhs.toString());
}
