#ifndef ABSTRACTVM_INT32_HPP
    #define ABSTRACTVM_INT32_HPP

    #include "IOperand.hpp"

    class Int32 : public IOperand
    {
    public:
        Int32() = default;
        explicit Int32(std::string v);

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
        const eOperandType _type = eOperandType::t_Int32;
        std::string _value;
    };

#endif //ABSTRACTVM_INT32_HPP
