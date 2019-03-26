/***************************************************************
 * Name:      BookMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Kondratyuk Vadim (kvadiml256@gmail.com)
 * Created:   2019-03-24
 * Copyright: Kondratyuk Vadim (github.com/vadim256)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "BookMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(BookFrame)
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(BookFrame)
const long BookFrame::ID_SEARCHCTRL1 = wxNewId();
const long BookFrame::ID_LISTBOX1 = wxNewId();
const long BookFrame::ID_TEXTCTRL1 = wxNewId();
const long BookFrame::ID_SPLITTERWINDOW1 = wxNewId();
const long BookFrame::ID_MENUITEM1 = wxNewId();
const long BookFrame::idMenuQuit = wxNewId();
const long BookFrame::idMenuAbout = wxNewId();
const long BookFrame::ID_STATUSBAR1 = wxNewId();
const long BookFrame::idNewContact = wxNewId();
const long BookFrame::idUpdateContact = wxNewId();
const long BookFrame::idDeleteContact = wxNewId();
const long BookFrame::ID_TOOLBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(BookFrame,wxFrame)
    //(*EventTable(BookFrame)
    //*)
END_EVENT_TABLE()

BookFrame::BookFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(BookFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, _("PhoneBook"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(450,500));
    SetMinSize(wxSize(450,500));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    SearchCtrl1 = new wxSearchCtrl(this, ID_SEARCHCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SEARCHCTRL1"));
    BoxSizer3->Add(SearchCtrl1, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer3, 2, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 2);
    SplitterWindow1 = new wxSplitterWindow(this, ID_SPLITTERWINDOW1, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_3DBORDER|wxSP_LIVE_UPDATE|wxDOUBLE_BORDER, _T("ID_SPLITTERWINDOW1"));
    SplitterWindow1->SetMinimumPaneSize(125);
    SplitterWindow1->SetSashGravity(0.5);
    ListBox1 = new wxListBox(SplitterWindow1, ID_LISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    TextCtrl1 = new wxTextCtrl(SplitterWindow1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    SplitterWindow1->SplitVertically(ListBox1, TextCtrl1);
    SplitterWindow1->SetSashPosition(175);
    BoxSizer1->Add(SplitterWindow1, 1, wxALL|wxEXPAND, 2);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Show Dialog"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    ToolBar1 = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER, _T("ID_TOOLBAR1"));
    ToolBarItem1 = ToolBar1->AddTool(idNewContact, _("New "), wxBitmap(wxImage(_T("/home/ameliepulen/project3/phbook/add_contact.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem2 = ToolBar1->AddTool(idUpdateContact, _("Update"), wxBitmap(wxImage(_T("/home/ameliepulen/project3/phbook/update_contact.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem3 = ToolBar1->AddTool(idDeleteContact, _("Delete"), wxBitmap(wxImage(_T("/home/ameliepulen/project3/phbook/delete_contact.png"))), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBar1->Realize();
    SetToolBar(ToolBar1);
    SetSizer(BoxSizer1);
    Layout();
    Center();

    Connect(ID_SPLITTERWINDOW1,wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGING,(wxObjectEventFunction)&BookFrame::OnSplitterWindow1SashPosChanging);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BookFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&BookFrame::OnAbout);
    Connect(idNewContact,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&BookFrame::OnToolBarItem1Clicked);


    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&BookFrame::OnClose);
    //*)
}

BookFrame::~BookFrame()
{
    //(*Destroy(BookFrame)
    //*)
}

void BookFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void BookFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void BookFrame::OnSplitterWindow1SashPosChanging(wxSplitterEvent& event)
{
}

void BookFrame::OnToolBarItem1Clicked(wxCommandEvent& event)
{
    auto dialog = new ContactDialog(nullptr);
    dialog->ShowModal();
}

void BookFrame::OnClose(wxCloseEvent& event)
{
    this->Destroy();
}
