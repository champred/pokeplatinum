    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _000E
    ScriptEntry _0068
    ScriptEntry _007B
    .short 0xFD13

_000E:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    GoToIfSet 0x139, _005D
    Message 0
    SetVar 0x8004, 218
    SetVar 0x8005, 1
    ScrCmd_07D 0x8004, 0x8005, 0x800C
    GoToIfEq 0x800C, 0, _0053
    SetFlag 0x139
    ScrCmd_014 0x7E0
    CloseMessage
    ReleaseAll
    End

_0053:
    ScrCmd_014 0x7E1
    CloseMessage
    ReleaseAll
    End

_005D:
    Message 1
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0068:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 2
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_007B:
    PlayFanfare 0x5DC
    LockAll
    Message 3
    ScrCmd_03E 0x800C
    GoToIfEq 0x800C, 0, _009D
    GoTo _00D3
    End

_009D:
    ScrCmd_0CD 0
    Message 4
    CloseMessage
    FadeScreen 6, 1, 0, 0
    WaitFadeScreen
    ScrCmd_04E 0x48E
    ScrCmd_04F
    ScrCmd_14E
    FadeScreen 6, 1, 1, 0
    WaitFadeScreen
    ScrCmd_0CD 0
    Message 5
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_00D3:
    CloseMessage
    ReleaseAll
    End

    .byte 0
    .byte 0
    .byte 0
