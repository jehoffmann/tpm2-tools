//**********************************************************************;
// Copyright (c) 2017, Intel Corporation
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// 3. Neither the name of Intel Corporation nor the names of its contributors
// may be used to endorse or promote products derived from this software without
// specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//**********************************************************************;
#ifndef LIB_TPM2_NV_UTIL_H_
#define LIB_TPM2_NV_UTIL_H_

#include <sapi/tpm20.h>

#include "tpm2_util.h"

/**
 * Reads the public portion of a Non-Volatile (nv) index.
 * @param sapi_context
 *  The system API context.
 * @param nv_index
 *  The index to read.
 * @param nv_public
 *  The public data structure to store the results in.
 * @return
 *  The error code from the TPM. TPM_RC_SUCCESS on success.
 */
static inline TPM_RC tpm2_util_nv_read_public(TSS2_SYS_CONTEXT *sapi_context,
        TPMI_RH_NV_INDEX nv_index, TPM2B_NV_PUBLIC *nv_public) {

    TPM2B_NAME nv_name = TPM2B_TYPE_INIT(TPM2B_NAME, name);

    return Tss2_Sys_NV_ReadPublic(sapi_context, nv_index, NULL, nv_public,
            &nv_name, NULL);
}

#endif /* LIB_TPM2_NV_UTIL_H_ */
