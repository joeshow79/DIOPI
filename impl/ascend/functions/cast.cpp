/**
 * @file
 * @author DeepLink
 * @copyright  (c) 2023, DeepLink.
 */

#include <diopi/functions.h>

#include "../common/acloprunner.hpp"

namespace impl {
namespace ascend {

extern "C" diopiError_t diopiCastDtype(diopiContextHandle_t ctx, diopiTensorHandle_t out, diopiConstTensorHandle_t input) {
    AclOpRunner<1, 1>("Cast").addInput(input).addOutput(out).setAttr<int32_t>("dst_type", getAclDataType(out)).run(ctx);
    return diopiSuccess;
}

}  // namespace ascend
}  // namespace impl
