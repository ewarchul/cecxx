#include "cecxx/functions/unimodal/sphere.hpp"

#include <span>

namespace cecxx::functions::unimodal {

auto sphere(std::span<const double> input) -> double {
    auto output{0.0};
    for (const auto &x : input) {
        output += x * x;
    }

    return output;
}
} // namespace cecxx::functions::unimodal
