// MPark.Patterns
//
// Copyright EXP 2023
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at
// http://boost.org/LICENSE_1_0.txt)

#ifndef MPARK_PATTERNS_EXPECTED_HPP
#define MPARK_PATTERNS_EXPECTED_HPP

#include <utility>

namespace mpark::patterns {

// inline constexpr struct Err {} none{};

template <typename Pattern>
struct Err {
  const Pattern &pattern;
};

// template <typename Value, typename F>
// auto try_match(Err, Value &&value, F &&f) {
//   return value ? no_match : match_invoke(std::forward<F>(f));
// }

template <typename Pattern>
struct Ok {
  const Pattern &pattern;
};

template <typename Pattern>
auto ok(const Pattern &pattern) {
  return Ok<Pattern>{pattern};
}

template <typename Pattern>
auto err(const Pattern &pattern) {
  return Err<Pattern>{pattern};
}
template <typename Pattern, typename Value, typename F>
auto try_match(const Ok<Pattern> &some, Value &&value, F &&f) {
  return value.has_value() ? try_match(some.pattern, *std::forward<Value>(value),
                           std::forward<F>(f))
               : no_match;
}

template <typename Pattern, typename Value, typename F>
auto try_match(const Err<Pattern> &err, Value &&value, F &&f) {
  return (value.has_value()) ? no_match:try_match(err.pattern, *std::forward<Value>(value),
                             std::forward<F>(f));
}
}  // namespace mpark::patterns

#endif  // MPARK_PATTERNS_OPTIONAL_HPP
