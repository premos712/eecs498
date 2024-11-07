/*
 *  This file is auto generated by oeedger8r. DO NOT EDIT.
 */
#ifndef EDGER8R_HELLOWORLD_ARGS_H
#define EDGER8R_HELLOWORLD_ARGS_H

#include <openenclave/bits/result.h>

/**** User includes. ****/
#include "openenclave/bits/edl/syscall_types.h"
#include "openenclave/corelibc/bits/types.h"
#include "openenclave/bits/types.h"
#include "openenclave/bits/sgx/sgxtypes.h"
#include "openenclave/log.h"

/**** User defined types in EDL. ****/
#ifndef EDGER8R_STRUCT_OE_DIRENT
#define EDGER8R_STRUCT_OE_DIRENT
typedef struct oe_dirent
{
    uint64_t d_ino;
    oe_off_t d_off;
    uint16_t d_reclen;
    uint8_t d_type;
    char d_name[256];
} oe_dirent;
#endif

#ifndef EDGER8R_STRUCT___ST
#define EDGER8R_STRUCT___ST
typedef struct __st
{
    time_t tv_sec;
    suseconds_t tv_nsec;
} __st;
#endif

#ifndef EDGER8R_STRUCT_OE_STAT_T
#define EDGER8R_STRUCT_OE_STAT_T
typedef struct oe_stat_t
{
    oe_dev_t st_dev;
    oe_ino_t st_ino;
    oe_nlink_t st_nlink;
    oe_mode_t st_mode;
    oe_uid_t st_uid;
    oe_gid_t st_gid;
    uint32_t __st_pad0;
    oe_dev_t st_rdev;
    oe_off_t st_size;
    oe_blksize_t st_blksize;
    oe_blkcnt_t st_blocks;
    struct __st st_atim;
    struct __st st_mtim;
    struct __st st_ctim;
} oe_stat_t;
#endif

#ifndef EDGER8R_STRUCT_OE_HOST_POLLFD
#define EDGER8R_STRUCT_OE_HOST_POLLFD
typedef struct oe_host_pollfd
{
    oe_host_fd_t fd;
    short int events;
    short int revents;
} oe_host_pollfd;
#endif

#ifndef EDGER8R_STRUCT_OE_POLLFD
#define EDGER8R_STRUCT_OE_POLLFD
typedef struct oe_pollfd
{
    int fd;
    short int events;
    short int revents;
} oe_pollfd;
#endif

#ifndef EDGER8R_STRUCT_OE_SOCKADDR
#define EDGER8R_STRUCT_OE_SOCKADDR
typedef struct oe_sockaddr
{
    oe_sa_family_t sa_family;
    char sa_data[14];
} oe_sockaddr;
#endif

#ifndef EDGER8R_STRUCT_OE_ADDRINFO
#define EDGER8R_STRUCT_OE_ADDRINFO
typedef struct oe_addrinfo
{
    int ai_flags;
    int ai_family;
    int ai_socktype;
    int ai_protocol;
    oe_socklen_t ai_addrlen;
    struct oe_sockaddr* ai_addr;
    char* ai_canonname;
    struct oe_addrinfo* ai_next;
} oe_addrinfo;
#endif

#ifndef EDGER8R_STRUCT_OE_TIMESPEC
#define EDGER8R_STRUCT_OE_TIMESPEC
typedef struct oe_timespec
{
    time_t tv_sec;
    long int tv_nsec;
} oe_timespec;
#endif

#ifndef EDGER8R_STRUCT_OE_UTSNAME
#define EDGER8R_STRUCT_OE_UTSNAME
typedef struct oe_utsname
{
    char sysname[65];
    char nodename[65];
    char release[65];
    char version[65];
    char machine[65];
    char domainname[65];
} oe_utsname;
#endif

#ifndef EDGER8R_STRUCT_FORMAT_IDS_T
#define EDGER8R_STRUCT_FORMAT_IDS_T
typedef struct format_ids_t
{
    void* data;
    size_t size;
} format_ids_t;
#endif

#ifndef EDGER8R_STRUCT_OE_REPORT_BUFFER_T
#define EDGER8R_STRUCT_OE_REPORT_BUFFER_T
typedef struct oe_report_buffer_t
{
    uint8_t* buffer;
    size_t size;
} oe_report_buffer_t;
#endif

#ifndef EDGER8R_STRUCT_OE_HOST_WORKER_CONTEXT_T
#define EDGER8R_STRUCT_OE_HOST_WORKER_CONTEXT_T
typedef struct oe_host_worker_context_t
{
    void* call_arg;
    oe_enclave_t* enc;
    int64_t is_stopping;
    int64_t event;
    uint64_t spin_count;
    uint64_t total_spin_count;
} oe_host_worker_context_t;
#endif

#ifndef EDGER8R_STRUCT_OE_ENCLAVE_WORKER_CONTEXT_T
#define EDGER8R_STRUCT_OE_ENCLAVE_WORKER_CONTEXT_T
typedef struct oe_enclave_worker_context_t
{
    void* call_arg;
    oe_enclave_t* enc;
    int64_t is_stopping;
    int64_t event;
    uint64_t spin_count;
    uint64_t spin_count_threshold;
    uint64_t total_spin_count;
} oe_enclave_worker_context_t;
#endif

#ifndef EDGER8R_STRUCT_TDX_QUOTE_COLLATERAL_T
#define EDGER8R_STRUCT_TDX_QUOTE_COLLATERAL_T
typedef struct tdx_quote_collateral_t
{
    uint8_t* data;
    uint32_t size;
} tdx_quote_collateral_t;
#endif

#endif // EDGER8R_HELLOWORLD_ARGS_H
