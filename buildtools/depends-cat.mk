cat_base:=$(call my-dir)/../depends/cat/lib/c
cat_output:=$(OUTPUT_PATH)/lib/libcat.a
cat_cpp_flags:=-I$(cat_base)/include \
               -I$(cat_base)/src \
               -I$(my-dir)/custom/cat
cat_c_flags:=-Wno-format-security
cat_src:=$(wildcard $(cat_base)/src/lib/*.c) \
         $(wildcard $(cat_base)/src/ccat/*.c)

ifeq ($(OS_NAME),mac)
    cat_c_flags+=-Wno-ignored-qualifiers
else
    cat_c_flags+=-Wno-discarded-qualifiers
endif

$(eval $(call def_library,cat))
