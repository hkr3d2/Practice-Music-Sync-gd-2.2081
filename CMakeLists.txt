cmake_minimum_required(VERSION 3.16)
project(PracticeMusicSyncMod VERSION 1.0.0 LANGUAGES CXX)

# Include Geode SDK
include(FetchContent)
FetchContent_Declare(
    geode
    GIT_REPOSITORY https://github.com/geode-sdk/geode
    GIT_TAG main
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(geode)

# Create the mod
geode_mod(
    NAME PracticeMusicSyncMod
    ID exal.practice-music-sync
    VERSION 1.0.0
    FILES
        mod.json
        about.md
        resources/PracticeMusicSync.png
)
