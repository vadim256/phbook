#include "BookContact.h"

Contact::Contact(const std::string & fname, const std::string & lname,
                 const std::string & phone_number,const std::string & city)
: m_FirstName(fname), m_LastName(lname), m_PhoneNumber(phone_number), m_City(city)
{

}

const std::string & Contact::GetFirstName() const {
    return m_FirstName;
}
void Contact::SetFirstName(const std::string & fname) {
    m_FirstName = fname;
}

const std::string & Contact::GetLastName() const {
    return m_LastName;
}

void Contact::SetLastName(const std::string & lname) {
    m_LastName = lname;
}

const std::string & Contact::GetPhoneNumber() const {
    return m_PhoneNumber;
}

void Contact::SetPhoneNumber(const std::string & phone_number) {
    m_PhoneNumber = phone_number;
}

const std::string & Contact::GetCity() const {
    return m_City;
}

void Contact::SetCity(const std::string & city) {
    m_City = city;
}
