#pragma once

namespace cecxx::benchmark {

enum class budget_sample_policy {
    pre_cec_2022,
    post_cec_2022,
};

enum class cec_edition_t { cec2017 };

using dimension_t = unsigned int;
using problem_number_t = unsigned int;

} // namespace cecxx::benchmark
