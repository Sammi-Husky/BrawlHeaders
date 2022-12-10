#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <snd/snd_3d_generator.h>

class soSound3dGeneratorAccesser {
protected:
    struct GeneratorInstance {
        int m_0;
        snd3DGenerator m_soundGenerator;
    };

public:
    virtual ~soSound3dGeneratorAccesser();
    virtual void activate(Vec3f* pos);
    virtual void deactivate();
    virtual void getInstance();
};

class soSound3dGeneratorAccesserImpl : public soSound3dGeneratorAccesser {
    GeneratorInstance m_generatorInstance;

public:
    virtual ~soSound3dGeneratorAccesserImpl();
    virtual void activate(Vec3f* pos);
    virtual void deactivate();
    virtual GeneratorInstance* getInstance(int);

    STATIC_CHECK(sizeof(soSound3dGeneratorAccesserImpl) == 16)

};