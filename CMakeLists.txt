cmake_minimum_required(VERSION 3.25)
project("Shadow Of Fire")

set(CMAKE_CXX_STANDARD 23)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_executable("ShadowOfFire" main.cpp Game.cpp Scene.cpp)

target_link_libraries("ShadowOfFire"
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
        spdlog::spdlog spdlog::spdlog_header_only
)

file(COPY assets DESTINATION .)
file(COPY assets/maps/tilesets DESTINATION ./assets)
