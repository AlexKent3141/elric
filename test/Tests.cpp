#include "catch2/catch.hpp"
#include "helper/Object.h"
#include "helper/TestSchema.h"
#include "../include/Serialise.h"
#include <vector>

TEST_CASE("Serialise and deserialise a string", "[Reading and writing tests]")
{
    const std::string& TestString = "Elric is cool";
    Object<std::string> pre = { TestString };

    std::string serialised = Serialise::To<TestSchema>(pre);
    Object<std::string> post = Serialise::From<TestSchema, Object<std::string>>(serialised);

    REQUIRE(post.content == TestString);
}

TEST_CASE("Serialise and deserialise a bool", "[Reading and writing tests]")
{
    const bool TestBool = true;
    Object<bool> pre = { TestBool };

    std::string serialised = Serialise::To<TestSchema>(pre);
    Object<bool> post = Serialise::From<TestSchema, Object<bool>>(serialised);

    REQUIRE(post.content == TestBool);
}

TEST_CASE("Serialise and deserialise a signed int", "[Reading and writing tests]")
{
    const int TestInt = -3141;
    Object<int> pre = { TestInt };

    std::string serialised = Serialise::To<TestSchema>(pre);
    Object<int> post = Serialise::From<TestSchema, Object<int>>(serialised);

    REQUIRE(post.content == TestInt);
}

TEST_CASE("Serialise and deserialise a unsigned int", "[Reading and writing tests]")
{
    const unsigned int TestUInt = 3141;
    Object<unsigned int> pre = { TestUInt };

    std::string serialised = Serialise::To<TestSchema>(pre);
    Object<unsigned int> post = Serialise::From<TestSchema, Object<unsigned int>>(serialised);

    REQUIRE(post.content == TestUInt);
}

TEST_CASE("Serialise and deserialise a signed 64 bit integer", "[Reading and writing tests]")
{
    const int64_t TestInt64 = -31415926535;
    Object<int64_t> pre = { TestInt64 };

    std::string serialised = Serialise::To<TestSchema>(pre);
    Object<int64_t> post = Serialise::From<TestSchema, Object<int64_t>>(serialised);

    REQUIRE(post.content == TestInt64);
}

TEST_CASE("Serialise and deserialise an unsigned 64 bit integer", "[Reading and writing tests]")
{
    const uint64_t TestUInt64 = 31415926535;
    Object<uint64_t> pre = { TestUInt64 };

    std::string serialised = Serialise::To<TestSchema>(pre);
    Object<uint64_t> post = Serialise::From<TestSchema, Object<uint64_t>>(serialised);

    REQUIRE(post.content == TestUInt64);
}

TEST_CASE("Serialise and deserialise a double", "[Reading and writing tests]")
{
    const double TestDouble = 3.14159;
    Object<double> pre = { TestDouble };

    std::string serialised = Serialise::To<TestSchema>(pre);
    Object<double> post = Serialise::From<TestSchema, Object<double>>(serialised);

    REQUIRE(post.content == TestDouble);
}

TEST_CASE("Attempt to serialise unsupported type", "[Error scenarios]")
{
    bool thrown = false;
    try
    {
        Object<std::vector<int>> pre = { std::vector<int>() };
        Serialise::To<TestSchema, Object<std::vector<int>>>(pre);
    }
    catch (const ElricException& e)
    {
        REQUIRE(e.GetError() == ErrorCode::TypeNotSupported);
        thrown = true;
    }

    REQUIRE(thrown);
}

TEST_CASE("Attempt to deserialise a string which is missing content", "[Error scenarios]")
{
    bool thrown = false;
    try
    {
        std::string pre = ""; // String which is missing the "content" field.
        Serialise::From<TestSchema, Object<int>>(pre);
    }
    catch (const ElricException& e)
    {
        REQUIRE(e.GetError() == ErrorCode::KeyDoesNotExist);
        thrown = true;
    }

    REQUIRE(thrown);
}
