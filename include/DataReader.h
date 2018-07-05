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

    // Get the field with the specified name.
    template<typename T>
    T GetData(const std::string& name) const
    {
        auto it = _pairs.find(name);
        if (it == _pairs.end()) throw ElricException(ErrorCode::KeyDoesNotExist);
        return Convert<T>(it->second);
    }

protected:
    std::map<std::string, std::string> _pairs;
};

#endif // __DATA_READER_H__
