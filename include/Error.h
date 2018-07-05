#ifndef __ERROR_H__
#define __ERROR_H__

#include <exception>
#include <iostream>
#include <string>

enum ErrorCode
{
    Success = 0,
    TypeNotSupported = 1,
    KeyDoesNotExist = 2
};

class ElricException : public std::exception
{
public:
    ElricException() = delete;

    ElricException(ErrorCode error) : _error(error)
    {
        _errorMessage = "Failed with error code: " + std::to_string(_error);
    }

    ErrorCode GetError() const
    {
        return _error;
    }

    const char* what() const throw()
    {
        return _errorMessage.c_str();
    }

private:
    ErrorCode _error = ErrorCode::Success;
    std::string _errorMessage;
};

#endif // __ERROR_H__
