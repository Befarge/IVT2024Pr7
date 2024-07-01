function set_mode_rules()
    --set_toolset("cc", "/opt/homebrew/opt/llvm/bin/clang")
    --set_toolset("c++", "/opt/homebrew/opt/llvm/bin/clang++")
    --set_toolset("ld", "/opt/homebrew/opt/llvm/bin/clang++")
    if is_mode("debug") then
        set_symbols("debug")
        set_optimize("none")
        add_cflags("-Wall")
    elseif is_mode("release") then
        set_symbols("hidden")
        set_optimize("aggressive")
        set_strip("all")
    end
end

target("geomath-static")
    set_languages("cxx11")
    set_kind("static")
    add_includedirs("include")
    add_files("src/**.cpp")
    set_mode_rules()
    --set_policy("build.optimization.lto", true)

    
target("dev")
    set_kind("binary")
    add_deps("geomath-static")
    add_files("examples/dev.cpp")
    add_includedirs("include")
    set_languages("cxx11")
   
    
tests_dir = "tests"
for _, file in ipairs(os.files(tests_dir .. "/**.cpp")) do
    local name = path.basename(file)
    
    target(file:sub(tests_dir:len()+2, -5))
        set_kind("binary")
        set_default(false)
        add_includedirs("include")
        add_deps("geomath-static")
        
        add_files(file)
        add_tests("")
end