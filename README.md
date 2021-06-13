## imgui ひな形
### clone
```
git clone https://github.com/babiron-modder/imgui_template.git
```
### このファイル構成に至るまで(ファイルの準備方法)
- mingwは事前に準備
- python3系も事前に準備
- glfwはWindows用のものを別で準備する必要がある(32bit)
  - ダウンロード先: https://github.com/glfw/glfw/releases/download/3.3.4/glfw-3.3.4.bin.WIN32.zip
- luaもWindows用のものを別で準備する必要がある(32bit)
  - ダウンロード先: http://luabinaries.sourceforge.net/download.html
- コマンド
```
git submodule add https://github.com/ocornut/imgui.git imgui
git submodule add https://github.com/skaslev/gl3w.git gl3w
git submodule add https://github.com/g-truc/glm.git glm
cd gl3w
python gl3w_gen.py
cd ../
```
