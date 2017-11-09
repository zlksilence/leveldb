#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>
#include <leveldb/db.h>
using namespace std;
int main(void)
{
	leveldb::DB *db;
	leveldb::Options options;
	options.create_if_missing=true;
	//options.error_if_exists =true;
	leveldb::Status status = leveldb::DB::Open(options,"./testdb",&db);
	assert(status.ok());
	std::string key1="people";
	std::string value1="jason";
	std::string value;
	leveldb::Status s=db->Put(leveldb::WriteOptions(),key1,value1);
	if(s.ok())
		s=db->Get(leveldb::ReadOptions(),"people",&value);
	if(s.ok())
		cout<<value<<endl;
	else
		cout<<s.ToString()<<endl;
	delete db;
	return 0;
}
