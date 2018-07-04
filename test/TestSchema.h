#ifndef __TEST_SCHEMA_H__
#define __TEST_SCHEMA_H__

#include "../headers/DataReader.h"
#include "../headers/DataWriter.h"
#include <iostream>
#include <sstream>

class TestSchema : public DataReader, public DataWriter
{
public:
    ~TestSchema()
    {
    }

    // Deserialise an object that is expressed using the test schema.
    void Parse(const std::string& data)
    {
        std::stringstream dataStream(data);
        std::string line, name, value;
        while (std::getline(dataStream, line))
        {
            if (line != Start && line != End)
            {
                int spaceLoc = line.find(" ");
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
