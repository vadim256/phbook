#include "wx_pch.h"
#include "ContactDialog.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(ContactDialog)
	//*)
#endif
//(*InternalHeaders(ContactDialog)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(ContactDialog)
//*)

BEGIN_EVENT_TABLE(ContactDialog,wxDialog)
	//(*EventTable(ContactDialog)
	//*)
END_EVENT_TABLE()

ContactDialog::ContactDialog(wxWindow* parent)
{
	//(*Initialize(ContactDialog)
	wxXmlResource::Get()->LoadObject(this,parent,_T("ContactDialog"),_T("wxDialog"));
	StaticText1 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT1"));
	TextCtrl1 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL1"));
	StaticText2 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT2"));
	TextCtrl2 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL2"));
	StaticText3 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT3"));
	TextCtrl3 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL3"));
	StaticLine1 = (wxStaticLine*)FindWindow(XRCID("ID_STATICLINE1"));
	Button1 = (wxButton*)FindWindow(XRCID("wxID_OK"));
	Button2 = (wxButton*)FindWindow(XRCID("wxID_CANCEL"));
	Button3 = (wxButton*)FindWindow(XRCID("ID_BUTTON3"));
	Button4 = (wxButton*)FindWindow(XRCID("ID_BUTTON4"));

	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&ContactDialog::OnInit);
	//*)
}

ContactDialog::~ContactDialog()
{
	//(*Destroy(ContactDialog)
	//*)
}


void ContactDialog::OnInit(wxInitDialogEvent& event)
{
}
