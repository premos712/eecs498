cmake_minimum_required(VERSION 3.11)
project("Hello World Sample" LANGUAGES C CXX)

# 查找 Open Enclave SDK
find_package(OpenEnclave CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(OE_CRYPTO_LIB openssl) 

# 添加子目录
add_subdirectory(enclave)
add_subdirectory(host)

# 使用 OpenSSL 生成密钥并签名 enclave
add_custom_command(
  OUTPUT ${CMAKE_BINARY_DIR}/enclave/enclave.signed
  COMMAND openssl genrsa -out ${CMAKE_BINARY_DIR}/private.pem -3 3072
  COMMAND openenclave::oesign sign -e $<TARGET_FILE:enclave>
          -c ${CMAKE_SOURCE_DIR}/enclave/helloworld.conf -k ${CMAKE_BINARY_DIR}/private.pem
  DEPENDS enclave enclave/helloworld.conf
  COMMENT "Generating key and signing the enclave"
)

# 自定义目标用于签名
add_custom_target(sign_enclave ALL DEPENDS ${CMAKE_BINARY_DIR}/enclave/enclave.signed)

# 添加运行和模拟目标
add_custom_target(
  run
  DEPENDS helloworld_host sign_enclave
  COMMAND helloworld_host ${CMAKE_BINARY_DIR}/enclave/enclave.signed)

add_custom_target(
  simulate
  DEPENDS helloworld_host sign_enclave
  COMMAND helloworld_host ${CMAKE_BINARY_DIR}/enclave/enclave.signed --simulate)
