# pybind11_test

```bash
mkdir build/
cd    build/
cmake ..              # will clone https://github.com/pybind/pybind11.git (stable)
cmake --build . -j    # will also copy mysum.py into the build/ directory
./go                  # run (need a python with numpy)
```

The result is:

```
Sum is: 15
double free or corruption (out)
Aborted (core dumped)
```

It fails in [this line](https://github.com/user706/pybind11_test/blob/79c26f576ece40db9b306a5019add50c89e6dace/main.cpp#L32), but only the 2nd time through the loop!!!

So if I simply change the following line  
 [`constexpr int NUM_LOOPS = 2;`](main.cpp#L28)  
 to this  
 `constexpr int NUM_LOOPS = 1;`  
 then it will not fail.

Why does it fail with `NUM_LOOPS = 2`?  
How can one fix it? 

Thanks
