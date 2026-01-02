cmake_minimum_required(VERSION 3.10)
project(ptest VERSION 1.0 LANGUAGES C)

# Set C standard and prevent compilation if not supported
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set the compiler to Clang
set(CMAKE_C_COMPILER clang)

# Enable optimization flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -march=native -pipe -fPIC")

# Internal include directories for the build process
include_directories(
    include
    src/lib
    src/
)

# Define source files based on the new project structure
set(SOURCES
    src/ptest_add.c
    src/ptest_init.c
    src/ptest_run.c
    src/ptest_test.c
)

# Create Static and Shared library targets
add_library(ptest_static STATIC ${SOURCES})
add_library(ptest_shared SHARED ${SOURCES})

# Set output names to libptest.a and libptest.so
set_target_properties(ptest_static PROPERTIES OUTPUT_NAME ptest)
set_target_properties(ptest_shared PROPERTIES OUTPUT_NAME ptest)

# --- Installation Logic ---

# Install library binaries to the system lib directory
install(TARGETS ptest_shared ptest_static
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

# Install ONLY the public API header and ptest_test.h
install(FILES include/ptest.h 
        src/ptest_test.h
        DESTINATION include/ptest-${PROJECT_VERSION})

# --- Uninstall Target ---

# Custom command to remove installed files and directories
add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -E rm -f ${CMAKE_INSTALL_PREFIX}/lib/libptest.a
    COMMAND ${CMAKE_COMMAND} -E rm -f ${CMAKE_INSTALL_PREFIX}/lib/libptest.so
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${CMAKE_INSTALL_PREFIX}/include/ptest-${PROJECT_VERSION}
)
