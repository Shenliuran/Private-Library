#include"myDictionary.h"
template<typename KeyType, typename ValueType>
bool Dictionary<KeyType, ValueType>::__KeyIsExist(const KeyType & matchKey)
{
	for (int i = 1; i <= mSum; i++)
	{
		Lemma<KeyType, ValueType> temp;
		temp = mLemmaList[i];
		if (temp.mKey == matchKey)
			return true;
	}
	return false;
}

template<typename KeyType, typename ValueType>
void Dictionary<KeyType, ValueType>::_Entry(const KeyType & newKey, const ValueType & newValue)
{
	if (__KeyIsExist(newKey) == true)
		cout << "writer error!!" << endl;
	else
	{
		Lemma<KeyType, ValueType> newLemma;
		newLemma.mKey = newKey;
		newLemma.mValue = newValue;
		mLemmaList.push_back(newLemma);
		mSum = mLemmaList.getSize();
	}
}
template<typename KeyType, typename ValueType>
ValueType Dictionary<KeyType, ValueType>::_Read(const KeyType & relativeKey)
{
	for (int i = 1; i <= mSum; i++)
	{
		Lemma<KeyType, ValueType> temp;
		temp = mLemmaList[i];
		if (relativeKey == temp.mKey)
			return temp.mValue;
	}
	return ValueType();
}

template<typename KeyType, typename ValueType>
ValueType Dictionary<KeyType, ValueType>::Values(const KeyType & relativeKey)
{
	if (_Read(relativeKey) == ValueType())
	{
		cout << "there is not such lemma!!" << endl;
		return ValueType();
	}
	else
		return _Read(relativeKey);
}
template<typename KeyType, typename ValueType>
void Dictionary<KeyType, ValueType>::Entry(const KeyType & newKey, const ValueType & newValue)
{
	if (__KeyIsExist(newKey) == true)
	{
		cout << "writer error!!" << endl;
		return;
	}
	else
		_Entry(newKey, newValue);
}
