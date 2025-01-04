#include "cecxx/functions/unimodal/ellips.hpp"

#include <cmath>
#include <span>

namespace cecxx::functions::unimodal {

auto ellips(std::span<const double> input) -> double {
    auto output{0.0};
    for (auto i = 0u; i < input.size(); ++i) {
        output += std::pow(10.0, 6.0 * i / (static_cast<double>(input.size()) - 1)) * input[i] * input[i];
    }

    return output;
}
} // namespace cecxx::functions::unimodal
