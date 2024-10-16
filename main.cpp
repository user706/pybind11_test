#include <iostream>
#include <pybind11/embed.h> // everything needed for embedding
#include <pybind11/stl.h>
#include <vector>
#include <thread>

namespace py = pybind11;


py::object *my_sum; // lifetime beyond certain scoping

void func()
{
    py::gil_scoped_acquire acquire;

    std::vector<int16_t> vec;
    vec.resize(200);
    vec[0] = 10;
    vec[1] = 5;
    
    py::list arr = py::cast(vec);
    std::cout << "Sum is: " << (*my_sum)(arr).cast<int64_t>() << std::endl;
}



int main() {
    constexpr int NUM_LOOPS = 2;           // CHANGE THIS TO 1 ... AND IT WILL NOT FAIL (WHY DOES IT FAIL WITH 2 ??)
    for (int i = 0; i < NUM_LOOPS; ++i) {
        py::scoped_interpreter inter;
        {
            py::object imported = py::module::import("mysum");
            my_sum = new py::object(imported.attr("my_sum"));
        }
        {
            py::gil_scoped_release rel;
            std::thread th1(func);
            th1.join();
        }
        delete my_sum;
    }
}
