#ifndef __JSON_WRITER_H__
#define __JSON_WRITER_H__

#include "../../include/DataWriter.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;

// This class is a thin wrapper around Tencent's rapidjson library which implements the DataWriter
// interface.
class JsonWriter : public DataWriter
{
public:
    JsonWriter()
    {
        _writer = new Writer<StringBuffer>(_s);
    }

    ~JsonWriter()
    {
        if (_writer != nullptr)
        {
            delete _writer;
            _writer = nullptr;
        }
    }

    void StartObject()
    {
        _writer->StartObject();
    }

    void EndObject()
    {
        _writer->EndObject();
    }

    std::string Get() const
    {
        return _s.GetString();
    }

    void AddString(const char* name, const std::string& value)
    {
        _writer->Key(name);
        _writer->String(value.c_str());
    }

    void AddBool(const char* name, const bool& value)
    {
        _writer->Key(name);
        _writer->Bool(value);
    }

    void AddInt(const char* name, const int& value)
    {
        _writer->Key(name);
        _writer->Int(value);
    }

private:
    StringBuffer _s;
    Writer<StringBuffer>* _writer = nullptr;
};

#endif // __JSON_H__
