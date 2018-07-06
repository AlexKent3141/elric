#ifndef __JSON_READER_H__
#define __JSON_READER_H__

#include "../../include/DataReader.h"
#include "rapidjson/reader.h"

using namespace rapidjson;

// This class is a thin wrapper around Tencent's rapidjson library which implements the DataReader
// interface.
class JsonReader : public DataReader
{
public:
    void Parse(const std::string& json)
    {
        Reader reader;
        StringStream ss(json.c_str());
        reader.Parse(ss, *this);
    }

    // These methods are called by the rapidjson reader.
    bool Key(const char* str, size_t length, bool copy)
    {
        _latestKey = std::string(str);
        return true;
    }

    bool Bool(bool b)
    {
        _pairs[_latestKey] = std::to_string(b);
        return true;
    }

    bool Int(int i)
    {
        _pairs[_latestKey] = std::to_string(i);
        return true;
    }

    bool Uint(unsigned int u)
    {
        _pairs[_latestKey] = std::to_string(u);
        return true;
    }

    bool String(const char* str, size_t length, bool copy)
    {
        _pairs[_latestKey] = std::string(str);
        return true;
    }

    // These methods are required by the rapidjson Reader but are not used in this example.
    bool Null() { return true; }
    bool Int64(int64_t i) { return true; }
    bool Uint64(uint64_t u) { return true; }
    bool Double(double d) { return true; }
    bool RawNumber(const char* str, size_t length, bool copy) { return true; }
    bool StartObject() { return true; }
    bool EndObject(size_t memberCount) { return true; }
    bool StartArray() { return true; }
    bool EndArray(size_t elementCount) { return true; }

private:
    std::string _latestKey;
};

#endif // __JSON_READER_H__
