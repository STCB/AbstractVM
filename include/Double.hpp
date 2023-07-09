#ifndef ABSTRACTVM_Double_HPP
    #define ABSTRACTVM_Double_HPP

    #include "IOperand.hpp"
    #include <float.h>

    class Double : public IOperand
    {
    public:
        Double() = default;
        explicit Double(std::string v);

        std::string toString() const override { return _value; };
        void setValue(std::string value) { _value = std::move(value); };
        eOperandType getType() const override;

        IOperand *operator+(IOperand const &rhs) const override;
        IOperand *operator-(IOperand const &rhs) const override;
        IOperand *operator*(IOperand const &rhs) const override;
        IOperand *operator/(IOperand const &rhs) const override;
        IOperand *operator%(IOperand const &rhs) const override;
        bool operator==(IOperand const &rhs) const;
    private:
        const eOperandType _type = eOperandType::t_Double;
        std::string _value;
    };

#endif //ABSTRACTVM_Double_HPP
