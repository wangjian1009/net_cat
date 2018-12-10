#ifndef NET_STATISTICS_CAT_H_INCLEDED
#define NET_STATISTICS_CAT_H_INCLEDED
#include "cpe/utils/utils_types.h"
#include "net_statistics_cat_system.h"

CPE_BEGIN_DECL

net_statistics_cat_t net_statistics_cat_create(
    mem_allocrator_t alloc, error_monitor_t em, net_statistics_t statistics, uint8_t debug,
    const char * app_key, uint8_t enable_heartbeat);
void net_statistics_cat_free(net_statistics_cat_t statistics_cat);

CPE_END_DECL

#endif
