Warehouse passing optimization
===
## Author
name: Jan Holáň \
login: xholan11 \
email: xholan11@vutbr.cz

# Intro
These code is a part of bachelor thesis.  It solves the problem of optimizing picking while passing through the warehouse.
All the specification comes from company, which desires to stay anonymous.

# Dependencies
Libraries **python3.11** and **nlohmann/json** have to be installed.

Code of this work is written with expectation, that nlohmann/json library is included in directory */usr/include*. Source code of this library can be found in the directory *./libs* or at https://github.com/nlohmann/json.

# Creating static and dynamic library
All the code including the makefile is in the directory *./src*.

Type `make` or `make static` in src folder to compile static library called *libwarehouse_pick_opt.a*. Type `make dynamic` to compile dynamic library called.*libwarehouse_pick_opt.so*.

# Usage
To use this library you have to include file *WarehousePickingOpt.h* into your code. If you also want to debug the code, you'll need to also include *warehouse_picking_opt_debug.h*.

Compile your code, where you use this library, with parameter `-lpython3.11`, otherwise it won't work.

# Testing
In addition to GUI testing, it is possible to use the **main.cpp** file for testing. This file is stored in *./test* folder. It can be compiled and run with makefile command `make run`. The makefile uses static library, which is described above.

