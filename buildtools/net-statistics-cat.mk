net_statistics_cat_base:=$(call my-dir)/../statistics_cat
net_statistics_cat_output:=$(OUTPUT_PATH)/lib/libnet_statistics_cat.a
net_statistics_cat_cpp_flags:=-I$(call my-dir)/../../cpe/include \
                              -I$(call my-dir)/../../net/statistics/include \
                              -I$(call my-dir)/../depends/cat/lib/c/include \
                              -I$(call my-dir)/../statistics_cat/include
net_statistics_cat_src:=$(wildcard $(net_statistics_cat_base)/src/*.c)
$(eval $(call def_library,net_statistics_cat))
