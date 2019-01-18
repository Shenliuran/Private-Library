#pragma once
#define LEMMA_NULL Lemma<KeyType, ValueType>()
#include "myList.h"
template<typename KeyType, typename ValueType>
class Lemma
{
public:
	KeyType mKey;
	ValueType mValue;
	Lemma() {}
	Lemma(const KeyType &constKey, const ValueType &constValue) :mKey(constKey), mValue(constValue) {}
	bool operator ==(const Lemma comparedLemma)
	{
		if (comparedLemma.mKey == mKey && comparedLemma.mValue == mValue)
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
	bool __KeyIsExist(const KeyType & matchKey);
protected:
	void _Entry(const KeyType &newKey, const ValueType & newValue);
	ValueType _Read(const KeyType & relativeKey);
public:
	Dictionary() :mSum(0) {}
	ValueType Values(const KeyType &relativeKey);
	void Entry(const KeyType & newKey, const ValueType & newValue);
	bool IsEmpty() { if (mSum == 0) return true; else return false; }
};