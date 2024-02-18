// Calculator Program

/* ### TO DO ###
- define min Windowsize per view
- "Delete" and "Clear" span across two fields
- Unicode for Emoji support > Clipboard svg
- Version/F1 = open repo url
- F2, F3, F4 = change views
- F10 = toggle theme
- F12 = toggle debug
- debugging console
- base convertion
- display/hide elements depending on view
- define Calculator.ico in Calculator.rc file
- dynamically scale button & text sizes
*/

#include <wx/wx.h>
#include "gui/CalculatorFrame.h"
#include "ElementIds.h"

// #include "httplib.h"
// #include "json.hpp"
#include "thirdparty/exprtk.hpp"
#include <sstream>
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
        const std::string &temp = std::to_string(equation);
        typedef exprtk::expression<T> expression_t;
        typedef exprtk::parser<T> parser_t;
        T x;

        expression_t expression;
        parser_t parser;
        parser.compile(temp, expression);

        T result = expression.value();

        return std::to_string(result);
    }
    void OnViewSelection(wxCommandEvent &event)
    {
        int viewSimple;
        int viewAdvanced;
        int viewProgrammer;
        int colSize[6];
        int rowSize[6];

        wxInt16 viewId = event.GetId() - 100;

        wchar_t buffer[64]{};
        wsprintfW(buffer, L"ID: %d", viewId);
        // swprintf_s(buffer, 64, L"ID: %d", viewId);
        toConsole(std::to_string(viewId));

        MessageBox(NULL, buffer, L"<3", MB_OK);
        switch (viewId)
        {
        case 1: // Simple View
        {
            int colValues[] = {0, 8, 8, 8, 8, 0};
            int rowValues[] = {10, 0, 10, 10, 10, 10};
            std::copy(std::begin(colValues), std::end(colValues), colSize);
            std::copy(std::begin(rowValues), std::end(rowValues), rowSize);
            break;
        }
        case 2: // Advanced View
        {
            int colValues[] = {0, 8, 8, 8, 8, 0};
            int rowValues[] = {10, 0, 10, 10, 10, 10};
            std::copy(std::begin(colValues), std::end(colValues), colSize);
            std::copy(std::begin(rowValues), std::end(rowValues), rowSize);
            break;
        }
        case 3: // Programmer View
        {
            int colValues[] = {0, 8, 8, 8, 8, 0};
            int rowValues[] = {10, 0, 10, 10, 10, 10};
            std::copy(std::begin(colValues), std::end(colValues), colSize);
            std::copy(std::begin(rowValues), std::end(rowValues), rowSize);
            break;
        }
        }

        // Create a loop to iterate over the UI elements and hide/show depending on colSize & rowSize
        for (int i = 0; i < 6; ++i)
        {
            if (colSize[i] == 0 && rowSize[i] == 0)
            {
                // Hide UI Element
            }
            else
            {
                // Show UI Element
            }
        }

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
        int currentBase = event.GetId() - 200;
        /*switch (currentBase)
        {
        case 64:

            break;
        case 16:
            break;
        case 10:
            break;
        case 2:
            break;
        }*/
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
    void OnButtonView1(wxCommandEvent &event)
    {
        auto button_id = event.GetId();
        switch (button_id)
        {
        case View1::BT_EVAL:
        {
            // std::string result = MathEvaluate<std::string>(label_input->GetLabelText());
            // TextSet(label_input, result);
            // toConsole(result);
            break;
        }
        case View1::SYM_COMMA:
        {
            TextAdd(label_input, ",");
            break;
        }
        case View1::OP_ADD:
        {
            TextAdd(label_input, "+");
            break;
        }
        case View1::OP_SUB:
        {
            TextAdd(label_input, "-");
            break;
        }
        case View1::OP_MUL:
        {
            TextAdd(label_input, "*");
            break;
        }
        case View1::OP_DIV:
        {
            TextAdd(label_input, "/");
            break;
        }
        case View1::NUM_0:
        {
            TextAdd(label_input, "0");
            break;
        }
        case View1::NUM_1:
        {
            TextAdd(label_input, "1");
            break;
        }
        case View1::NUM_2:
        {
            TextAdd(label_input, "2");
            break;
        }
        case View1::NUM_3:
        {
            TextAdd(label_input, "3");
            break;
        }
        case View1::NUM_4:
        {
            TextAdd(label_input, "4");
            break;
        }
        case View1::NUM_5:
        {
            TextAdd(label_input, "5");
            break;
        }
        case View1::NUM_6:
        {
            TextAdd(label_input, "6");
            break;
        }
        case View1::NUM_7:
        {
            TextAdd(label_input, "7");
            break;
        }
        case View1::NUM_8:
        {
            TextAdd(label_input, "8");
            break;
        }
        case View1::NUM_9:
        {
            TextAdd(label_input, "9");
            break;
        }
        }
    }
    void OnButtonView2(wxCommandEvent &event)
    {
        auto button_id = event.GetId();
        switch (button_id)
        {
        case View2::SYM_PI:
        {
            break;
        }
        case View2::SYM_RECIPROCAL:
        {
            break;
        }
        case View2::SYM_NEGATE:
        {
            break;
        }
        case View2::SYM_FACTORIAL:
        {
            break;
        }
        case View2::SYM_SQRT:
        {
            break;
        }
        case View2::SYM_POW:
        {
            break;
        }
        case View2::SYM_PERCENT:
        {
            break;
        }
        case View2::SYM_BRACKET_OPEN:
        {
            break;
        }
        case View2::SYM_BRACKET_CLOSE:
        {
            break;
        }
        }
    }
    void OnButtonView3(wxCommandEvent &event)
    {
        auto button_id = event.GetId();
        switch (button_id)
        {
        case View3::BT_COPY:
        {
            break;
        }
        case View3::BT_DELETE:
        {
            std::string currentString = TextGet(label_input);
            int newStringLength = currentString.length() - 1;
            std::string newString = currentString.substr(newStringLength);
            TextSet(label_input, newString);
            break;
        }
        case View3::BT_CLEAR:
        {
            TextSet(label_eval, "");
            TextSet(label_input, "");
            TextSet(label_symbol, "");
            break;
        }
        case View3::NUM_A:
        {
            TextAdd(label_input, "A");
            break;
        }
        case View3::NUM_B:
        {
            TextAdd(label_input, "B");
            break;
        }
        case View3::NUM_C:
        {
            TextAdd(label_input, "C");
            break;
        }
        case View3::NUM_D:
        {
            TextAdd(label_input, "D");
            break;
        }
        case View3::NUM_E:
        {
            TextAdd(label_input, "E");
            break;
        }
        case View3::NUM_F:
        {
            TextAdd(label_input, "F");
            break;
        }
        }
    }

    void OnButtonPressed(wxCommandEvent &event)
    {
        std::string button_id_str = event.GetString();

        // Extract the namespace from the button ID string
        std::istringstream iss(button_id_str);
        std::string namespace_str;
        std::getline(iss, namespace_str, ':'); // Get everything before the colon

        // Determine the view based on the extracted namespace
        if (namespace_str == "View1")
        {
            // Buttons for View1 (Simple View)
            OnButtonView1(event);
        }
        else if (namespace_str == "View2")
        {
            // Buttons for View2 (Advanced View)
            OnButtonView2(event);
        }
        else if (namespace_str == "View3")
        {
            // Buttons for View3 (Programmer View)
            OnButtonView3(event);
        }
        else
        {
            // Handle any other cases or errors
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
