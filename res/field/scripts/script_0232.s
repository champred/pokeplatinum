    .include "macros/scrcmd.inc"

    .data

    ScriptEntry _0006
    .short 0xFD13

_0006:
    PlayFanfare 0x5DC
    LockAll
    FacePlayer
    Message 0
    WaitButtonPress
    CloseMessage
    ApplyMovement 16, _0024
    WaitMovement
    ReleaseAll
    End

    .balign 4, 0
_0024:
    MoveAction_000
    EndMovement
