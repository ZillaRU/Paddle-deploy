/* Copyright (c) 2021 PaddlePaddle Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#include <memory>

#include "paddle/fluid/operators/collective/c_allgather_op.h"

namespace paddle {
namespace operators {

template <typename T>
class CAllGatherOpASCENDKernel : public framework::OpKernel<T> {
 public:
  void Compute(const framework::ExecutionContext &ctx) const override {
    PADDLE_THROW(platform::errors::PreconditionNotMet(
        "PaddlePaddle should compile with NPU."));
  }
};

}  // namespace operators
}  // namespace paddle

namespace ops = paddle::operators;
namespace plat = paddle::platform;

REGISTER_OP_NPU_KERNEL(c_allgather,
                       ops::CAllGatherOpASCENDKernel<int8_t>,
                       ops::CAllGatherOpASCENDKernel<int>,
                       ops::CAllGatherOpASCENDKernel<int64_t>,
                       ops::CAllGatherOpASCENDKernel<float>,
                       ops::CAllGatherOpASCENDKernel<plat::float16>);
