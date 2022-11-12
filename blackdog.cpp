#include "blackdog.h"


void blackdog::connect() {
    settings = ConfigurationManager::ConnectionStrings["ARRAY[FOO]"];
    fac = DbProviderFactories::GetFactory(settings->ProviderName);
    conn = fac->CreateConnection();
    conn->ConnectionString = settings->ConnectionString;
    conn->Open();
    cmd = fac->CreateCommand();
    cmd->CommandType = CommandType::Text;
}

void blackdog::eraseDB() {
    query = "DELETE FROM DBmain;";

    cmd->CommandText = query;
    cmd->Connection = conn;
    cmd->ExecuteNonQuery();
}

void blackdog::adminChange(String^ pass, String^ upd){
    query = "UPDATE Administrator SET Pass = '" + pass + "' WHERE Pass = '" + upd + "'";
    cmd->CommandText = query;
    cmd->Connection = conn;
    cmd->ExecuteNonQuery();
}

void blackdog::search(String^ data, String^ filter) {
    dataClass^ str = gcnew dataClass;
    query = "SELECT * FROM DBmain WHERE (" +
        " ProductName LIKE '%" + data + "%' OR" +
        " Brand LIKE '%" + data + "%' OR" +
        " Category LIKE '%" + data + "%' )" +
        " ORDER BY " + filter + "; ";
    cmd->CommandText = query;
    cmd->Connection = conn;
    DbDataReader^ reader = cmd->ExecuteReader();
    start = gcnew dataClass;

    while (reader->Read()) {
        dataClass^ ptr = gcnew dataClass;
        ptr->ProductName = reader->GetString(1);
        ptr->Brand = reader->GetString(2);
        ptr->Category = reader->GetString(3);
        ptr->quantity = reader->GetInt32(4);
        ptr->price = reader->GetInt32(5);
        if (!dataContent) {
            start = ptr;
            str = start;
            dataContent = true;
        }
        else {
            str->next = ptr;
            str = ptr;
        }
    }
    str->last = true;
    reader->Close();
    delete str;
}

void blackdog::getStockStatus(){
    dataClass^ str = gcnew dataClass;
    query = "SELECT * FROM DBmain WHERE Quantity < " + getSettings("StockWarningLevel") + " ORDER BY Quantity ASC";
    cmd->CommandText = query;
    cmd->Connection = conn;
    DbDataReader^ reader = cmd->ExecuteReader();
    start = gcnew dataClass;
    while (reader->Read()) {
        dataClass^ ptr = gcnew dataClass;
        ptr->ProductName = reader->GetString(1);
        ptr->Brand = reader->GetString(2);
        ptr->Category = reader->GetString(3);
        ptr->quantity = reader->GetInt32(4);
        ptr->price = reader->GetInt32(5);
        if (!dataContent) {
            start = ptr;
            str = start;
            dataContent = true;
        }
        else {
            str->next = ptr;
            str = ptr;
        }
    }
    str->last = true;
    reader->Close();
    delete str;
}

String^ blackdog::getSettings(String^ data){
   
    query = "SELECT " + "StockWarningLevel" + " FROM Settings;";
    cmd->CommandText = query;
    cmd->Connection = conn;
    DbDataReader^ reader = cmd->ExecuteReader();
    reader->Read();
    String^ temp = reader->GetString(0);
    reader->Close();
    return temp;

}

void blackdog::updateSettings(String^ loc, String^ data){
    query = "UPDATE Settings SET " + loc + " = " + data + " ;";
    cmd->CommandText = query;
    cmd->Connection = conn;
    cmd->ExecuteNonQuery();

}

String^ blackdog::getStockLow(){
    query = "SELECT COUNT (Quantity) FROM DBmain WHERE Quantity < " + getSettings("StockWarningLevel") + " ;";
    cmd->CommandText = query;
    cmd->Connection = conn;
    DbDataReader^ reader = cmd->ExecuteReader();
    reader->Read();
    String^ temp = "";
    if (reader->GetInt32(0) > 0) {
        temp = "" + reader->GetInt32(0);
    }
    else {
        temp = "0";
    }
    reader->Close();
    return temp;
}

String^ blackdog::getStockLow(String^ data){
    query = "SELECT COUNT (Quantity) FROM DBmain WHERE Quantity < " + data + " ;";
    cmd->CommandText = query;
    cmd->Connection = conn;
    DbDataReader^ reader = cmd->ExecuteReader();
    reader->Read();
    String^ temp = "";
    if (reader->GetInt32(0) > 0) {
        temp = "" + reader->GetInt32(0);
    }
    else {
        temp = "0";
    }
    reader->Close();
    return temp;
}

void blackdog::deleteItem(String^ data) {
    dataClass^ str = gcnew dataClass;
    query = "DELETE * FROM DBmain WHERE " +
        " ProductName = '" + data + "';";
    cmd->CommandText = query;
    cmd->Connection = conn;
    cmd->ExecuteNonQuery();

}

void blackdog::reset(String^ type) {

    if (type == "search results") {
        if (dataContent) {
            dataClass^ str = gcnew dataClass;
            dataContent = false;
            str = start;
            do {
                dataClass^ ptr = str;
                if (str->next != nullptr) {
                    str = str->next;
                }
                delete ptr;
            } while (str->last != true);
            delete start;
            delete str;
        }
    }

    if (type == "loghp results") {
        if (dataContentLH) {
            dataClass^ str = gcnew dataClass;
            dataContentLH = false;
            str = start;
            do {
                dataClass^ ptr = str;
                if (str->next != nullptr) {
                    str = str->next;
                }
                delete ptr;
            } while (str->last != true);
            delete start;
            delete str;
        }
    }
}

void blackdog::stock_sale_insert(String^ PN, String^ B, String^ C, int^ Q, int^ P) {
    int count = 0;
    query = "SELECT COUNT(1) FROM DBmain WHERE ProductName = '" + PN + "'";
    cmd->CommandText = query;
    cmd->Connection = conn;
    count = (int)cmd->ExecuteScalar();
    if (count == 1) {
        query = "UPDATE DBmain SET Quantity = Quantity + " + Q + ", Price = " + P +
            " WHERE ProductName = '" + PN +
            "' ;";
    }
    else {
        query = " INSERT INTO DBmain ( ProductName, Brand, Category, Quantity, Price )" +
            " VALUES ( '" + PN + "', '" + B + "', '" + C + "', '" + Q + "', '" + P + "' ) ";
    }
    cmd->CommandText = query;
    cmd->Connection = conn;
    cmd->ExecuteNonQuery();
}

void blackdog::log(String^ PN, String^ B, String^ C, int^ Q, int^ Tot) {

    System::DateTime date = System::DateTime::Now;
    query = " INSERT INTO DBlog ( ProductName, Brand, Category, Quantity, Cost, LogDate )" +
        " VALUES ( '" + PN + "', '" + B + "', '" + C + "', '" + Q + "', '" + Tot + "', '" + date + "' ) ";
    cmd->CommandText = query;
    cmd->Connection = conn;
    cmd->ExecuteNonQuery();
}

void blackdog::getlog(String^ data) {
  
   
    query = "SELECT * FROM DBlog WHERE LOGDATE LIKE '" + data + "%'";
    cmd->CommandText = query;
    cmd->Connection = conn;
    DbDataReader^ reader = cmd->ExecuteReader();
    dataClass^ str = gcnew dataClass;
    start = gcnew dataClass;
    while (reader->Read()) {
        dataClass^ ptr = gcnew dataClass;
        ptr->ProductName = reader->GetString(1);
        ptr->Brand = reader->GetString(2);
        ptr->Category = reader->GetString(3);
        ptr->quantity = reader->GetInt32(4);
        ptr->price = reader->GetInt32(5);
        ptr->Misc = reader->GetString(6);
        if (!dataContentLH) {
            start = ptr;
            str = start;
            dataContentLH = true;
        }
        else {
            str->next = ptr;
            str = ptr;
        }
    }
    str->last = true;
    reader->Close();
    delete str;

    query = "SELECT SUM(Quantity), ProductName FROM DBlog" + " WHERE LOGDATE LIKE '" + data + "%'" + " GROUP BY ProductName ORDER BY SUM(Quantity) ASC; ";
    cmd->CommandText = query;
    cmd->Connection = conn;

    reader = cmd->ExecuteReader();

    str = gcnew dataClass;
    loghelper = gcnew dataClass;

    while (reader->Read()) {
        dataClass^ ptr = gcnew dataClass;
        ptr->ProductName = Convert::ToString(reader->GetValue(1));
        ptr->quantity = Convert::ToInt32(reader->GetValue(0));
        if (!dataContent) {
            loghelper = ptr;
            str = loghelper;
            dataContent = true;
        }
        else {
            str->next = ptr;
            str = ptr;
        }
    }  
    str->last = true;
    reader->Close();
    delete str;


}

bool blackdog::adminLogin(String^ pass) {
    query = "SELECT COUNT(1) FROM ADMINISTRATOR WHERE Pass = '" + pass + "'";
    cmd->CommandText = query;
    cmd->Connection = conn;
    if ((int)cmd->ExecuteScalar() != 0) {
        return true;
    }
    else {
        return false;
    }
}
