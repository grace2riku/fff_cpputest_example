file(GLOB SOURCES 
	"./*.c" "./*.cpp"
	"cpputest_fff/*.c" "cpputest_fff/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${PROJECT_SOURCE_DIR}/include)

# プリプロセッサ出力
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps")
#target_compile_options(${PROJECT_NAME} -save-temps)    // これはエラーになる

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
    imp_cpputest imp_libCppUTestExt
    )
