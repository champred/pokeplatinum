    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _000A
    ScriptEntry _002A
    .short 0xFD13

_000A:
    SetFlag 0x9D4
    Call _001C
    ScrCmd_285 0x410B, 0x410C
    End

_001C:
    SetVar 0x410B, 0
    SetVar 0x410C, 0
    Return

_002A:
    GoToIfSet 0x121, _0046
    PlayFanfare 0x5DC
    LockAll
    Message 0
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0046:
    PlayFanfare 0x5DC
    LockAll
    Message 1
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

    .byte 0
