project(crc32)

cmake_minimum_required(VERSION 3.16)

add_definitions( -D__for_linux )

add_executable(crc32 crc32.c)

install(TARGETS crc32 DESTINATION /usr/local/bin PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
