#include "bitmask.h"

#include <iostream>

DECLARE_BITMASK_ENUM_8(Foo, V1, V2, V3, V4)

struct Bar {
	struct Baz {
		DECLARE_BITMASK_ENUM_8(Quux, V1, V2, V3)
	};
};

int main()
{
	static_assert(Foo::V1 == Foo::V1, "Test 1 failed");															// test two bits are equal
	static_assert(Foo::V1 != Foo::V2, "Test 2 failed");															// test two bits are inequal
	static_assert((Foo::V1 & Foo::V1) == Foo::V1, "Test 3 failed");												// test a bit AND'ed with itself is itself
	static_assert((Foo::V1 & Foo::V2) == Foo::NONE, "Test 4 failed"); 											// test a bit AND'ed with something else is NONE
	static_assert((Foo::V1 | Foo::V1) == Foo::V1, "Test 5 failed");												// test a bit OR'ed with itself is itself
	static_assert((Foo::V1 | Foo::NONE) == Foo::V1, "Test 6 failed");											// test a bit OR'ed with NONE is itself
	static_assert(((Foo::V1 | Foo::V2) != Foo::V1) && ((Foo::V1 | Foo::V2) != Foo::V2), "Test 7 failed");		// test a bit OR'ed with a different one is not either
	static_assert(((Foo::V1 | Foo::V2) | Foo::V3) == (Foo::V1 | (Foo::V2 | Foo::V3)), "Test 8 failed");			// test that OR is transitive
	static_assert(((Foo::V1 | Foo::V2) & Foo::V2) == Foo::V2, "Test 9 failed");									// test combining and then extraction
	static_assert(~(~Foo::V1) == Foo::V1, "Test 10 failed");													// test double negation equals the original item
	static_assert(Bar::Baz::Quux::V1 == Bar::Baz::Quux::V1, "Test 11 failed");									// test macro can be use in a nested environment
    return 0;
}