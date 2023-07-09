//
// Created by steph on 7/6/23.
//

#ifndef ABSTRACTVM_IOPERAND_HPP
    #define ABSTRACTVM_IOPERAND_HPP

    #include <string>
    #include <utility>
    #include <sstream>
    #include "eOperandType.hpp"

    class IOperand
    {
    public:
        virtual std::string toString() const = 0;
        virtual eOperandType getType() const = 0;

        virtual IOperand *operator+(IOperand const &rhs) const = 0;
        virtual IOperand *operator-(IOperand const &rhs) const = 0;
        virtual IOperand *operator*(IOperand const &rhs) const = 0;
        virtual IOperand *operator/(IOperand const &rhs) const = 0;
        virtual IOperand *operator%(IOperand const &rhs) const = 0;

        virtual ~IOperand() = default;
    };

#endif //ABSTRACTVM_IOPERAND_HPP
