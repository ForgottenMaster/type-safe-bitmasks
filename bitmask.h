#pragma once

#include <bitset>
#include <climits>
#include <iostream>
#include <type_traits>

// Workaround for MSVC bullshit
#define EXPAND(x) x

// Macro magic to count the number of __VA_ARGS__ given to a macro
#define __REVERSE_SEQUENCE()        \
    64,63,62,61,60,                 \
    59,58,57,56,55,54,53,52,51,50,  \
    49,48,47,46,45,44,43,42,41,40,  \
    39,38,37,36,35,34,33,32,31,30,  \
    29,28,27,26,25,24,23,22,21,20,  \
    19,18,17,16,15,14,13,12,11,10,  \
    9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define __ARG_COUNT(                            \
    _1, _2, _3, _4, _5, _6, _7, _8, _9, _10,    \
    _11,_12,_13,_14,_15,_16,_17,_18,_19,_20,    \
    _21,_22,_23,_24,_25,_26,_27,_28,_29,_30,    \
    _31,_32,_33,_34,_35,_36,_37,_38,_39,_40,    \
    _41,_42,_43,_44,_45,_46,_47,_48,_49,_50,    \
    _51,_52,_53,_54,_55,_56,_57,_58,_59,_60,    \
    _61,_62,_63,_64,N,...) N

#define __VA_ARG_COUNT(...) \
    EXPAND(__ARG_COUNT(__VA_ARGS__))

#define VA_ARG_COUNT(...) \
    __VA_ARG_COUNT(__VA_ARGS__, __REVERSE_SEQUENCE())

// functions to add members to the enum based on how many members there are to add
#define __ADD_MEMBERS_COUNT(Count) __ADD_MEMBERS_##Count

#define __ADD_MEMBERS_1(Count, UnderlyingType, Name)	\
    Name = UnderlyingType{1} << (Count - 1),

#define __ADD_MEMBERS_2(Count, UnderlyingType, Name, ...)		\
    Name = UnderlyingType{1} << (Count - 2),                    \
    EXPAND(__ADD_MEMBERS_1(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_3(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 3),                    \
    EXPAND(__ADD_MEMBERS_2(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_4(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 4),                    \
    EXPAND(__ADD_MEMBERS_3(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_5(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 5),                    \
    EXPAND(__ADD_MEMBERS_4(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_6(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 6),                    \
    EXPAND(__ADD_MEMBERS_5(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_7(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 7),                    \
    EXPAND(__ADD_MEMBERS_6(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_8(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 8),                    \
    EXPAND(__ADD_MEMBERS_7(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_9(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 9),                    \
    EXPAND(__ADD_MEMBERS_8(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_10(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 10),                    \
    EXPAND(__ADD_MEMBERS_9(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_11(Count, UnderlyingType, Name, ...)			\
    Name = UnderlyingType{1} << (Count - 11),						\
    EXPAND(__ADD_MEMBERS_10(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_12(Count, UnderlyingType, Name, ...)			\
    Name = UnderlyingType{1} << (Count - 12),                    	\
    EXPAND(__ADD_MEMBERS_11(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_13(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 13),                    \
    EXPAND(__ADD_MEMBERS_12(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_14(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 14),                    \
    EXPAND(__ADD_MEMBERS_13(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_15(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 15),                    \
    EXPAND(__ADD_MEMBERS_14(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_16(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 16),                    \
    EXPAND(__ADD_MEMBERS_15(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_17(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 17),                    \
    EXPAND(__ADD_MEMBERS_16(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_18(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 18),                    \
    EXPAND(__ADD_MEMBERS_17(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_19(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 19),                    \
    EXPAND(__ADD_MEMBERS_18(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_20(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 20),                    \
    EXPAND(__ADD_MEMBERS_19(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_21(Count, UnderlyingType, Name, ...)			\
    Name = UnderlyingType{1} << (Count - 21),						\
    EXPAND(__ADD_MEMBERS_20(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_22(Count, UnderlyingType, Name, ...)			\
    Name = UnderlyingType{1} << (Count - 22),                    	\
    EXPAND(__ADD_MEMBERS_21(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_23(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 23),                    \
    EXPAND(__ADD_MEMBERS_22(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_24(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 24),                    \
    EXPAND(__ADD_MEMBERS_23(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_25(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 25),                    \
    EXPAND(__ADD_MEMBERS_24(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_26(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 26),                    \
    EXPAND(__ADD_MEMBERS_25(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_27(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 27),                    \
    EXPAND(__ADD_MEMBERS_26(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_28(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 28),                    \
    EXPAND(__ADD_MEMBERS_27(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_29(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 29),                    \
    EXPAND(__ADD_MEMBERS_28(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_30(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 30),                    \
    EXPAND(__ADD_MEMBERS_29(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_31(Count, UnderlyingType, Name, ...)			\
    Name = UnderlyingType{1} << (Count - 31),						\
    EXPAND(__ADD_MEMBERS_30(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_32(Count, UnderlyingType, Name, ...)			\
    Name = UnderlyingType{1} << (Count - 32),                    	\
    EXPAND(__ADD_MEMBERS_31(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_33(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 33),                    \
    EXPAND(__ADD_MEMBERS_32(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_34(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 34),                    \
    EXPAND(__ADD_MEMBERS_33(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_35(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 35),                    \
    EXPAND(__ADD_MEMBERS_34(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_36(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 36),                    \
    EXPAND(__ADD_MEMBERS_35(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_37(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 37),                    \
    EXPAND(__ADD_MEMBERS_36(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_38(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 38),                    \
    EXPAND(__ADD_MEMBERS_37(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_39(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 39),                    \
    EXPAND(__ADD_MEMBERS_38(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_40(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 40),                    \
    EXPAND(__ADD_MEMBERS_39(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_41(Count, UnderlyingType, Name, ...)			\
    Name = UnderlyingType{1} << (Count - 41),						\
    EXPAND(__ADD_MEMBERS_40(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_42(Count, UnderlyingType, Name, ...)			\
    Name = UnderlyingType{1} << (Count - 42),                    	\
    EXPAND(__ADD_MEMBERS_41(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_43(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 43),                    \
    EXPAND(__ADD_MEMBERS_42(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_44(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 44),                    \
    EXPAND(__ADD_MEMBERS_43(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_45(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 45),                    \
    EXPAND(__ADD_MEMBERS_44(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_46(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 46),                    \
    EXPAND(__ADD_MEMBERS_45(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_47(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 47),                    \
    EXPAND(__ADD_MEMBERS_46(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_48(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 48),                    \
    EXPAND(__ADD_MEMBERS_47(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_49(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 49),                    \
    EXPAND(__ADD_MEMBERS_48(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_50(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 50),                    \
    EXPAND(__ADD_MEMBERS_49(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_51(Count, UnderlyingType, Name, ...)			\
    Name = UnderlyingType{1} << (Count - 51),						\
    EXPAND(__ADD_MEMBERS_50(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_52(Count, UnderlyingType, Name, ...)			\
    Name = UnderlyingType{1} << (Count - 52),                    	\
    EXPAND(__ADD_MEMBERS_51(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_53(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 53),                    \
    EXPAND(__ADD_MEMBERS_52(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_54(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 54),                    \
    EXPAND(__ADD_MEMBERS_53(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_55(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 55),                    \
    EXPAND(__ADD_MEMBERS_54(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_56(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 56),                    \
    EXPAND(__ADD_MEMBERS_55(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_57(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 57),                    \
    EXPAND(__ADD_MEMBERS_56(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_58(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 58),                    \
    EXPAND(__ADD_MEMBERS_57(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_59(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 59),                    \
    EXPAND(__ADD_MEMBERS_58(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_60(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 60),                    \
    EXPAND(__ADD_MEMBERS_59(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_61(Count, UnderlyingType, Name, ...)			\
    Name = UnderlyingType{1} << (Count - 61),						\
    EXPAND(__ADD_MEMBERS_60(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_62(Count, UnderlyingType, Name, ...)			\
    Name = UnderlyingType{1} << (Count - 62),                    	\
    EXPAND(__ADD_MEMBERS_61(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_63(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 63),                    \
    EXPAND(__ADD_MEMBERS_62(Count, UnderlyingType, __VA_ARGS__))

#define __ADD_MEMBERS_64(Count, UnderlyingType, Name, ...)       \
    Name = UnderlyingType{1} << (Count - 64),                    \
    EXPAND(__ADD_MEMBERS_63(Count, UnderlyingType, __VA_ARGS__))

// functions to add static instances to the wrapping enum class
#define __ADD_INSTANCES_COUNT(Count) __ADD_INSTANCES_##Count

#define __ADD_INSTANCES_1(WrapperName, InstanceName)		\
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };

#define __ADD_INSTANCES_2(WrapperName, InstanceName, ...)		\
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };    								\
    EXPAND(__ADD_INSTANCES_1(WrapperName, __VA_ARGS__))

#define __ADD_INSTANCES_3(WrapperName, InstanceName, ...)		\
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };									\
    EXPAND(__ADD_INSTANCES_2(WrapperName, __VA_ARGS__))

#define __ADD_INSTANCES_4(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_3(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_5(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_4(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_6(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_5(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_7(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_6(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_8(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_7(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_9(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_8(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_10(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_9(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_11(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_10(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_12(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_11(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_13(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_12(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_14(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_13(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_15(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_14(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_16(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_15(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_17(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_16(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_18(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_17(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_19(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_18(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_20(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_19(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_21(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_20(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_22(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_21(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_23(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_22(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_24(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_23(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_25(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_24(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_26(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_25(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_27(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_26(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_28(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_27(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_29(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_28(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_30(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_29(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_31(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_30(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_32(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_31(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_33(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_32(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_34(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_33(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_35(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_34(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_36(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_35(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_37(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_36(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_38(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_37(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_39(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_38(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_40(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_39(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_41(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_40(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_42(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_41(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_43(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_42(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_44(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_43(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_45(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_44(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_46(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_45(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_47(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_46(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_48(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_47(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_49(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_48(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_50(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_49(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_51(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_50(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_52(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_51(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_53(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_52(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_54(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_53(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_55(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_54(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_56(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_55(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_57(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_56(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_58(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_57(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_59(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_58(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_60(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_59(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_61(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_60(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_62(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_61(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_63(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_62(WrapperName,__VA_ARGS__))

#define __ADD_INSTANCES_64(WrapperName, InstanceName, ...)							    \
    constexpr static const Bit<WrapperName> InstanceName = { WrapperName::Enum::InstanceName, #InstanceName };	\
    EXPAND(__ADD_INSTANCES_63(WrapperName,__VA_ARGS__))

// forward declaration of Bit so that Bitmask can friend it.
template <typename T>
class Bit;

// class that represents a mask or combination of named bits of the type.
template <typename T>
class Bitmask 
{
	friend class Bit<T>;

private:
	using UnderlyingType = std::underlying_type_t<typename T::Enum>;
	constexpr static const char* const ClassName = T::ClassName;
	constexpr static const std::uint8_t BitCount = T::BitCount;

	constexpr Bitmask(const UnderlyingType value) : value{ value } {}

	UnderlyingType value;

public:
	constexpr explicit Bitmask(const Bit<T> bit) noexcept : value { static_cast<UnderlyingType>(bit.value) } {}
	friend std::ostream& operator<<(std::ostream& os, const Bitmask& obj) noexcept {
		return os
			<< "Bitmask<"
			<< Bitmask::ClassName
			<< ">{ "
			<< std::bitset<Bitmask::BitCount>(obj.value)
			<< " }";
	}

	// Bitmask/Bit operations
	constexpr Bit<T> operator&(const Bit<T> rhs) const noexcept { return ((value & static_cast<UnderlyingType>(rhs.value)) == 0) ? T::NONE : rhs; }
	constexpr Bitmask operator|(const Bit<T> rhs) const noexcept { return *this | Bitmask{ rhs }; }
	constexpr Bitmask operator^(const Bit<T> rhs) const noexcept { return *this ^ Bitmask{ rhs }; }
	constexpr bool operator==(const Bit<T> rhs) const noexcept { return *this == Bitmask{ rhs }; }
	constexpr bool operator!=(const Bit<T> rhs) const noexcept { return *this != Bitmask{ rhs }; }

	// Bitmask/Bitmask operations
	constexpr Bitmask operator&(const Bitmask rhs) const noexcept { return Bitmask{ static_cast<UnderlyingType>(value & rhs.value) }; }
	constexpr Bitmask operator|(const Bitmask rhs) const noexcept { return Bitmask{ static_cast<UnderlyingType>(value | rhs.value) }; }
	constexpr Bitmask operator^(const Bitmask rhs) const noexcept { return Bitmask{ static_cast<UnderlyingType>(value ^ rhs.value) }; }
	constexpr bool operator==(const Bitmask rhs) const noexcept { return value == rhs.value; }
	constexpr bool operator!=(const Bitmask rhs) const noexcept { return value != rhs.value; }

	// Complement
	constexpr Bitmask operator~() const noexcept { return Bitmask{ static_cast<UnderlyingType>(~value) }; }
};

// class that represents a single named bit of the type.
template <typename T>
class Bit
{
	friend T;
	friend class Bitmask<T>;

private:
	using UnderlyingType = std::underlying_type_t<typename T::Enum>;
	constexpr static const char* const ClassName = T::ClassName;
	constexpr static const std::uint8_t BitCount = T::BitCount;

	constexpr Bit(const typename T::Enum value, const char* const name) noexcept : value{ value }, name{ name } {}

	const typename T::Enum value;
	const char* const name;

public:
	friend std::ostream& operator<<(std::ostream& os, const Bit& obj) noexcept {
		return os 
			<< "Bit<"
			<< Bit::ClassName
			<< ">{ "
			<< std::bitset<Bit::BitCount>(static_cast<Bit::UnderlyingType>(obj.value))
			<< " }";
	}
	constexpr operator typename T::Enum() const noexcept { return value; }

	// Bit/Bit operations
	constexpr Bit operator&(const Bit rhs) const noexcept { return Bitmask<T>{ *this } & rhs; }
	constexpr Bitmask<T> operator|(const Bit rhs) const noexcept { return Bitmask<T>{ *this } | Bitmask<T>{ rhs }; }
	constexpr Bitmask<T> operator^(const Bit rhs) const noexcept { return Bitmask<T>{ *this } ^ Bitmask<T>{ rhs }; }
	constexpr bool operator==(const Bit rhs) const noexcept { return value == rhs.value; }
	constexpr bool operator!=(const Bit rhs) const noexcept { return value != rhs.value; }

	// Bit/Bitmask operations
	constexpr Bit operator&(const Bitmask<T> rhs) const noexcept { return rhs & *this; }
	constexpr Bitmask<T> operator|(const Bitmask<T> rhs) const noexcept { return Bitmask<T>{ *this } | rhs; }
	constexpr Bitmask<T> operator^(const Bitmask<T> rhs) const noexcept { return Bitmask<T>{ *this } ^ rhs; }
	constexpr bool operator==(const Bitmask<T> rhs) const noexcept { return Bitmask{ *this } == rhs; }
	constexpr bool operator!=(const Bitmask<T> rhs) const noexcept { return Bitmask{ *this } != rhs; }

	// Complement
	constexpr Bitmask<T> operator~() const noexcept { return ~Bitmask<T>{ *this }; }
};

// functions to build up the enum class and count __VA_ARGS__ given
#define __DECLARE_BITMASK_ENUM_WITH_UNDERLYING_TYPE_AND_COUNT(Name, UnderlyingType, Count, ...)             \
class Name																	                                \
{																					 			            \
	friend class Bit<Name>;																					\
	friend class Bitmask<Name>;																				\
																											\
private:                                                                                         			\
	enum class Enum : UnderlyingType 															            \
	{													 		 								            \
		NONE = 0,																				            \
		EXPAND(__ADD_MEMBERS_COUNT(Count)(Count, UnderlyingType, __VA_ARGS__))					            \
	};																							            \
																											\
	constexpr static const char* const ClassName = #Name;													\
	constexpr static const std::uint8_t BitCount = Count;													\
																											\
public:																										\
	constexpr static const Bit<Name> NONE = { Name::Enum::NONE, "NONE" };									\
	EXPAND(__ADD_INSTANCES_COUNT(Count)(Name, __VA_ARGS__))													\
};																								            \
static_assert((sizeof(UnderlyingType) * CHAR_BIT) >= Count, "You are trying to create a bitmask with too many options, try a bigger backing type.");

#define __DECLARE_BITMASK_ENUM_WITH_UNDERLYING_TYPE(Name, UnderlyingType, ...)                                      \
__DECLARE_BITMASK_ENUM_WITH_UNDERLYING_TYPE_AND_COUNT(Name, UnderlyingType, VA_ARG_COUNT(__VA_ARGS__), __VA_ARGS__)

// top level functions to create bitmasks of various sizes
#define DECLARE_BITMASK_ENUM_8(Name, ...) __DECLARE_BITMASK_ENUM_WITH_UNDERLYING_TYPE(Name, std::uint8_t, __VA_ARGS__)
#define DECLARE_BITMASK_ENUM_16(Name, ...) __DECLARE_BITMASK_ENUM_WITH_UNDERLYING_TYPE(Name, std::uint16_t, __VA_ARGS__)
#define DECLARE_BITMASK_ENUM_32(Name, ...) __DECLARE_BITMASK_ENUM_WITH_UNDERLYING_TYPE(Name, std::uint32_t, __VA_ARGS__)
#define DECLARE_BITMASK_ENUM_64(Name, ...) __DECLARE_BITMASK_ENUM_WITH_UNDERLYING_TYPE(Name, std::uint64_t, __VA_ARGS__)
#define DECLARE_BITMASK_ENUM(Name, ...) DECLARE_BITMASK_ENUM_64(Name, __VA_ARGS__)