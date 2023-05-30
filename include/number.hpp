#ifndef NUMBER_HPP_
#define NUMBER_HPP_

#include <cstddef>
#include <cstdint>

#include <type_traits>

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
