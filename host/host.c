#include <stdio.h>
#include <stdlib.h>
#include <openenclave/host.h>
#include "helloworld_u.h"

// OCall 实现
void ocall_print(const char* str) {
    printf("%s\n", str);
}

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s enclave_image_path\n", argv[0]);
        return 1;
    }

    oe_enclave_t* enclave = NULL;
    const uint32_t flags = OE_ENCLAVE_FLAG_DEBUG;

    // 创建 Enclave
    oe_result_t result = oe_create_helloworld_enclave(argv[1], flags, NULL, 0, &enclave);
    if (result != OE_OK) {
        fprintf(stderr, "Failed to create enclave: %s\n", oe_result_str(result));
        return 1;
    }

    // 调用 ECall 函数，打印消息
    result = ecall_print_message(enclave);
    if (result != OE_OK) {
        fprintf(stderr, "ECall failed: %s\n", oe_result_str(result));
    }

    // 准备并调用 ECall 函数，打印数组
    int arr[] = {1, 2, 3, 4, 5};
    result = ecall_print_array(enclave, arr, sizeof(arr) / sizeof(arr[0]));
    if (result != OE_OK) {
        fprintf(stderr, "ECall to print array failed: %s\n", oe_result_str(result));
    }

    // 销毁 Enclave
    oe_terminate_enclave(enclave);
    return 0;
}