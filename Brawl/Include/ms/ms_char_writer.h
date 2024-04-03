#pragma once

#include <StaticAssert.h>
#include <types.h>
#include <nw4r/ut/color.h>

using namespace nw4r::ut;

// Used to print text with a gradient color.
struct ColorRect {
    Color topLeft;
    Color topRight;
    Color bottomLeft;
    Color bottomRight;
};

namespace ms {
    class CharWriter {
    public:
        // These get set by SetColorMapping
        Color m_colorMapping1;  // 0
        Color m_colorMapping2;  // 4
        struct {
            Color m_topLeft;     // 8
            Color m_topRight;    // 12, 0xC
            Color m_bottomLeft;  // 16, 0x10
            Color m_bottomRight; // 20, 0x14
        } m_colorRect; 
        Color m_textColor; // 24, 0x18
        int m_28; // Always 0xFFFFFFFF?, 0x1C
        char m_32[4]; // 0x20
        float m_fontScaleX; // 36, 0x24
        float m_fontScaleY; // 40, 0x28
        float m_xPos; // 44, 0x2C
        float m_yPos; // 48, 0x30
        float m_zPos; // 52, 0x34
        int m_56; // Always = 1?, 0x38
        int m_60; // Always = 1?, 0x3C
        char _64[3]; // Always 0xCCCCFF?, 0x40
        // offset 67
        bool m_isFixedWidth;
        // offset 68
        float m_fixedWidth; // Seems to be -1 if unset.
        // This is the pointer to a font resource.
        // More investigation should be used to determine which class specifically.
        // The melee font which is always loaded seems to be at 0x80497e44
        // offset 72
        void* m_font;
        char _76[4];
        // offset 80
        float m_scale; // World scaler, so it affects positioning too. Usually 1.
        char _84[4];
        // offset 88
        float m_unknownFontWidthModifier; // Usually close to 1, seems to affect width.
        // offset 92
        float m_edgeWidth; // Text outline in units / 6
        // offset 96
        Color m_edgeColor;
        // offset 100
        int m_100;
        float m_104;
        u8 m_108;
        char _109[3];

        CharWriter();
        virtual ~CharWriter();

        /* Setters */
        void SetCursor(float x, float y); // 
        void SetCursor(float x, float y, float z);
        void SetCursorX(float x);
        void SetCursorY(float y);
        void SetCursorZ(float z);
        void SetScale(float x, float y);
        void SetScale(float scale);
        void SetEdge(float width, Color color); // 8006ab20
        // Not sure what this does yet.
        void SetColorMapping(Color a, Color b);
        void SetTextColor(Color textColor);
        void setAlpha(unsigned char alpha);
        void SetFixedWidth(float fixedWidth);
        void EnableFixedWidth(bool enabled);

        /* Getters */
        float getAdjustFontScale() const;
        float GetCursorX() const;
        float GetCursorY() const;
        float GetCursorZ() const;
        float GetFixedWidth() const;
        void* GetFont() const;
        float GetFontAscent() const;
        float GetFontDescent() const;
        float GetFontHeight() const;
        float GetFontWidth() const;
        float GetScaleH() const;
        float GetScaleV() const;
        void GetTextColor() const;


        /* GFX Stuff */
        void SetupGX(); 
        // Called by SetupGX(), presumably with the values in the charwriter already.
        void SetupGXWithColorMapping(Color color1, Color color2);

        /* The magic function. */
        void Print(u16 character);

        // glyphTexture here seems to be a `FontData` pointer, but it's clearly 
        // not the root fontdata, it's the fontData for a specific UTF16 char.
        // This function in general seems like internal API... the print() function
        // sets up its args and calls it.
        void PrintGlyph(double x, double y, double z, const void* glyphTexture); // 0x8007001c
    };
    // Originally 0x70, virtual dtor made it bigger?
    static_assert(sizeof(CharWriter) == 0x74, "Class is the wrong size!");
}