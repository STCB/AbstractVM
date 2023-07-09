/*
** EPITECH PROJECT, 2023
** abstractVM
** File description:
** Factory.hpp
*/

#ifndef FACTORY_HPP_
	#define FACTORY_HPP_

    #include "IOperand.hpp"

    class Factory {
        public:
            Factory() = default;
            ~Factory() = default;

            static IOperand* createOperand(eOperandType type, const std::string& value);

        private:
            static IOperand* createInt8(const std::string& value);
            static IOperand* createInt16(const std::string& value);
            static IOperand* createInt32(const std::string& value);
            static IOperand* createFloat(const std::string& value);
            static IOperand* createDouble(const std::string& value);
    };

#endif /*FACTORY_HPP_*/