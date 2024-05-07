# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

add_subdirectory(MPI)

# C++ files
set(PSyNet_SRC
    lib.cpp
)

set(PSyNet_HEADER_INSTALL
    lib.hpp
)

# Create PSyNet library
add_library(PSyNet SHARED ${PSyNet_SRC})


set(PSyNet_Targets_List
    hello_mpi
    ${MPI_C_LIBRARIES}
)

set(PSyNet_INSTALL_Targets_List
    hello_mpi
    ${MPI_C_LIBRARIES}
)

# Set installable targets
install(TARGETS ${PSyNet_INSTALL_Targets_List} EXPORT PSyNetTargets)


target_include_directories(PSyNet INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(PSyNet PUBLIC Boost::boost)
target_link_libraries(hello_mpi PUBLIC MPI::MPI_CXX)


target_link_libraries(PSyNet PUBLIC ${PSyNet_Targets_List})

# All users of this library will need at least C++11
target_compile_features(PSyNet PUBLIC cxx_std_11)

# Install targets
install(TARGETS PSyNet
        EXPORT PSyNetTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

# install include headers
install(FILES ${PSyNet_HEADER_INSTALL} DESTINATION include/pws)