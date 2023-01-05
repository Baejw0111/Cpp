cmake_minimum_required(VERSION 3.0.0)
project(C++ VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB_RECURSE SRC "*.cpp" "*.h")
set(EXCLUDE_PATHS "CMakeFiles")
foreach(TMP_PATH ${SRC})
    foreach(EXCLUDE_PATH ${EXCLUDE_PATHS})
        string(FIND ${TMP_PATH} ${EXCLUDE_PATH} RESULT)
        if(NOT ${RESULT} EQUAL -1)
            list(REMOVE_ITEM SRC ${TMP_PATH})
        endif()
    endforeach(EXCLUDE_PATH)
endforeach(TMP_PATH)

add_executable(C++ ${SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
