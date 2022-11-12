
#ifndef blackdog_h
#define blackdog_h

using namespace System;
using namespace System::Data;
using namespace System::Data::Common;
using namespace System::Configuration;

public ref class dataClass {
public:
    String^ ProductName, ^ Brand, ^ Category, ^ Misc;
    int^ quantity, ^ price;
    dataClass^ next;
    bool last = false;
};

public ref class blackdog {
public:
    ConnectionStringSettings^ settings;
    DbProviderFactory^ fac;
    DbConnection^ conn;
    DbCommand^ cmd;

    String^ query;
    int size = 0;
    bool dataContent = false, dataContentLH = false;
    dataClass^ start, ^ distinctLogStart, ^ loghelper;

    void search(String^ data, String^ filter);
    void deleteItem(String^ data);
    void stock_sale_insert(String^ PN, String^ B, String^ C, int^ Q, int^ P);
    void blackdog::log(String^ PN, String^ B, String^ C, int^ Q, int^ Tot);
    void getlog(String^ data);
    bool adminLogin(String^ pass);
    void connect();
    void reset(String^ type);
    void eraseDB();
    void adminChange(String^ pass, String^ upd);
    void getStockStatus();
    void updateSettings(String^ loc, String^ data);
    String^ getSettings(String^ data);
    String^ getStockLow();
    String^ getStockLow(String^ data);
};

#endif