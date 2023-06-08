# number

[![CI](https://github.com/jimmy-park/number/actions/workflows/ci.yaml/badge.svg)](https://github.com/jimmy-park/number/actions/workflows/ci.yaml)

Abbreviated form of fixed-width numeric types in C++ (inspired by Rust)

~~I'm sick of writing things like `std::uint32_t` even in hobby projects~~

- Integer types
  - Unsigned : `u8`, `u16`, `u32`, `u64`, `u128`, `usize`
  - Signed : `i8`, `i16`, `i32`, `i64`, `i128`, `isize`
- Floating-point types (IEEE 754)
  - `f32`, `f64`

## Usage

```cpp
#include <number.hpp>

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
    number
    URL https://github.com/jimmy-park/number/archive/main.tar.gz
)
FetchContent_MakeAvailable(number)

# If you're using CPM.cmake
# CPMAddPackage(
#     NAME number
#     URL https://github.com/jimmy-park/number/archive/main.tar.gz
# )

add_executable(main main.cpp)
target_link_libraries(main PRIVATE number::number)
```

## Reference

- [Data Types - The Rust Programming Language](https://doc.rust-lang.org/book/ch03-02-data-types.html)
- [P0330: Literal Suffix for (signed) size_t](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/p0330r8.html)
- [P1227: Signed ssize() functions, unsigned size() functions](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p1227r2.html)
