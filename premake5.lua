workspace "Game"
  -- configurations { "Debug", "Release" }
  configurations {"Debug"}

include("conanbuildinfo.premake.lua")

buildoptions { "--std=c++17"}

linkoptions { }

symbols "On"

project "engine"
  kind "SharedLib"
  language "C++"
  targetdir "lib/"

  includedirs {
    conan_includedirs,
    "include"
  }

  libdirs {
    conan_libdirs
  }

  links {
    conan_libs,
    conan_system_libs
  }

  files {
    "src/engine.cpp"
  }

project "game"
  kind "ConsoleApp"
  language "C++"
  targetdir "bin/"

  includedirs {
    conan_includedirs,
    "include"
  }

  libdirs {
    conan_libdirs,
    "lib"
  }

  links {
    conan_libs,
    conan_system_libs,
    "engine"
  }

  files {
    "src/main.cpp"
  }
