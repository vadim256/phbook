#include "BookDB.h"
const BookDB::std::array<const wxString, SizeTables> arrayTables = { wxT("contacts"), wxT("live"), wxT("phones")};

const wxString BookDB::name_db(wxT("phonebook.sqlite3"));


BookDB::ConnectDBError::ConnectDBError(std::string const & what_arg)
: std::runtime_error((const char *)what_arg.mb_str(wxConvUTF8)) { }

BookDB::BookDB(wxString const & name_db){
    vecFunc.push_back(&BookDB::CreateTableContacts);
    vecFunc.push_back(&BookDB::CreateTableLive);
    vecFunc.push_back(&BookDB::CreateTablePhones);

    auto result = sqlite3_open16(name_db.mbc_str(), &m_PtrDB);
    if(result != SQLITE_OK)
        throw ConnectDBError();

    auto CallFuncIt = vec.begin();
    for(auto name_tb : arrayTables){
        if(!this->IsCreatedTable(name_tb)){
            (*CallFuncIt)();
        }
        ++CallFuncIt;
    }
}

BookDB::~BookDB(){
    sqlite3_close_v2(m_PtrDB);
}

bool BookDB::IsCreatedTable(wxString const & name_table){

    wxString request;
    request.Printf(wxT("SELECT name FROM sqlite3_master"
                       " WHERE type='table' AND name='%s';"),
                   (const char *)name_table.mb_str(wxConvUTF8));

    sqlite3_stmt * PtrStmt;
    auto result = sqlite3_prepare16_v2(m_PtrDB, request.mb_str(), request.Len()+1, &stmt, nullptr);
    assert(result == SQLITE_OK);
    result = sqlite3_step(PtrStmt);
    sqlite3_finalize(PtrStmt);
    if(result == SQLITE_DONE){
            return FALSE;
    } else {
            return TRUE;
    }
}
void BookDB::CreateTableContacts(){
    wxString request(wxT("CREATE TABLE contacts("
                         "contact_id INTEGER AUTOINCREMENT PRIMARY KEY,"
                         "first_name_ct VARCHAR(255) NOT NULL"
                         "last_name_ct VARCHAR(255)"
                         ");"));
    sqlite3_stmt * PtrStmt;
    auto result = sqlite3_prepare16_v2(m_PtrDB, request.mb_str(), request.Len()+1, &stmt, nullptr);
    assert(result == SQLITE_OK);
    result = sqlite3_step(PtrStmt);
    sqlite3_finalize(PtrStmt);
    assert(result == SQLITE_DONE);
}

void BookDB::CreateTableLive(){
    wxString request(wxT("CREATE TABLE live(
                         "live_id INTEGER AUTOINCREMENT PRIMARY KEY,"
                         "name_city VARCHAR(255) NOT NULL, "
                         "FOREIGN KEY(live_id) REFERENCES contacts(contact_id)"
                         ");"));
    sqlite3_stmt * PtrStmt;
    auto result = sqlite3_prepare16_v2(m_PtrDB, request.mb_str(), request.Len()+1, &stmt, nullptr);
    assert(result == SQLITE_OK);
    result = sqlite3_step(PtrStmt);
    sqlite3_finalize(PtrStmt);
    assert(result == SQLITE_DONE);
}

void BookDB::CreateTablePhones(){
    wxString request(wxT("CREATE TABLE phones(
                         "phone_id INTEGER AUTOINCREMENT PRIMARY KEY,"
                         "phone_number VARCHAR(20) NOT NULL,"
                         "contact_id INTEGER NOT NULL,"
                         "FOREIGN KEY(contact_id) REFERENCES contacts(contact_id)
                         ");"));
    sqlite3_stmt * PtrStmt;
    auto result = sqlite3_prepare16_v2(m_PtrDB, request.mb_str(), request.Len()+1, &stmt, nullptr);
    assert(result == SQLITE_OK);
    result = sqlite3_step(PtrStmt);
    sqlite3_finalize(PtrStmt);
    assert(result == SQLITE_DONE);
}
