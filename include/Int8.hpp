#ifndef ABSTRACTVM_INT8_HPP
    #define ABSTRACTVM_INT8_HPP

    #include "IOperand.hpp"

    class Int8 : public IOperand
    {
    public:
        Int8() = default;
        explicit Int8(std::string v);

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
        const eOperandType _type = eOperandType::t_Int8;
        std::string _value;
    };

#endif //ABSTRACTVM_INT8_HPP
