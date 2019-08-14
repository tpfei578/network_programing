cmake_minimum_required(VERSION 2.6)
project(simple_tcp)



#compile exec
include_directories( )
#link_directories(${LIB_PATH})
set (CLIENT_SRC "tcp_client.cpp") 
set (CLIENT "tcp_client")

add_executable(${CLIENT} ${CLIENT_SRC})
#target_link_libraries(tcp_client )
add_custom_command(TARGET ${CLIENT} POST_BUILD COMMAND cp -vf $<TARGET_FILE:${CLIENT}> ${OUTPUT_PATH})

# compile tcp_server 
set (SERVER "tcp_server")
set (SERVER_SRC "tcp_server.cpp" "readn.cpp")
add_executable(${SERVER} ${SERVER_SRC})
add_custom_command(TARGET ${SERVER} POST_BUILD COMMAND cp -vf $<TARGET_FILE:${SERVER}> ${OUTPUT_PATH})