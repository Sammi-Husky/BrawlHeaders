
#include <types.h>

class gfScene {
public:
    char* sceneName;
    virtual void start();
    virtual void process();
    virtual void exit();
    virtual void setModule();
};

class gfSequence {
public:
    char* sequenceName;
    virtual void start();
    virtual void setNext();
    virtual void exit();
};

class gfSceneManager {
    char _spacer[4];
    gfScene* currentScene;
    char _spacer2[16];
    gfScene* scenes[100];
    gfSequence* sequences[50];
    int sceneCount;
    int sequenceCount;
    char _spacer3[168];
};