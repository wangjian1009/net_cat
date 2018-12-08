#include "net_statistics_backend.h"
#include "net_statistics_cat_i.h"

static int net_statistics_cat_backend_init(net_statistics_backend_t backend);
static void net_statistics_cat_backend_fini(net_statistics_backend_t backend);

static void net_statistics_cat_log_event(net_statistics_backend_t backend, const char *type, const char *name, const char *status, const char *data);
static void net_statistics_cat_log_metric_for_count(net_statistics_backend_t backend, const char *name, int quantity);
static void net_statistics_cat_log_metric_for_duration(net_statistics_backend_t backend, const char *name, uint64_t duration_ms);

net_statistics_cat_t net_statistics_cat_create(mem_allocrator_t alloc, error_monitor_t em, net_statistics_t statistics) {
    net_statistics_backend_t backend =
        net_statistics_backend_create(
            statistics,
            "cat",
            sizeof(struct net_statistics_cat),
            net_statistics_cat_backend_init,
            net_statistics_cat_backend_fini,
            net_statistics_cat_log_event,
            net_statistics_cat_log_metric_for_count,
            net_statistics_cat_log_metric_for_duration);
    if (backend == NULL) {
        CPE_ERROR(em, "net_statistics_cat: create backend fail!");
        return NULL;
    }
    
    net_statistics_cat_t statistics_cat = net_statistics_backend_data(backend);
    
    statistics_cat->m_alloc = alloc;
    statistics_cat->m_em = em;
    statistics_cat->m_debug = 0;

    CatClientConfig config = DEFAULT_CCAT_CONFIG;
    config.enableHeartbeat = 0;
    config.enableDebugLog = 1;
    catClientInitWithConfig("ccat", &config);
    
    return statistics_cat;
}

void net_statistics_cat_free(net_statistics_cat_t statistics_cat) {
    net_statistics_backend_free(net_statistics_backend_from_data(statistics_cat));
}

uint8_t net_statistics_cat_debug(net_statistics_cat_t statistics_cat) {
    return statistics_cat->m_debug;
}

void net_statistics_cat_set_debug(net_statistics_cat_t statistics_cat, uint8_t debug) {
    statistics_cat->m_debug = debug;
}

static int net_statistics_cat_backend_init(net_statistics_backend_t backend) {
    net_statistics_cat_t statistics_cat = net_statistics_backend_data(backend);
    
    statistics_cat->m_alloc = NULL;
    statistics_cat->m_em = NULL;
    statistics_cat->m_debug = 0;

    return 0;
}

static void net_statistics_cat_backend_fini(net_statistics_backend_t backend) {
    catClientDestroy();
}

static void net_statistics_cat_log_event(net_statistics_backend_t backend, const char *type, const char *name, const char *status, const char *data) {
    logEvent(type, name, status, data);
}

static void net_statistics_cat_log_metric_for_count(net_statistics_backend_t backend, const char *name, int quantity) {
    logMetricForCount(name, quantity);
}

static void net_statistics_cat_log_metric_for_duration(net_statistics_backend_t backend, const char *name, uint64_t duration_ms) {
    logMetricForDuration(name, (unsigned long long)duration_ms);
}
