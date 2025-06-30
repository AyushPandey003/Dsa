import time
import io
import contextlib

def run_script(filename):
    try:
        with open(filename, "r") as f:
            code = f.read()
        buf = io.StringIO()
        start = time.time()
        with contextlib.redirect_stdout(buf):
            exec(code, {})
        duration = time.time() - start
        output = buf.getvalue().strip()
        return output, duration, None
    except Exception as e:
        return None, None, str(e)

if __name__ == "__main__":
    files = ["Solution1.py", "Solution2.py"]
    results = []

    for file in files:
        output, duration, error = run_script(file)
        results.append((file, output, duration, error))

    for file, output, duration, error in results:
        print(f"== {file} ==")
        if error:
            print("Error:", error)
        else:
            print("Output:", output)
            print("Time:", round(duration, 6), "seconds")
        print()

    if all(r[3] is None for r in results) and results[0][1] == results[1][1]:
        print("✔️ Both solutions produced the same output.")
    else:
        print("❌ Outputs differ or an error occurred.")