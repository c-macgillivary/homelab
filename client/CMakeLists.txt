add_executable(client
  src/main.cpp
  src/Client.cpp
)

set_target_properties(client PROPERTIES
  CXX_STANDARD 26
  CXX_STANDARD_REQUIRED ON
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<LOWER_CASE:$<CONFIG>>
)

target_include_directories(client
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

target_link_libraries(client common)

install(TARGETS client DESTINATION bin)
