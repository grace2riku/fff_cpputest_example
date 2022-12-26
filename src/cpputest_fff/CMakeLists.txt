file(GLOB SOURCES "./*.c" "./*.cpp")

add_library(cpputest_fff STATIC ${SOURCES})
target_include_directories(cpputest_fff PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${PROJECT_SOURCE_DIR}/include/cpputest_fff)
