#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include "Error.h"
#include <string>

template<typename T>
T Convert(const std::string& data)
{
    throw ElricException(ErrorCode::TypeNotSupported);
}

template<>
std::string Convert(const std::string& data)
{
    return data;
}

template<>
int Convert(const std::string& data)
{
    return stoi(data);
}

template<>
unsigned int Convert(const std::string& data)
{
    return stoul(data);
}

template<>
int64_t Convert(const std::string& data)
{
    return stoll(data);
}

template<>
uint64_t Convert(const std::string& data)
{
    return stoull(data);
}

template<>
double Convert(const std::string& data)
{
    return stod(data);
}

#endif // __UTILITIES_H__
