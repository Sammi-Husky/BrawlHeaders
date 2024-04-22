#pragma once

#include <StaticAssert.h>
#include <types.h>
#include <nw4r/ut/color.h>

namespace ms {
    class CharWriter {
    public:
        // These get set by SetColorMapping
        nw4r::ut::Color m_colorMapping1;  // 0
        nw4r::ut::Color m_colorMapping2;  // 4
        struct {
            nw4r::ut::Color m_topLeft;     // 8
            nw4r::ut::Color m_topRight;    // 12, 0xC
            nw4r::ut::Color m_bottomLeft;  // 16, 0x10
            nw4r::ut::Color m_bottomRight; // 20, 0x14
        } m_colorRect;
        nw4r::ut::Color m_textColor; // 24, 0x18
        nw4r::ut::Color m_unkColor;  // 28, 0x1C some other color, used by setAlpha if offset 0x20 is 1
        char m_32;    // 0x20, flag used in setAlpha?
        char m_33[3]; // 0x21 // seems to be an int enum?
        float m_fontScaleX; // 36, 0x24
        float m_fontScaleY; // 40, 0x28
        float m_xPos; // 44, 0x2C
        float m_yPos; // 48, 0x30
        float m_zPos; // 52, 0x34
        int m_56; // Always = 1?, 0x38
        int m_60; // Always = 1?, 0x3C
        char _64[2]; // Always 0xCCCC? Might be padding.
        u8 m_alpha; // 66, 0x42
        // offset 67
        bool m_isFixedWidth;
        // offset 68
        float m_fixedWidth; // Seems to be -1 if unset.
        // This is the pointer to a font resource.
        // More investigation should be used to determine which class specifically.
        // The melee font which is always loaded seems to be at 0x80497e44
        // offset 72
        void* m_font;
        char _76[4]; // 0x4C, set to 0 in constructor
        // offset 80
        float m_scale; // 80, 0x50 World scaler, so it affects positioning too. Set to 1 in ctor.
        u8 _84;  // 84, 0x54 // unk flag, set to 0
        u8 _85;  // 85, 0x55 // unk flag, set to 0
        char _86[2];  // 86, 0x56 Looks like padding?
        float m_unknownFontWidthModifier; // 88, 0x58   Usually close to 1, seems to affect width. Set to 1 in ctor
        float m_edgeWidth; // 92, 0x5C Text outline in units / 6, set to 0 in ctor
        nw4r::ut::Color m_edgeColor; // 96, 0x60, set to 0xFF in the constructor, aka black.
        // offset 100
        int m_100; // 100, 0x64, set to 1 in ctor
        float m_104; // 104, 0x68, set to 1.0 in ctor
        u8 m_108; // 108, 0x6C, set to 0 in ctor
        char _109[3];

        CharWriter();
        ~CharWriter();

        /* Setters */
        void SetCursor(float x, float y); // 
        void SetCursor(float x, float y, float z);
        void SetCursorX(float x);
        void SetCursorY(float y);
        void SetCursorZ(float z);
        void SetScale(float x, float y);
        void SetScale(float scale);
        void SetEdge(float width, nw4r::ut::Color color); // 8006ab20
        // Not sure what this does yet.
        void SetColorMapping(nw4r::ut::Color a, nw4r::ut::Color b);
        void SetTextColor(nw4r::ut::Color textColor);
        void SetAlpha(unsigned char alpha); // Doesn't affect edge color it seems.
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
        void SetupGXWithColorMapping(nw4r::ut::Color color1, nw4r::ut::Color color2);

        /* The magic function. */
        void Print(u16 character);

        // glyphTexture here seems to be a `FontData` pointer, but it's clearly 
        // not the root fontdata, it's the fontData for a specific UTF16 char.
        // This function in general seems like internal API... the print() function
        // sets up its args and calls it.
        void PrintGlyph(double x, double y, double z, const void* glyphTexture); // 0x8007001c
    };
    static_assert(sizeof(CharWriter) == 0x70, "Class is the wrong size!");
}
