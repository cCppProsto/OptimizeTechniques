TEMPLATE = subdirs


# https://github.com/google/benchmark
# http://quick-bench.com/_adcYxKW_WAhA69bwZTKyeQ-_Ok
# https://godbolt.org/

SUBDIRS += \
    loop_1 \
    swap_vs_my_swap \
    pass_by_val_ref_pointer \
    postpone_declaration \
    init_and_assignment \
    list_of_initialization \
    loop_collapsing \
    loop_fusion \
    loop_unrolling \
    tail_recursion \
    unswitching \
    volatile
