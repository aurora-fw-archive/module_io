message(STATUS "Loading io module...")

if (NOT CONFIGURED_ONCE)
	set(MODULE_IO_MODULE_IO_SOURCE_DIR O_DIR}/src)
endif()

include_directories(${MODULE_IO_DIR}/include)

add_library (aurora-io SHARED ${MODULE_IO_SOURCE_DIR}/InfoOS.cpp
                              ${MODULE_IO_SOURCE_DIR}/InfoRAM.cpp
                              ${MODULE_IO_SOURCE_DIR}/Timer.cpp)

set_target_properties(aurora-io PROPERTIES OUTPUT_NAME aurora-io)
