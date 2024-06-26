// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "include/batch_headers/data_types.cl"
#include "include/batch_headers/fetch_data.cl"

KERNEL(pooling_gpu)(const __global INPUT0_TYPE* input, __global OUTPUT_TYPE* output, const __global float* arg_max)
{
#if OUTPUT_LAYOUT_BFYX  || OUTPUT_LAYOUT_BYXF
    const uint x    = (uint)get_global_id(0);
    const uint y    = (uint)get_global_id(1);
    const uint bf   = (uint)get_global_id(2);
    const uint f    = bf % INPUT0_FEATURE_NUM;
    const uint b    = bf / INPUT0_FEATURE_NUM;

    if (x >= INPUT0_SIZE_X)
    {
        return;
    }
#elif OUTPUT_LAYOUT_YXFB
    const uint x    = (uint)get_global_id(1);
    const uint y    = (uint)get_global_id(2);
    const uint bf   = (uint)get_global_id(0);
    const uint f    = bf / INPUT0_BATCH_NUM;
    const uint b    = bf % INPUT0_BATCH_NUM;
#endif

    const uint input_id = GET_DATA_INDEX(INPUT0, b, f, y, x);
    const uint arg_max_id = GET_DATA_INDEX(INPUT1, b, f, y, x);
    const uint pool_idx = convert_uint(arg_max[arg_max_id]);

#if OUTPUT_PADDED
    const uint x_output = pool_idx % OUTPUT_SIZE_X;
    const uint y_output = (pool_idx / OUTPUT_SIZE_X) % OUTPUT_SIZE_Y;
    const uint f_output = (pool_idx / OUTPUT_SIZE_X / OUTPUT_SIZE_Y) % OUTPUT_FEATURE_NUM;
    const uint b_output = pool_idx / OUTPUT_SIZE_X / OUTPUT_SIZE_Y / OUTPUT_FEATURE_NUM;

    const uint output_pos = GET_DATA_INDEX(OUTPUT, b_output, f_output, y_output, x_output);
    output[output_pos] += ACTIVATION(input[input_id], ACTIVATION_PARAMS);
#else
    output[pool_idx] += ACTIVATION(input[input_id], ACTIVATION_PARAMS);
#endif
}
