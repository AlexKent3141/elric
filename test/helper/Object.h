#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "../../include/MetaProperty.h"

// This object aids in testing the serialisation of a specific member type.
template <typename T>
struct Object
{
    T content;

    constexpr static auto metaProperties = std::make_tuple(
        MetaProperty(&Object::content, "content")
    );
};

#endif // __OBJECT_H__
