cmake_minimum_required(VERSION 3.3)
project(rest_utilities)

include_directories(. include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  "${PROJECT_SOURCE_DIR}/lib/")

set(URLTEMPLATE_SOURCE_FILES
        UrlTemplate/UrlTemplate.cpp
        UrlTemplate/UrlTemplate.h
        UrlTemplate/UrlTemplateTester.cpp
        )

add_library(UrlTemplate SHARED ${URLTEMPLATE_SOURCE_FILES})

set(HYPERMEDIA_SOURCE_FILES
        Hypermedia/Form.cpp
        Hypermedia/Form.h
        Hypermedia/Link.cpp
        Hypermedia/Link.h
        )

add_library(Hypermedia SHARED ${HYPERMEDIA_SOURCE_FILES})
target_link_libraries(Hypermedia UrlTemplate)

add_executable(HypermediaTester Hypermedia/HypermediaTester.cpp)
target_link_libraries(HypermediaTester Hypermedia UrlTemplate)

add_executable(UrlTemplateTester UrlTemplate/UrlTemplateTester.cpp)
target_link_libraries(UrlTemplateTester UrlTemplate)

