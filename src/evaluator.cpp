#include "cecxx/benchmark/evaluator.hpp"

namespace cecxx::benchmark {

evaluator::evaluator(const cec_edition_t edition, const int dimension, const std::filesystem::path& storage)
    : dim_{dimension}, ctx_{edition, storage, dim_}, edition_{edition} {}

}  // namespace cecxx
