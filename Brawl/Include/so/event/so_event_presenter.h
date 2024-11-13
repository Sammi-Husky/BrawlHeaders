#pragma once

#include <gf/gf_task.h>
#include <so/event/so_event_system.h>
#include <so/so_null.h>
#include <types.h>

class soModuleAccesser;
class StageObject;

template <class T>
class soEventObserver {
public:
    virtual void addObserver(short param1, s8 param2);
    short m_manageID;
    short m_unitID;
    short m_sendID;

    soEventObserver(short unitID) {
        m_manageID = -1;
        m_unitID = unitID;
        m_sendID = -1;
    }

    void removeObserver() {
        if (soEventSystem::getInstance()->m_instanceManager.isContain(m_manageID)) {
            soEventSystem::getInstance()->getManager(m_manageID)->eraseObserver(m_unitID, m_sendID);
        }
        this->m_sendID = -1;
        this->m_manageID = -1;
    }

    ~soEventObserver() {
        removeObserver();
    }

    void initialize(short param1, u8 param2) {
        addObserver(param1, param2);
    }

    void setupObserver(short manageId) {
        bool bVar5 = false;
        bool bVar4 = false;
        bool bVar3 = false;
        bool bVar2 = false;
        if (-1 < m_manageID && -1 < m_unitID) {
            bVar2 = true;
        }
        if (bVar2 && -1 < m_sendID) {
            bVar3 = true;
        }
        if (bVar3) {
            if (soEventSystem::getInstance()->m_instanceManager.isContain(this->m_manageID)) {
                bVar4 = true;
            }
        }
        if (bVar4) {
            if (soEventSystem::getInstance()->getManager(this->m_manageID)->isExist(m_unitID)) {
                bVar5 = true;
            }
        }
        if (bVar5) {
            if (soEventSystem::getInstance()->m_instanceManager.isContain(this->m_manageID)) {
                soEventSystem::getInstance()->getManager(this->m_manageID)->eraseObserver(m_unitID, m_sendID);
            }
            m_sendID = -1;
            m_manageID = -1;
        }
        if (-1 < manageId && -1 < m_unitID) {
            if (soEventSystem::getInstance()->m_instanceManager.isContain(manageId)) {
                soEventManager* eventManager = soEventSystem::getInstance()->getManager(manageId);
                if (!eventManager->isNullUnit(m_unitID)) {
                    int sendId;
                    if (eventManager->isExist(m_unitID)) {
                        soEventUnitWrapper<T>* eventUnit = dynamic_cast<soEventUnitWrapper<T>*>(eventManager->getEventUnit(m_unitID));
                        if (eventUnit == NULL) {
                            sendId = -1;
                        }
                        else {
                            sendId = eventUnit->addObserverSub(static_cast<T*>(this), -1);
                        }
                    }
                    else {
                        sendId = -1;
                    }
                    this->m_sendID = sendId;
                    if (-1 < sendId) {
                        this->m_manageID = manageId;
                    }
                }
            }
        }
    }
};
static_assert(sizeof(soEventObserver<void>) == 0xC, "Class is wrong size!");

template <class T>
class soEventPresenter {
    virtual ~soEventPresenter();

    // TODO: Verify
    char _spacer1[8];
};

class soEventObserverRegistrationDesc : public soNullable {
    virtual ~soEventObserverRegistrationDesc();
    virtual bool checkCollisionHit();
    virtual bool checkCollisionAttack();
    virtual bool checkCollisionCatch();
    virtual bool checkGimmick();
    virtual bool checkStatus();
    virtual bool checkAnimCmd();
    virtual bool checkDamage();
    virtual bool checkLink();
    virtual bool checkSituation();
    virtual bool checkModel();
    virtual bool checkMotion();
    virtual bool checkArticle();
    virtual bool checkItemManage();
    virtual bool checkCapture();
    virtual bool checkCollisionShield();
    virtual bool checkCollisionReflector();
    virtual bool checkCollisionAbsorber();
    virtual bool checkCollisionSearch();
    virtual bool checkTurn();

};
