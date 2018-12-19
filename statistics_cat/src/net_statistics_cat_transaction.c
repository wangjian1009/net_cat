#include "net_statistics_cat_transaction_i.h"

int net_statistics_cat_transaction_init(
    net_statistics_backend_t backend, net_statistics_transaction_t transaction, void * data, const char * type)
{
    struct net_statistics_cat_transaction * t = data;

    t->m_transaction = newTransaction("E", type);
    if (t->m_transaction == NULL) return -1;
    
    return 0;
}

void net_statistics_cat_transaction_fini(
    net_statistics_backend_t backend, net_statistics_transaction_t transaction, void * data)
{
    struct net_statistics_cat_transaction * t = data;
    t->m_transaction->complete(t->m_transaction);
}

void net_statistics_cat_transaction_set_state(
    net_statistics_backend_t backend, net_statistics_transaction_t transaction, void * data, const char * state)
{
    struct net_statistics_cat_transaction * t = data;

    t->m_transaction->addData(t->m_transaction, data);
    t->m_transaction->setStatus(t->m_transaction, state);
}

