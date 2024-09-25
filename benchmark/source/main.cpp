#include <benchmark/benchmark.h>
#include <greeter/greeter.h>

static void BM_SomeFunction(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    greeter::Greeter g {"Greeter"};
    const auto s = g.greet();
  }
}
// Register the function as a benchmark
BENCHMARK(BM_SomeFunction);
// Run the benchmark
BENCHMARK_MAIN();