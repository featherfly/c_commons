set_project("c_commons")

-- set xmake minimum version
set_xmakever("2.7.7")

-- set language: c99
stdc = "c99"
set_languages(stdc)

add_rules("mode.debug", "mode.release")

if is_mode("debug") then 
    add_defines("ENABLE_DEBUG")
end
   

target("assemble")
    -- set_kind("object")
    add_includedirs("include")
    add_files("src/*.c")

target("test")
    set_kind("binary")
    add_includedirs("include")
    add_files("src/*.c")
    add_files("test/*.c")

target("test-strings")
    set_kind("binary")
    add_includedirs("include")
    add_files("src/*.c")
    add_files("test/strings/*.c")

target("test-number")
    set_kind("binary")
    add_includedirs("include")
    add_files("test/test_number.c")

target("c_commons")
    -- make as a static/shared library
    set_kind("$(kind)")
    -- set_kind("static")
    add_includedirs("include")
    add_files("src/*.c")

--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro defination
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

