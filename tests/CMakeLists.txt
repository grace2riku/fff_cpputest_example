file(GLOB SOURCES 
	"./*.c" "./*.cpp"
	"hello/*.c" "hello/*.cpp"
	"cpputest_fff/*.c" "cpputest_fff/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${PROJECT_SOURCE_DIR}/include)

# include CppUTest headers
include_directories($ENV{CPPUTEST_HOME}/include)

# add cpputest library
add_library(imp_cpputest STATIC IMPORTED)
set_property(TARGET imp_cpputest PROPERTY
             IMPORTED_LOCATION $ENV{CPPUTEST_HOME}/lib/libCppUTest.a)

add_library(imp_libCppUTestExt STATIC IMPORTED)
set_property(TARGET imp_libCppUTestExt PROPERTY
             IMPORTED_LOCATION $ENV{CPPUTEST_HOME}/lib/libCppUTestExt.a)

target_link_libraries(${PROJECT_NAME} 
    cpputest_fff
    hello
    imp_cpputest imp_libCppUTestExt
    )
