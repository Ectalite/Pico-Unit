//
// Created by i40015712 on 25.04.2024.
//
#include "framework.h"
#include <stdbool.h>
#include "pico/stdlib.h"

TEST_FUNCTION(test1(size_t amount),
    //Calculate something
    ASSERT(amount == 42, "Amount is not 42")
)

TEST_FUNCTION(test2(),
    //Calculate something
    ASSERT(true, "Never false assert")
)

DEFINE_FAMILY(meineTestFamilie(size_t amount),
    TEST(test1, amount)
    TEST(test2)
)

int main() {
    stdio_init_all();

    while (1) {
        busy_wait_ms(1000);
        START_TEST

        TEST_FAMILY(meineTestFamilie(100))

        STOP_TEST
    }
}