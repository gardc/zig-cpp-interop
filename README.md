Test project to show how C++ and Zig can interchangeably call function from both languages, and compile to a single binary.

This works by exposing a C API from the C++ source defining an export interface, and by defining extern functions and data in Zig by using the `extern` keyword. In `build.zig` the build process is neatly defined where one can extend it by adding C/C++ dependencies and which files to include and build. `LibCpp` is also enabled and linked to the main executable in `build.zig`:

```zig
const exe = b.addExecutable(.{
    .name = "zig-cpp-test",
    .root_source_file = b.path("src/main.zig"),
    .target = target,
    .optimize = optimize,
});

// add the C++ source files to the executable
exe.addCSourceFiles(.{
    .root = b.path("cpp-src/"),
    .files = &.{"wrapper.cpp"},
});
exe.installHeadersDirectory(b.path("cpp-src/"), "", .{
    .include_extensions = &.{"h"},
});
exe.linkLibCpp();
```
