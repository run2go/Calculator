// Calculator Program
#include <wx/wx.h>

#include "ButtonIds.h"
#include "gui/CalculatorFrame.h"
// #include "httplib.hpp"
// #include "json.hpp"

#include "exprtk/exprtk.hpp"
/* ~ToDo
Delete & Clear Buttons spanning
Implement exprtk
*/
class WrappedCalculatorFrame : public CalculatorFrame
{
public:
    WrappedCalculatorFrame() : CalculatorFrame(NULL, wxID_ANY, wxEmptyString)
    {
        this->SetLabel(wxT("Calculator"));
        this->Center(); // Center Window
        // fontSmall.SetFaceName("Arial");
        // fontSmall.SetPointSize(8);
        // fontMed.SetFaceName("Arial");
        // fontMed.SetPointSize(12);
        // fontLarge.SetFaceName("Arial");
        // fontLarge.SetPointSize(16);
        //  label_input->SetFont(fontLarge);
    }

    ~WrappedCalculatorFrame()
    {
    }

    wxString TextGet(wxStaticText *event)
    {
        return event->GetLabelText();
    }
    void TextSet(wxStaticText *event, wxString text)
    {
        event->SetLabelText(text);
    }
    void TextAdd(wxStaticText *event, wxString character)
    {
        auto label = TextGet(event);
        label += character;
        event->SetLabelText(label);
    }

    /*emplate <typename T>
    void trig_function()
    {
        typedef exprtk::symbol_table<T> symbol_table_t;
        typedef exprtk::expression<T> expression_t;
        typedef exprtk::parser<T> parser_t;

        const std::string expression_string =
            "clamp(-1.0,sin(2 * pi * x) + cos(x / 2 * pi),+1.0)";

        T x;

        symbol_table_t symbol_table;
        symbol_table.add_variable("x", x);
        symbol_table.add_constants();

        expression_t expression;
        expression.register_symbol_table(symbol_table);

        parser_t parser;
        parser.compile(expression_string, expression);

        for (x = T(-5); x <= T(+5); x += T(0.001))
        {
            const T y = expression.value();
            printf("%19.15f\t%19.15f\n", x, y);
        }
    }*/

    template <typename T>
    wxString MathEvaluate(wxString equation)
    {
        // const std::string &temp = std::to_string(equation);
        // typedef exprtk::expression<T> expression_t;
        // typedef exprtk::parser<T> parser_t;
        // T x;
        //
        // expression_t expression;
        // parser_t parser;
        // parser.compile(temp, expression);
        //
        // T result = expression.value();
        // Convert result to string
        return "Yes.";
    }
    void OnViewSelection(wxCommandEvent &event)
    {
        wxInt16 viewId = event.GetId() - 100;
        std::string testString = "";
        switch (viewId)
        {
        case 1:
            testString = "1";
            break;
        case 2:
            testString = "2";
            break;
        case 3:
            testString = "3";
            break;
        }
        toConsole(std::to_string(viewId));

        // LPCWSTR testString = L"";
        // MessageBox(NULL, testString, L"<3", MB_OK);

        wchar_t buffer[64]{};
        wsprintfW(buffer, L"ID: %d", viewId);
        // swprintf_s(buffer, 64, L"ID: %d", viewId);

        MessageBox(NULL, buffer, L"<3", MB_OK);

        event.WasProcessed();
    }
    void OnDarkModeChange(wxCommandEvent &event)
    {
        toConsole("Dark Mode");
    }
    void OnVersion(wxCommandEvent &event)
    {
        toConsole("Version");
    }
    void OnDebugModeChange(wxCommandEvent &event)
    {
        bool debugMode = !!event.GetInt();

        if (debugMode)
        {
            AllocConsole();                  // allocate/create console
            freopen("CONOUT$", "w", stdout); // redirect print to console
        }
        else
        {
            // Closing console is bugged
            _fcloseall(); // fcloseall() is deprecated, use _fcloseall() instead
            bool success = FreeConsole();
            printf("%d", success);
        }

        event.WasProcessed();
    }

    void OnBaseSelection(wxCommandEvent &event)
    {
        int16_t selectedBase = 10;
        currentBase = 10;
        toConsole(std::to_string(currentBase));

        event.WasProcessed();
    }
    void OnBaseCopy(wxCommandEvent &event)
    {
        std::string button_number = event.GetString();
        toClipboard(button_number);
        toConsole(button_number);

        event.WasProcessed();
    }
    void OnButtonPressed(wxCommandEvent &event)
    {
        auto button_id = event.GetId();
        switch (button_id)
        {
        case ButtonIds::BT_EVAL:
        {
            std::string result = MathEvaluate<std::string>(label_input->GetLabelText());
            TextSet(label_input, result);
            toConsole(result);
            break;
        }
        case ButtonIds::BT_COPY:
            break;
        case ButtonIds::BT_DELETE:
            break;
        case ButtonIds::BT_CLEAR:
            break;
        case ButtonIds::SYM_PI:
            break;
        case ButtonIds::SYM_RECIPROCAL:
            break;
        case ButtonIds::SYM_NEGATE:
            break;
        case ButtonIds::SYM_FACTORIAL:
            break;
        case ButtonIds::SYM_SQRT:
            break;
        case ButtonIds::SYM_POW:
            break;
        case ButtonIds::SYM_PERCENT:
            break;
        case ButtonIds::SYM_BRACKET_OPEN:
            break;
        case ButtonIds::SYM_BRACKET_CLOSE:
            break;
        case ButtonIds::SYM_COMMA:
            TextAdd(label_input, ",");
            break;
        case ButtonIds::OP_ADD:
            TextAdd(label_input, "+");
            break;
        case ButtonIds::OP_SUB:
            TextAdd(label_input, "-");
            break;
        case ButtonIds::OP_MUL:
            TextAdd(label_input, "*");
            break;
        case ButtonIds::OP_DIV:
            TextAdd(label_input, "/");
            break;
        case ButtonIds::NUM_0:
            TextAdd(label_input, "0");
            break;
        case ButtonIds::NUM_1:
            TextAdd(label_input, "1");
            break;
        case ButtonIds::NUM_2:
            TextAdd(label_input, "2");
            break;
        case ButtonIds::NUM_3:
            TextAdd(label_input, "3");
            break;
        case ButtonIds::NUM_4:
            TextAdd(label_input, "4");
            break;
        case ButtonIds::NUM_5:
            TextAdd(label_input, "5");
            break;
        case ButtonIds::NUM_6:
            TextAdd(label_input, "6");
            break;
        case ButtonIds::NUM_7:
            TextAdd(label_input, "7");
            break;
        case ButtonIds::NUM_8:
            TextAdd(label_input, "8");
            break;
        case ButtonIds::NUM_9:
            TextAdd(label_input, "9");
            break;
        case ButtonIds::NUM_A:
            TextAdd(label_input, "A");
            break;
        case ButtonIds::NUM_B:
            TextAdd(label_input, "B");
            break;
        case ButtonIds::NUM_C:
            TextAdd(label_input, "C");
            break;
        case ButtonIds::NUM_D:
            TextAdd(label_input, "D");
            break;
        case ButtonIds::NUM_E:
            TextAdd(label_input, "E");
            break;
        case ButtonIds::NUM_F:
            TextAdd(label_input, "F");
            break;
        }

        event.WasProcessed();
    }
    void toConsole(const std::string &s) // Write to console if in debug mode
    {
        if (debugMode)
            std::cout << s << std::endl;
    }

    void toClipboard(const std::string &s) // Write string to clipboard
    {
        OpenClipboard(0);
        EmptyClipboard();
        HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size());
        if (!hg)
        {
            CloseClipboard();
            return;
        }
        memcpy(GlobalLock(hg), s.c_str(), s.size());
        GlobalUnlock(hg);
        SetClipboardData(CF_TEXT, hg);
        CloseClipboard();
        GlobalFree(hg);
    }

private:
    bool debugMode = false;
    wxInt16 currentBase = 10;
    wxFloat64 lastResult{};
    wxString outputText{};
    wxFont fontSmall{};
    wxFont fontMed{};
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
    frame->Show();
    return true;
}

int MyApp::OnExit()
{
    return false;
}
