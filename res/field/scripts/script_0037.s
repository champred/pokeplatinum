    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _0012
    ScriptEntry _0028
    ScriptEntry _003E
    ScriptEntry _0056
    .short 0xFD13

_0012:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_014 0x7E3
    ScrCmd_035
    ScrCmd_147 1
    ReleaseAll
    End

_0028:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_014 0x7E3
    ScrCmd_035
    ScrCmd_148 16
    ReleaseAll
    End

_003E:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_0D1 0, 24
    Message 0
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0056:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_0D1 0, 57
    Message 1
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

    .byte 0
    .byte 0
