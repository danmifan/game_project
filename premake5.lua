workspace "Game"
  -- configurations { "Debug", "Release" }
  configurations {"Debug"}

include("conanbuildinfo.premake.lua")

buildoptions { "--std=c++17"}

linkoptions { }

symbols "On"


project "imgui"
  kind "SharedLib"
  language "C++"
  targetdir "lib/"

  includedirs {
    "thirdparty/imgui"
  }

  files {
    "thirdparty/imgui/*.cpp"
  }

project "imgui-sfml"
  kind "SharedLib"
  language "C++"
  targetdir "lib/"

  includedirs {
    "thirdparty/imgui",
    "thirdparty/imgui-sfml"
  }

  libdirs {
    "lib"
  }

  links {
    "imgui"
  }

  files {
    "thirdparty/imgui-sfml/*.cpp"
  }

project "engine"
  kind "SharedLib"
  language "C++"
  targetdir "lib/"

  includedirs {
    conan_includedirs,
    "include",
    "thirdparty/imgui",
    "thirdparty/imgui-sfml"
  }

  libdirs {
    "lib",
    conan_libdirs
  }

  links {
    conan_libs,
    conan_system_libs,
    "imgui",
    "imgui-sfml"
  }

  files {
    "src/engine.cpp",
    "src/gui/*.cpp"
  }

project "game"
  kind "ConsoleApp"
  language "C++"
  targetdir "bin/"

  includedirs {
    conan_includedirs,
    "include",
    "thirdparty/imgui",
    "thirdparty/imgui-sfml"
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
