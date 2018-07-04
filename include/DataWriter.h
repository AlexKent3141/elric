#ifndef __DATA_WRITER_H__
#define __DATA_WRITER_H__

// This is the base class for objects which can serialise data.
// The data format could be JSON, a markup language like XML or some other language.
class DataWriter
{
public:
    virtual ~DataWriter() {}

    virtual void BeginObject() = 0;
    virtual void EndObject() = 0;

    // Get the formatted object string.
    virtual std::string Get() const = 0;

    // Override these methods to serialise different types.
    virtual void AddString(const char* name, const std::string& value) {}
    virtual void AddInt(const char* name, const int& value) {}

    // Add new data to be formatted.
    // Each data type that can be serialised has a specialisation of this method and
    // corresponding virtual adding method.
    template<typename T>
    void AddData(const char* name, const T& value)
    {
        throw;
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

#endif // __DATA_WRITER_H__
