#include"myDictionary.h"
template<typename KeyType, typename ValueType>
void Dictionary<KeyType, ValueType>::_Entry(const KeyType & newKey, const ValueType & newValue)
{
	
	Lemma<KeyType, ValueType> newLemma;
	newLemma.mKey = newKey;
	newLemma.mValue = newValue;
	ListNode< Lemma<KeyType, ValueType> > newNode;
	newNode.elem = newLemma;
	mLemmaList.push_back(newNode);
	mSum = mLemmaList.getSize();
}

template<typename KeyType, typename ValueType>
Lemma<KeyType, ValueType> Dictionary<KeyType, ValueType>::_Read(const KeyType & searchKey)
{
	Lemma<KeyType, ValueType> temp;
	temp.mKey = searchKey;
	int record = mLemmaList.searchByElem(temp);
	if (record == -1)
	{
		cout << "there is not such lemma, can not be read!!" << endl;
		return Lemma<KeyType, ValueType>();
	}
	else
	{
		return mLemmaList[record];
	}
}
