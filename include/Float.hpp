#ifndef ABSTRACTVM_Float_HPP
    #define ABSTRACTVM_Float_HPP

    #include "IOperand.hpp"

    #include <cfloat>

    class Float : public IOperand
    {
    public:
        Float() = default;
        explicit Float(std::string v);

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
        const eOperandType _type = eOperandType::t_Float;
        std::string _value;
    };

#endif //ABSTRACTVM_Float_HPP
