#ifndef NET_STATISTICS_CAT_TRANSACTION_I_H_INCLEDED
#define NET_STATISTICS_CAT_TRANSACTION_I_H_INCLEDED
#include "net_statistics_cat_i.h"

CPE_BEGIN_DECL

struct net_statistics_cat_transaction {
    CatTransaction * m_transaction;
};

int net_statistics_cat_transaction_init(
    net_statistics_backend_t backend, net_statistics_transaction_t transaction, void * data, const char * type);
void net_statistics_cat_transaction_fini(
    net_statistics_backend_t backend, net_statistics_transaction_t transaction, void * data);
void net_statistics_cat_transaction_set_state(
    net_statistics_backend_t backend, net_statistics_transaction_t transaction, void * data, const char * state);

CPE_END_DECL

#endif
