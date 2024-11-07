# 使用 edger8r 生成 C 绑定文件（helloworld_t.h 和 helloworld_t.c）
add_custom_command(
  OUTPUT helloworld_t.h helloworld_t.c helloworld_args.h
  DEPENDS ${CMAKE_SOURCE_DIR}/helloworld.edl
  COMMAND
    /opt/openenclave/bin/oeedger8r --trusted ${CMAKE_SOURCE_DIR}/helloworld.edl
    --search-path ${OE_INCLUDEDIR} --search-path ${OE_INCLUDEDIR}/openenclave/edl/sgx
)

# 使用 add_enclave 定义 Enclave 目标并指定依赖的源文件
add_enclave(
  TARGET enclave
  SOURCES enc.c helloworld_t.c
)

# 需要生成的文件 helloworld_t.h
target_include_directories(enclave PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# 设置 Enclave 的编译定义
target_compile_definitions(enclave PUBLIC OE_API_VERSION=2)

# 根据 LVI 防护设置链接相关库
if (LVI_MITIGATION MATCHES ControlFlow)
  # 启用编译选项以支持 LVI 缓解措施
  apply_lvi_mitigation(enclave)
  # 链接带有 LVI 缓解的库
  target_link_libraries(
    enclave openenclave::oeenclave-lvi-cfg
    openenclave::oecrypto${OE_CRYPTO_LIB}-lvi-cfg openenclave::oelibc-lvi-cfg
  )
else ()
  target_link_libraries(
    enclave openenclave::oeenclave openenclave::oecrypto${OE_CRYPTO_LIB}
    openenclave::oelibc
  )
endif ()
