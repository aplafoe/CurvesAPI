#include "Curves.h"
#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include <random>
#include <queue>
#include <thread>
#include <mutex>

void worker(std::queue<std::shared_ptr<ICurve>>& curve_queue, std::mutex& mtx, double& total_sum) {
    double sum = 0.0;
    while (true) {
        std::shared_ptr<ICurve> curve;
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (curve_queue.empty()) {
                break;
            }
            curve = curve_queue.front();
            curve_queue.pop();
        }
        sum += curve->getRadiusX();
    }
    {
        std::lock_guard<std::mutex> lock(mtx);
        total_sum += sum;
    }
}

int main() {
    //Implement computation of the total sum of radii using parallel computations (e.g. OpenMP or Intel
    //TBB library).


    constexpr size_t SIZE = 10u;
    constexpr size_t NUM_THREADS = 5u;
    std::queue<std::shared_ptr<ICurve>> curve_queue;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> curve_params(1, 153);

    for (size_t i = 0; i < SIZE; ++i) {
        curve_queue.push(std::make_shared<Circle>(curve_params(gen)));
    }

    std::mutex mtx;
    double total_sum = 0.0f;
    std::vector<std::thread> threads;

    for (size_t i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back([&curve_queue, &mtx, &total_sum]() {
            worker(curve_queue, mtx, total_sum);
            });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "sum of radii = " << total_sum << std::endl;
    return 0;
}