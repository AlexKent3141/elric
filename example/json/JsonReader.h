#ifndef __JSON_READER_H__
#define __JSON_READER_H__

#include "../../include/DataReader.h"
#include "rapidjson/reader.h"
#include <vector>

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
        AddData(_latestKey, b);
        return true;
    }

    bool Int(int i)
    {
        AddData(_latestKey, i);
        return true;
    }

    bool Uint(unsigned int u)
    {
        if (_arrayStarted)
        {
            _array.push_back(u);
        }
        else
        {
            AddData(_latestKey, u);
        }

        return true;
    }

    bool String(const char* str, size_t length, bool copy)
    {
        AddData(_latestKey, std::string(str));
        return true;
    }

    bool StartArray()
    {
        _arrayStarted = true;
        return true;
    }

    bool EndArray(size_t elementCount)
    {
        assert(elementCount == _array.size());
        AddData(_latestKey, _array);
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

private:
    bool _arrayStarted = false;
    std::string _latestKey;
    std::vector<unsigned int> _array;
};

#endif // __JSON_READER_H__
