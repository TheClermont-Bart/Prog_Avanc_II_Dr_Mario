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
  "C:/Users/ocler/Documents/Ecole/Prog_Avanc_II_Dr_Mario/Prog_Avanc_II_Engine/Includes/**"
  "C:/Users/ocler/Documents/Ecole/Prog_Avanc_II_Dr_Mario/Prog_Avanc_II_Engine/Includes"
  "C:/Users/ocler/Documents/Ecole/Prog_Avanc_II_Dr_Mario/SDL/include"
  "C:/Program Files (x86)/Visual Leak Detector/include"
)
set(SOURCE_FILES
  "C:/Users/ocler/Documents/Ecole/Prog_Avanc_II_Dr_Mario/Prog_Avanc_II_DrMario/Sources/main.cpp"
  "C:/Users/ocler/Documents/Ecole/Prog_Avanc_II_Dr_Mario/Prog_Avanc_II_Engine/Includes/Console_Log.h"
  "C:/Users/ocler/Documents/Ecole/Prog_Avanc_II_Dr_Mario/Prog_Avanc_II_Engine/Includes/Engine.h"
  "C:/Users/ocler/Documents/Ecole/Prog_Avanc_II_Dr_Mario/Prog_Avanc_II_Engine/Includes/File_Log.h"
  "C:/Users/ocler/Documents/Ecole/Prog_Avanc_II_Dr_Mario/Prog_Avanc_II_Engine/Includes/IGfx.h"
  "C:/Users/ocler/Documents/Ecole/Prog_Avanc_II_Dr_Mario/Prog_Avanc_II_Engine/Includes/IInput.h"
  "C:/Users/ocler/Documents/Ecole/Prog_Avanc_II_Dr_Mario/Prog_Avanc_II_Engine/Includes/ILogger.h"
  "C:/Users/ocler/Documents/Ecole/Prog_Avanc_II_Dr_Mario/Prog_Avanc_II_Engine/Includes/SDLGfx.h"
  "C:/Users/ocler/Documents/Ecole/Prog_Avanc_II_Dr_Mario/Prog_Avanc_II_Engine/Includes/SdlInput.h"
  "C:/Users/ocler/Documents/Ecole/Prog_Avanc_II_Dr_Mario/Prog_Avanc_II_Engine/Sources/Console_Log.cpp"
  "C:/Users/ocler/Documents/Ecole/Prog_Avanc_II_Dr_Mario/Prog_Avanc_II_Engine/Sources/Engine.cpp"
  "C:/Users/ocler/Documents/Ecole/Prog_Avanc_II_Dr_Mario/Prog_Avanc_II_Engine/Sources/File_Log.cpp"
  "C:/Users/ocler/Documents/Ecole/Prog_Avanc_II_Dr_Mario/Prog_Avanc_II_Engine/Sources/SDLGfx.cpp"
  "C:/Users/ocler/Documents/Ecole/Prog_Avanc_II_Dr_Mario/Prog_Avanc_II_Engine/Sources/SdlInput.cpp"
)
add_executable(DrMario ${SOURCE_FILES})
target_link_libraries(DrMario
  C:\Users\ocler\Documents\Ecole\Prog_Avanc_II_Dr_Mario\SDL\lib\SDL2
  C:\Users\ocler\Documents\Ecole\Prog_Avanc_II_Dr_Mario\SDL\lib\SDL2main
  C:\Users\ocler\Documents\Ecole\Prog_Avanc_II_Dr_Mario\SDL\lib\SDL2_image
  C:\Program Files (x86)\Visual Leak Detector\lib\Win64\vld
)
