    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _000A
    ScriptEntry _0020
    .short 0xFD13

_000A:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_014 0x7E3
    ScrCmd_035
    ScrCmd_147 1
    ReleaseAll
    End

_0020:
    End

    .byte 0
    .byte 0
