#include "net_statistics_cat_i.h"

net_statistics_cat_t net_statistics_cat_create(mem_allocrator_t alloc, error_monitor_t em) {
    net_statistics_cat_t statistics_cat = mem_alloc(alloc, sizeof(struct net_statistics_cat));

    return statistics_cat;
}

void net_statistics_cat_free(net_statistics_cat_t statistics_cat) {
}

uint8_t net_statistics_debug(net_statistics_cat_t statistics_cat) {
    return statistics_cat->m_debug;
}

void net_statistics_set_debug(net_statistics_cat_t statistics_cat, uint8_t debug) {
    statistics_cat->m_debug = debug;
}

