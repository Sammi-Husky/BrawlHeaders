#pragma once

#include <StaticAssert.h>
//#include <so/so_array.h>
#include <types.h>

class soTransitionInfo {
public:
	int m_groupId;
	int m_unitId;
	u32 m_unknown1;
};
static_assert(sizeof(soTransitionInfo) == 0xC, "Class is wrong size!");

class soGeneralTerm {
public:
	// soArrayConstractibleTable<T>, not literally a char array.
	u8 m_animCmdTable[0x10];
};
static_assert(sizeof(soGeneralTerm) == 0x10, "Class is wrong size!");

class soTransitionModule {
public:
	virtual int checkEstablish(soModuleAccesser* accesser, int*, int groupID, u16*, int);
	virtual void enableTerm(int unitID, int groupID);
	virtual void unableTerm(int unitID, int groupID);
	virtual void enableTermAll(int groupID);
	virtual void unableTermAll(int groupID);
	virtual void enableTermGroup(int groupID);
	virtual void unableTermGroup(int groupID);
	virtual bool isEnableTermGroup(int groupID);
	virtual void addTerm(int groupID, int, int unitID, int, u16* option);
	virtual void addGeneralTerm(int groupID, int unitID, soGeneralTerm* term);
	virtual void addGeneralTermLastTerm(int groupID, soGeneralTerm* term);
	virtual void clearTransitionTermAll(int groupID);
	virtual int notifyEventAnimCmd(int commandType, void* commandArgList, u8* option, soModuleAccesser* accesser);
	virtual soTransitionInfo* getLastTransitionInfo();
	virtual ~soTransitionModule();
};

class soTransitionModuleImpl : public soTransitionModule {
private:
	// soArrayVector<soTransitionTermGroup, C>, not literally a char array.
	u8 m_transitionTermGroupArray[0x4];
	int m_groupID;
	soTransitionInfo m_transitionInfo;
public:
	virtual int checkEstablish(soModuleAccesser* accesser, int*, int groupID, u16*, int);
	virtual void enableTerm(int unitID, int groupID);
	virtual void unableTerm(int unitID, int groupID);
	virtual void enableTermAll(int groupID);
	virtual void unableTermAll(int groupID);
	virtual void enableTermGroup(int groupID);
	virtual void unableTermGroup(int groupID);
	virtual bool isEnableTermGroup(int groupID);
	virtual void addTerm(int groupID, int, int unitID, int, u16* option);
	virtual void addGeneralTerm(int groupID, int unitID, soGeneralTerm* term);
	virtual void addGeneralTermLastTerm(int groupID, soGeneralTerm* term);
	virtual void clearTransitionTermAll(int groupID);
	virtual int notifyEventAnimCmd(int commandType, void* commandArgList, u8* option, soModuleAccesser* accesser);
	virtual soTransitionInfo* getLastTransitionInfo();
	virtual ~soTransitionModuleImpl();
};
static_assert(sizeof(soTransitionModuleImpl) == 0x18, "Class is wrong size!");
