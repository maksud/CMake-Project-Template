# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.


# C++ files
set(HelloMPI_SRC
    hello_mpi.cpp
)

# Header files
set(HelloMPI_HEADER
    hello_mpi.hpp
)

# Build shared library hello_mpi
add_library(hello_mpi SHARED ${HelloMPI_SRC})

target_include_directories(hello_mpi PUBLIC 
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}>
    $<INSTALL_INTERFACE:include>
)

# install include headers
install(FILES ${HelloMPI_HEADER} DESTINATION include/pws/MPI)