# Overview
This header-only library is designed to allow easy creation of type-safe bitmask structures which are themselves designed to not allow any undefined behaviour and whose operations are designed to keep the internal state valid.

The type safety offered by the library is intended to avoid the kinds of bugs that can accidentally occur with untyped bitmasks such as raw integers.

# Usage
This section displays a sample usage of the library macro in order to give a point of reference for the remaining sections.

```cpp
#include "bitmask.h"

DECLARE_BITMASK_ENUM(Foo, Value_1, Value_2, Value_3);

constexpr auto bitmask = Foo::Value_1 | Foo::Value_2;
constexpr auto bit = Foo::Value_1;
static_assert((bitmask & bit) == bit, "Failed assertion that bit is set in the bitmask"); // shouldn't fail
```

# The Macros
While the header of the library is over 670 lines of code, it's mainly due to the many internal macros required due to the preprocessor not allowing recursion or overloading. There are only 5 macros used from a user's point of view, and one of those is an alias.

The macros are all of the form "DECLARE_BITMASK_ENUM_X" where X defines the backing type size and allowed maximum number of bits/variants (checked at compile time).

The backing type is always an unsigned integer and is one of 8, 16, 32, or 64 bits. It was decided to not allow selection of the backing type and only of the bit count because it's unnecessary for it to be represented as anything other than an unsigned integer.

Additionally, the user is able to specify the name of the generated type, along with the bit names, but is not able to specify the integer values for the bits. This is because when dealing with bitmasks and bits, we only really need care about the names of the bits, and in most cases, individual bits represented in the enumeration are assigned continuous, ascending powers of two. We shouldn't give the user the opportunity to set their own values because it would allow for accidental issues such as assigning a non power of two, or repeating values.

As mentioned, the macros all follow the form: DECLARE_BITMASK_ENUM_<bit count>(<type name>, <variant 1 name>, <variant 2 name>, etc.)
  
The additional 5th macro is used when we don't want to define a bit count and is an alias for the 64 bit variant to allow maximum number of values to be specified.

Also as mentioned, the number of variants passed to the macro is checked against the bit count used so the user cannot define more than the underlying type can represent.

# Bitmasks and Bits
In order to leverage the type system and to provide correct functionality, it's necessary to separate the idea of an individual bit from a bitmask. The library therefore keeps these type separated, with differing internal representations, and operations defined to leave entities in a valid state. This section will explain these two distinct classes and what can be done with them.
