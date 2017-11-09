#include <iostream>
#include "leveldb/db.h"
using namespace std;
using namespace leveldb;
int main() {
    DB *db ;
    Options op;
    op.create_if_missing = true;
    Status s = DB::Open(op,"/tmp/testdb",&db); ///tmp/testdb就是数据库文件
    if(s.ok()){
        cout << "创建成功11111" << endl;
        s = db->Put(WriteOptions(),"abcd","1234");
        if(s.ok()){
            cout << "插入数据成功1111111" << endl;
            string value;
            s = db->Get(ReadOptions(),"abcd",&value);
            if(s.ok()){
                cout << "获取数据成功11111111,value:" << value << endl;
            }
            else{
                cout << "获取数据失败" << endl;
            }
        }
        else{
            cout << "插入数据失败" << endl;
        }
    }
    else{
        cout << "创建数据库失败" << endl;
    }
    delete db;
    cout<<"1212121212"<<endl;
    return 0;
}
