// Calculator Program
#include <wx/wx.h>

#include "ButtonIds.h"
#include "gui/CalculatorFrame.h"
// #include "httplib.hpp"
// #include "json.hpp"

class WrappedCalculatorFrame : public CalculatorFrame
{
public:
    WrappedCalculatorFrame() : CalculatorFrame(NULL, wxID_ANY, wxEmptyString)
    {
        fontSmall.SetFaceName("Arial");
        fontSmall.SetPointSize(8);
        fontMed.SetFaceName("Arial");
        fontMed.SetPointSize(12);
        fontLarge.SetFaceName("Arial");
        fontLarge.SetPointSize(16);
        label_output->SetFont(fontLarge);
        label_output->SetLabelText("<3");
    }

    ~WrappedCalculatorFrame()
    {
    }

    void AppendString(wxString character)
    {
        auto label_text = label_output->GetLabelText();
        label_text += character;
        label_output->SetLabelText(label_text);
    }

    wxString MathEvaluate(wxString equation)
    {
        label_output->SetFont(fontLarge);
        label_output->SetLabelText(equation);
        return "Yes.";
    }

    void OnButtonPressed(wxCommandEvent &event)
    {
        auto button_id = event.GetId();
        // wxString button_text = event.GetButt
        switch (button_id)
        {
        case ButtonIds::BT_EVAL:
            MathEvaluate(label_output->GetLabelText());
            break;
        case ButtonIds::BT_COMMA:
            AppendString(",");
            break;
        case ButtonIds::OP_ADD:
            AppendString("+");
            break;
        case ButtonIds::OP_SUB:
            AppendString("-");
            break;
        case ButtonIds::OP_MUL:
            AppendString("*");
            break;
        case ButtonIds::OP_DIV:
            AppendString("/");
            break;
        case ButtonIds::NUM_0:
            AppendString("0");
            break;
        case ButtonIds::NUM_1:
            AppendString("1");
            break;
        case ButtonIds::NUM_2:
            AppendString("2");
            break;
        case ButtonIds::NUM_3:
            AppendString("3");
            break;
        case ButtonIds::NUM_4:
            AppendString("4");
            break;
        case ButtonIds::NUM_5:
            AppendString("5");
            break;
        case ButtonIds::NUM_6:
            AppendString("6");
            break;
        case ButtonIds::NUM_7:
            AppendString("7");
            break;
        case ButtonIds::NUM_8:
            AppendString("8");
            break;
        case ButtonIds::NUM_9:
            AppendString("9");
            break;
        }

        // wchar_t buf[64]{};
        // swprintf_s(buf, 64, L"ID: %d", button_id);
        // MessageBox(NULL, buf, L"<3", MB_OK);

        event.WasProcessed(); // Finish processing event
    }
    void OnViewSimple(wxCommandEvent &event)
    {
        MessageBox(NULL, L"Simple Mode", L"<3", MB_OK);
    }
    void OnViewAdvanced(wxCommandEvent &event)
    {
        MessageBox(NULL, L"Advanced Mode", L"<3", MB_OK);
    }
    void OnViewProgrammer(wxCommandEvent &event)
    {
        MessageBox(NULL, L"Programmer Mode", L"<3", MB_OK);
    }
    void OnDarkModeChange(wxCommandEvent &event)
    {
        MessageBox(NULL, L"Dark Mode", L"Pain goes here.", MB_OK);
    }
    void OnVersion(wxCommandEvent &event)
    {
        MessageBox(NULL, L"Version Stuff!", L"<3", MB_OK);
    }
    void OnDebugModeChange(wxCommandEvent &event)
    {
        bool debug_on = !!event.GetInt();

        if (debug_on)
        {
            AllocConsole();                  // allocate/create console
            freopen("CONOUT$", "w", stdout); // redirect print to console
        }
        else
        {
            // Bug closing console again
            _fcloseall(); // fcloseall() is deprecated, use _fcloseall() instead
            // bool success = FreeConsole();
            // printf("%d", success);
        }
    }

private:
    wxString outputText{};

public:
    wxFont fontSmall{};

public:
    wxFont fontMed{};

public:
    wxFont fontLarge{};
};

/// wxWidgets Setup

// Define a new application type, each program should derive a class from wxApp
class MyApp : public wxApp
{
public:
    // override base class virtuals
    // ----------------------------

    // this one is called on application startup and is a good place for the app
    // initialization (doing it here and not in the ctor allows to have an error
    // return: if OnInit() returns false, the application terminates)
    virtual bool OnInit() override;
    virtual int OnExit() override;
};
wxIMPLEMENT_APP(MyApp);

// ----------------------------------------------------------------------------
// the application class
// ----------------------------------------------------------------------------
// 'Main program' equivalent: the program execution "starts" here
bool MyApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    wxInitAllImageHandlers(); // Initialize resource images

    // Create & display frame
    auto frame = new WrappedCalculatorFrame;
    SetTopWindow(frame);
    frame->Center(); // Center Window
    frame->Show();
    return true;
}

int MyApp::OnExit()
{
    return false;
}
