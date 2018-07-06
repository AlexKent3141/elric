# Elric

<i>"Alchemy: the science of understanding the structure of matter, breaking it down, then reconstructing it as something else. It can even make gold from lead. But alchemy is a science so it must follow the natural laws: to create, something of equal value must be lost. This is the principal of equivalent exchange." - Edward Elric</i>

Elric is a attempt to make object serialisation in C++ a less painful experience by removing the need to add extra code to objects for this purpose.

The motivation for this project comes from the way the C# .NET XmlSerializer works out-of-the-box and can be informed using Attributes. In the C++ world we need to find our own mechanism for attaching this metadata to objects. In Elric this is achieved by constructing a tuple of properties at compile time and then enumerating them (credit to Guillaume Racicot for his answer to https://stackoverflow.com/questions/17549906/c-json-serialization/34165367# which pointed me down this route).

# Example

For a look at Elric in action check out the [example](example/json) which uses Tencent's RapidJson library to serialise an object. Once the abstraction layer between Elric and the RapidJson library has been written the resulting serialisation code is rather straightforward!

# Todo

- Support more member types (arrays?)
- Nested serialisable objects
