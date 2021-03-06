INCLUDE(${CMAKE_SOURCE_DIR}/Builds/Common/OpenSGToolboxTutorialsTest.cmake)
INCLUDE(${CMAKE_SOURCE_DIR}/Builds/Common/OpenSGToolboxLibraryDoc.cmake)
INCLUDE(${CMAKE_SOURCE_DIR}/Builds/Common/OpenSGToolboxTutorialConfig.cmake)
INCLUDE(${CMAKE_SOURCE_DIR}/Builds/Common/OpenSGToolboxSourceGroupFunc.cmake)

SET(LIBRARY_SHORT_NAME Animation)
SET(LIBRARY_NAME OSG${LIBRARY_SHORT_NAME})

IF(NOT BUILD_INPUT)
   MESSAGE(SEND_ERROR "Could not configure ${LIBRARY_SHORT_NAME} because the Input library is not included in this build.  Set BUILD_INPUT to ON")
ELSE(NOT BUILD_INPUT)
   MESSAGE("Configuring ${LIBRARY_SHORT_NAME} Library")
ENDIF(NOT BUILD_INPUT)

#Get a listing of the Header, source, and inline files
FILE(GLOB_RECURSE HEADERS [^~]*.h)
FILE(GLOB_RECURSE SOURCES [^~]*.cpp)
FILE(GLOB_RECURSE INLINES [^~]*.inl)

#Make all of the source groups for the cpp sources
RECURSIVE_DIRECTORY_FIND(${CMAKE_CURRENT_SOURCE_DIR}  "/.svn" ${CMAKE_CURRENT_SOURCE_DIR})

#Definition required when building the library
ADD_DEFINITIONS(-DOSG_COMPILEANIMATIONLIB)

#Include Boost and OpenSG
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS} ${OPENSG_INC_DIR} "./" "${OPENSG_TOOLBOX_BUILD_DIR}/include" "${OPENSG_INPUT_BUILD_DIR}/include")

#Link to bost and OpenSG
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS} ${OPENSG_LIB_DIR} "${OPENSG_TOOLBOX_BUILD_DIR}" "${OPENSG_INPUT_BUILD_DIR}")

#Configure shared library creation
ADD_LIBRARY(${LIBRARY_NAME} SHARED ${HEADERS} ${SOURCES} ${INLINES})
ADD_DEPENDENCIES(${LIBRARY_NAME} OSGToolbox OSGToolbox_headers OSGInput
   OSGInput_headers)

#Header files build
FILE(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include")
FILE(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include/OpenSG")
FILE(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include/OpenSG/${LIBRARY_SHORT_NAME}")
ADD_CUSTOM_TARGET(${LIBRARY_NAME}_headers
                  ALL
                  COMMAND ${CMAKE_SOURCE_DIR}/Builds/Common/CopyIncludes.sh
                  ${CMAKE_SOURCE_DIR}/Builds/Common/
                  ${CMAKE_CURRENT_SOURCE_DIR}
                  ${CMAKE_CURRENT_BINARY_DIR}/include/OpenSG/${LIBRARY_SHORT_NAME}
                  ${LIBRARY_SHORT_NAME}
                  DEPENDS ${HEADERS} ${INLINES})

#Attach all of the Compile flags
SET(CMAKE_CXX_FLAGS_DEBUG "${OPENSG_CXX_FLAGS_DBG} ${OPENSG_CXX_BUILDDLL_FLAGS}")
SET(CMAKE_CXX_FLAGS_DEBUG "${OPENSG_CXX_FLAGS_OPT} ${OPENSG_CXX_BUILDDLL_FLAGS}")

SET_TARGET_PROPERTIES(${LIBRARY_NAME}
   PROPERTIES
   COMPILE_FLAGS "${PLATFORM_COMPILE_FLAGS}"
   LINK_FLAGS_DEBUG "${OPENSG_LIBS_DBG} ${PLATFORM_LINKER_FLAGS}"
   LINK_FLAGS "${OPENSG_LIBS_OPT} ${PLATFORM_LINKER_FLAGS}"
   LINK_FLAGS_MINSIZEREL "${OPENSG_LIBS_OPT} ${PLATFORM_LINKER_FLAGS}"
   LINK_FLAGS_RELWITHDEBINFO "${OPENSG_LIBS_OPT} ${PLATFORM_LINKER_FLAGS}")

#Attach all of the linker libraries
TARGET_LINK_LIBRARIES(${LIBRARY_NAME} ${Boost_LIBRARIES} optimized OSGToolbox
   optimized OSGInput debug OSGToolboxD debug OSGInputD)


#Installing instructions
INSTALL(CODE "MESSAGE(\"Installing ${LIBRARY_NAME}\")")

#Install the headers
INSTALL(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/OpenSG/${LIBRARY_SHORT_NAME}
        DESTINATION include/OpenSG
        COMPONENT headers)

#install the libraries
INSTALL(TARGETS ${LIBRARY_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        COMPONENT optLibs)

#Doxygen documentation
# Generating documentation with doxygen
if(DOXYGEN_EXECUTABLE)
    TOOLBOX_LIBRARY_DOCUMENTATION(${DOXYGEN_EXECUTABLE} ${Project_WC_REVISION}
       ${LIBRARY_SHORT_NAME} ${ENABLE_USER_DOCUMENTATION} ${ENABLE_DEVELOPER_DOCUMENTATION} ${HEADERS} ${INLINES} ${SOURCES})
endif(DOXYGEN_EXECUTABLE)


IF(CONFIGURE_TUTORIALS)
   #Configure the cmake build of the tutorials
   TOOLBOX_TUTORIAL_CONFIG("${CMAKE_CURRENT_SOURCE_DIR}/../Tutorials" "${LIBRARY_SHORT_NAME}")

   #Configure some tests to ensure that the tutorials built
   TOOLBOX_TUTORIALS_TESTS("${CMAKE_CURRENT_SOURCE_DIR}/../Tutorials" "${LIBRARY_SHORT_NAME}")
   
ENDIF(CONFIGURE_TUTORIALS)
