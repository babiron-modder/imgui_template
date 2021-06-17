
rd .git
git init
rd gl3w /S /Q
rd imgui /S /Q
rd glm /S /Q
git init
git submodule add https://github.com/ocornut/imgui.git imgui
git submodule add https://github.com/skaslev/gl3w.git gl3w
git submodule add https://github.com/g-truc/glm.git glm
git submodule init
git submodule update
cd gl3w
python gl3w_gen.py
cd ../
mingw32-make run
