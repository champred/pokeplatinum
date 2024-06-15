    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _008D
    ScriptEntry _00A0
    ScriptEntry _00FA
    ScriptEntry _0111
    ScriptEntry _013D
    ScriptEntry _0150
    ScriptEntry _0022
    ScriptEntry _0128
    .short 0xFD13

_0022:
    GetTimePeriod 0x4000
    GoToIfEq 0x4000, 0, _0069
    GoToIfEq 0x4000, 1, _007B
    GoToIfEq 0x4000, 2, _007B
    GoToIfEq 0x4000, 3, _007B
    GoToIfEq 0x4000, 4, _007B
    End

_0069:
    ClearFlag 0x273
    ClearFlag 0x275
    SetFlag 0x272
    SetFlag 0x274
    End

_007B:
    ClearFlag 0x272
    ClearFlag 0x274
    SetFlag 0x273
    SetFlag 0x275
    End

_008D:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 0
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_00A0:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    GoToIfSet 205, _00E5
    Message 1
    SetVar 0x8004, 0x189
    SetVar 0x8005, 1
    ScrCmd_07D 0x8004, 0x8005, 0x800C
    GoToIfEq 0x800C, 0, _00F0
    ScrCmd_014 0x7FC
    SetFlag 205
    GoTo _00E5

_00E5:
    Message 2
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_00F0:
    ScrCmd_014 0x7E1
    CloseMessage
    ReleaseAll
    End

_00FA:
    ScrCmd_036 5, 1, 0, 0x800C
    ScrCmd_038 3
    ScrCmd_039
    ScrCmd_03B 0x800C
    ScrCmd_014 0x7D0
    End

_0111:
    ScrCmd_036 6, 1, 0, 0x800C
    ScrCmd_038 3
    ScrCmd_039
    ScrCmd_03B 0x800C
    ScrCmd_014 0x7D0
    End

_0128:
    ScrCmd_037 3, 0
    ScrCmd_038 3
    ScrCmd_039
    ScrCmd_03A 7, 0x800C
    ScrCmd_014 0x7D0
    End

_013D:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 3
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0150:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 4
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

    .byte 0
