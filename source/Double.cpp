#include "Double.hpp"

eOperandType Double::getType() const {
    return _type;
}

Double::Double(std::string v) {
    if (std::stold(v) > DBL_MAX || std::stold(v) < std::numeric_limits<double>::lowest())
        throw std::overflow_error("Double oveflow on generation: " + v + " is out of range");
    setValue(std::move(v));
}

std::string Double::toString() const
{
    std::ostringstream oss;

    oss.precision(15);
    oss << _value;
    return oss.str();
}

IOperand* Double::operator+(const IOperand &rhs) const {
    long double res = std::stold(rhs.toString()) + std::stold(_value);
    if (res > DBL_MAX || res < std::numeric_limits<double>::lowest())
        throw std::overflow_error("Double oveflow: +");

    return new Double(std::to_string(res));
}

IOperand *Double::operator-(const IOperand &rhs) const {
    long double res = std::stold(rhs.toString()) - std::stold(_value);
    if (res > DBL_MAX || res < std::numeric_limits<double>::lowest())
        throw std::overflow_error("Double oveflow: -");
    return new Double(std::to_string(res));
}

IOperand *Double::operator/(const IOperand &rhs) const {
    if (std::stold(_value) == 0)
        throw std::runtime_error("Double: Division by zero is not implemented yet");
    long double res = std::stold(rhs.toString()) / std::stold(_value);
    if (res > DBL_MAX || res < std::numeric_limits<double>::lowest())
        throw std::overflow_error("Double oveflow: /");
    return new Double(std::to_string(res));
}

IOperand *Double::operator*(const IOperand &rhs) const {
    long double res = std::stold(rhs.toString()) * std::stold(_value);
    if (res > DBL_MAX || res < std::numeric_limits<double>::lowest())
        throw std::overflow_error("Double oveflow: *");
    return new Double(std::to_string(res));
}

IOperand *Double::operator%(const IOperand &rhs) const {
    if (std::stol(_value) == 0)
        throw std::overflow_error("Double: Modulo by zero is not implemented yet");
    long double res = fmod(std::stod(rhs.toString()), std::stod(_value));
    if (res > DBL_MAX || res < std::numeric_limits<double>::lowest())
        throw std::overflow_error("Double oveflow: %");
    return new Double(std::to_string(res));
}

bool Double::operator==(const IOperand &rhs) const {
    return std::stod(_value) == std::stod(rhs.toString());
}
