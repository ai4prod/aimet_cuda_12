//==============================================================================
//
//  @@-COPYRIGHT-START-@@
//
//  Copyright (c) 2019, Qualcomm Innovation Center, Inc. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//
//  1. Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//  2. Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//  3. Neither the name of the copyright holder nor the names of its contributors
//     may be used to endorse or promote products derived from this software
//     without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
//  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//
//  SPDX-License-Identifier: BSD-3-Clause
//
//  @@-COPYRIGHT-END-@@
//
//==============================================================================

#ifndef MLTRAININGTOOLS_HIGHBIASFOLD_H
#define MLTRAININGTOOLS_HIGHBIASFOLD_H

#include <cmath>
#include <vector>


namespace AimetEqualization
{
/**
 * @brief Layer parameters
 */

typedef struct LayerParams
{
    // The shape of weight tensor
    std::vector<int> weightShape;

    // Layer's weight tensor
    float* weight;

    // Layer's layer's bias
    float* bias;

    // Layer's activation function is relu or not
    bool activationIsRelu;

} LayerParams;

/**
 * @brief Batch norm layer parameters
 */

typedef struct
{
    // BN layer's bias
    float* beta;

    // BN layer's weight
    float* gamma;
} BNParamsHighBiasFold;


class HighBiasFold
{
public:
    /**
     * @brief Updates bias of prev and current layer
     * @param prevLayerParams Struct of type LayerParams
     * @param currLayerParams Struct of type LayerParams
     * @param prevLayerBNParams Struct of BN params of prev layer
     */
    static void updateBias(LayerParams& prevLayerParams, LayerParams& currLayerParams,
                           BNParamsHighBiasFold& prevLayerBNParams);
};

}   // namespace AimetEqualization
#endif   // MLTRAININGTOOLS_HIGHBIASFOLD_H