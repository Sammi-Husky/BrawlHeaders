
#include <types.h>
#include <StaticAssert.h>

class gfScene {
public:
    char* m_sceneName;
    virtual void start();
    virtual void process();
    virtual void exit();
    virtual void setModule();

    STATIC_CHECK(sizeof(gfScene) == 8)
};

class gfSequence {
public:
    char* m_sequenceName;
    virtual void start();
    virtual void setNext();
    virtual void exit();

    STATIC_CHECK(sizeof(gfSequence) == 8)
};

class gfSceneManager {
public:
    char _spacer[4];
    gfScene* m_currentScene;
    char _spacer2[16];
    gfScene* m_scenes[100];
    gfSequence* m_sequences[50];
    int m_sceneCount;
    int m_sequenceCount;
    char _spacer3[168];

    gfScene* searchScene(char* sceneName);
    static gfSceneManager* getInstance();

    STATIC_CHECK(sizeof(gfSceneManager) == 800)
};