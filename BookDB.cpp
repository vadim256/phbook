#include "BookDB.h"

const std::array<const std::string, BookDB::SizeTables> BookDB::arrayTables = { "contacts", "live", "phones"};

const std::string BookDB::name_db("phonebook.sqlite3");

BookDB::ConnectDBError::ConnectDBError(std::string const & what_arg)
: std::runtime_error(what_arg) { }

BookDB::BookDB(std::string const & name_db){
    vecFunc.push_back(&BookDB::CreateTableContacts);
    vecFunc.push_back(&BookDB::CreateTableLive);
    vecFunc.push_back(&BookDB::CreateTablePhones);

    auto result = sqlite3_open_v2(name_db.c_str(), &m_PtrDB, SQLITE_OPEN_CREATE|SQLITE_OPEN_READWRITE, nullptr);
    if(result != SQLITE_OK)
        throw ConnectDBError();

    int index = 0;
    for(auto f : vecFunc){
        if(!(this->IsCreatedTable(arrayTables[index]))){
            (this->*f)();
        }
        ++index;
    }
}

BookDB::~BookDB(){
    sqlite3_close_v2(m_PtrDB);
}

bool BookDB::IsCreatedTable(std::string const & name_table){

    std::string request("SELECT name FROM sqlite_master"
                       " WHERE type='table' AND name='"+ name_table + "';");

    sqlite3_stmt * PtrStmt;
    auto result = sqlite3_prepare_v2(m_PtrDB, request.c_str(), request.size()+1, &PtrStmt, nullptr);
    //assert(result == SQLITE_OK);
    result = sqlite3_step(PtrStmt);
    sqlite3_finalize(PtrStmt);
    if(result == SQLITE_DONE){
            return FALSE;
    } else {
            return TRUE;
    }
}

void BookDB::CreateTableContacts(){
    std::string request("CREATE TABLE contacts("
                         "contact_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                         "first_name_ct VARCHAR(255) NOT NULL,"
                         "last_name_ct VARCHAR(255)"
                         ");");
    sqlite3_stmt * PtrStmt;
    auto result = sqlite3_prepare_v2(m_PtrDB, request.c_str(), request.size()+1, &PtrStmt, nullptr);
    //assert(result == SQLITE_OK);
    result = sqlite3_step(PtrStmt);
    sqlite3_finalize(PtrStmt);
    //assert(result == SQLITE_DONE);
}

void BookDB::CreateTableLive(){
    std::string request("CREATE TABLE live("
                         "live_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                         "name_city VARCHAR(255) NOT NULL, "
                         "FOREIGN KEY(live_id) REFERENCES contacts(contact_id)"
                         ");");
    sqlite3_stmt * PtrStmt;
    auto result = sqlite3_prepare_v2(m_PtrDB, request.c_str(), request.size()+1, &PtrStmt, nullptr);
    //assert(result == SQLITE_OK);
    result = sqlite3_step(PtrStmt);
    sqlite3_finalize(PtrStmt);
    //assert(result == SQLITE_DONE);
}

void BookDB::CreateTablePhones(){
    std::string request("CREATE TABLE phones("
                         "phone_id INTEGER PRIMARY KEY AUTOINCREMENT,"
                         "phone_number VARCHAR(20) NOT NULL,"
                         "contact_id INTEGER NOT NULL,"
                         "FOREIGN KEY(contact_id) REFERENCES contacts(contact_id)"
                         ");");
    sqlite3_stmt * PtrStmt;
    auto result = sqlite3_prepare_v2(m_PtrDB, request.c_str(), request.size()+1, &PtrStmt, nullptr);
    //assert(result == SQLITE_OK);
    result = sqlite3_step(PtrStmt);
    sqlite3_finalize(PtrStmt);
    //assert(result == SQLITE_DONE);
}

void BookDB::SetContact(const Contact & contact) {
    m_CurrentContact = contact;
}

const Contact & BookDB::GetContact(const Contact & contact) const {
    return m_CurrentContact;
}
