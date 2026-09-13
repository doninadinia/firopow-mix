#include "firopow-mix/work.h"

#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc > 1 && std::string(argv[1]) == "--help") {
        std::cerr << "firopow-mix [rounds]\n";
        return 0;
    }
    std::uint32_t rounds = 16;
    if (argc > 1) {
        rounds = static_cast<std::uint32_t>(std::stoul(argv[1]));
    }
    auto job = firopow::make_job(firopow::algo());
    auto n = firopow::bench(rounds);
    std::cout << "algo=" << firopow::algo() << " job=" << job.id << " rounds=" << n << "\n";
    return 0;
}
