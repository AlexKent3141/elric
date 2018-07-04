#ifndef __TEST_SCHEMA_H__
#define __TEST_SCHEMA_H__

#include "../../include/DataReader.h"
#include "../../include/DataWriter.h"
#include <sstream>

// This is an example data formatting schema which is used in the unit tests.
class TestSchema : public DataReader, public DataWriter
{
public:
    // Deserialise an object that is expressed using the test schema.
    void Parse(const std::string& data)
    {
        std::stringstream dataStream(data);
        std::string line, name, value;
        while (std::getline(dataStream, line))
        {
            if (line != Start && line != End)
            {
                size_t spaceLoc = line.find(" ");
                if (spaceLoc != std::string::npos)
                {
                    name = line.substr(0, spaceLoc);
                    value = line.substr(spaceLoc + 1);
                    _pairs[name] = value;
                }
            }
        }
    }

    void BeginObject()
    {
        _data += Start;
    }

    void EndObject()
    {
        _data += "\n" + End;
    }

    std::string Get() const
    {
        return _data;
    }

    void AddString(const char* name, const std::string& value)
    {
        _data += "\n" + std::string(name) + " " + value;
    }

    void AddInt(const char* name, const int& value)
    {
        _data += "\n" + std::string(name) + " " + std::to_string(value);
    }

private:
    const std::string Start = "start";
    const std::string End = "end";

    std::string _data;
};

#endif // __TEST_SCHEMA_H__
