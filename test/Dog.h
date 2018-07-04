#ifndef __DOG_H__
#define __DOG_H__

#include "../headers/MetaProperty.h"
#include <string>
#include <tuple>

struct Dog
{
    std::string barkType;
    std::string colour;
    int weight;

    constexpr static auto metaProperties = std::make_tuple(
        MetaProperty(&Dog::barkType, "barkType"),
        MetaProperty(&Dog::colour, "colour"),
        MetaProperty(&Dog::weight, "weight")
    );
};

#endif // __DOG_H__
