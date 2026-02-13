# Parabyte Penix Test

**Penix-test** is a minimal library under the Penix standard that provides functions to Create unit-tests for your projects and manage their performance based on these tests. Its simple structure makes it easy to manage, maintain, and develop while being highly functional.

### Installation

To install it on Unix-based operating systems, first download the project and navigate into it:

```bash
git clone https://github.com/libremahdi/penix-test.git
cd penix-test
```

Next, create a directory like **build** and navigate into it:

```bash
mkdir -p build
cd build/
```

For compilation and installation, use the following commands:

```bash
cmake ..
make
sudo make install
```

If everything goes smoothly—fingers crossed—this library is now installed on your system. To uninstall it, remain in the **build** directory and run the following commands after `cmake ..` and `make`:

```bash
sudo make uninstall
```

### Usage

To use it, you need to include the header `#include <ptest-1.1/ptest.h>` in your project. For easy compilation of your project, you can use the following command:

```bash
clang -L/usr/local/lib -lptest -Wl,-rpath,/usr/local/lib Source-file.c
```

For more information, check and compile the file `test/main.c`.

### License

This project is developed and distributed under the GNU GPL-3.0 license. For more information, please check the **LICENSE** file.