# Loosely Synchronized Rule-Based Planning (LSRP) for Multi-Agent Path Finding with Asynchronous Actions and Capacity

This repository provides an implementation of the Loosely Synchronized Rule-Based Planning (LSRP) algorithm for solving Multi-Agent Path Finding with asynchronous actions  problems  (MAPF-AA). LSRP is designed to handle a large number of agents by trading off solution quality for scalability. More technical details can be found in [[1](https://arxiv.org/pdf/2412.11678)].

The code is distributed for academic and non-commercial use. THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

<p align="center">
    <img src="https://github.com/ShuaiZhou302/ShuaiZhou302.github.io/blob/main/static/uploads/video_1_10-ezgif.com-resize.gif" width="600" alt="A 100 agent MAPF-AA instances.">
    <p align="center">(Fig 1: A 100 agent MAPF-AA instances.)</p>
</p>






## Requirements

* C++ compiler supporting C++11 or later
* CMake (version 2.8.3 or later)
* Make

## Project Structure

* `data/` - Contains a few input files for the toy examples
* `demo/` - Contains a few input files for the command example cases
* `include/` - Contains all header files.
* `source/` - Contains all source files corresponding to the headers.
* `test/` - Contains toy example file that shows how to use the code.


## Installation and Usage

1. Clone this repository.
2. `mkdir build/`
3. `cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -B build`
3. `cd build/`
4. `make`
5. Run the program with the following command:
   ```sh
   ./lsrp <map_path> <scen_path> <duration_path> <node_capacity> <runtime> [swap]
    ```
   To run the program with 10 agents on the specified map and scenario files, and save the results to `result.xml` with a maximum runtime of 30 seconds and the swap feature enabled, use the following command:
   ```sh
   ./lsrp ../demo/warehouse-10-20-10-2-1.map ../demo/warehouse-10-20-10-2-1-random-1.scen ../demo/duration.txt 30 swap ../demo/output.txt
   ```
   If you do not enter <node_capacity>, then the capacity will default to 1 for all nodes and execute the most basic Lsrp
   ```sh   
    ./lsrp ../demo/warehouse-10-20-10-2-1.map ../demo/warehouse-10-20-10-2-1-random-1.scen ../demo/duration.txt 30 swap 
   ```
#### Command Line Arguments
- `<map_path>`: The path to the map file.
- `<scen_path>`: The path to the scenario file.
- `<duration_path>`: The path to the duration file where the durations for each agent is written.
- `<runtime>`: The maximum runtime for the algorithm in seconds.
- `<node_capacity>`:The capacity seted for each node
- `[swap]` (optional): If provided, enables the swap feature.

#### Example 


## Visualization

For visualization of the results, you can use the [Visualizer](https://github.com/ShuaiZhou302/Continuous-MAPF_visualizer).

This Qt framework-based visualizer allows you to load and display the output files generated by this project.


## References

* [1] Loosely Synchronized Rule-Based Planning for Multi-Agent Path Finding with Asynchronous Actions.\
  Shuai Zhou, Shizhe Zhao, Zhongqiang Ren.\
  [[Bibtex](https://shuaizhou302.github.io/publication/zhou-2024-looselysynchronizedrulebasedplanning/cite.bib)][[Paper](https://arxiv.org/pdf/2412.11678)]
## License

This code is distributed under the MIT License. See the LICENSE file for details.


