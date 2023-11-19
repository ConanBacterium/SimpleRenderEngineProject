# Engine Only

file(GLOB_RECURSE Engine-src "*.cpp")
file(GLOB_RECURSE Engine-hpp "*.h")

set(MYENGINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "" FORCE)


add_library(Engine ${Engine-src} ${Engine-hpp})

target_link_libraries(Engine ${all_libs})

target_include_directories(Engine PUBLIC ${MYENGINE_INCLUDE_DIR})
target_include_directories(Engine PUBLIC "3rdParty")
