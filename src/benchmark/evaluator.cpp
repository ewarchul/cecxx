#include "cecxx/benchmark/evaluator.hpp"

namespace cecxx::benchmark {

evaluator::evaluator(const cec_edition_t edition, std::span<const dimension_t> dimensions,
                     const std::filesystem::path storage)
    : ctx_{edition, storage, dimensions}, edition_{edition} {}

} // namespace cecxx::benchmark
