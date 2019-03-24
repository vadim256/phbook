#ifndef BOOK_DB_H_
#define BOOK_DB_H_
#include <wx/string.h>
#include <sqlite3.h>
#include <cassert>
#include <stdexcept>
#include <array>
#include <vector>

class BookDB {
public:

    struct ConnectDBError : std::runtime_error {
        explicit ConnectDBError(wxString const & what_arg = wxT("сould not connect to database"));
    };

    static const wxString name_db;
    explicit BookDB(wxString const & = name_db);
    ~BookDB();
    BookDB & operator=(const BookDB & ) = delete;
    BookDB(const BookDB &) = delete;


    enum {
        SizeTables = 3
    };
    static const std::array<const wxString, SizeTables> arrayTables;

private:

    bool IsCreatedTable(wxString const &);
    void CreateTableContacts();
    void CreateTableLive();
    void CreateTablePhones();

    sqlite3 * m_PtrDB;
    std::vector<void(*)()> vecFunc;

};
#endif // BOOK_DB_H_
