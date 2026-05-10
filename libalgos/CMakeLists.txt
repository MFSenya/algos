MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()


SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
include(GoogleTest)

# Add a separate executable for test file in each subdirectory,
# link it against googletest default main and discover tests
message(STATUS "Add tests for: ")
FOREACH(subdir ${SUBDIRS})
  message(STATUS " -- ${subdir}")
  set(unittestexename ${subdir}_test)
  # Add an executable
  add_executable(
    ${unittestexename}
    ${subdir}/${subdir}.test.cpp
  )
  # Add cpp file of the same name if it exists
  if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/${subdir}.cpp")
    target_sources(${unittestexename} PRIVATE "${subdir}/${subdir}.cpp")
  endif()
  # Add an include dir
  target_include_directories(
    ${unittestexename}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/..
  )
  target_link_libraries(
    ${unittestexename}
    GTest::gtest_main
  )
  gtest_discover_tests(${unittestexename})
ENDFOREACH()
