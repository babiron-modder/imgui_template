#include <windows.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include "lua.hpp"

using namespace std;


int main(int argc, char *argv[]) {
	int i;
	// GLFWの初期化
	if (!glfwInit())
		return -1;

	GLFWwindow* window = glfwCreateWindow(640, 480, "ImGui Viewer", NULL, NULL);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	gl3wInit();

	// ImGuiの初期化
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();
	ImGuiIO &io = ImGui::GetIO(); // ここからフォントの追加
	ImVector<ImWchar> ranges;
	ImFontGlyphRangesBuilder builder;
	builder.AddText("―‐∥…‥‘’“”≠≦≧∞∴♂♀′″℃☆★○●◎◇◆□■△▲▽▼※→←↑↓∈∋⊆⊇⊂⊃∪∩∧∨⇒⇔∀∃∠⊥⌒∂∇≡≒≪≫√∽∝∵∫∬Å‰♯♭♪†‡◯ΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩαβγδεζηθικλμνξοπρστυφχψωАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя─│┌┐┘└├┬┤┴┼━┃┏┓┛┗┣┳┫┻╋┠┯┨┷┿┝┰┥┸╂");
	builder.AddRanges(io.Fonts->GetGlyphRangesChineseFull());
	// builder.AddRanges(io.Fonts->GetGlyphRangesJapanese());
	builder.BuildRanges(&ranges);
	io.Fonts->AddFontFromFileTTF("font/mplus-2p-regular.ttf", 16.0f, nullptr, ranges.Data);
	io.Fonts->AddFontDefault();
	io.Fonts->Build();


	while (!glfwWindowShouldClose(window)) {
		static float rgb[3]={0.27f, 0.514f, 0.72f};
		// バッファのクリア
		glClearColor(rgb[0], rgb[1], rgb[2], 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Imguiの初期化
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::StyleColorsLight();

		static int a;
		ImGui::InputInt("hoge", &a);
		static int b[2];
		ImGui::InputInt2("hoge", b);
		static float c;
		ImGui::ProgressBar(c);
		ImGui::SliderFloat("", &c, 0, 1);
		ImGui::SmallButton("miso");
		ImGui::TextWrapped("吾輩は猫である。名前はまだ無い。どこで生まれたか頓と見當がつかぬ。何ても暗薄いじめじめした所でニャー／＼泣いて居た事丈は記憶して居る。吾輩はこゝで始めて人間といふものを見た。然もあとで聞くとそれは書生といふ人間で一番獰惡な種族であつたさうだ。此書生といふのは時々我々を捕へて煮て食ふといふ話である。然し其當時は何といふ考もなかつたから別段恐しいとも思はなかつた。但彼の掌に載せられてスーと持ち上げられた時何だかフハフハした感じが有つた許りである。掌の上で少し落ち付いて書生の顏を見たが所謂人間といふものゝ見始であらう。此の時妙なものだと思つた感じが今でも殘つて居る。第一毛を以て裝飾されべき筈の顏がつる／＼して丸で藥罐だ。其後猫にも大分逢つたがこんな片輪には一度も出會はした事がない。加之顏の眞中が餘りに突起して居る。そうして其穴の中から時々ぷう／＼と烟を吹く。どうも咽せぽくて實に弱つた。是が人間の飮む烟草といふものである事は漸く此頃知つた。");


		// Imguiの画面更新
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		// ダブルバッファのスワップ
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	// GLFWの終了処理
	glfwTerminate();

	return 0;
}
