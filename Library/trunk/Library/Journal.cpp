#include "Journal.h"

Journal::Journal(long CID,string JN,int journal_num):BaseBook(CID),_journal_name(JN),_journal_num(journal_num)//c'tor
{
	_borrow_days=7;
}
