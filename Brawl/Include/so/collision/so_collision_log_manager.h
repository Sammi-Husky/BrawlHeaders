#pragma once

#include <StaticAssert.h>
#include <gf/gf_task.h>
#include <nw4r/ut/ut_list.h>
#include <so/collision/so_collision_log.h>
#include <sr/sr_common.h>

class soCollisionLogGroupRecord {
public:
    nw4r::ut::List m_logLists[3];
    u32 m_ownerInstanceId;
    u32 m_logGroupIdentity : 8;
    u32 m_referenceCount : 8;
    u32 m_reservedFlags : 15;
    u32 m_isActive : 1;
    nw4r::ut::Link m_link;
};
static_assert(sizeof(soCollisionLogGroupRecord) == 0x34,
    "Collision log-group record size is wrong");
static_assert(offsetof(soCollisionLogGroupRecord, m_link) == 0x2C,
    "Collision log-group record link offset is wrong");

class soCollisionLogManager : public gfTask {
public:
    soCollisionLogManager();
    nw4r::ut::List m_logQueues[7];
    soCollisionLog* m_logRecords;
    nw4r::ut::List m_retainedLogs;
    soCollisionLogGroupRecord* m_logGroupRecordsBuffer;
    nw4r::ut::List m_logGroupRecords;
    u8 m_runtimeState[0x1454];

    void retainLog(soCollisionLog* log);
    soCollisionLog* takeRetainedLog();
    u32 getLogRecordIndex(soCollisionLog* log);
    soCollisionLog* getLogRecord(u32 index);
    u8 takeLogGroupRecordFlags();
    void appendLogGroupRecord(u32 index);
    u8 acquireLogGroup(u32 index, u32* ownerInstanceId);
    void releaseLogGroup(u32 index);
    void releaseLogGroupReference(u32 index);
    void activateLogGroup(u32 index);

    static soCollisionLogManager* getInstance();
};
static_assert(offsetof(soCollisionLogManager, m_retainedLogs) == 0x98,
    "Retained collision-log list offset is wrong");
static_assert(offsetof(soCollisionLogManager, m_logGroupRecords) == 0xA8,
    "Collision log-group record list offset is wrong");
static_assert(sizeof(soCollisionLogManager) == 0x1508,
    "Collision log manager size is wrong");

extern soCollisionLogManager* g_collisionLogManager;

inline soCollisionLogManager* soCollisionLogManager::getInstance() {
    if (g_collisionLogManager == NULL) {
        g_collisionLogManager = new (Heaps::System) soCollisionLogManager;
    }
    return g_collisionLogManager;
}
