cmake_minimum_required(VERSION 3.27)
project(rpg)

set(CMAKE_CXX_STANDARD 17)

add_executable(rpg main.cpp
        src/Model/Character/Character.cpp
        include/Model/Character/Character.h
        src/Model/Character/Player/Player.cpp
        include/Model/Character/Player/Player.h
        src/Model/Character/Enemy/Enemy.cpp
        include/Model/Character/Enemy/Enemy.h
        Utils.h
        src/Model/Combat/Combat.cpp
        include/Model/Combat/Combat.h
        Tables.h
)
