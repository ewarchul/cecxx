#include <cecxx/functions/multimodal/levy.hpp>

#include <cmath>
#include <span>
#include <vector>

namespace cecxx::functions::multimodal {
auto levy(std::span<const double> input) -> double {
    const auto nrow = input.size();
    auto w = std::vector<double>(nrow);
    for (auto i = 0u; i < nrow; i++) {
        w[i] = 1.0 + (input[i] - 1.0) / 4.0;
    }
    double term1 = std::pow((std::sin(M_PI * w[0])), 2);
    double term2 = std::pow((w[nrow - 1] - 1), 2) * (1 + std::pow((std::sin(2 * M_PI * w[nrow - 1])), 2));
    double sum = 0.0;
    for (auto i = 0u; i < nrow - 1; i++) {
        sum += std::pow((w[i] - 1), 2) * (1 + 10 * std::pow((std::sin(M_PI * w[i] + 1)), 2));
    }
    return term1 + sum + term2;
}
} // namespace cecxx::functions::multimodal
