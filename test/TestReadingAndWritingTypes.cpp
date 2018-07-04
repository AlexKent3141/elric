#ifndef __TEST_READING_AND_WRITING_TYPES_H__
#define __TEST_READING_AND_WRITING_TYPES_H__

#include "catch2/catch.hpp"
#include "helper/Object.h"
#include "helper/TestSchema.h"
#include "../include/Serialise.h"

TEST_CASE("Serialise and deserialise a string", "[Reading and writing tests]")
{
    const std::string& TestString = "Elric is cool";
    Object<std::string> pre = { TestString };

    std::string serialised = Serialise::To<TestSchema>(pre);
    Object<std::string> post = Serialise::From<TestSchema, Object<std::string>>(serialised);

    REQUIRE(post.content == TestString);
}

TEST_CASE("Serialise and deserialise a int", "[Reading and writing tests]")
{
    const int TestInt = 3141;
    Object<int> pre = { TestInt };

    std::string serialised = Serialise::To<TestSchema>(pre);
    Object<int> post = Serialise::From<TestSchema, Object<int>>(serialised);

    REQUIRE(post.content == TestInt);
}

TEST_CASE("Serialise and deserialise a double", "[Reading and writing tests]")
{
    const double TestDouble = 3.14159;
    Object<double> pre = { TestDouble };

    std::string serialised = Serialise::To<TestSchema>(pre);
    Object<double> post = Serialise::From<TestSchema, Object<double>>(serialised);

    REQUIRE(post.content == TestDouble);
}

#endif // __TEST_READING_AND_WRITING_TYPES_H__
