#include "wx_pch.h"
#include "ContactDialog.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(ContactDialog)
	#include <wx/string.h>
	#include <wx/intl.h>
	//*)
#endif
//(*InternalHeaders(ContactDialog)
//*)

//(*IdInit(ContactDialog)
const long ContactDialog::ID_STATICTEXT1 = wxNewId();
const long ContactDialog::ID_TEXTCTRL1 = wxNewId();
const long ContactDialog::ID_STATICTEXT2 = wxNewId();
const long ContactDialog::ID_TEXTCTRL2 = wxNewId();
const long ContactDialog::ID_STATICTEXT3 = wxNewId();
const long ContactDialog::ID_TEXTCTRL3 = wxNewId();
const long ContactDialog::ID_STATICTEXT4 = wxNewId();
const long ContactDialog::ID_TEXTCTRL4 = wxNewId();
const long ContactDialog::ID_PANEL1 = wxNewId();
const long ContactDialog::ID_BUTTON1 = wxNewId();
const long ContactDialog::ID_BUTTON2 = wxNewId();
const long ContactDialog::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ContactDialog,wxDialog)
	//(*EventTable(ContactDialog)
	//*)
END_EVENT_TABLE()

ContactDialog::ContactDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ContactDialog)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer6;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Control contact"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(300,300));
	Move(wxDefaultPosition);
	SetMinSize(wxSize(300,300));
	SetMaxSize(wxSize(300,300));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	FlexGridSizer1 = new wxFlexGridSizer(2, 2, 10, wxDLG_UNIT(Panel1,wxSize(20,0)).GetWidth());
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("First name:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 0, wxALL|wxALIGN_LEFT, 1);
	TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RICH2|wxTE_CENTRE|wxRAISED_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer2->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxSHAPED, 1);
	FlexGridSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 1);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Second name:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer3->Add(StaticText2, 0, wxALL|wxALIGN_LEFT, 1);
	TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RICH2|wxTE_CENTRE|wxRAISED_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer3->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 1);
	FlexGridSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND, 1);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Phone number:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer4->Add(StaticText3, 0, wxALL|wxALIGN_LEFT, 1);
	TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RICH2|wxTE_CENTRE|wxRAISED_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	BoxSizer4->Add(TextCtrl3, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 1);
	FlexGridSizer1->Add(BoxSizer4, 1, wxALL|wxEXPAND, 1);
	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Live city:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer5->Add(StaticText4, 0, wxALL|wxALIGN_LEFT, 1);
	TextCtrl4 = new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RICH2|wxTE_CENTRE|wxRAISED_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	BoxSizer5->Add(TextCtrl4, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED, 1);
	FlexGridSizer1->Add(BoxSizer5, 1, wxALL|wxEXPAND, 1);
	Panel1->SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(Panel1);
	FlexGridSizer1->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND, 10);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer6->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Button2 = new wxButton(this, ID_BUTTON2, _("Reset"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer6->Add(Button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Button3 = new wxButton(this, ID_BUTTON3, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer6->Add(Button3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BoxSizer1->Add(BoxSizer6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();
	Center();
	//*)
}

ContactDialog::~ContactDialog()
{
	//(*Destroy(ContactDialog)
	//*)
}

