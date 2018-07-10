#ifndef __DATA_WRITER_H__
#define __DATA_WRITER_H__

#include "Error.h"
#include <string>

// This is the base class for objects which can serialise key-value pairs.
// The data format could be JSON, a markup language like XML or some other language.
class DataWriter
{
public:
    virtual ~DataWriter() {}

    virtual void StartObject() = 0;
    virtual void EndObject() = 0;

    virtual void StartArray() {}
    virtual void EndArray() {}

    virtual void AddKey(const char* name) = 0;

    // Override these methods to serialise different types.
    virtual void AddString(const std::string& value) {}
    virtual void AddBool(const bool& value) {}
    virtual void AddInt(const int& value) {}
    virtual void AddUInt(const unsigned int& value) {}
    virtual void AddInt64(const int64_t& value) {}
    virtual void AddUInt64(const uint64_t& value) {}
    virtual void AddDouble(const double& value) {}

    // Get the formatted object string.
    virtual std::string Get() const = 0;

    // Add new data to be formatted.
    // Each data type that can be serialised has a specialisation of this method and
    // corresponding virtual adding method.
    template<typename T>
    void AddValue(const T& value)
    {
        throw ElricException(ErrorCode::TypeNotSupported);
    }

    template<typename T, size_t N>
    void AddValue(const T(&array)[N])
    {
        StartArray();

        for (const T& value : array)
        {
            AddValue(value);
        }

        EndArray();
    }
};

template<>
void DataWriter::AddValue<std::string>(const std::string& value)
{
    AddString(value);
}

template<>
void DataWriter::AddValue<bool>(const bool& value)
{
    AddBool(value);
}

template<>
void DataWriter::AddValue<int>(const int& value)
{
    AddInt(value);
}

template<>
void DataWriter::AddValue<unsigned int>(const unsigned int& value)
{
    AddUInt(value);
}

template<>
void DataWriter::AddValue<int64_t>(const int64_t& value)
{
    AddInt64(value);
}

template<>
void DataWriter::AddValue<uint64_t>(const uint64_t& value)
{
    AddUInt64(value);
}

template<>
void DataWriter::AddValue<double>(const double& value)
{
    AddDouble(value);
}

#endif // __DATA_WRITER_H__
