#include <nitro.h>
#include <string.h>

#include "field/field_system.h"
#include "overlay006/wild_encounters.h"

#include "narc.h"
#include "heap.h"
#include "map_header.h"
#include "map_header_data.h"
#include "map_object.h"

#include "constants/heap.h"

static void MapHeaderData_LoadEvents(MapHeaderData * data, int headerID);
static void MapHeaderData_ParseEvents(MapHeaderData * data);
static void MapHeaderData_LoadScripts(MapHeaderData * data, int headerID);

void MapHeaderData_Init (FieldSystem * fieldSystem, enum HeapId heapID)
{
    GF_ASSERT(fieldSystem->mapHeaderData == NULL);
    fieldSystem->mapHeaderData = Heap_AllocFromHeap(heapID, sizeof(MapHeaderData));
}

void MapHeaderData_Free (FieldSystem * fieldSystem)
{
    GF_ASSERT(fieldSystem->mapHeaderData != NULL);
    Heap_FreeToHeap(fieldSystem->mapHeaderData);
}

void MapHeaderData_Load (FieldSystem * fieldSystem, int headerID)
{
    GF_ASSERT(fieldSystem->mapHeaderData != NULL);

    MapHeaderData_LoadEvents(fieldSystem->mapHeaderData, headerID);
    MapHeaderData_ParseEvents(fieldSystem->mapHeaderData);
    MapHeaderData_LoadWildEncounters(&fieldSystem->mapHeaderData->wildEncounters, headerID);
    MapHeaderData_LoadScripts(fieldSystem->mapHeaderData, headerID);
}

static void MapHeaderData_LoadEvents (MapHeaderData * data, int headerID)
{
    int eventsID = MapHeader_GetEventsArchiveID(headerID);
    GF_ASSERT(NARC_GetMemberSizeByIndexPair(NARC_INDEX_FIELDDATA__EVENTDATA__ZONE_EVENT, eventsID) < sizeof(data->tmpEventsBuf));
    NARC_ReadWholeMemberByIndexPair(data->tmpEventsBuf, NARC_INDEX_FIELDDATA__EVENTDATA__ZONE_EVENT, eventsID);
}

void sub_0203A418 (FieldSystem * fieldSystem)
{
    int numObjectEvents = fieldSystem->mapHeaderData->numObjectEvents;

    GF_ASSERT(fieldSystem->mapHeaderData != NULL);

    if (numObjectEvents != 0) {
        sub_02062068(fieldSystem->mapObjMan, fieldSystem->location->mapId, numObjectEvents, fieldSystem->mapHeaderData->objectEvents);
    }
}

const BgEvent * MapHeaderData_GetBgEvents (const FieldSystem * fieldSystem)
{
    return fieldSystem->mapHeaderData->bgEvents;
}

int MapHeaderData_GetNumBgEvents (const FieldSystem * fieldSystem)
{
    return fieldSystem->mapHeaderData->numBgEvents;
}

const WarpEvent * MapHeaderData_GetWarpEventByIndex (const FieldSystem * fieldSystem, int index)
{
    return (index >= fieldSystem->mapHeaderData->numWarpEvents)
        ? NULL
        : &fieldSystem->mapHeaderData->warpEvents[index];
}

int MapHeaderData_GetIndexOfWarpEventAtPos (const FieldSystem * fieldSystem, int x, int z)
{
    for (int i = 0; i < fieldSystem->mapHeaderData->numWarpEvents; i++) {
        if (fieldSystem->mapHeaderData->warpEvents[i].x == x
            && fieldSystem->mapHeaderData->warpEvents[i].z == z) {
            return i;
        }
    }

    return -1;
}

int MapHeaderData_GetNumCoordEvents (const FieldSystem * fieldSystem)
{
    return fieldSystem->mapHeaderData->numCoordEvents;
}

const CoordEvent * MapHeaderData_GetCoordEvents (const FieldSystem * fieldSystem)
{
    return fieldSystem->mapHeaderData->coordEvents;
}

u32 MapHeaderData_GetNumObjectEvents (const FieldSystem * fieldSystem)
{
    return fieldSystem->mapHeaderData->numObjectEvents;
}

const ObjectEvent * MapHeaderData_GetObjectEvents (const FieldSystem * fieldSystem)
{
    return fieldSystem->mapHeaderData->objectEvents;
}

BOOL MapHeaderData_SetObjectEventPos (FieldSystem * fieldSystem, int localID, u16 x, u16 z)
{
    int i;
    ObjectEvent * objectEvent = fieldSystem->mapHeaderData->objectEvents;
    u32 numObjectEvents = fieldSystem->mapHeaderData->numObjectEvents;

    for (i = 0; i < numObjectEvents; i++) {
        if (objectEvent[i].localID == localID) {
            objectEvent[i].x = x;
            objectEvent[i].z = z;
            return TRUE;
        }
    }

    GF_ASSERT(FALSE);
    return FALSE;
}

BOOL MapHeaderData_SetObjectEventDir (FieldSystem * fieldSystem, int localID, int dir)
{
    int i;
    ObjectEvent * objectEvent = fieldSystem->mapHeaderData->objectEvents;
    u32 numObjectEvents = fieldSystem->mapHeaderData->numObjectEvents;

    for (i = 0; i < numObjectEvents; i++) {
        if (objectEvent[i].localID == localID) {
            objectEvent[i].dir = dir;
            return TRUE;
        }
    }

    GF_ASSERT(FALSE);
    return FALSE;
}

BOOL MapHeaderData_SetObjectEventMovementType (FieldSystem * fieldSystem, int localID, int movementType)
{
    int i;
    ObjectEvent * objectEvent = fieldSystem->mapHeaderData->objectEvents;
    u32 numObjectEvents = fieldSystem->mapHeaderData->numObjectEvents;

    for (i = 0; i < numObjectEvents; i++) {
        if (objectEvent[i].localID == localID) {
            objectEvent[i].movementType = movementType;
            return TRUE;
        }
    }

    GF_ASSERT(FALSE);
    return FALSE;
}

BOOL MapHeaderData_SetWarpEventPos (FieldSystem * fieldSystem, u16 index, u16 x, u16 z)
{
    WarpEvent * warpEvent = fieldSystem->mapHeaderData->warpEvents;
    warpEvent[index].x = x;
    warpEvent[index].z = z;
    return TRUE;
}

BOOL MapHeaderData_SetWarpEventDestHeaderID (FieldSystem * fieldSystem, u16 index, u16 destHeaderID)
{
    WarpEvent * warpEvents = fieldSystem->mapHeaderData->warpEvents;
    warpEvents[index].destHeaderID = destHeaderID;
    return TRUE;
}

BOOL MapHeaderData_SetWarpEventDestWarpID (FieldSystem * fieldSystem, u16 index, u16 destWarpID)
{
    WarpEvent * warpEvents = fieldSystem->mapHeaderData->warpEvents;
    warpEvents[index].destWarpID = destWarpID;
    return TRUE;
}

BOOL MapHeaderData_SetBgEventPos (FieldSystem * fieldSystem, u16 index, u16 x, u16 z)
{
    BgEvent * bgEvent = MapHeaderData_GetBgEvents(fieldSystem);

    bgEvent += index;
    bgEvent->x = x;
    bgEvent->z = z;

    return TRUE;
}

static void MapHeaderData_ParseEvents (MapHeaderData * data)
{
    const u8 * events = (const u8 *)data->tmpEventsBuf;

    // bgEvents
    {
        data->numBgEvents = *(u32 *)events;
        events += sizeof(u32);
        if (data->numBgEvents != 0) {
            data->bgEvents = (const BgEvent *)events;
        } else {
            data->bgEvents = NULL;
        }
        events += sizeof(BgEvent) * data->numBgEvents;
    }

    // objectEvents
    {
        data->numObjectEvents = *(u32 *)events;
        events += sizeof(u32);
        if (data->numObjectEvents != 0) {
            data->objectEvents = (const ObjectEvent *)events;
        } else {
            data->objectEvents = NULL;
        }
        events += sizeof(ObjectEvent) * data->numObjectEvents;
    }

    // warpEvents
    {
        data->numWarpEvents = *(u32 *)events;
        events += sizeof(u32);
        if (data->numWarpEvents != 0) {
            data->warpEvents = (const WarpEvent *)events;
        } else {
            data->warpEvents = NULL;
        }
        events += sizeof(WarpEvent) * data->numWarpEvents;
    }

    // coordEvents
    {
        data->numCoordEvents = *(u32 *)events;
        events += sizeof(u32);
        if (data->numCoordEvents != 0) {
            data->coordEvents = (const CoordEvent *)events;
        } else {
            data->coordEvents = NULL;
        }
        events += sizeof(CoordEvent) * data->numCoordEvents;
    }
}

void MapHeaderData_LoadWildEncounters (WildEncounters * data, int headerID)
{
    memset(data, 0, sizeof(WildEncounters));
    if (MapHeader_HasWildEncounters(headerID)) {
        int narcIndex = (GAME_VERSION == DIAMOND || GAME_VERSION == PLATINUM)
            ? NARC_INDEX_FIELDDATA__ENCOUNTDATA__PL_ENC_DATA
            : NARC_INDEX_FIELDDATA__ENCOUNTDATA__P_ENC_DATA;
        NARC_ReadWholeMemberByIndexPair(data, narcIndex, MapHeader_GetWildEncountersArchiveID(headerID));
    }
}

const WildEncounters * MapHeaderData_GetWildEncounters (const FieldSystem * fieldSystem)
{
    return &fieldSystem->mapHeaderData->wildEncounters;
}

static void MapHeaderData_LoadScripts (MapHeaderData * data, int headerID)
{
    int mapScriptID = MapHeader_GetMapScriptArchiveID(headerID);

    MI_CpuClearFast(data->scripts, sizeof(data->scripts));
    GF_ASSERT(NARC_GetMemberSizeByIndexPair(NARC_INDEX_FIELDDATA__SCRIPT__SCR_SEQ, mapScriptID) < sizeof(data->scripts));

    NARC_ReadWholeMemberByIndexPair(data->scripts, NARC_INDEX_FIELDDATA__SCRIPT__SCR_SEQ, mapScriptID);
}

const u8 * MapHeaderData_GetScripts (const FieldSystem * fieldSystem)
{
    GF_ASSERT(fieldSystem->mapHeaderData != NULL);
    return (const u8 *)&fieldSystem->mapHeaderData->scripts;
}

BOOL MapHeaderData_IsAnyObjectEventAtPos (const FieldSystem * fieldSystem, u16 x, u16 z)
{
    const MapHeaderData * data = fieldSystem->mapHeaderData;

    for (u32 i = 0; i < data->numObjectEvents; i++) {
        if (data->objectEvents[i].x == x && data->objectEvents[i].z == z) {
            return FALSE;
        }
    }

    return TRUE;
}
