// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#ifndef REGISTER_FACTORY
#error "REGISTER_FACTORY is not defined"
#endif

// ------------------------------ Supported v0 ops ------------------------------ //
REGISTER_FACTORY(v0, Abs);
REGISTER_FACTORY(v0, Acos);
REGISTER_FACTORY(v0, Asin);
REGISTER_FACTORY(v0, Atan);
REGISTER_FACTORY(v0, Ceiling);
REGISTER_FACTORY(v0, Clamp);
REGISTER_FACTORY(v0, Concat);
REGISTER_FACTORY(v0, Constant);
REGISTER_FACTORY(v0, Convert);
REGISTER_FACTORY(v0, Cos);
REGISTER_FACTORY(v0, Cosh);
REGISTER_FACTORY(v0, CumSum);
REGISTER_FACTORY(v0, CTCGreedyDecoder);
REGISTER_FACTORY(v0, DepthToSpace);
REGISTER_FACTORY(v0, DetectionOutput);
REGISTER_FACTORY(v0, Elu);
REGISTER_FACTORY(v0, Erf);
REGISTER_FACTORY(v0, Exp);
REGISTER_FACTORY(v0, FakeQuantize);
REGISTER_FACTORY(v0, Floor);
REGISTER_FACTORY(v0, Gelu);
REGISTER_FACTORY(v0, GRN);
REGISTER_FACTORY(v0, HardSigmoid);
// REGISTER_FACTORY(v0, Interpolate); Supported via v0 -> v4 conversion
REGISTER_FACTORY(v0, Log);
REGISTER_FACTORY(v0, LRN);
REGISTER_FACTORY(v0, MatMul);
REGISTER_FACTORY(v0, MVN);
REGISTER_FACTORY(v0, Negative);
REGISTER_FACTORY(v0, NormalizeL2);
REGISTER_FACTORY(v0, Parameter);
REGISTER_FACTORY(v0, PRelu);
REGISTER_FACTORY(v0, PriorBox);
REGISTER_FACTORY(v0, PriorBoxClustered);
REGISTER_FACTORY(v0, Proposal);
REGISTER_FACTORY(v0, PSROIPooling);
REGISTER_FACTORY(v0, Relu);
REGISTER_FACTORY(v0, Result);
REGISTER_FACTORY(v0, RegionYolo);
REGISTER_FACTORY(v0, ReorgYolo);
REGISTER_FACTORY(v0, ReverseSequence);
REGISTER_FACTORY(v0, ROIPooling);
REGISTER_FACTORY(v0, Sigmoid);
REGISTER_FACTORY(v0, Sqrt);
REGISTER_FACTORY(v0, Selu);
REGISTER_FACTORY(v0, Sin);
REGISTER_FACTORY(v0, Sinh);
REGISTER_FACTORY(v0, Sign);
REGISTER_FACTORY(v0, SquaredDifference);
REGISTER_FACTORY(v0, SpaceToDepth);
REGISTER_FACTORY(v0, Squeeze);
REGISTER_FACTORY(v0, ShuffleChannels);
REGISTER_FACTORY(v0, Tan);
REGISTER_FACTORY(v0, Tanh);
REGISTER_FACTORY(v0, TensorIterator);
REGISTER_FACTORY(v0, Tile);
REGISTER_FACTORY(v0, Unsqueeze);

// ----------------------------- Unsupported v0 ops ----------------------------- //
// Deprecated ops
// REGISTER_FACTORY(v0, Add);
// REGISTER_FACTORY(v0, Divide);
// REGISTER_FACTORY(v0, Greater);
// REGISTER_FACTORY(v0, GreaterEq);
// REGISTER_FACTORY(v0, Less);
// REGISTER_FACTORY(v0, LessEq);
// REGISTER_FACTORY(v0, LSTMSequence);
// REGISTER_FACTORY(v0, LSTMCell);
// REGISTER_FACTORY(v0, Maximum);
// REGISTER_FACTORY(v0, Minimum);
// REGISTER_FACTORY(v0, Multiply);
// REGISTER_FACTORY(v0, NotEqual);
// REGISTER_FACTORY(v0, Power);
// REGISTER_FACTORY(v0, Quantize);
// REGISTER_FACTORY(v0, Select);
// REGISTER_FACTORY(v0, Subtract);
// REGISTER_FACTORY(v0, Xor); // Not marked as deprecated yet, but removed from new opsets

// REGISTER_FACTORY(v0, BatchNormInference);
// REGISTER_FACTORY(v0, Range);
// REGISTER_FACTORY(v0, RNNCell);
// REGISTER_FACTORY(v0, ShapeOf);

// ------------------------------ Supported v1 ops ------------------------------ //
REGISTER_FACTORY(v1, Add);
REGISTER_FACTORY(v1, AvgPool);
REGISTER_FACTORY(v1, BatchToSpace);
REGISTER_FACTORY(v1, BinaryConvolution);
REGISTER_FACTORY(v1, Broadcast);
REGISTER_FACTORY(v1, ConvertLike);
REGISTER_FACTORY(v1, Convolution);
REGISTER_FACTORY(v1, ConvolutionBackpropData);
REGISTER_FACTORY(v1, DeformableConvolution);
REGISTER_FACTORY(v1, DeformablePSROIPooling);
REGISTER_FACTORY(v1, Divide);
REGISTER_FACTORY(v1, Equal);
REGISTER_FACTORY(v1, FloorMod);
REGISTER_FACTORY(v1, Gather);
REGISTER_FACTORY(v1, GatherTree);
REGISTER_FACTORY(v1, Greater);
REGISTER_FACTORY(v1, GreaterEqual);
REGISTER_FACTORY(v1, GroupConvolution);
REGISTER_FACTORY(v1, GroupConvolutionBackpropData);
REGISTER_FACTORY(v1, Less);
REGISTER_FACTORY(v1, LessEqual);
REGISTER_FACTORY(v1, LogicalAnd);
REGISTER_FACTORY(v1, LogicalNot);
REGISTER_FACTORY(v1, LogicalOr);
REGISTER_FACTORY(v1, LogicalXor);
REGISTER_FACTORY(v1, MaxPool);
REGISTER_FACTORY(v1, Maximum);
REGISTER_FACTORY(v1, Minimum);
REGISTER_FACTORY(v1, Multiply);
REGISTER_FACTORY(v1, NotEqual);
// REGISTER_FACTORY(v1, NonMaxSuppression); Supported via v1 -> v5 internal conversion
REGISTER_FACTORY(v1, OneHot);
REGISTER_FACTORY(v1, Pad);
REGISTER_FACTORY(v1, Power);
REGISTER_FACTORY(v1, ReduceMax);
REGISTER_FACTORY(v1, ReduceLogicalAnd);
REGISTER_FACTORY(v1, ReduceLogicalOr);
REGISTER_FACTORY(v1, ReduceMean);
REGISTER_FACTORY(v1, ReduceMin);
REGISTER_FACTORY(v1, ReduceProd);
REGISTER_FACTORY(v1, ReduceSum);
REGISTER_FACTORY(v1, Reshape);
REGISTER_FACTORY(v1, Subtract);
REGISTER_FACTORY(v1, SpaceToBatch);
REGISTER_FACTORY(v1, Softmax);
REGISTER_FACTORY(v1, StridedSlice);
REGISTER_FACTORY(v1, Select);
REGISTER_FACTORY(v1, Split);
REGISTER_FACTORY(v1, Transpose);
REGISTER_FACTORY(v1, TopK);
REGISTER_FACTORY(v1, VariadicSplit);
REGISTER_FACTORY(v1, Mod);

// ----------------------------- Unsupported v1 ops ----------------------------- //
// REGISTER_FACTORY(v1, Reverse);

// ------------------------------ Supported v3 ops ------------------------------ //
REGISTER_FACTORY(v3, Asinh);
REGISTER_FACTORY(v3, Acosh);
REGISTER_FACTORY(v3, Atanh);
REGISTER_FACTORY(v3, Broadcast);
REGISTER_FACTORY(v3, EmbeddingBagOffsetsSum);
REGISTER_FACTORY(v3, EmbeddingBagPackedSum);
REGISTER_FACTORY(v3, EmbeddingSegmentsSum);
REGISTER_FACTORY(v3, ExtractImagePatches);
REGISTER_FACTORY(v3, ROIAlign);
REGISTER_FACTORY(v3, ScatterUpdate);
REGISTER_FACTORY(v3, ScatterElementsUpdate);
REGISTER_FACTORY(v3, ScatterNDUpdate);
// REGISTER_FACTORY(v3, NonMaxSuppression); Supported via v3 -> v5 internal conversion

// ----------------------------- Unsupported v3 ops ----------------------------- //
// REGISTER_FACTORY(v3, Assign);
// REGISTER_FACTORY(v3, Bucketize);
// REGISTER_FACTORY(v3, GRUCell);
// REGISTER_FACTORY(v3, NonZero);
// REGISTER_FACTORY(v3, ReadValue);
// REGISTER_FACTORY(v3, ShapeOf);
// REGISTER_FACTORY(v3, TopK);

// ------------------------------ Supported v4 ops ------------------------------ //
REGISTER_FACTORY(v4, HSwish);
REGISTER_FACTORY(v4, Interpolate);
REGISTER_FACTORY(v4, LSTMCell);
REGISTER_FACTORY(v4, Mish);
// REGISTER_FACTORY(v4, NonMaxSuppression); Supported via v4 -> v5 internal conversion
REGISTER_FACTORY(v4, Proposal);
REGISTER_FACTORY(v4, ReduceL1);
REGISTER_FACTORY(v4, ReduceL2);
REGISTER_FACTORY(v4, SoftPlus);
REGISTER_FACTORY(v4, Swish);

// ----------------------------- Unsupported v4 ops ----------------------------- //
// REGISTER_FACTORY(v4, CTCLoss);
// REGISTER_FACTORY(v4, Range);

// ------------------------------ Supported v5 ops ------------------------------ //
REGISTER_FACTORY(v5, HSigmoid);
REGISTER_FACTORY(v5, LogSoftmax);
REGISTER_FACTORY(v5, LSTMSequence);
//REGISTER_FACTORY(v5, NonMaxSuppression); Supported via v5 -> v5 internal conversion
REGISTER_FACTORY(v5, Round);
REGISTER_FACTORY(v5, GatherND);
REGISTER_FACTORY(v5, Loop);

// ----------------------------- Unsupported v5 ops ----------------------------- //
// REGISTER_FACTORY(v5, BatchNormInference);
// REGISTER_FACTORY(v5, GRUSequence);
// REGISTER_FACTORY(v5, RNNSequence);

// ------------------------------ Supported v6 ops ------------------------------ //
REGISTER_FACTORY(v6, CTCGreedyDecoderSeqLen);
REGISTER_FACTORY(v6, MVN);
REGISTER_FACTORY(v6, GatherElements);
REGISTER_FACTORY(v6, ExperimentalDetectronROIFeatureExtractor);

// ------------------------------ Supported v7 ops ------------------------------ //
REGISTER_FACTORY(v7, Gather);

// ------------------------------ Supported v8 ops ------------------------------ //
REGISTER_FACTORY(v8, Gather);
REGISTER_FACTORY(v8, GatherND);
REGISTER_FACTORY(v8, DeformableConvolution);
REGISTER_FACTORY(v8, NV12toRGB);
REGISTER_FACTORY(v8, NV12toBGR);

// --------------------------- Supported internal ops --------------------------- //
REGISTER_FACTORY(internal, NonMaxSuppressionIEInternal);