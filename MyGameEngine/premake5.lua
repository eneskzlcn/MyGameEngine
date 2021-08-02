workspace "MyGameEngine"
    architecture "x64"
    startproject "Sandbox"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }
    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "vendor/GLFW/include"

include "vendor/GLFW"

project "MyGameEngine"

    location "MyGameEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" ..outputdir.. "/%{prj.name}")
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    pchheader "myengpch.h"
    pchsource "MyGameEngine/src/myengpch.cpp"
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "MyGameEngine/MyGameEngine/vendor/spdlog/include",
        "MyGameEngine/src",
         "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
    
    defines
    {
        "MYENG_PLATFORM_WINDOWS",
        "MYENG_BUILD_DLL"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }
    
    filter "configurations:Debug"
        defines 
        {
        "MY_ENG_DEBUG","MYENG_ENABLE_ASSERTS"  
        }
        symbols "On"

    filter "configurations:Release"
        defines "MY_ENG_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "MY_ENG_DIST"
        optimize "On"
    

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" ..outputdir.. "/%{prj.name}")
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "MyGameEngine/MyGameEngine/vendor/spdlog/include",
        "MyGameEngine/src"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
    
    defines
    {
        "MYENG_PLATFORM_WINDOWS"
    }
    links
    {
        "MyGameEngine"
    }
    
    filter "configurations:Debug"
        defines "MY_ENG_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "MY_ENG_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "MY_ENG_DIST"
        optimize "On"
    