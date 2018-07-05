#ifndef __DATA_WRITER_H__
#define __DATA_WRITER_H__

#include "Error.h"
#include <string>

// This is the base class for objects which can serialise data.
// The data format could be JSON, a markup language like XML or some other language.
class DataWriter
{
public:
    virtual ~DataWriter() {}

    virtual void StartObject() = 0;
    virtual void EndObject() = 0;

    // Get the formatted object string.
    virtual std::string Get() const = 0;

    // Override these methods to serialise different types.
    virtual void AddString(const char* name, const std::string& value) {}
    virtual void AddInt(const char* name, const int& value) {}
    virtual void AddUInt(const char* name, const unsigned int& value) {}
    virtual void AddInt64(const char* name, const int64_t& value) {}
    virtual void AddUInt64(const char* name, const uint64_t& value) {}
    virtual void AddDouble(const char* name, const double& value) {}

    // Add new data to be formatted.
    // Each data type that can be serialised has a specialisation of this method and
    // corresponding virtual adding method.
    template<typename T>
    void AddData(const char* name, const T& value)
    {
        throw ElricException(ErrorCode::TypeNotSupported);
    }
};

template<>
void DataWriter::AddData<std::string>(const char* name, const std::string& value)
{
    AddString(name, value);
}

template<>
void DataWriter::AddData<int>(const char* name, const int& value)
{
    AddInt(name, value);
}

template<>
void DataWriter::AddData<unsigned int>(const char* name, const unsigned int& value)
{
    AddUInt(name, value);
}

template<>
void DataWriter::AddData<int64_t>(const char* name, const int64_t& value)
{
    AddInt64(name, value);
}

template<>
void DataWriter::AddData<uint64_t>(const char* name, const uint64_t& value)
{
    AddUInt64(name, value);
}

template<>
void DataWriter::AddData<double>(const char* name, const double& value)
{
    AddDouble(name, value);
}

#endif // __DATA_WRITER_H__
