#include <memory>

#define GL_SILENCE_DEPRECATION
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <iostream>
#include <string>

#include "Automaton.h"
#include "DFA.h"
#include "PDA.h"
#include "NPDA.h"

static void glfw_error_callback(int error, const char *description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

void setup_darcula_style()
{
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;
    
    // Darcula color scheme with purple and green accents
    colors[ImGuiCol_Text]                   = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
    colors[ImGuiCol_TextDisabled]           = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg]               = ImVec4(0.13f, 0.14f, 0.15f, 0.85f);
    colors[ImGuiCol_ChildBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_PopupBg]                = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
    colors[ImGuiCol_Border]                 = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
    colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg]                = ImVec4(0.25f, 0.25f, 0.25f, 0.54f);
    colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.40f, 0.40f, 0.40f, 0.40f);
    colors[ImGuiCol_FrameBgActive]          = ImVec4(0.55f, 0.35f, 0.85f, 0.67f);
    colors[ImGuiCol_TitleBg]                = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
    colors[ImGuiCol_TitleBgActive]          = ImVec4(0.29f, 0.19f, 0.45f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    colors[ImGuiCol_MenuBarBg]              = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
    colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
    colors[ImGuiCol_CheckMark]              = ImVec4(0.26f, 0.80f, 0.46f, 1.00f);
    colors[ImGuiCol_SliderGrab]             = ImVec4(0.55f, 0.35f, 0.85f, 1.00f);
    colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.65f, 0.45f, 0.95f, 1.00f);
    colors[ImGuiCol_Button]                 = ImVec4(0.55f, 0.35f, 0.85f, 0.40f);
    colors[ImGuiCol_ButtonHovered]          = ImVec4(0.55f, 0.35f, 0.85f, 1.00f);
    colors[ImGuiCol_ButtonActive]           = ImVec4(0.45f, 0.25f, 0.75f, 1.00f);
    colors[ImGuiCol_Header]                 = ImVec4(0.55f, 0.35f, 0.85f, 0.31f);
    colors[ImGuiCol_HeaderHovered]          = ImVec4(0.55f, 0.35f, 0.85f, 0.80f);
    colors[ImGuiCol_HeaderActive]           = ImVec4(0.55f, 0.35f, 0.85f, 1.00f);
    colors[ImGuiCol_Separator]              = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
    colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.26f, 0.80f, 0.46f, 0.78f);
    colors[ImGuiCol_SeparatorActive]        = ImVec4(0.26f, 0.80f, 0.46f, 1.00f);
    colors[ImGuiCol_ResizeGrip]             = ImVec4(0.55f, 0.35f, 0.85f, 0.25f);
    colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.55f, 0.35f, 0.85f, 0.67f);
    colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.55f, 0.35f, 0.85f, 0.95f);
    colors[ImGuiCol_Tab]                    = ImVec4(0.18f, 0.18f, 0.18f, 0.86f);
    colors[ImGuiCol_TabHovered]             = ImVec4(0.55f, 0.35f, 0.85f, 0.80f);
    colors[ImGuiCol_TabActive]              = ImVec4(0.35f, 0.22f, 0.55f, 1.00f);
    colors[ImGuiCol_TabUnfocused]           = ImVec4(0.07f, 0.07f, 0.07f, 0.97f);
    colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    
    style.WindowRounding = 5.0f;
    style.FrameRounding = 3.0f;
    style.GrabRounding = 3.0f;
    style.ScrollbarRounding = 5.0f;
    style.TabRounding = 4.0f;
    style.WindowBorderSize = 1.0f;
    style.FrameBorderSize = 0.0f;
    style.PopupBorderSize = 1.0f;
    style.WindowPadding = ImVec2(12.0f, 12.0f);
    style.FramePadding = ImVec2(6.0f, 4.0f);
    style.ItemSpacing = ImVec2(12.0f, 6.0f);
    style.ItemInnerSpacing = ImVec2(6.0f, 6.0f);
    style.ScrollbarSize = 16.0f;
    style.GrabMinSize = 12.0f;
}

struct AutomatonInfo {
    const char* name;
    const char* description;
    const char* success_msg;
    const char* error_msg;
};

static const AutomatonInfo automaton_info[] = {
    {"DFA", "Exactly one '1'", "String has exactly one '1'.", "String does not have exactly one '1'."},
    {"PDA", "0^n 1^(n+1) format", "String follows 0^n 1^(n+1) pattern.", "String does not follow 0^n 1^(n+1) pattern."},
    {"NPDA", "Palindromes", "String is a palindrome.", "String is not a palindrome."}
};

void renderAutomatonInterface(dfa& dfaMachine, pda& pdaMachine, npda& npdaMachine)
{
    static int selected_automaton = 0;
    static char input_buffer[256] = "";
    static std::string result_message = "";
    static bool show_result = false;
    static bool string_accepted = false;
    
    DasAutomat* automatons[] = {&dfaMachine, &pdaMachine, &npdaMachine};
    
    ImGuiIO& io = ImGui::GetIO();
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);
    
    ImGuiWindowFlags flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | 
                            ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | 
                            ImGuiWindowFlags_NoSavedSettings;
    
    ImGui::Begin("Main", nullptr, flags);
    
    ImGui::TextColored(ImVec4(0.55f, 0.35f, 0.85f, 1.0f), "●");
    ImGui::SameLine();
    ImGui::TextColored(ImVec4(0.26f, 0.80f, 0.46f, 1.0f), "Automaton Simulator");
    
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    ImGui::Text("Select Automaton");
    ImGui::Spacing();
    
    ImGui::PushStyleColor(ImGuiCol_CheckMark, ImVec4(0.26f, 0.80f, 0.46f, 1.0f));
    for (int i = 0; i < 3; i++) {
        if (ImGui::RadioButton(automaton_info[i].name, &selected_automaton, i)) {
            show_result = false;
        }
        ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "   %s", automaton_info[i].description);
        ImGui::Spacing();
    }
    ImGui::PopStyleColor();
    
    ImGui::Separator();
    ImGui::Spacing();

    ImGui::Text("Input String");
    ImGui::SetNextItemWidth(-1);
    ImGui::InputTextWithHint("##input", "Enter your string here...", input_buffer, sizeof(input_buffer));
    
    ImGui::Spacing();
    
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.55f, 0.35f, 0.85f, 0.6f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.55f, 0.35f, 0.85f, 0.8f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.45f, 0.25f, 0.75f, 1.0f));
    
    if (ImGui::Button("Process String", ImVec2(-1, 45))) {
        std::string input_string(input_buffer);
        automatons[selected_automaton]->reset();
        string_accepted = automatons[selected_automaton]->read(input_string);
        result_message = string_accepted ? automaton_info[selected_automaton].success_msg 
                                         : automaton_info[selected_automaton].error_msg;
        show_result = true;
    }
    ImGui::PopStyleColor(3);
    
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    if (show_result) {
        ImGui::Text("Result");
        ImGui::Spacing();
        
        if (string_accepted) {
            ImGui::TextColored(ImVec4(0.26f, 0.80f, 0.46f, 1.0f), "ACCEPTED");
            ImGui::TextWrapped("%s", result_message.c_str());
            ImGui::Spacing();
        } else {
            ImGui::TextColored(ImVec4(0.85f, 0.35f, 0.35f, 1.0f), "REJECTED");
            ImGui::TextWrapped("%s", result_message.c_str());
        }
        
        ImGui::Spacing();
        if (ImGui::Button("Clear Result ")) {
            show_result = false;
        }
    }
    
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    if (ImGui::CollapsingHeader("Quick Guide", ImGuiTreeNodeFlags_DefaultOpen)) {
        ImGui::TextColored(ImVec4(0.26f, 0.80f, 0.46f, 1.0f), "DFA:");
        ImGui::TextWrapped("  Try: '010', '1', '101' (exactly one '1')");
        
        ImGui::TextColored(ImVec4(0.55f, 0.35f, 0.85f, 1.0f), "PDA:");
        ImGui::TextWrapped("  Try: '01', '001', '0011' (0^n 1^(n+1) pattern)");
        
        ImGui::TextColored(ImVec4(0.26f, 0.80f, 0.46f, 1.0f), "NPDA:");
        ImGui::TextWrapped("  Try: '101', '0110', 'aba' (palindromes)");
    }
    
    ImGui::End();
}

int main(int, char **)
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) return 1;

#if __APPLE__
    const char *glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#else
    const char *glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#endif

    GLFWwindow *window = glfwCreateWindow( 414,622, "Automaton Simulator", NULL, NULL);
    if (!window) return 1;
    
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW!\n");
        return 1;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    
    io.FontGlobalScale = 1.0f;
    
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    
    setup_darcula_style();

    dfa dfaMachine;
    pda pdaMachine;
    npda npdaMachine;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        glClearColor(0.08f, 0.08f, 0.08f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        renderAutomatonInterface(dfaMachine, pdaMachine, npdaMachine);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
} 