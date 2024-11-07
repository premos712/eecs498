# 使用 edger8r 生成 Enclave 的 C 绑定文件 (helloworld_t.h 和 helloworld_t.c)
add_custom_command(
    OUTPUT helloworld_t.h helloworld_t.c helloworld_args.h
    DEPENDS ${CMAKE_SOURCE_DIR}/helloworld.edl
    COMMAND /opt/openenclave/bin/oeedger8r --trusted ${CMAKE_SOURCE_DIR}/helloworld.edl
            --search-path ${OE_INCLUDEDIR} --search-path ${OE_INCLUDEDIR}/openenclave/edl/sgx
)

# 添加生成的文件和其他源文件构建静态库
add_library(enclave STATIC enc.c helloworld_t.c)

# 包含生成文件的路径
target_include_directories(enclave PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# 编译选项：设置 API 版本和禁用某些安全功能（可选）
target_compile_definitions(enclave PUBLIC OE_API_VERSION=2)

# 链接 Open Enclave 库
target_link_libraries(enclave openenclave::oeenclave openenclave::oecrypto${OE_CRYPTO_LIB} openenclave::oelibc)

# 配置签名命令
add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/enclave/enclave.signed
    DEPENDS enclave private.pem public.pem
    COMMAND /opt/openenclave/bin/oesign sign -e $<TARGET_FILE:enclave>
            -c ${CMAKE_SOURCE_DIR}/enclave/helloworld.conf -k private.pem
)

# 创建一个自定义目标，将签名后的文件加入构建流程
add_custom_target(sign_enclave ALL DEPENDS ${CMAKE_BINARY_DIR}/enclave/enclave.signed)