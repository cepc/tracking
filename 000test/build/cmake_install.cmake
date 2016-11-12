# Install script for directory: /home/zhaomr/workdir/cepc/Tracking/000test

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/zhaomr/workdir/cepc/Tracking/000test")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "0")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmymarlin.so.0.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmymarlin.so.0.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmymarlin.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHECK
           FILE "${file}"
           RPATH "/home/zhaomr/workdir/cepc/Tracking/000test/lib:/projects/ilc/soft/v01-17-06/Marlin/v01-05/lib:/projects/ilc/soft/v01-17-06/lcio/v02-05/lib:/projects/ilc/soft/v01-17-06/mysql/usr/lib64:/projects/ilc/soft/v01-17-06/gear/v01-04-01/lib:/projects/ilc/soft/v01-17-06/CLHEP/2.1.3.1/lib:/projects/ilc/soft/v01-17-06/ilcutil/v01-02/lib")
    ENDIF()
  ENDFOREACH()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES
    "/home/zhaomr/workdir/cepc/Tracking/000test/build/lib/libmymarlin.so.0.1.0"
    "/home/zhaomr/workdir/cepc/Tracking/000test/build/lib/libmymarlin.so.0.1"
    "/home/zhaomr/workdir/cepc/Tracking/000test/build/lib/libmymarlin.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmymarlin.so.0.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmymarlin.so.0.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmymarlin.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/projects/ilc/soft/v01-17-06/Marlin/v01-05/lib:/projects/ilc/soft/v01-17-06/lcio/v02-05/lib:/projects/ilc/soft/v01-17-06/mysql/usr/lib64:/projects/ilc/soft/v01-17-06/gear/v01-04-01/lib:/projects/ilc/soft/v01-17-06/CLHEP/2.1.3.1/lib:/projects/ilc/soft/v01-17-06/ilcutil/v01-02/lib:::::::::::::::::::::::::::::::::::::::::::::::"
           NEW_RPATH "/home/zhaomr/workdir/cepc/Tracking/000test/lib:/projects/ilc/soft/v01-17-06/Marlin/v01-05/lib:/projects/ilc/soft/v01-17-06/lcio/v02-05/lib:/projects/ilc/soft/v01-17-06/mysql/usr/lib64:/projects/ilc/soft/v01-17-06/gear/v01-04-01/lib:/projects/ilc/soft/v01-17-06/CLHEP/2.1.3.1/lib:/projects/ilc/soft/v01-17-06/ilcutil/v01-02/lib")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/projects/ilc/soft/v01-17-06/mysql/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/zhaomr/workdir/cepc/Tracking/000test/build/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/zhaomr/workdir/cepc/Tracking/000test/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
