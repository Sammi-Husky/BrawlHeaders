#pragma once

#include <ac/ac_anim_cmd_impl.h>
#include <StaticAssert.h>
#include <types.h>

class soGeneralTerm {
public:
	soArrayContractibleTable<acCmdArgConv> m_animCmdTable;
};
static_assert(sizeof(soGeneralTerm) == 0x10, "Class is wrong size!");

class soGeneralTermManager
{
public:
	soGeneralTerm* m_generalTerms;
	s16* m_indices;
	u16 _unk08;
	u16 m_numGeneralTerms;
	// Same as m_generalTerms?
	soGeneralTerm* m_generalTerms2;
	// Same as m_indices?
	s16* m_indices2;
};
extern soGeneralTermManager g_soGeneralTermManager;

class soTransitionInfo {
public:
	int m_groupId;
	int m_unitId;
	u32 _unk08;
};
static_assert(sizeof(soTransitionInfo) == 0xC, "Class is wrong size!");

class soTransitionTerm {
public:
	u8 _unk00[2];
	u16 m_targetKind;
	s16 m_generalTermIndex;
	u8 _unk06[2];

	void addGeneralTerm(soGeneralTerm* termIn);
};
static_assert(sizeof(soTransitionTerm) == 0x8, "Class is wrong size!");

class soTransitionTermGroup {
public:
	u8 _unk00[4];
	soInstanceManagerFullPropertyEccentric<soTransitionTerm> m_transitionTermInstanceManager;
	u32 m_unitID;

	// Creates/locates the entry corresponding to the specified UnitID, and 
	void addTerm(u32 unitId, u32, soTransitionTerm* termIn, u16*);
	// Calls addGeneralTerm on registered transitionTerm whose UnitID matches the supplied value (or the last registered, if -1 is supplied).
	void addGeneralTerm(soTransitionTermGroup* param_1, u32 unitID, soGeneralTerm* termIn);
};
static_assert(sizeof(soTransitionTermGroup) == 0x14, "Class is wrong size!");


class soTransitionModule {
public:
	virtual int checkEstablish(soModuleAccesser* accesser, int*, int groupID, u16*, void* generalTermCachePtr);
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
public:
	soArray<soTransitionTermGroup>* m_transitionTermGroupArray;
	int m_groupID;
	soTransitionInfo m_transitionInfo;
	virtual int checkEstablish(soModuleAccesser* accesser, int*, int groupID, u16*, void* generalTermCachePtr);
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
