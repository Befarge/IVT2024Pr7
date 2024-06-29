for _, file in ipairs(os.files("tests/test_*.cpp")) do
     local name = path.basename(file)
     target(name)
         set_kind("binary")
         set_default(false)
         add_files("tests/" .. name .. ".cpp")
         add_tests("default")
         add_tests("args", {runargs = {"foo", "bar"}})
         add_tests("pass_output", {trim_output = true, runargs = "foo", pass_outputs = "hello foo"})
         add_tests("fail_output", {fail_outputs = {"hello2 .*", "hello xmake"}})
end

target("example_lib")
    set_kind("binary")
    add_files("src/*.cpp")
    add_includedirs("include")
    set_languages("cxx11")