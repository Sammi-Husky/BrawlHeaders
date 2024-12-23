#pragma once

#include <StaticAssert.h>
#include <mt/mt_vector.h>
#include <types.h>

class Matrix {
private:
    float m_elements[3][4];

public:
    inline float& operator()(int row, int col) {
        return m_elements[row][col];
    }
    inline float operator()(int row, int col) const { // for const objects
        return m_elements[row][col];
    }

    void setIdentity();
    void rotY(float angle);
    inline void rotY(float angle, Matrix* outMatrix) {
        *outMatrix = *this;
        outMatrix->rotY(angle);

    }
    void mul(Matrix* mulMatrix, Matrix* outMatrix);
    void getRotate(Vec3f* outRot);

    inline void getPosition(Vec3f* outPos) {
        outPos->m_x = this->m_elements[0][3];
        outPos->m_y = this->m_elements[1][3];
        outPos->m_z = this->m_elements[2][3];
    }
    inline Vec3f getPosition() {
        Vec3f outPos;
        this->getPosition(&outPos);
        return outPos;
    }

    inline Matrix operator*(Matrix& A) {
        Matrix outMatrix;
        this->mul(&A, &outMatrix);
        return outMatrix;
    }

    inline Matrix(bool noInit = false) {
        if (!noInit) {
            this->setIdentity();
        }
    }
    inline Matrix(Matrix* matrix) {
        *this = *matrix;
    }
    inline Matrix(float f00, float f01, float f02, float f03,
                  float f10, float f11, float f12, float f13,
                  float f20, float f21, float f22, float f23) {
        this->m_elements[0][0] = f00;
        this->m_elements[0][1] = f01;
        this->m_elements[0][2] = f02;
        this->m_elements[0][3] = f03;
        this->m_elements[1][0] = f10;
        this->m_elements[1][1] = f11;
        this->m_elements[1][2] = f12;
        this->m_elements[1][3] = f13;
        this->m_elements[2][0] = f20;
        this->m_elements[2][1] = f21;
        this->m_elements[2][2] = f22;
        this->m_elements[2][3] = f23;
    };

};
static_assert(sizeof(Matrix) == 48, "Class is wrong size!");
