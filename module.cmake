message(STATUS "Loading io module...")

if (NOT CONFIGURED_ONCE)
	set(MODULE_IO_SOURCE_DIR ${MODULE_IO_DIR}/src)
endif()

include_directories(${MODULE_IO_DIR}/include)

add_library (aurorafw-io SHARED ${MODULE_IO_SOURCE_DIR}/InfoOS.cpp
                              ${MODULE_IO_SOURCE_DIR}/InfoRAM.cpp
                              ${MODULE_IO_SOURCE_DIR}/Timer.cpp)

set_target_properties(aurorafw-io PROPERTIES OUTPUT_NAME aurorafw-io)
