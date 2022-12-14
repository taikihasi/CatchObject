#include "ObjectBase.h"

ObjectBase::ObjectBase()
{
	m_pMain = nullptr;
	m_isExist = false;
}

bool ObjectBase::isCol(ObjectBase& target)
{
	// 存在しない物体は当たらない
	if (!m_isExist)	return false;
	if (!target.isExist())	return false;
	// Noneは何にもぶつからない
	if (getColType() == ColType::kNone)	return false;
	if(getTargetColType() == ColType::kNone)	return false;
	// 自身がぶつかる対象以外にはぶつからない
	if (getTargetColType() != target.getColType())	return false;

	if (target.getRight() < getLeft())	return false;
	if (target.getLeft() > getRight())	return false;
	if (target.getTop() > getBottom())	return false;
	if (target.getBottom() < getTop())	return false;
	return true;
}