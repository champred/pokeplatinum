    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _0020
    ScriptEntry _0033
    ScriptEntry _0046
    ScriptEntry _0057
    ScriptEntry _006A
    ScriptEntry _0134
    ScriptEntry _001E
    .short 0xFD13

_001E:
    End

_0020:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 3
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0033:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 4
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0046:
    PlayFanfare 0x5DC
    LockAll
    Message 5
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_0057:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 2
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_006A:
    LockAll
    ApplyMovement 4, _00FC
    ApplyMovement 0xFF, _00F0
    WaitMovement
    Message 0
    CloseMessage
    ApplyMovement 4, _0110
    WaitMovement
    ClearFlag 0x1BB
    ScrCmd_186 5, 12, 15
    ScrCmd_188 5, 16
    ScrCmd_189 5, 2
    ScrCmd_064 5
    ScrCmd_065 4
    SetFlag 113
    SetVar 0x411D, 1
    WaitFrames 30, 0x800C
    Message 1
    ApplyMovement 5, _0110
    WaitMovement
    ClearFlag 0x1C2
    ScrCmd_186 4, 12, 15
    ScrCmd_188 4, 16
    ScrCmd_189 4, 2
    ScrCmd_064 4
    ScrCmd_065 5
    CloseMessage
    ReleaseAll
    End

    .balign 4, 0
_00F0:
    MoveAction_03F 9
    MoveAction_023
    EndMovement

    .balign 4, 0
_00FC:
    MoveAction_026
    MoveAction_04B
    MoveAction_03F 2
    MoveAction_00E 2
    EndMovement

    .balign 4, 0
_0110:
    MoveAction_001
    MoveAction_03D
    MoveAction_003
    MoveAction_03E
    MoveAction_000
    MoveAction_03E
    MoveAction_002
    MoveAction_03D
    EndMovement

_0134:
    ScrCmd_07E 0x1D3, 1, 0x800C
    GoToIfEq 0x800C, 0, _01AA
    ScrCmd_28B 3, 0x800C
    GoToIfEq 0x800C, 0, _01AA
    GoToIfUnset 129, _01AA
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    ScrCmd_0CD 0
    ScrCmd_0D1 1, 0x1D3
    Message 6
    CloseMessage
    PlayFanfare 0x5FB
    FadeScreen 6, 1, 0, 0x7FFF
    WaitFadeScreen
    ScrCmd_065 6
    ScrCmd_04B 0x5FB
    FadeScreen 6, 1, 1, 0x7FFF
    WaitFadeScreen
    Message 7
    WaitButtonPress
    CloseMessage
    ReleaseAll
    End

_01AA:
    End
