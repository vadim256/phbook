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

	Connect(XRCID("ID_BUTTON4"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ContactDialog::OnButton4Click);
	//*)
	InitTmpVar();
    TransferAndValidateInput();
}

ContactDialog::~ContactDialog()
{
	//(*Destroy(ContactDialog)
	//*)
}


void ContactDialog::OnInit(wxInitDialogEvent& event) {
}

void ContactDialog::TransferAndValidateInput() {

    wxTextValidator tmp1(wxFILTER_EXCLUDE_CHAR_LIST, &m_FullName);
	tmp1.SetCharExcludes(wxString(wxT("1234567890")));
    TextCtrl1->SetValidator(tmp1);

	wxTextValidator tmp2(wxFILTER_INCLUDE_CHAR_LIST, &m_PhoneNumber);
	tmp2.SetCharIncludes(wxString(wxT("1234567890+ ()-")));
	TextCtrl2->SetValidator(tmp2);

    wxTextValidator tmp3(wxFILTER_EXCLUDE_CHAR_LIST, &m_City);
	tmp3.SetCharExcludes(wxString(wxT("1234567890")));
    TextCtrl3->SetValidator(tmp3);
}

const Contact & ContactDialog::GetContact() {

    wxStringTokenizer m_SepareName(m_FullName, wxT(" "));
    m_PrepareContact.SetFirstName((const char*)m_SepareName.GetNextToken().mb_str(wxConvUTF8));
    m_PrepareContact.SetLastName((const char*)m_SepareName.GetNextToken().mb_str(wxConvUTF8));
    m_PrepareContact.SetPhoneNumber((const char *)m_PhoneNumber.mb_str(wxConvUTF8));
    m_PrepareContact.SetCity((const char *)m_City.mb_str(wxConvUTF8));

    return m_PrepareContact;
}

void ContactDialog::SetContact(const Contact & contact){

    m_PrepareContact = contact;
}

void ContactDialog::InitTmpVar() {
    m_FullName = m_PrepareContact.GetFirstName();
    m_FullName += wxString(wxT(" ")) + m_PrepareContact.GetLastName();
    m_PhoneNumber = m_PrepareContact.GetPhoneNumber();
    m_City = m_PrepareContact.GetCity();
}

void ContactDialog::OnButton4Click(wxCommandEvent& event)
{
    this->InitTmpVar();
    TransferDataToWindow();
}
