# Copyright (C) 2018-2022 Intel Corporation
# SPDX-License-Identifier: Apache-2.0

from openvino.tools.mo.ops.activation_ops import SoftPlus
from openvino.tools.mo.front.extractor import FrontExtractorOp


class SoftPlusExtractor(FrontExtractorOp):
    op = 'Softplus'
    enabled = True

    @classmethod
    def extract(cls, node):
        SoftPlus.update_node_stat(node, {})
        return cls.enabled
