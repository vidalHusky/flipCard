cmake_minimum_required(VERSION 3.23)
project(FlipCardB)

set(CMAKE_CXX_STANDARD 14)

add_executable(FlipCardB main.cpp Card.cpp Card.h Deck.cpp Deck.h Node.h playFlip.cpp playFlip.h)
