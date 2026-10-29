add_executable(server
  src/main.cpp
  src/Server.cpp
  src/Client.cpp
  src/CommandRegistry.cpp
  src/EchoCommand.cpp
)

set_target_properties(server PROPERTIES
  CXX_STANDARD 26
  CXX_STANDARD_REQUIRED ON
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<LOWER_CASE:$<CONFIG>>
)

target_include_directories(server
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

target_link_libraries(server
    PRIVATE common
)

install(TARGETS server DESTINATION bin)
