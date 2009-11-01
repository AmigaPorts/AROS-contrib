/**************************************************************************
 *
 * Copyright 2009 VMware, Inc.
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL VMWARE AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 **************************************************************************/


/**
 * Depth/stencil testing to LLVM IR translation.
 *
 * @author Jose Fonseca <jfonseca@vmware.com>
 */

#ifndef LP_BLD_DEPTH_H
#define LP_BLD_DEPTH_H


#include <llvm-c/Core.h>  

 
struct pipe_depth_state;
struct util_format_description;
union lp_type;
struct lp_build_mask_context;


union lp_type
lp_depth_type(const struct util_format_description *format_desc,
              unsigned length);


void
lp_build_depth_test(LLVMBuilderRef builder,
                    const struct pipe_depth_state *state,
                    union lp_type type,
                    const struct util_format_description *format_desc,
                    struct lp_build_mask_context *mask,
                    LLVMValueRef src,
                    LLVMValueRef dst_ptr);


#endif /* !LP_BLD_DEPTH_H */
