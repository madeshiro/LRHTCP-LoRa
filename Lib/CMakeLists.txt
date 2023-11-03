#####################################################################################
# LightWhale Communication Protocol for LoRa                                        #
# Copyright (c) 2023 Rin "madeshiro" Baudelet                                       #
#                                                                                   #
# Permission is hereby granted, free of charge, to any person obtaining a copy      #
# of this software and associated documentation files (the "Software"), to deal     #
# in the Software without restriction, including without limitation the rights      #
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell         #
# copies of the Software, and to permit persons to whom the Software is             #
# furnished to do so, subject to the following conditions:                          #
#                                                                                   #
# The above copyright notice and this permission notice shall be included in all    #
# copies or substantial portions of the Software.                                   #
#                                                                                   #
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR        #
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,          #
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE       #
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER            #
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,     #
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE     #
# SOFTWARE.                                                                         #
#####################################################################################
set(TARGET lightwhale)

### C Files

set(SOURCES
        src/lightwhale.c
        src/lwdef.c
)

set(HEADERS
        include/lightwhale.h
        include/LightWhaleLibrary.h
        include/lwdef.h
)

### C++ Files

set(SOURCES_CXX
        src/cxx/lightwhale.cxx
)

set(HEADERS_CXX
        include/lightwhale
        include/cxx/lightwhale.hh
)

# Setup Targets
message("> setup target '${TARGET}' (protocollib)...")

# C Targets
add_library(${TARGET} STATIC ${SOURCES} ${HEADERS})
add_library(${TARGET}.so SHARED ${SOURCES} ${HEADERS})
set_target_properties(${TARGET}.so PROPERTIES OUTPUT_NAME ${TARGET})

# C++ Targets
add_library(${TARGET}-c++ STATIC ${SOURCES_CXX} ${HEADERS_CXX})
add_library(${TARGET}-c++.so SHARED ${SOURCES_CXX} ${HEADERS_CXX})
set_target_properties(${TARGET}-c++.so PROPERTIES OUTPUT_NAME ${TARGET}-c++)

# Windows Resources
if (WIN32)
    target_sources(${TARGET} PRIVATE resources.rc)
    target_sources(${TARGET}.so PRIVATE resources.rc)
    target_sources(${TARGET}-c++ PRIVATE resources.rc)
    target_sources(${TARGET}-c++.so PRIVATE resources.rc)
endif ()

# Instanciate Test Applications
include_directories("test")
create_test_sourcelist(ctest_testmodule ${TARGET}_testmodule.cxx
    test/lw_init.cxx
)

add_executable(${TARGET}_testmodule ${ctest_testmodule})
target_link_libraries(${TARGET}_testmodule ${TARGET})

set(ctest_runtest
        ${ctest_testmodule}
        )
list(REMOVE_ITEM ctest_runtest ${TARGET}_testmodule.cxx)

foreach(test ${ctest_runtest})
    get_filename_component(test_name ${test} NAME_WE)
    add_test(NAME ${TARGET}.${test_name} COMMAND ${TARGET}_testmodule test/${test_name})
    set_property(TEST ${TARGET}.${test_name} PROPERTY LABELS ${TARGET})
    message("> add test ${TARGET}.${test_name}")
endforeach()

# # Install CPack
# install(TARGETS   ${TARGET}         DESTINATION lib)
# install(TARGETS   ${TARGET}-c++     DESTINATION lib)
# install(TARGETS   ${TARGET}.so      DESTINATION lib)
# install(TARGETS   ${TARGET}-c++.so  DESTINATION lib)
# install(DIRECTORY include           DESTINATION include)
# install(FILES     src               DESTINATION src/lightwhale)

message("> target '${TARGET}' (protocollib) setup successfuly !")