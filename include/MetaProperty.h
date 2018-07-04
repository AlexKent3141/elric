#ifndef __META_PROPERTY_H__
#define __META_PROPERTY_H__

#include <string>

// A meta-property associates a name to a class instance member.
template<typename Class, typename Member>
struct MetaPropertyImpl
{
    constexpr MetaPropertyImpl(Member Class::*_member, const char* _name)
        : member(_member), name(_name)
    {
    }

    using Type = Member;

    Member Class::*member;
    const char* name;
};

// Helper which allows for neater compile-time construction of meta-properties.
template<typename Class, typename MemberType>
constexpr auto MetaProperty(MemberType Class::*member, const char* name)
{
    return MetaPropertyImpl<Class, MemberType>(member, name);
}

#endif // __META_PROPERTY_H__
