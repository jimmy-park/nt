#ifndef NUMBER_HPP_
#define NUMBER_HPP_

#include <cstddef>
#include <cstdint>

#include <type_traits>

#ifdef _MSC_VER
#include <__msvc_int128.hpp>
using u128 = std::_Unsigned128;
using i128 = std::_Signed128;
#else
using u128 = __uint128_t;
using i128 = __int128_t;
#endif

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using usize = std::size_t;

using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;
using isize = std::common_type_t<std::ptrdiff_t, std::make_signed_t<usize>>;

using f32 = float;
using f64 = double;

#endif // NUMBER_HPP_
