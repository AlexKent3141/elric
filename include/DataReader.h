#ifndef __DATA_READER_H__
#define __DATA_READER_H__

#include "DataValue.h"
#include "Error.h"
#include <map>
#include <vector>

// This is the base class for objects which can read data.
// The data format could be JSON, a markup language like XML or some other language.
class DataReader
{
public:
    virtual ~DataReader()
    {
        auto it = _pairs.begin();
        while (it != _pairs.end()) delete it++->second;
    }

    // Parse the formatted data into key-value pairs.
    virtual void Parse(const std::string&) = 0;

    // Helper method to be called when parsing which adds key/value pairs.
    template<typename T>
    void AddData(const std::string& name, const T& value)
    {
        _pairs[name] = new DataValue<T>(value);
    }

    // Get the field with the specified name.
    template<typename T>
    void GetData(const std::string& name, T& value) const
    {
        auto it = _pairs.find(name);
        if (it == _pairs.end()) throw ElricException(ErrorCode::KeyDoesNotExist);

        auto data = static_cast<DataValue<T>*>(it->second);
        value = data->value;
    }

    // Get an array field by name.
    // Internally the array was stored as a vector type.
    template<typename T, size_t N>
    void GetData(const std::string& name, T(&value)[N]) const
    {
        auto it = _pairs.find(name);
        if (it == _pairs.end()) throw ElricException(ErrorCode::KeyDoesNotExist);

        auto data = static_cast<DataValue<std::vector<T>>*>(it->second);
        const auto& val = data->value;

        // Copy the contents of the vector into the array.
        for (size_t i = 0; i < N; i++)
        {
            value[i] = val[i];
        }
    }

protected:
    std::map<std::string, Value*> _pairs;
};

#endif // __DATA_READER_H__
