# nt

[![CI](https://github.com/jimmy-park/nt/actions/workflows/ci.yaml/badge.svg)](https://github.com/jimmy-park/nt/actions/workflows/ci.yaml)

Abbreviated form of fixed width numeric types in C++ (inspired by Rust)

~~I'm sick of writing things like `std::uint32_t` even in hobby projects~~

## Supported Types

| Bits | Signed | Unsigned | Floating-point |
| --- | --- | --- | --- |
| `8` | `i8` | `u8` | |
| `16` | `i16` | `u16` | |
| `32` | `i32` | `u32` | `f32` |
| `64` | `i64` | `u64` | `f64` |
| `128` | `i128` | `u128` | |
| `arch` | `isize` | `usize` | |

### Notes

- Floating-point types
  - They are actually `float` and `double` (IEEE 754)
  - Since C++23, we can use extended types defined in `<stdfloat>`
- 128-bit integer types
  - Use a compiler extension `__int128` on GCC/Clang
  - Use an experimental `<__msvc_int128.hpp>` on MSVC
- `isize`
  - May be wider than `usize` on some platforms

## Usage

```cpp
#include <nt.hpp>

u32 add(u32 a, u32 b)
{
    return a + b;
}
```

### CMake Integration

Require CMake 3.23+ due to `target_sources(FILE_SET)`

```CMake
include(FetchContent)

FetchContent_Declare(
    nt
    URL https://github.com/jimmy-park/nt/archive/main.tar.gz
)
FetchContent_MakeAvailable(nt)

# If you're using CPM.cmake
# CPMAddPackage(
#     NAME nt
#     URL https://github.com/jimmy-park/nt/archive/main.tar.gz
# )

add_executable(main main.cpp)
target_link_libraries(main PRIVATE nt::nt)
```

## Reference

- [Data Types - The Rust Programming Language](https://doc.rust-lang.org/book/ch03-02-data-types.html)
- [Fixed width integer types (since C++11)](https://en.cppreference.com/w/cpp/types/integer)
- [Fixed width floating-point types (since C++23)](https://en.cppreference.com/w/cpp/types/floating-point)
- [P0330: Literal Suffix for (signed) size_t](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/p0330r8.html)
- [P1227: Signed ssize() functions, unsigned size() functions](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p1227r2.html)
