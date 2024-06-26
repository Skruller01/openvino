// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "base_reference_test.hpp"
#include "inference_engine.hpp"

namespace reference_tests {

class ReferenceCNNTest {
public:
    ReferenceCNNTest();

    void Exec();

    void LoadNetwork();
    void FillInputs();  // Both for legacy and for OV2.0 API
    void Infer();

    void LoadNetworkLegacy();
    void InferLegacy();

    virtual void Validate();

protected:
    const std::string targetDevice;
    std::shared_ptr<ov::Model> function;
    InferenceEngine::CNNNetwork legacy_network;

    float threshold = 1e-5f;     // Relative diff
    float abs_threshold = -1.f;  // Absolute diff (not used when negative)

    std::vector<ov::Tensor> outputs_ov20;
    std::vector<ov::Tensor> outputs_legacy;

protected:
    // These will be generated by default, if user has not specified inputs manually
    std::vector<ov::Tensor> inputData;
    InferenceEngine::BlobMap legacy_input_blobs;

private:
    std::shared_ptr<ov::Core> core;
    ov::CompiledModel executableNetwork;
    ov::InferRequest inferRequest;

    std::shared_ptr<InferenceEngine::Core> legacy_core;
    InferenceEngine::ExecutableNetwork legacy_exec_network;
    InferenceEngine::InferRequest legacy_infer_request;
};

}  // namespace reference_tests
