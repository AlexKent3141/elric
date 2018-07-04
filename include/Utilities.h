#ifndef __UTILITIES_H__
#define __UTILITIES_H__

// This method iterates over a tuple and applies "f" to each element.
template <typename T, T... S, typename F>
constexpr void ForEachInSequence(std::integer_sequence<T, S...>, F&& f)
{
    using unpack_t = int[];
    (void)unpack_t{(static_cast<void>(f(std::integral_constant<T, S>{})), 0)..., 0};
}

#endif // __UTILITIES_H__
