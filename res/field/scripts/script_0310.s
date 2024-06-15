    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _000E
    ScriptEntry _0062
    ScriptEntry _007D
    .short 0xFD13

_000E:
    SetFlag 0x9D5
    ScrCmd_22D 2, 0x4000
    GoToIfEq 0x4000, 0, _005C
    ScrCmd_07E 0x1C4, 1, 0x4000
    GoToIfEq 0x4000, 0, _005C
    ScrCmd_28B 1, 0x4000
    GoToIfEq 0x4000, 0, _005C
    GoToIfSet 0x123, _005C
    ClearFlag 0x251
    End

_005C:
    SetFlag 0x251
    End

_0062:
    GoToIfSet 142, _006F
    End

_006F:
    SetFlag 0x251
    ScrCmd_065 0
    ClearFlag 142
    End

_007D:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_04C 0x1EC, 0
    Message 0
    CloseMessage
    SetFlag 142
    ScrCmd_318 0x1EC, 30
    ClearFlag 142
    ScrCmd_0EC 0x800C
    GoToIfEq 0x800C, 0, _00D7
    ScrCmd_2BC 0x800C
    GoToIfEq 0x800C, 1, _00C8
    SetFlag 0x123
    ReleaseAll
    End

_00C8:
    Message 1
    WaitButtonPress
    CloseMessage
    ClearFlag 0x251
    ReleaseAll
    End

_00D7:
    ScrCmd_0EB
    ClearFlag 0x251
    ReleaseAll
    End

    .byte 0
    .byte 0
    .byte 0
