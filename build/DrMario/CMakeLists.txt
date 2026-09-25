cmake_minimum_required(VERSION 3.10)
project(DrMario)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -static-libgcc -static-libstdc++")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DKINC_STATIC_COMPILE -DUSE_SDL")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DKINC_STATIC_COMPILE -DUSE_SDL")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DKINC_STATIC_COMPILE -DUSE_SDL -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DKINC_STATIC_COMPILE -DUSE_SDL -DNDEBUG")
include_directories(
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Includes/**"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Includes"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/SDL/include"
  "C:/Program Files (x86)/Visual Leak Detector/include"
)
set(SOURCE_FILES
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_DrMario/Sources/main.cpp"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Includes/Console_Log.h"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Includes/Engine.h"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Includes/File_Log.h"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Includes/IGfx.h"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Includes/IInput.h"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Includes/ILogger.h"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Includes/ISfx.h"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Includes/SDLGfx.h"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Includes/SdlInput.h"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Includes/SdlSfx.h"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Sources/Console_Log.cpp"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Sources/Engine.cpp"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Sources/File_Log.cpp"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Sources/SDLGfx.cpp"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Sources/SdlInput.cpp"
  "D:/Olivier Clermont/Programmation Avancee II/Homer/Prog_Avanc_II_Engine/Sources/SdlSfx.cpp"
)
add_executable(DrMario ${SOURCE_FILES})
target_link_libraries(DrMario
  D:\Olivier Clermont\Programmation Avancee II\Homer\SDL\lib\SDL2
  D:\Olivier Clermont\Programmation Avancee II\Homer\SDL\lib\SDL2main
  D:\Olivier Clermont\Programmation Avancee II\Homer\SDL\lib\SDL2_image
  C:\Program Files (x86)\Visual Leak Detector\lib\Win64\vld
)
