
git submodule init
git submodule update
git submodule add https://github.com/ocornut/imgui.git imgui
git submodule add https://github.com/skaslev/gl3w.git gl3w
git submodule add https://github.com/g-truc/glm.git glm
cd gl3w
python gl3w_gen.py
cd ../
mingw32-make run
