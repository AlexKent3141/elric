#ifndef __SERIALISE_H__
#define __SERIALISE_H__

#include "DataReader.h"
#include "DataWriter.h"
#include "Utilities.h"

// This class performs serialisation and deserialisation on objects.
class Serialise
{
public:
    // Serialise the specified object using the given type of writer.
    template<class Writer, class C>
    static std::string To(const C& object)
    {
        static_assert(std::is_base_of<DataWriter, Writer>::value, "Writer is not a DataWriter");
        Writer writer;
        writer.BeginObject();

        // Iterate over the meta-properties in the tuple and add each to the writer.
        constexpr auto numProperties = std::tuple_size<decltype(C::metaProperties)>::value;
        ForEachInSequence(std::make_index_sequence<numProperties>{}, [&](auto i) {
            constexpr auto property = std::get<i>(C::metaProperties);
            writer.AddData(property.name, object.*(property.member));
        });

        writer.EndObject();

        return writer.Get();
    }
    
    // Deserialise an instance of class C from the specified data using the given type of reader.
    template<class Reader, class C>
    static C From(const std::string& data)
    {
        static_assert(std::is_base_of<DataReader, Reader>::value, "Reader is not a DataReader");
        Reader reader;
        reader.Parse(data);
        C object;

        // Iterate over the meta-properties in the tuple and deserialise them into the object.
        constexpr auto numProperties = std::tuple_size<decltype(C::metaProperties)>::value;
        ForEachInSequence(std::make_index_sequence<numProperties>{}, [&](auto i) {
            constexpr auto property = std::get<i>(C::metaProperties);
            using MemberType = typename decltype(property)::Type;

            // Not sure why explicitly stating that GetData is templated below is required, but
            // ommitting this results in a compiler error under gcc 5.4.0.
            object.*(property.member) = reader.template GetData<MemberType>(property.name); 
        });

        return object;
    }
};

#endif // __SERIALISE_H__
