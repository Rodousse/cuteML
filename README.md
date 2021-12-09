# cuteML

cuteML is a qml formatter written in C++17.

Please do have in mind before going ahead this is a **work in progress**. With that in mind, I hope you will find what you desire here in the near future.

## Purpose

The whole purpose comes from the need to have a qml formatter outside of Qt creator itself without the need to have Qt related code anyhow.

The end goal is to generate a clang-format like tool.
The tool will use a description file `.cuteml` with a simple syntax:

```
indentation: 'space'
indentation-size: '4'
...
```

You will say... *Is this inspired from clang-format?*, well yes it is. A tool that is used in the vast majority of C++ projects today, so why not keep this recipe.

cuteML is written in pure C++ only and will hopefully be exported and usable in many IDEs.

## Build

Nothing too fancy, you just need CMake and a C++17 compatible compiler:

```bash
git clone https://github.com/Rodousse/cuteML.git
cd cuteML
mkdir build && cd build
cmake ..
make
```

## Contribute

Let's save this section for later... but PR and issues are obviously welcome.
