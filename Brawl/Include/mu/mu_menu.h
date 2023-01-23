#pragma once

class muMenu
{
public:
    //    int activeRumbleController;
    //    int globalRumbleSetting;

    static void loadMenuSound();
    static bool isLoadFinishMenuSound();
    static int exchangeSelchkind2SelCharVoice(int id);
    static int exchangeSelCharVoice2SelCharVoiceLengthE(int id);
    static int exchangeSelCharVoice2SelCharVoiceLengthJ(int id);
    static int exchangeGmCharacterKind2MuStockchkind(int id);
    static int exchangeGmCharacterKind2Something(int id);
    static void startRumbleController(int controller, int rumbleStrength, int rumbleSetting);
};
