//
// Created by i40015712 on 24.04.2024.
//

#ifndef STRESSTESTING_FRAMEWORK_H
#define STRESSTESTING_FRAMEWORK_H

#include <stdio.h>
#include <stdint.h>

#define newAssert

#ifdef newAssert
#define ASSERT(e,p)                 if(e) {                                                 \
                                        assertOk++;}                                        \
                                    else {                                                  \
                                        test = false;                                       \
                                        printf("[Test %s] FAILED - %s\n", __func__, p);     \
                                    }                                                       \
                                    assertAmount++
#else
#define ASSERT(e,p) assert(e)
#endif
#define TEST2(func, param) \
                                    if(func(param)) {                       \
                                        printf("TEST "#func" OK\n");        \
                                    } else {                                \
                                        ret.testsFailed++;                  \
                                        printf("TEST "#func" FAILED\n");    \
                                    }                                       \
                                    ret.totalTests++

#define TEST1(func)                 TEST2(func, )
#define GET_MACRO(_1,_2,NAME,...)   NAME
#define TEST(...)                   GET_MACRO(__VA_ARGS__, TEST2, TEST1)(__VA_ARGS__)

#define START_TEST                  TEST_results_t total = {0,0};                           \
                                    printf("####### Starting tests #######\n");             \
                                    TEST_results_t ret

#define STOP_TEST                   printf("####### Ending tests #######\n");                               \
                                    printf("Total tests: %u\n", total.totalTests);                          \
                                    printf("Succeeded tests: %u\n", total.totalTests - total.testsFailed);  \
                                    printf("Failed tests: %u\n", total.testsFailed)

#define TEST_FUNCTION(func, ...)    static bool func {                                                                \
                                        printf("####### Starting %s #######\n", __func__);                                   \
                                        bool test = true;                                                               \
                                        unsigned int assertAmount = 0;                                                  \
                                        unsigned int assertOk = 0;                                                      \
                                        __VA_ARGS__                                                                     \
                                        printf("[Test %s] %u/%u asserts passed\n", __func__, assertOk, assertAmount);        \
                                        return test;                                                                    \
                                    }

#define DEFINE_FAMILY(func, ...)    TEST_results_t func{ \
                                        TEST_results_t ret = {0,0};             \
                                        __VA_ARGS__                                \
                                        return ret;                     \
                                    }

#define DECLARE_FAMILY(func)        TEST_results_t func

#define TEST_FAMILY(func)           ret = func;         \
                                    total.totalTests = ret.totalTests + total.totalTests; \
                                    total.testsFailed = ret.testsFailed + total.testsFailed \

typedef struct TEST_results {
    uint16_t totalTests;
    uint16_t testsFailed;
} TEST_results_t;

#endif //STRESSTESTING_FRAMEWORK_H
