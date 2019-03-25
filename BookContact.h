
#ifndef BOOK_CONTACT_H_
#define BOOK_CONTACT_H_
#include <string>
struct Contact {
    explicit Contact(const std::string & = "",
                     const std::string & = "",
                     const std::string & = "",
                     const std::string & = ""
                    );
    Cotact(const Contact &) = default;
    Contact & operator=(const Contact &) = default;
    ~Contact() = default;
    const std::string & GetFirstName() const;
    void SetFirstName(const std::string &);

    const std::string & GetLastName() const;
    void SetLastName(const std::string &);

    const std::string & GetPhoneNumber() const;
    void SetPhoneNumber(const std::string &);

    const std::string & GetCity() const;
    void SetCity(const std::string &);
private:
    std::string m_FirstName, m_LastName, m_PhoneNumber, m_City;

};


#endif // BOOK_CONTACT_H_
