cmake_minimum_required(VERSION 3.15)
project(A4_Tycoon)

set(CMAKE_CXX_STANDARD 14)

add_executable(A4_Tycoon main.cpp Tycoon.cpp Tycoon.h Property.cpp Property.h BusinessBuilding.cpp BusinessBuilding.h ApartmentBuilding.cpp ApartmentBuilding.h ResidentialBuilding.cpp ResidentialBuilding.h Tennant.cpp Tennant.h BusinessTennant.cpp BusinessTennant.h ResidentialTennant.cpp ResidentialTennant.h)