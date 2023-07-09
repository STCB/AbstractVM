#include "Double.hpp"
#include <cmath>

eOperandType Double::getType() const {
    return _type;
}

Double::Double(std::string v) {
    setValue(std::move(v));
}

IOperand* Double::operator+(const IOperand &rhs) const {
    long double res = std::stold(_value) + std::stold(rhs.toString());
    if (res > DBL_MAX || res < DBL_MIN)
        throw std::overflow_error("Double: +");
    return new Double(std::to_string(res));
}

IOperand *Double::operator-(const IOperand &rhs) const {
    long double res = std::stold(_value) - std::stold(rhs.toString());
    if (res > DBL_MAX || res < DBL_MIN)
        throw std::overflow_error("Double: -");
    return new Double(std::to_string(res));
}

IOperand *Double::operator/(const IOperand &rhs) const {
    long double res = std::stold(_value) / std::stold(rhs.toString());
    if (res > DBL_MAX || res < DBL_MIN)
        throw std::overflow_error("Double: /");
    return new Double(std::to_string(res));
}

IOperand *Double::operator*(const IOperand &rhs) const {
    long double res = std::stold(_value) * std::stold(rhs.toString());
    if (res > DBL_MAX || res < DBL_MIN)
        throw std::overflow_error("Double: *");
    return new Double(std::to_string(res));
}

IOperand *Double::operator%(const IOperand &rhs) const {
    long double res = fmod(std::stod(_value), std::stod(rhs.toString()));
    if (res > DBL_MAX || res < DBL_MIN)
        throw std::overflow_error("Double: %");
    return new Double(std::to_string(res));
}

bool Double::operator==(const IOperand &rhs) const {
    return std::stod(_value) == std::stod(rhs.toString());
}
