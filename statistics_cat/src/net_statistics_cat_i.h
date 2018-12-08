#ifndef NET_STATISTICS_CAT_I_H_INCLEDED
#define NET_STATISTICS_CAT_I_H_INCLEDED
#include "client.h"
#include "cpe/pal/pal_queue.h"
#include "cpe/utils/memory.h"
#include "cpe/utils/error.h"
#include "cpe/utils/buffer.h"
#include "cpe/utils/hash.h"
#include "net_statistics_cat.h"

CPE_BEGIN_DECL

struct net_statistics_cat {
    mem_allocrator_t m_alloc;
    error_monitor_t m_em;
    uint8_t m_debug;
};

CPE_END_DECL

#endif
