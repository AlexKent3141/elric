#ifndef __DATA_READER_H__
#define __DATA_READER_H__

#include "Error.h"
#include "Utilities.h"
#include <map>

// This is the base class for objects which can read data.
// The data format could be JSON, a markup language like XML or some other language.
class DataReader
{
public:
    virtual ~DataReader() {}

    // Parse the formatted data into key-value pairs.
    virtual void Parse(const std::string&) = 0;

    // Allow clients to implement their own boolean parser as there are a few natural ways for these
    // to be stored e.g. 1/0 or "true"/"false".
    // By default we assume an integral representation.
    virtual bool BoolFromString(const std::string& value) const
    {
        return Convert<int>(value);
    }

    // Get the field with the specified name.
    template<typename T>
    T GetData(const std::string& name) const
    {
        auto it = _pairs.find(name);
        if (it == _pairs.end()) throw ElricException(ErrorCode::KeyDoesNotExist);
        return ConvertFromString<T>(it->second);
    }

    template<typename T>
    T ConvertFromString(const std::string& value) const
    {
        return Convert<T>(value);
    }

protected:
    std::map<std::string, std::string> _pairs;
};

template<>
bool DataReader::ConvertFromString<bool>(const std::string& value) const
{
    return BoolFromString(value);
}

#endif // __DATA_READER_H__
