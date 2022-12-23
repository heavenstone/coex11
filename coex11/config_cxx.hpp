
/// \file config_cxx.hpp
/// \brief

#ifndef COEX11_CONFIG_CXX_HPP
#define COEX11_CONFIG_CXX_HPP (1)

#include <cstdlib>

#ifndef COEX11_CXX11
#  if __cplusplus >= 201103L || _MSC_VER >= 1600
#    define COEX11_CXX11 (1)
#  endif
#endif

#ifndef COEX11_CXX17
#  if __cplusplus >= 201703L || _MSC_VER >= 1900
#    define CRYPTOPP_CXX17 (1)
#  endif
#endif

#ifndef COEX11_CONSTEXPR
#  if COEX11_CXX11
#    define COEX11_CONSTEXPR constexpr
#  else
#    define COEX11_CONSTEXPR
#  endif
#endif

#ifndef COEX11_NULLPTR
#  if COEX11_CXX11
#    define COEX11_NULLPTR nullptr
#  else
#    define COEX11_NULLPTR NULL
#  endif
#endif

#ifndef COEX11_NOEXCEPT
#  if COEX11_CXX11
#    define COEX11_NOEXCEPT noexcept
#  else
#    define COEX11_NOEXCEPT throw()
#  endif
#endif

#ifndef COEX11_STATIC_ASSERT
#  if COEX11_CXX17
#    define COEX11_STATIC_ASSERT(...) static_assert(__VA_ARGS__)
#  elif COEX11_CXX11
#    define COEX11_DETAIL_STATIC_ASSERT_1(exp) static_assert(exp, "")
#    define COEX11_DETAIL_STATIC_ASSERT_2(exp, msg) static_assert(exp, msg)
#    define COEX11_DETAIL_STATIC_ASSERT_EXPAND(x) x
#    define COEX11_DETAIL_STATIC_ASSERT_(_1, _2, _N) _N
#    define COEX11_STATIC_ASSERT(...)                                  \
      COEX11_DETAIL_STATIC_ASSERT_EXPAND(COEX11_DETAIL_STATIC_ASSERT_( \
          __VA_ARGS__, COEX11_DETAIL_STATIC_ASSERT_2,                  \
          COEX11_DETAIL_STATIC_ASSERT_1)(__VA_ARGS__))
#  else
#    define COEX11_STATIC_ASSERT(...)
#  endif
#endif

#endif  // COEX11_CONFIG_CXX_HPP
