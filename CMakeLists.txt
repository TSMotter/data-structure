cmake_minimum_required (VERSION 3.14)
project (data_structure)

# Variable TARGET_GROUP should be passed as an argument when calling cmake
set(TARGET_GROUP production CACHE STRING "What Should I Build?")

if(TARGET_GROUP STREQUAL helloworld)
  add_subdirectory(helloworld)
elseif(TARGET_GROUP STREQUAL array)
  add_subdirectory(array)
elseif(TARGET_GROUP STREQUAL linked_list)
  add_subdirectory(linked_list)
else()
  message(FATAL_ERROR "I don't know the TARGET_GROUP you gave me!")
endif()