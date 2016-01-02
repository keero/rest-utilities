cmake_minimum_required(VERSION 3.3)
project(rest_utilities)

include_directories("${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/include/")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib/")

set(URLTEMPLATE_SOURCE_FILES
        UrlTemplate/UrlTemplate.cpp
        UrlTemplate/UrlTemplate.h
        UrlTemplate/UrlTemplateTester.cpp
        )

add_library(UrlTemplate SHARED ${URLTEMPLATE_SOURCE_FILES})

set(HYPERMEDIA_SOURCE_FILES
        Ready4Air/DTO/Hypermedia/Form.cpp
        Ready4Air/DTO/Hypermedia/Form.h
        Ready4Air/DTO/Hypermedia/Link.cpp
        Ready4Air/DTO/Hypermedia/Link.h
        Ready4Air/DTO/Hypermedia/Crud.cpp
        Ready4Air/DTO/Hypermedia/Crud.h
        Ready4Air/DTO/Abstract/JsonDeserializable.h)

add_library(Hypermedia SHARED ${HYPERMEDIA_SOURCE_FILES})
target_link_libraries(Hypermedia UrlTemplate)


add_executable(HypermediaTester Ready4Air/DTO/Hypermedia/HypermediaTester.cpp)
target_link_libraries(HypermediaTester Hypermedia UrlTemplate)

add_executable(UrlTemplateTester UrlTemplate/UrlTemplateTester.cpp)
target_link_libraries(UrlTemplateTester UrlTemplate)

