#include "macros/btlcmd.inc"

    .data

_000:
    UpdateVarFromVar OPCODE_SET, BTLVAR_MSG_BATTLER_TEMP, BTLVAR_ATTACKER
    UpdateMonDataFromVar OPCODE_GET, BTLSCR_ATTACKER, BATTLEMON_MAX_HP, BTLVAR_HP_CALC_TEMP
    UpdateVar OPCODE_MUL, BTLVAR_HP_CALC_TEMP, -1
    DivideVarByValue BTLVAR_HP_CALC_TEMP, 4
    UpdateVar OPCODE_FLAG_ON, BTLVAR_BATTLE_CTX_STATUS, SYSCTL_SKIP_SPRITE_BLINK
    Call BATTLE_SUBSCRIPT_UPDATE_HP
    // {0} is hit with recoil!
    PrintMessage pl_msg_00000368_00279, TAG_NICKNAME, BTLSCR_ATTACKER
    Wait 
    WaitButtonABTime 30
    End 
