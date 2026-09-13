#include "firopow-mix/work.h"

#include <cstdlib>
#include <iostream>

#define CHECK(cond)                                                          \
    do {                                                                     \
        if (!(cond)) {                                                       \
            std::cerr << "fail: " #cond " (" << __FILE__ << ":" << __LINE__  \
                      << ")\n";                                              \
            return 1;                                                        \
        }                                                                    \
    } while (0)

int main() {
    auto a = firopow::make_job("pool");
    auto b = firopow::make_job("pool");
    CHECK(a.id == b.id);
    CHECK(firopow::hash_nonce(a, 1) != firopow::hash_nonce(a, 2));
    CHECK(firopow::bench(8) == 8);
    CHECK(firopow::algo() != nullptr);
    std::cout << "ok\n";
    return 0;
}
