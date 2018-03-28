#include "stdafx.h"
#include "PersonListItem.h"

PersonListItem::PersonListItem(Person* person)
{
	Value = person;
}

Person* PersonListItem::GetValue()
{
	return Value;
}