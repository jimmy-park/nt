#include <iostream>
#include <string>
#include <typeinfo>

#ifndef _MSC_VER
#include <cstdlib>
#include <cxxabi.h>
#endif

#include <number.hpp>

static_assert(sizeof(u8) == 1);
static_assert(sizeof(u16) == 2);
static_assert(sizeof(u32) == 4);
static_assert(sizeof(u64) == 8);

static_assert(sizeof(i8) == 1);
static_assert(sizeof(i16) == 2);
static_assert(sizeof(i32) == 4);
static_assert(sizeof(i64) == 8);

static_assert(sizeof(f32) == 4);
static_assert(sizeof(f64) == 8);

template <template <typename> typename Pred, typename... Ts>
constexpr auto all_of = std::conjunction_v<Pred<Ts>...>;

static_assert(all_of<std::is_unsigned, u8, u16, u32, u64, usize>);
static_assert(all_of<std::is_signed, i8, i16, i32, i64, isize>);

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
              << "usize : " << GetTypeName<usize>() << '\n'
              << '\n'
              << "i8    : " << GetTypeName<i8>() << '\n'
              << "i16   : " << GetTypeName<i16>() << '\n'
              << "i32   : " << GetTypeName<i32>() << '\n'
              << "i64   : " << GetTypeName<i64>() << '\n'
              << "isize : " << GetTypeName<isize>() << '\n'
              << '\n'
              << "f32   : " << GetTypeName<f32>() << '\n'
              << "f64   : " << GetTypeName<f64>() << '\n';

    return 0;
}
