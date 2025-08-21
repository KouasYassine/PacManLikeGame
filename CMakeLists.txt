cmake_minimum_required(VERSION 3.4)
set(CMAKE_OSX_ARCHITECTURES x86_64) #Apple Silicon
project(Maze)
list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?
set(CMAKE_CXX_STANDARD 11)
find_package(Imagine REQUIRED COMPONENTS Graphics)
add_executable(Maze
  main.cpp
  labyrinthe.cpp
  labyrinthe.h
  joueur.h joueur.cpp
  Point.h Point.cpp
  File.h File.cpp
  icecreamguy.h icecreamguy.cpp
  point.h point.cpp
  outils.h
  outil.cpp
  ennemi.h
  ennemi.cpp
  cherry.cpp
  cherry.h
  GameManager.h
  GameManager.cpp
)
target_link_libraries(Maze Imagine::Graphics)

