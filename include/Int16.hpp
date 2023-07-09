#ifndef ABSTRACTVM_INT16_HPP
    #define ABSTRACTVM_INT16_HPP

    #include "IOperand.hpp"

    class Int16 : public IOperand
    {
    public:
        Int16() = default;
        explicit Int16(std::string v);

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
        const eOperandType _type = eOperandType::t_Int16;
        std::string _value;
    };

#endif //ABSTRACTVM_INT16_HPP
