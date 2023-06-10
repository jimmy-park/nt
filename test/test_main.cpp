#ifndef _MSC_VER
#include <cxxabi.h>

#include <cstdlib>
#endif

#include <concepts>
#include <iostream>
#include <string>
#include <typeinfo>

#include <nt.hpp>

template <typename T>
concept Assignment = requires(T a, T b) {
    { a =   b };
    { a +=  b };
    { a -=  b };
    { a *=  b };
    { a /=  b };
    { a %=  b };
    { a &=  b };
    { a |=  b };
    { a ^=  b };
    { a <<= b };
    { a >>= b };
};

template <typename T>
concept IncrementDecrement = requires(T a) {
    { ++a };
    { --a };
    { a-- };
    { a++ };
};

template <typename T>
concept Arithmetic = requires(T a, T b) {
    { +a     };
    { -a     };
    { a +  b };
    { a -  b };
    { a *  b };
    { a /  b };
    { a %  b };
    { ~a     };
    { a &  b };
    { a |  b };
    { a ^  b };
    { a << b };
    { a >> b };
};

template <typename T>
concept Logical = requires(T a, T b) {
    { !a     };
    { a && b };
    { a || b };
};

template <typename T>
concept Comparison = requires(T a, T b) {
    { a ==  b };
    { a !=  b };
    { a <   b };
    { a >   b };
    { a <=  b };
    { a >=  b };
    { a <=> b };
};

template <typename... Ts>
constexpr auto assignment = (Assignment<Ts> && ...);

template <typename... Ts>
constexpr auto increment_decrement = (IncrementDecrement<Ts> && ...);

template <typename... Ts>
constexpr auto arithmetic = (Arithmetic<Ts> && ...);

template <typename... Ts>
constexpr auto logical = (Logical<Ts> && ...);

template <typename... Ts>
constexpr auto comparison = (Comparison<Ts> && ...);

template <template <typename> typename Pred, typename... Ts>
constexpr auto all_of = std::conjunction_v<Pred<Ts>...>;

// Check basic operations
static_assert(assignment<u8, u16, u32, u64, u128, usize>);
static_assert(assignment<i8, i16, i32, i64, i128, isize>);
static_assert(!assignment<f32, f64>);

static_assert(increment_decrement<u8, u16, u32, u64, u128, usize>);
static_assert(increment_decrement<i8, i16, i32, i64, i128, isize>);
static_assert(increment_decrement<f32, f64>);

static_assert(arithmetic<u8, u16, u32, u64, u128, usize>);
static_assert(arithmetic<i8, i16, i32, i64, i128, isize>);
static_assert(!arithmetic<f32, f64>);

static_assert(logical<u8, u16, u32, u64, u128, usize>);
static_assert(logical<i8, i16, i32, i64, i128, isize>);
static_assert(logical<f32, f64>);

static_assert(comparison<u8, u16, u32, u64, u128, usize>);
static_assert(comparison<i8, i16, i32, i64, i128, isize>);
static_assert(comparison<f32, f64>);

// Check size
static_assert(sizeof(u8) == 1);
static_assert(sizeof(u16) == 2);
static_assert(sizeof(u32) == 4);
static_assert(sizeof(u64) == 8);
static_assert(sizeof(u128) == 16);

static_assert(sizeof(i8) == 1);
static_assert(sizeof(i16) == 2);
static_assert(sizeof(i32) == 4);
static_assert(sizeof(i64) == 8);
static_assert(sizeof(i128) == 16);

static_assert(sizeof(usize) <= sizeof(isize));

static_assert(sizeof(f32) == 4);
static_assert(sizeof(f64) == 8);

// Check properties of 128-bit integer types
static_assert(all_of<std::is_trivially_copyable, u128, i128>);
static_assert(all_of<std::is_standard_layout, u128, i128>);
static_assert(all_of<std::has_unique_object_representations, u128, i128>);

template <typename T>
std::string GetTypeName()
{
#ifdef _MSC_VER
    return typeid(T).name();
#else
    auto* name = abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, nullptr);
    std::string ret { name };
    std::free(name);

    return ret;
#endif
}

i32 main()
{
    std::cout << "u8    : " << GetTypeName<u8>() << '\n'
              << "u16   : " << GetTypeName<u16>() << '\n'
              << "u32   : " << GetTypeName<u32>() << '\n'
              << "u64   : " << GetTypeName<u64>() << '\n'
#ifndef __APPLE__
              << "u128  : " << GetTypeName<u128>() << '\n'
#endif
              << "usize : " << GetTypeName<usize>() << '\n'
              << '\n'
              << "i8    : " << GetTypeName<i8>() << '\n'
              << "i16   : " << GetTypeName<i16>() << '\n'
              << "i32   : " << GetTypeName<i32>() << '\n'
              << "i64   : " << GetTypeName<i64>() << '\n'
#ifndef __APPLE__
              << "i128  : " << GetTypeName<i128>() << '\n'
#endif
              << "isize : " << GetTypeName<isize>() << '\n'
              << '\n'
              << "f32   : " << GetTypeName<f32>() << '\n'
              << "f64   : " << GetTypeName<f64>() << '\n';

    return 0;
}
