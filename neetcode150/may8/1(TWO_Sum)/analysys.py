# analyzer.py
#!/usr/bin/env python3
import os
import sys
import importlib.util
import timeit
import tracemalloc
import ast
import inspect
import math
from matplotlib import pyplot as plt

def load_module_from_path(path):
    spec = importlib.util.spec_from_file_location("user_module", path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module

def measure_runtime(func, arg_generator, sizes, repeats=5):
    timings = []
    sig = inspect.signature(func)
    for n in sizes:
        args = arg_generator(n)
        # Normalize to tuple of args
        if not isinstance(args, (tuple, list)):
            args = (args,)
        # wrapper to call with unpacked args
        t = timeit.timeit(lambda: func(*args), number=repeats)
        timings.append(t / repeats)
    return timings

def measure_memory(func, arg_generator, sizes):
    mems = []
    sig = inspect.signature(func)
    for n in sizes:
        args = arg_generator(n)
        if not isinstance(args, (tuple, list)):
            args = (args,)
        tracemalloc.start()
        func(*args)
        current, peak = tracemalloc.get_traced_memory()
        tracemalloc.stop()
        mems.append(peak / 1024)  # KiB
    return mems

class ComplexityAnalyzer(ast.NodeVisitor):
    def __init__(self):
        self.max_loop_depth = 0
        self._current_depth = 0
        self.collections = set()
    def visit_For(self, node):
        self._current_depth += 1
        self.max_loop_depth = max(self.max_loop_depth, self._current_depth)
        self.generic_visit(node)
        self._current_depth -= 1
    def visit_While(self, node):
        self._current_depth += 1
        self.max_loop_depth = max(self.max_loop_depth, self._current_depth)
        self.generic_visit(node)
        self._current_depth -= 1
    def visit_List(self, node):
        self.collections.add('list')
        self.generic_visit(node)
    def visit_Dict(self, node):
        self.collections.add('dict')
        self.generic_visit(node)
    def visit_Set(self, node):
        self.collections.add('set')
        self.generic_visit(node)

def estimate_complexities(source_code):
    tree = ast.parse(source_code)
    analyzer = ComplexityAnalyzer()
    analyzer.visit(tree)
    d = analyzer.max_loop_depth
    time_big_o = f"O(n^{d})" if d > 0 else "O(1)"
    space_big_o = "O(n)" if analyzer.collections else "O(1)"
    return time_big_o, space_big_o, analyzer.collections

def main():
    path = input("Enter path to your .py solution file: ").strip()
    if not os.path.isfile(path):
        print(f"File not found: {path}")
        sys.exit(1)

    with open(path, 'r') as f:
        source = f.read()
    time_o, space_o, cols = estimate_complexities(source)
    print(f"\nStatic analysis estimates:")
    print(f"  • Time complexity ≈ {time_o}")
    print(f"  • Space complexity ≈ {space_o}")
    if cols:
        print(f"  • Data structures detected: {', '.join(cols)}")
    else:
        print("  • No major data-structures detected")

    mod = load_module_from_path(path)
    if not hasattr(mod, 'solution'):
        print("No function named 'solution' found in module.")
        sys.exit(1)
    sol = mod.solution

    sig = inspect.signature(sol)
    param_count = len(sig.parameters)
    # Default argument generator supports up to 2 params
    def default_arg_gen(n):
        if param_count == 1:
            return list(range(n)) + [0]
        elif param_count == 2:
            arr = list(range(n)) + [0]
            k = n // 2
            return (k, arr)
        else:
            raise ValueError("Auto arg_gen supports only 1 or 2 parameters. Please customize arg_generator.")

    arg_gen = default_arg_gen
    sizes = [1000, 2000, 5000, 10000]

    print("\nMeasuring runtime...")
    times = measure_runtime(sol, arg_gen, sizes)
    print("Done.")

    print("Measuring memory usage...")
    mems = measure_memory(sol, arg_gen, sizes)
    print("Done.")

    # Plotting
    plt.figure(figsize=(8,4))
    plt.plot(sizes, times, marker='o')
    plt.xlabel("Input size (n)")
    plt.ylabel("Avg. runtime (s)")
    plt.tight_layout()
    plt.show()

    plt.figure(figsize=(8,4))
    plt.plot(sizes, mems, marker='o')
    plt.xlabel("Input size (n)")
    plt.ylabel("Peak memory (KiB)")
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    main()
