cmake_minimum_required(VERSION 3.21)
project(Collisions_internship LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Collisions_internship src/main.cpp src/SAT.h src/SAT.h src/SAT.cpp src/Triangle.h src/Triangle.h src/Triangle.cpp)
target_link_libraries(Collisions_internship PRIVATE sfml-graphics)
target_compile_features(Collisions_internship PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Collisions_internship POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Collisions_internship> $<TARGET_FILE_DIR:Collisions_internship> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Collisions_internship)