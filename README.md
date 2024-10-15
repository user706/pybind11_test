# pybind11_test

```bash
mkdir build/
cd    build/
cmake ..
cmake --build . -j    # will also copy mysum.py into the build/ directory
./go                  # run
```

The result is:

```
Sum is: 15
double free or corruption (out)
Aborted (core dumped)
```
