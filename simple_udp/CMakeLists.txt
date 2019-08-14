cmake_minimum_required(VERSION 2.6)
project(simple_udp)

#compile exec
include_directories( ../ )
#link_directories(${LIB_PATH})
set (CLIENT_SRC "udp_client.cpp") 
set (CLIENT "udp_client")

add_executable(${CLIENT} ${CLIENT_SRC})
#target_link_libraries(${CLIENT} )
add_custom_command(TARGET ${CLIENT} POST_BUILD COMMAND cp -vf $<TARGET_FILE:${CLIENT}> ${OUTPUT_PATH})

# compile udp_server 
set (SERVER "udp_server")
set (SERVER_SRC "udp_server.cpp" )
add_executable(${SERVER} ${SERVER_SRC})
add_custom_command(TARGET ${SERVER} POST_BUILD COMMAND cp -vf $<TARGET_FILE:${SERVER}> ${OUTPUT_PATH})