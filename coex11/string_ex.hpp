
/// \file string_ex.hpp
/// \brief
/// \since coex11 1.0

#ifndef COEX11_STRING_EX_HPP
#define COEX11_STRING_EX_HPP (1)

#include <limits>

#include "config.hpp"

COEX11_NAMESPACE_BEGIN

namespace detail {

inline COEX11_CONSTEXPR size_t strnlen_ex_(char const* s, size_t n,
                                           size_t cnt) COEX11_NOEXCEPT {
  return (!n || !*s) ? cnt : strnlen_ex_(++s, --n, ++cnt);
}

inline COEX11_CONSTEXPR char* strchr_ex_(const char* s, int c) COEX11_NOEXCEPT {
}

}  // namespace detail

/// \brief
/// \since coex11 1.0
inline COEX11_CONSTEXPR size_t strnlen_ex(char const* s,
                                          size_t n) COEX11_NOEXCEPT {
  return detail::strnlen_ex_(s, n, 0U);
}

/// \brief
/// \since coex11 1.0
inline COEX11_CONSTEXPR size_t strlen_ex(char const* s) COEX11_NOEXCEPT {
  return strnlen_ex(s, std::numeric_limits<size_t>::max());
}
COEX11_STATIC_ASSERT(strlen_ex("") == 0U);
COEX11_STATIC_ASSERT(strlen_ex("geeks") == 5U);

/// \brief
/// \since coex11 1.0
inline COEX11_CONSTEXPR int strncmp_ex(char const* s1, char const* s2,
                                       size_t n) COEX11_NOEXCEPT {
  return (!n || !*s1 || !*s2 || (*s1 != *s2)) ? *s1 - *s2
                                              : strncmp_ex(++s1, ++s2, --n);
}

/// \brief
/// \since coex11 1.0
inline COEX11_CONSTEXPR int strcmp_ex(char const* s1,
                                      char const* s2) COEX11_NOEXCEPT {
  return strncmp_ex(s1, s2, std::numeric_limits<size_t>::max());
}
COEX11_STATIC_ASSERT(strcmp_ex("abcd", "abcd") == 0);
COEX11_STATIC_ASSERT(strcmp_ex("abcd", "abCd") > 0);
COEX11_STATIC_ASSERT(strcmp_ex("abCd", "abcd") < 0);
COEX11_STATIC_ASSERT(strcmp_ex("a\0a", "a\0A") == 0);

/// \brief
/// \since coex11 1.0
inline COEX11_CONSTEXPR int memcmp_ex(char const* s1, char const* s2,
                                      size_t n) COEX11_NOEXCEPT {
  return (!n || (*s1 != *s2)) ? *s1 - *s2 : memcmp_ex(++s1, ++s2, --n);
}
COEX11_STATIC_ASSERT(memcmp_ex("abcd", "abcd", 4U) == 0);
COEX11_STATIC_ASSERT(memcmp_ex("abcd", "abCd", 4U) > 0);
COEX11_STATIC_ASSERT(memcmp_ex("abCd", "abcd", 4U) < 0);
COEX11_STATIC_ASSERT(memcmp_ex("a\0a", "a\0A", 3U) > 0);

/// \brief
/// \since coex11 1.0
inline COEX11_CONSTEXPR char* memchr_ex(char const* s, int c,
                                        size_t n) COEX11_NOEXCEPT {
  return (!s || !n)                     ? COEX11_NULLPTR
         : (*s == static_cast<char>(c)) ? const_cast<char*>(s)
         : (n <= 1U)                    ? COEX11_NULLPTR
                                        : memchr_ex(++s, c, --n);
}
COEX11_STATIC_ASSERT(memchr_ex("a\0A", 'A', 3U) != COEX11_NULLPTR);

/// \brief
/// \since coex11 1.0
inline COEX11_CONSTEXPR char* strchr_ex(char const* s, int c) COEX11_NOEXCEPT {
  return static_cast<char*>(memchr_ex(s, c, strlen_ex(s) + 1U));
}
COEX11_STATIC_ASSERT(strchr_ex("abcd", 'c') != COEX11_NULLPTR);
COEX11_STATIC_ASSERT(strchr_ex("abcd", 'e') == COEX11_NULLPTR);
COEX11_STATIC_ASSERT(strchr_ex("abcd", '\0') != COEX11_NULLPTR);

COEX11_NAMESPACE_END

#endif  // COEX11_STRING_EX_HPP
