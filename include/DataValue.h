#ifndef __DATA_VALUE_H__
#define __DATA_VALUE_H__

// Base class for DataValue types.
struct Value
{
    virtual ~Value() {}
};

// This type wraps up the type specified in the template parameter.
template<typename ValueType>
struct DataValue : public Value
{
    ValueType value;

    DataValue(ValueType _value) : value(_value) {}
};

#endif // __DATA_VALUE_H__
