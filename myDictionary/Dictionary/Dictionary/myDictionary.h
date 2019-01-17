#pragma once
#include "myList.h"
template<typename KeyType, typename ValueType>
class Lemma
{
public:
	KeyType mKey; ValueType mValue;
	Lemma() :mKey(KeyType(0)), mValue(ValueType(0)) {}
	Lemma(const KeyType &constKey, const ValueType &constValue) :mKey(constKey), mValue(constValue) {}
	bool operator ==(const Lemma comparedLemma)
	{
		if (comparedLemma.mKey == mKey)
			return true;
		else
			return false;
	}
	friend bool operator ==(const Lemma origianlLemma, const Lemma comparedLemma)
	{
		if (origianlLemma.mKey == comparedLemma.mKey
			&& origianlLemma.mValue == comparedLemma.mValue)
			return true;
		else
			return false;
	}
};


template<typename KeyType, typename ValueType>
class Dictionary:private Lemma<KeyType, ValueType>
{
private:
	int mSum;
	MyList<Lemma<KeyType, ValueType> > mLemmaList;
protected:
	void _Entry(const KeyType &newKey, const ValueType &newValue);
	Lemma<KeyType, ValueType> _Read(const KeyType &searchKey);
	bool _IsEmpty() { if (mSum == 0) return true; else return false; }
public:
	Dictionary() :mSum(0) {}
	ValueType Values(const KeyType &relativeKey);
};