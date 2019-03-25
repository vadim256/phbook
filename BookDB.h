#ifndef BOOK_DB_H_
#define BOOK_DB_H_
#include "BookContact.h"
#include <string>
#include <sqlite3.h>
#include <cassert>
#include <stdexcept>
#include <array>
#include <vector>
#include <list>

class BookDB {
public:
    struct ConnectDBError : std::runtime_error {
        explicit ConnectDBError(std::string const & what_arg = "сould not connect to database");
    };

    static const std::string name_db;
    explicit BookDB(std::string const & = name_db);
    ~BookDB();
    BookDB & operator=(const BookDB & ) = delete;
    BookDB(const BookDB &) = delete;

    void SetContact(const Contact &);
    const Contact & GetContact() const;

    void InsertContactDB();
    void UpdateContactDB();
    void DeleteContactDB();

    enum {
        SizeTables = 3
    };

    static const std::array<const std::string, SizeTables> arrayTables;

private:

    bool IsCreatedTable(std::string const &);
    void CreateTableContacts();
    void CreateTableLive();
    void CreateTablePhones();

    using PtrFunc  = void (BookDB::*)();

    sqlite3 * m_PtrDB;
    std::vector<PtrFunc> vecFunc;
    Contact m_CurrentContact;
};

#endif // BOOK_DB_H_
