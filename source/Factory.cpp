#include "Factory.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"


IOperand *Factory::createInt8(const std::string &value) {
    return new Int8(value);
}

IOperand *Factory::createInt16(const std::string &value) {
    return new Int16(value);
}

IOperand *Factory::createInt32(const std::string &value) {
    return new Int32(value);
}

IOperand *Factory::createFloat(const std::string &value) {
    return new Float(value);
}

IOperand *Factory::createDouble(const std::string &value) {
    return new Double(value);
}

IOperand *Factory::createOperand(eOperandType type, const std::string &value) {
    static IOperand* (*opTab[])(const std::string&) =
        {
            createInt8,
            createInt16,
            createInt32,
            createFloat,
            createDouble
        };
    return (opTab[type](const_cast<std::string &>(value)));
}
