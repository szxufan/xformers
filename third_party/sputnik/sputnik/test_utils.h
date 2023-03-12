// Copyright 2020 The Sputnik Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef THIRD_PARTY_SPUTNIK_TEST_UTILS_H_
#define THIRD_PARTY_SPUTNIK_TEST_UTILS_H_

#include <hipblas.h>
#include <hipsparse.h>

#include "glog/logging.h"

namespace sputnik {

#define CUDA_CALL(code)                                     \
  do {                                                      \
    hipError_t status = code;                              \
    std::string err = hipGetErrorString(status);           \
    CHECK_EQ(status, hipSuccess) << "CUDA Error: " << err; \
  } while (0)

#define CUSPARSE_CALL(code)                                        \
  do {                                                             \
    hipsparseStatus_t status = code;                                \
    CHECK_EQ(status, HIPSPARSE_STATUS_SUCCESS) << "CuSparse Error"; \
  } while (0)

#define CUBLAS_CALL(code)                                      \
  do {                                                         \
    hipblasStatus_t status = code;                              \
    CHECK_EQ(status, HIPBLAS_STATUS_SUCCESS) << "CuBLAS Error"; \
  } while (0)

}  // namespace sputnik

#endif  // THIRD_PARTY_SPUTNIK_TEST_UTILS_H_
