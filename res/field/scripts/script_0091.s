    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _000E
    ScriptEntry _0021
    ScriptEntry _0034
    .short 0xFD13

_000E:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 0
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0021:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 1
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0034:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 2
    ScrCmd_03E 0x800C
    GoToIfEq 0x800C, 1, _006F
    Message 3
    ScrCmd_03E 0x800C
    GoToIfEq 0x800C, 1, _006F
    Message 4
    GoTo _007A
    End

_006F:
    Message 5
    GoTo _007A
    End

_007A:
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

    .byte 0
    .byte 0
