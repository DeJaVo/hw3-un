#include "Journal.h"

Journal::Journal(long CID,string JN,int journal_num):BaseBook(CID),_journal_name(JN),_journal_num(journal_num)
{
	_borrow_days=7;
}

//bool Journal::operator==(const Journal& J)
//{
//	return _CatalogId==J.getCatalogId()?true:false;
//}
