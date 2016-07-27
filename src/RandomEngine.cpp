#include "RandomEngine.h"
#include <iostream>

using sl::RandomEngine;
using std::cout;
using std::cin;
using std::endl;

RandomEngine::value_type RandomEngine::seed = time(nullptr);
const RandomEngine::value_type RandomEngine::A = 48271;
const RandomEngine::value_type RandomEngine::M = 2147483647;
const RandomEngine::value_type RandomEngine::Q = M / A;
const RandomEngine::value_type RandomEngine::R = M % A;

double RandomEngine::random() {
    value_type tmpSeed = A * (seed % Q) - R * (seed / Q);
    if (tmpSeed >= 0) {
        seed = tmpSeed;
    } else {
        seed = tmpSeed + M;
    }
    return static_cast<double>(seed) / M;
}

double RandomEngine::randDouble(const double min, const double max) {
    return random() * (max - min) + min;
}

int RandomEngine::randInt(const int min, const int max) {
    return static_cast<int>(random() * (max - min + 1) + min);
}

unsigned RandomEngine::randLib(const unsigned min, const unsigned max) {
    static bool seedSet = false;
    if (!seedSet) {
        srand(static_cast<unsigned>(time(nullptr)));
        seedSet = true;
    }
    return rand() % (max - min + 1) + min;
}

void RandomEngine::setSeed(value_type seed_) {
    seed = seed_;
}

void RandomEngine::test() {
    unsigned min, max, cnt = 0;
    cout << "Input the range of the random number: ";
    cin >> min >> max;
    while ((++cnt) <= 20) {
        double num = RandomEngine::randDouble(min, max);
        cout << num << endl;
    }
}
