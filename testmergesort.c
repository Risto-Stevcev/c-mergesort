#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "mergesort.h"


void
array_cmp(int *arr1, int *arr2, int arrlen)
{
    for (int i = 0; i < arrlen; i++)
        CU_ASSERT(arr1[i] == arr2[i]);
}

int
setup_suite1(void)
{
    return 0;
}

int
teardown_suite1(void)
{
    return 0;
}

void
test_merge_suite1(void)
{
    int list[8] = {0};
    int sorted_list[] = {1,2,3,4,5,7,19,21};

    int left[] = {1,2,4,7};
    int right[] = {3,5,19,21};

    merge(left, 4, right, 4, list);
    array_cmp(list, sorted_list, 8);
}

void
test_merge_sort_suite1(void)
{
    int list[] = {3,1,2,4,5,21,19,7};
    int merged_list[] = {1,2,3,4,5,7,19,21};

    merge_sort(list, 8);
    array_cmp(list, merged_list, 8);   
}


int
main ()
{
    CU_pSuite pSuite1 = NULL;

    /* initialize registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add suites to registry */
    pSuite1 = CU_add_suite("Test merge", setup_suite1, teardown_suite1);

    if (pSuite1 == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add tests to suite */
    if (  (NULL == CU_add_test(pSuite1, "test merge", test_merge_suite1))
       || (NULL == CU_add_test(pSuite1, "test mergesort", test_merge_sort_suite1))  )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* run tests */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    CU_cleanup_registry();
    return CU_get_error();
}
