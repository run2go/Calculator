// -*- C++ -*-
//
// generated by wxGlade 1.0.5 on Thu Feb  8 21:30:53 2024
//
// Example for compiling a single file project under Linux using g++:
//  g++ MyApp.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp
//
// Example for compiling a multi file project under Linux using g++:
//  g++ main.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp Dialog1.cpp Frame1.cpp
//

#include <wx/wx.h>
#include "CalculatorFrame.h"
#include "ButtonIds.h"

// begin wxGlade: ::extracode
// end wxGlade

CalculatorFrame::CalculatorFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size, long style) : wxFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE)
{
    // begin wxGlade: CalculatorFrame::CalculatorFrame
    SetSize(wxSize(300, 450));
    SetTitle(wxT("frame"));
    Calculator_menubar = new wxMenuBar();
    wxMenu *wxglade_tmp_menu;
    wxMenuItem *wxglade_tmp_item;
    wxglade_tmp_menu = new wxMenu();
    wxglade_tmp_item = wxglade_tmp_menu->Append(wxID_ANY, wxT("Simple"), wxEmptyString, wxITEM_RADIO);
    Bind(wxEVT_MENU, &CalculatorFrame::OnViewSimple, this, wxglade_tmp_item->GetId());
    wxglade_tmp_item = wxglade_tmp_menu->Append(wxID_ANY, wxT("Advanced"), wxEmptyString, wxITEM_RADIO);
    Bind(wxEVT_MENU, &CalculatorFrame::OnViewAdvanced, this, wxglade_tmp_item->GetId());
    wxglade_tmp_item = wxglade_tmp_menu->Append(wxID_ANY, wxT("Programmer"), wxEmptyString, wxITEM_RADIO);
    Bind(wxEVT_MENU, &CalculatorFrame::OnViewProgrammer, this, wxglade_tmp_item->GetId());
    Calculator_menubar->Append(wxglade_tmp_menu, wxT("View"));
    wxglade_tmp_menu = new wxMenu();
    wxglade_tmp_item = wxglade_tmp_menu->Append(wxID_ANY, wxT("Darkmode"), wxEmptyString, wxITEM_CHECK);
    Bind(wxEVT_MENU, &CalculatorFrame::OnDarkModeChange, this, wxglade_tmp_item->GetId());
    wxglade_tmp_menu->Append(256, wxT("Debug"), wxEmptyString, wxITEM_CHECK);
    Bind(wxEVT_MENU, &CalculatorFrame::OnDebugModeChange, this, 256);
    Calculator_menubar->Append(wxglade_tmp_menu, wxT("Edit"));
    wxglade_tmp_menu = new wxMenu();
    Calculator_menubar->Append(wxglade_tmp_menu, wxT("Version"));
    SetMenuBar(Calculator_menubar);
    wxBoxSizer *sizer_main = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *sizer_output = new wxBoxSizer(wxHORIZONTAL);
    sizer_main->Add(sizer_output, 20, wxEXPAND, 0);
    label_output = new wxStaticText(this, wxID_ANY, wxEmptyString);
    label_output->SetFont(wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("Segoe UI")));
    sizer_output->Add(label_output, 0, wxALIGN_CENTER_VERTICAL | wxFIXED_MINSIZE | wxSHAPED, 0);
    wxStaticLine *static_line_separator = new wxStaticLine(this, wxID_ANY);
    sizer_main->Add(static_line_separator, 0, wxEXPAND, 0);
    wxBoxSizer *sizer_input = new wxBoxSizer(wxVERTICAL);
    sizer_main->Add(sizer_input, 80, wxEXPAND, 0);
    sizer_4 = new wxGridSizer(1, 4, 0, 0);
    sizer_input->Add(sizer_4, 1, wxEXPAND, 0);
    button_num_7 = new wxButton(this, ButtonIds::NUM_8, wxT("7"));
    button_num_7->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("Segoe UI")));
    sizer_4->Add(button_num_7, 0, wxEXPAND, 0);
    button_num_8 = new wxButton(this, ButtonIds::NUM_8, wxT("8"));
    button_num_8->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("Segoe UI")));
    sizer_4->Add(button_num_8, 0, wxEXPAND, 0);
    button_num_9 = new wxButton(this, ButtonIds::NUM_9, wxT("9"));
    button_num_9->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("Segoe UI")));
    sizer_4->Add(button_num_9, 0, wxEXPAND, 0);
    button_div = new wxButton(this, ButtonIds::OP_DIV, wxT("/"));
    button_div->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("Segoe UI")));
    sizer_4->Add(button_div, 0, wxEXPAND, 0);
    wxGridSizer *sizer_3 = new wxGridSizer(1, 4, 0, 0);
    sizer_input->Add(sizer_3, 1, wxEXPAND, 0);
    button_num_4 = new wxButton(this, ButtonIds::NUM_4, wxT("4"));
    button_num_4->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("Segoe UI")));
    sizer_3->Add(button_num_4, 0, wxEXPAND, 0);
    button_num_5 = new wxButton(this, ButtonIds::NUM_5, wxT("5"));
    button_num_5->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("Segoe UI")));
    sizer_3->Add(button_num_5, 0, wxEXPAND, 0);
    button_num_6 = new wxButton(this, ButtonIds::NUM_6, wxT("6"));
    button_num_6->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("Segoe UI")));
    sizer_3->Add(button_num_6, 0, wxEXPAND, 0);
    button_mul = new wxButton(this, ButtonIds::OP_MUL, wxT("x"));
    button_mul->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("Segoe UI")));
    sizer_3->Add(button_mul, 0, wxEXPAND, 0);
    wxGridSizer *sizer_2 = new wxGridSizer(1, 4, 0, 0);
    sizer_input->Add(sizer_2, 1, wxEXPAND, 0);
    button_num_1 = new wxButton(this, ButtonIds::NUM_1, wxT("1"));
    button_num_1->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("Segoe UI")));
    sizer_2->Add(button_num_1, 0, wxEXPAND, 0);
    button_num_2 = new wxButton(this, ButtonIds::NUM_2, wxT("2"));
    button_num_2->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("Segoe UI")));
    sizer_2->Add(button_num_2, 0, wxEXPAND, 0);
    button_num_3 = new wxButton(this, ButtonIds::NUM_3, wxT("3"));
    button_num_3->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("Segoe UI")));
    sizer_2->Add(button_num_3, 0, wxEXPAND, 0);
    button_sub = new wxButton(this, ButtonIds::OP_SUB, wxT("-"));
    button_sub->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("Segoe UI")));
    sizer_2->Add(button_sub, 0, wxEXPAND, 0);
    wxGridSizer *sizer_1 = new wxGridSizer(1, 4, 0, 0);
    sizer_input->Add(sizer_1, 1, wxEXPAND, 0);
    button_comma = new wxButton(this, ButtonIds::BT_COMMA, wxT(","));
    button_comma->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("Segoe UI")));
    sizer_1->Add(button_comma, 0, wxEXPAND, 0);
    button_num_0 = new wxButton(this, ButtonIds::NUM_0, wxT("0"));
    button_num_0->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("Segoe UI")));
    sizer_1->Add(button_num_0, 0, wxEXPAND, 0);
    button_eval = new wxButton(this, ButtonIds::BT_EVAL, wxT("="));
    button_eval->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("Segoe UI")));
    sizer_1->Add(button_eval, 0, wxEXPAND, 0);
    button_add = new wxButton(this, ButtonIds::OP_ADD, wxT("+"));
    button_add->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("Segoe UI")));
    sizer_1->Add(button_add, 0, wxEXPAND, 0);

    SetSizer(sizer_main);
    Layout();
    // end wxGlade
}

BEGIN_EVENT_TABLE(CalculatorFrame, wxFrame)
// begin wxGlade: CalculatorFrame::event_table
EVT_BUTTON(ButtonIds::NUM_8, CalculatorFrame::OnButtonPressed)
EVT_BUTTON(ButtonIds::NUM_8, CalculatorFrame::OnButtonPressed)
EVT_BUTTON(ButtonIds::NUM_9, CalculatorFrame::OnButtonPressed)
EVT_BUTTON(ButtonIds::OP_DIV, CalculatorFrame::OnButtonPressed)
EVT_BUTTON(ButtonIds::NUM_4, CalculatorFrame::OnButtonPressed)
EVT_BUTTON(ButtonIds::NUM_5, CalculatorFrame::OnButtonPressed)
EVT_BUTTON(ButtonIds::NUM_6, CalculatorFrame::OnButtonPressed)
EVT_BUTTON(ButtonIds::OP_MUL, CalculatorFrame::OnButtonPressed)
EVT_BUTTON(ButtonIds::NUM_1, CalculatorFrame::OnButtonPressed)
EVT_BUTTON(ButtonIds::NUM_2, CalculatorFrame::OnButtonPressed)
EVT_BUTTON(ButtonIds::NUM_3, CalculatorFrame::OnButtonPressed)
EVT_BUTTON(ButtonIds::OP_SUB, CalculatorFrame::OnButtonPressed)
EVT_BUTTON(ButtonIds::BT_COMMA, CalculatorFrame::OnButtonPressed)
EVT_BUTTON(ButtonIds::NUM_0, CalculatorFrame::OnButtonPressed)
EVT_BUTTON(ButtonIds::BT_EVAL, CalculatorFrame::OnButtonPressed)
EVT_BUTTON(ButtonIds::OP_ADD, CalculatorFrame::OnButtonPressed)
// end wxGlade
END_EVENT_TABLE();

void CalculatorFrame::OnViewSimple(wxCommandEvent &event) // wxGlade: CalculatorFrame.<event_handler>
{
    event.Skip();
    // notify the user that he hasn't implemented the event handler yet
    wxLogDebug(wxT("Event handler (CalculatorFrame::OnViewSimple) not implemented yet"));
}

void CalculatorFrame::OnViewAdvanced(wxCommandEvent &event) // wxGlade: CalculatorFrame.<event_handler>
{
    event.Skip();
    // notify the user that he hasn't implemented the event handler yet
    wxLogDebug(wxT("Event handler (CalculatorFrame::OnViewAdvanced) not implemented yet"));
}

void CalculatorFrame::OnViewProgrammer(wxCommandEvent &event) // wxGlade: CalculatorFrame.<event_handler>
{
    event.Skip();
    // notify the user that he hasn't implemented the event handler yet
    wxLogDebug(wxT("Event handler (CalculatorFrame::OnViewProgrammer) not implemented yet"));
}

void CalculatorFrame::OnDarkModeChange(wxCommandEvent &event) // wxGlade: CalculatorFrame.<event_handler>
{
    event.Skip();
    // notify the user that he hasn't implemented the event handler yet
    wxLogDebug(wxT("Event handler (CalculatorFrame::OnDarkModeChange) not implemented yet"));
}

void CalculatorFrame::OnDebugModeChange(wxCommandEvent &event) // wxGlade: CalculatorFrame.<event_handler>
{
    event.Skip();
    // notify the user that he hasn't implemented the event handler yet
    wxLogDebug(wxT("Event handler (CalculatorFrame::OnDebugModeChange) not implemented yet"));
}

void CalculatorFrame::OnVersion(wxCommandEvent &event) // wxGlade: CalculatorFrame.<event_handler>
{
    event.Skip();
    // notify the user that he hasn't implemented the event handler yet
    wxLogDebug(wxT("Event handler (CalculatorFrame::OnVersion) not implemented yet"));
}

void CalculatorFrame::OnButtonPressed(wxCommandEvent &event) // wxGlade: CalculatorFrame.<event_handler>
{
    event.Skip();
    // notify the user that he hasn't implemented the event handler yet
    wxLogDebug(wxT("Event handler (CalculatorFrame::OnButtonPressed) not implemented yet"));
}

// wxGlade: add CalculatorFrame event handlers
