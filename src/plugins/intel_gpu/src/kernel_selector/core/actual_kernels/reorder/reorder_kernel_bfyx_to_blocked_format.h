﻿// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "reorder_kernel_base.h"

namespace kernel_selector {
class ReorderKernel_bfyx_to_blocked_format : public ReorderKernelBase {
public:
    ReorderKernel_bfyx_to_blocked_format() : ReorderKernelBase("reorder_data_bfyx_to_blocked_format") {}

    bool Validate(const Params& p, const optional_params& o) const override;
    KernelsData GetKernelsData(const Params& params, const optional_params& options) const override;
    KernelsPriority GetKernelsPriority(const Params& params, const optional_params& options) const override;
    ParamsKey GetSupportedKey() const override;
protected:
    JitConstants GetJitConstants(const reorder_params& params) const override;
    CommonDispatchData SetDefault(const reorder_params& params) const override;
};
}  // namespace kernel_selector
