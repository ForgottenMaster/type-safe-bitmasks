# Overview
This header-only library is designed to allow easy creation of type-safe bitmask structures which are themselves designed to not allow any undefined behaviour and whose operations are designed to keep the internal state valid.

The type safety offered by the library is intended to avoid the kinds of bugs that can accidentally occur with untyped bitmasks such as raw integers.

# Usage
This section displays a sample usage of the library macro in order to give a point of reference for the remaining sections.

```cpp
#include "bitmask.h"

DECLARE_BITMASK_ENUM(Foo, Value_1, Value_2, Value_3)

constexpr auto bitmask = Foo::Value_1 | Foo::Value_2;
constexpr auto bit = Foo::Value_1;
static_assert((bitmask & bit) == bit, "Failed assertion that bit is set in the bitmask"); // shouldn't fail
```

# Bitmasks and Bits
In order to leverage the type system and to provide correct functionality, it's necessary to separate the idea of an individual bit from a bitmask. The library therefore keeps these type separated, with differing internal representations, and operations defined to leave entities in a valid state. This section will explain these two distinct classes and what can be done with them.
